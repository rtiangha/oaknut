// SPDX-FileCopyrightText: Copyright (c) 2023 merryhime <https://mary.rs>
// SPDX-License-Identifier: MIT

#include <array>
#include <cstdint>
#include <cstdio>
#include <limits>
#include <numeric>

#include <catch2/catch_test_macros.hpp>

#include "architecture.hpp"
#include "oaknut/oaknut.hpp"

using namespace oaknut;
using namespace oaknut::util;

#define T(HEX, CMD)                   \
    TEST_CASE(#CMD)                   \
    {                                 \
        using namespace oaknut;       \
        using namespace oaknut::util; \
                                      \
        std::uint32_t result;         \
        CodeGenerator code{&result};  \
                                      \
        code.CMD;                     \
                                      \
        REQUIRE(result == HEX);       \
    }

T(0x201007, AMX_LDX(X7))
T(0x201025, AMX_LDY(X5))
T(0x201049, AMX_STX(X9))
T(0x20106f, AMX_STY(X15))
T(0x201085, AMX_LDZ(X5))
T(0x2010a9, AMX_STZ(X9))
T(0x2010d8, AMX_LDZI(X24))
T(0x2010e3, AMX_STZI(X3))
T(0x20110c, AMX_EXTRX(X12))
T(0x20112b, AMX_EXTRY(X11))
T(0x201146, AMX_FMA64(X6))
T(0x201167, AMX_FMS64(X7))
T(0x201182, AMX_FMA32(X2))
T(0x2011ae, AMX_FMS32(X14))
T(0x2011cd, AMX_MAC16(X13))
T(0x2011eb, AMX_FMA16(X11))
T(0x201206, AMX_FMS16(X6))
T(0x201220, AMX_SET())
T(0x201221, AMX_CLR())
T(0x20125e, AMX_VECINT(X30))
T(0x20127d, AMX_VECFP(X29))
T(0x201291, AMX_MATINT(X17))
T(0x2012af, AMX_MATFP(X15))
T(0x2012c9, AMX_GENLUT(X9))

#if defined(ON_ARM64) & defined(__APPLE__)

#    include "oaknut/code_block.hpp"
#    include "oaknut/dual_code_block.hpp"

TEST_CASE("AMX_memcpy")
{
    std::array<uint8_t, 64> x_vec;
    x_vec.fill(1);

    std::array<uint8_t, 64> y_vec;
    y_vec.fill(0);

    CodeBlock mem{4096};
    CodeGenerator code{mem.ptr()};

    auto amx_memcpy = code.xptr<void (*)(void*, void*)>();

    mem.unprotect();

    code.AMX_SET();

    // Clear upper byte
    code.UBFX(X0, X0, 0, 56);
    code.UBFX(X1, X1, 0, 56);

    // Load vector X
    code.AMX_LDX(X0);

    // Store X into Y
    code.AMX_STX(X1);

    code.AMX_CLR();

    code.RET();

    mem.protect();
    mem.invalidate_all();

    amx_memcpy(x_vec.data(), y_vec.data());

    REQUIRE(x_vec == y_vec);
}

TEST_CASE("AMX_dot")
{
    std::array<uint16_t, 32> x_vec;
    std::iota(x_vec.begin(), x_vec.end(), 0);

    std::array<uint16_t, 32> y_vec;
    y_vec.fill(2);

    std::array<uint16_t, 32> z_vec;
    z_vec.fill(1);

    CodeBlock mem{4096};
    CodeGenerator code{mem.ptr()};

    mem.unprotect();

    auto dot = code.xptr<void (*)(void*, void*, void*)>();

    code.AMX_SET();

    // Clear upper byte
    code.UBFX(X0, X0, 0, 56);
    code.UBFX(X1, X1, 0, 56);
    code.UBFX(X2, X2, 0, 56);

    // Load vectors X and Y
    code.AMX_LDX(X0);
    code.AMX_LDY(X1);
    code.AMX_LDZ(X2);

    // Bit  Width
    // 63	1	Vector mode (1) or matrix mode (0)
    // 62	1	Z is i32 (1) or Z is i16 (0)	Ignored in vector mode; Z is always i16 there
    // 61	1	X is i8 (1) or X is i16 (0)
    // 60	1	Y is i8 (1) or Y is i16 (0)
    // 55	5	Right shift amount	Applied to x*y. When zero, sign of x and y inputs is less relevant.
    // 48	7	Ignored
    // 46	2	X enable mode
    // 41	5	X enable value	Meaning dependent upon associated mode
    // 39	2	Ignored
    // 37	2	Y enable mode	Ignored in vector mode
    // 32	5	Y enable value	Ignored in vector mode Meaning dependent upon associated mode
    // 30	2	Ignored
    // 29	1	Skip X input (1) or use X input (0)
    // 28	1	Skip Y input (1) or use Y input (0)
    // 27	1	Skip Z input (1) or use Z input (0)
    // 26	1	Ignored
    // 20	6	Z row	High bits ignored in matrix mode
    // 19	1	Ignored
    // 10	9	X offset (in bytes)
    // 9	1	Ignored
    // 0	9	Y offset (in bytes)
    code.MOV(X19, 0b1'0'0'0'00000'0000000'00'00000'00'00'00000'00'0'0'0'0'000000'0'000000000'0'000000000);

    // Z[i] += X[i] * Y[i]
    code.AMX_MAC16(X19);

    // Store Z
    code.AMX_STZ(X2);

    code.AMX_CLR();

    code.RET();

    mem.protect();
    mem.invalidate_all();

    dot(x_vec.data(), y_vec.data(), z_vec.data());

    for (const auto& element : z_vec) {
        std::printf("%u ", element);
    }
    std::putchar('\n');
}

#endif