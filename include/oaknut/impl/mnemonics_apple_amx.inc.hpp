// SPDX-FileCopyrightText: Copyright (c) 2023 merryhime <https://mary.rs>
// SPDX-License-Identifier: MIT

void AMX_LDX(XReg xn)
{
    emit<"0000000000100000000100ooooonnnnn", "o", "n">(0, xn);
}

void AMX_LDY(XReg xn)
{
    emit<"0000000000100000000100ooooonnnnn", "o", "n">(1, xn);
}

void AMX_STX(XReg xn)
{
    emit<"0000000000100000000100ooooonnnnn", "o", "n">(2, xn);
}

void AMX_STY(XReg xn)
{
    emit<"0000000000100000000100ooooonnnnn", "o", "n">(3, xn);
}

void AMX_LDZ(XReg xn)
{
    emit<"0000000000100000000100ooooonnnnn", "o", "n">(4, xn);
}

void AMX_STZ(XReg xn)
{
    emit<"0000000000100000000100ooooonnnnn", "o", "n">(5, xn);
}

void AMX_LDZI(XReg xn)
{
    emit<"0000000000100000000100ooooonnnnn", "o", "n">(6, xn);
}

void AMX_STZI(XReg xn)
{
    emit<"0000000000100000000100ooooonnnnn", "o", "n">(7, xn);
}

void AMX_EXTRX(XReg xn)
{
    emit<"0000000000100000000100ooooonnnnn", "o", "n">(8, xn);
}

void AMX_EXTRY(XReg xn)
{
    emit<"0000000000100000000100ooooonnnnn", "o", "n">(9, xn);
}

void AMX_FMA64(XReg xn)
{
    emit<"0000000000100000000100ooooonnnnn", "o", "n">(10, xn);
}

void AMX_FMS64(XReg xn)
{
    emit<"0000000000100000000100ooooonnnnn", "o", "n">(11, xn);
}

void AMX_FMA32(XReg xn)
{
    emit<"0000000000100000000100ooooonnnnn", "o", "n">(12, xn);
}

void AMX_FMS32(XReg xn)
{
    emit<"0000000000100000000100ooooonnnnn", "o", "n">(13, xn);
}

void AMX_MAC16(XReg xn)
{
    emit<"0000000000100000000100ooooonnnnn", "o", "n">(14, xn);
}

void AMX_FMA16(XReg xn)
{
    emit<"0000000000100000000100ooooonnnnn", "o", "n">(15, xn);
}

void AMX_FMS16(XReg xn)
{
    emit<"0000000000100000000100ooooonnnnn", "o", "n">(16, xn);
}

void AMX_SET()
{
    emit<"0000000000100000000100oooooiiiii", "o", "i">(17, 0);
}

void AMX_CLR()
{
    emit<"0000000000100000000100oooooiiiii", "o", "i">(17, 1);
}

void AMX_VECINT(XReg xn)
{
    emit<"0000000000100000000100ooooonnnnn", "o", "n">(18, xn);
}

void AMX_VECFP(XReg xn)
{
    emit<"0000000000100000000100ooooonnnnn", "o", "n">(19, xn);
}

void AMX_MATINT(XReg xn)
{
    emit<"0000000000100000000100ooooonnnnn", "o", "n">(20, xn);
}

void AMX_MATFP(XReg xn)
{
    emit<"0000000000100000000100ooooonnnnn", "o", "n">(21, xn);
}

void AMX_GENLUT(XReg xn)
{
    emit<"0000000000100000000100ooooonnnnn", "o", "n">(22, xn);
}
