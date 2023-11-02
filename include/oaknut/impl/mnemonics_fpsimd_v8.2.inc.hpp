// SPDX-FileCopyrightText: Copyright (c) 2022 merryhime <https://mary.rs>
// SPDX-License-Identifier: MIT

// FEAT_DotProd

void SDOT(VReg_2S rd, VReg_8B rn, SElem em)
{
    emit<"0000111110LMmmmm1110H0nnnnnddddd", "d", "n", "Mm", "H", "L">(rd, rn, em.reg_index(), em.elem_index() >> 1, em.elem_index() & 1);
}
void SDOT(VReg_4S rd, VReg_16B rn, SElem em)
{
    emit<"0100111110LMmmmm1110H0nnnnnddddd", "d", "n", "Mm", "H", "L">(rd, rn, em.reg_index(), em.elem_index() >> 1, em.elem_index() & 1);
}
void SDOT(VReg_2S rd, VReg_8B rn, VReg_8B rm)
{
    emit<"00001110100mmmmm100101nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void SDOT(VReg_4S rd, VReg_16B rn, VReg_16B rm)
{
    emit<"01001110100mmmmm100101nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void UDOT(VReg_2S rd, VReg_8B rn, SElem em)
{
    emit<"0010111110LMmmmm1110H0nnnnnddddd", "d", "n", "Mm", "H", "L">(rd, rn, em.reg_index(), em.elem_index() >> 1, em.elem_index() & 1);
}
void UDOT(VReg_4S rd, VReg_16B rn, SElem em)
{
    emit<"0110111110LMmmmm1110H0nnnnnddddd", "d", "n", "Mm", "H", "L">(rd, rn, em.reg_index(), em.elem_index() >> 1, em.elem_index() & 1);
}
void UDOT(VReg_2S rd, VReg_8B rn, VReg_8B rm)
{
    emit<"00101110100mmmmm100101nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void UDOT(VReg_4S rd, VReg_16B rn, VReg_16B rm)
{
    emit<"01101110100mmmmm100101nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}

// FEAT_FHM

void FMLAL(VReg_2S rd, VReg_2H rn, HElem em)
{
    if (em.reg_index() >= 16)
        throw OaknutException{ExceptionType::InvalidCombination};
    emit<"0000111110LMmmmm0000H0nnnnnddddd", "d", "n", "m", "H", "L", "M">(rd, rn, em.reg_index(), em.elem_index() >> 2, (em.elem_index() >> 1) & 1, em.elem_index() & 1);
}
void FMLAL(VReg_4S rd, VReg_4H rn, HElem em)
{
    if (em.reg_index() >= 16)
        throw OaknutException{ExceptionType::InvalidCombination};
    emit<"0100111110LMmmmm0000H0nnnnnddddd", "d", "n", "m", "H", "L", "M">(rd, rn, em.reg_index(), em.elem_index() >> 2, (em.elem_index() >> 1) & 1, em.elem_index() & 1);
}
void FMLAL2(VReg_2S rd, VReg_2H rn, HElem em)
{
    if (em.reg_index() >= 16)
        throw OaknutException{ExceptionType::InvalidCombination};
    emit<"0010111110LMmmmm1000H0nnnnnddddd", "d", "n", "m", "H", "L", "M">(rd, rn, em.reg_index(), em.elem_index() >> 2, (em.elem_index() >> 1) & 1, em.elem_index() & 1);
}
void FMLAL2(VReg_4S rd, VReg_4H rn, HElem em)
{
    if (em.reg_index() >= 16)
        throw OaknutException{ExceptionType::InvalidCombination};
    emit<"0110111110LMmmmm1000H0nnnnnddddd", "d", "n", "m", "H", "L", "M">(rd, rn, em.reg_index(), em.elem_index() >> 2, (em.elem_index() >> 1) & 1, em.elem_index() & 1);
}
void FMLAL(VReg_2S rd, VReg_2H rn, VReg_2H rm)
{
    emit<"00001110001mmmmm111011nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMLAL(VReg_4S rd, VReg_4H rn, VReg_4H rm)
{
    emit<"01001110001mmmmm111011nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMLAL2(VReg_2S rd, VReg_2H rn, VReg_2H rm)
{
    emit<"00101110001mmmmm110011nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMLAL2(VReg_4S rd, VReg_4H rn, VReg_4H rm)
{
    emit<"01101110001mmmmm110011nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMLSL(VReg_2S rd, VReg_2H rn, HElem em)
{
    if (em.reg_index() >= 16)
        throw OaknutException{ExceptionType::InvalidCombination};
    emit<"0000111110LMmmmm0100H0nnnnnddddd", "d", "n", "m", "H", "L", "M">(rd, rn, em.reg_index(), em.elem_index() >> 2, (em.elem_index() >> 1) & 1, em.elem_index() & 1);
}
void FMLSL(VReg_4S rd, VReg_4H rn, HElem em)
{
    if (em.reg_index() >= 16)
        throw OaknutException{ExceptionType::InvalidCombination};
    emit<"0100111110LMmmmm0100H0nnnnnddddd", "d", "n", "m", "H", "L", "M">(rd, rn, em.reg_index(), em.elem_index() >> 2, (em.elem_index() >> 1) & 1, em.elem_index() & 1);
}
void FMLSL2(VReg_2S rd, VReg_2H rn, HElem em)
{
    if (em.reg_index() >= 16)
        throw OaknutException{ExceptionType::InvalidCombination};
    emit<"0010111110LMmmmm1100H0nnnnnddddd", "d", "n", "m", "H", "L", "M">(rd, rn, em.reg_index(), em.elem_index() >> 2, (em.elem_index() >> 1) & 1, em.elem_index() & 1);
}
void FMLSL2(VReg_4S rd, VReg_4H rn, HElem em)
{
    if (em.reg_index() >= 16)
        throw OaknutException{ExceptionType::InvalidCombination};
    emit<"0110111110LMmmmm1100H0nnnnnddddd", "d", "n", "m", "H", "L", "M">(rd, rn, em.reg_index(), em.elem_index() >> 2, (em.elem_index() >> 1) & 1, em.elem_index() & 1);
}
void FMLSL(VReg_2S rd, VReg_2H rn, VReg_2H rm)
{
    emit<"00001110101mmmmm111011nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMLSL(VReg_4S rd, VReg_4H rn, VReg_4H rm)
{
    emit<"01001110101mmmmm111011nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMLSL2(VReg_2S rd, VReg_2H rn, VReg_2H rm)
{
    emit<"00101110101mmmmm110011nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMLSL2(VReg_4S rd, VReg_4H rn, VReg_4H rm)
{
    emit<"01101110101mmmmm110011nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}

// FEAT_FP16

void FABD(HReg rd, HReg rn, HReg rm)
{
    emit<"01111110110mmmmm000101nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FABD(VReg_4H rd, VReg_4H rn, VReg_4H rm)
{
    emit<"00101110110mmmmm000101nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FABD(VReg_8H rd, VReg_8H rn, VReg_8H rm)
{
    emit<"01101110110mmmmm000101nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FABS(HReg rd, HReg rn)
{
    emit<"0001111011100000110000nnnnnddddd", "d", "n">(rd, rn);
}
void FABS(VReg_4H rd, VReg_4H rn)
{
    emit<"0000111011111000111110nnnnnddddd", "d", "n">(rd, rn);
}
void FABS(VReg_8H rd, VReg_8H rn)
{
    emit<"0100111011111000111110nnnnnddddd", "d", "n">(rd, rn);
}
void FACGE(HReg rd, HReg rn, HReg rm)
{
    emit<"01111110010mmmmm001011nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FACGE(VReg_4H rd, VReg_4H rn, VReg_4H rm)
{
    emit<"00101110010mmmmm001011nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FACGE(VReg_8H rd, VReg_8H rn, VReg_8H rm)
{
    emit<"01101110010mmmmm001011nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FACGT(HReg rd, HReg rn, HReg rm)
{
    emit<"01111110110mmmmm001011nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FACGT(VReg_4H rd, VReg_4H rn, VReg_4H rm)
{
    emit<"00101110110mmmmm001011nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FACGT(VReg_8H rd, VReg_8H rn, VReg_8H rm)
{
    emit<"01101110110mmmmm001011nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FADD(HReg rd, HReg rn, HReg rm)
{
    emit<"00011110111mmmmm001010nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FADD(VReg_4H rd, VReg_4H rn, VReg_4H rm)
{
    emit<"00001110010mmmmm000101nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FADD(VReg_8H rd, VReg_8H rn, VReg_8H rm)
{
    emit<"01001110010mmmmm000101nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FADDP(HReg rd, VReg_2H rn)
{
    emit<"0101111000110000110110nnnnnddddd", "d", "n">(rd, rn);
}
void FADDP(VReg_4H rd, VReg_4H rn, VReg_4H rm)
{
    emit<"00101110010mmmmm000101nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FADDP(VReg_8H rd, VReg_8H rn, VReg_8H rm)
{
    emit<"01101110010mmmmm000101nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FCCMP(HReg rn, HReg rm, Imm<4> nzcv, Cond cond)
{
    emit<"00011110111mmmmmcccc01nnnnn0ffff", "n", "m", "f", "c">(rn, rm, nzcv, cond);
}
void FCCMPE(HReg rn, HReg rm, Imm<4> nzcv, Cond cond)
{
    emit<"00011110111mmmmmcccc01nnnnn1ffff", "n", "m", "f", "c">(rn, rm, nzcv, cond);
}
void FCMEQ(HReg rd, HReg rn, HReg rm)
{
    emit<"01011110010mmmmm001001nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FCMEQ(VReg_4H rd, VReg_4H rn, VReg_4H rm)
{
    emit<"00001110010mmmmm001001nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FCMEQ(VReg_8H rd, VReg_8H rn, VReg_8H rm)
{
    emit<"01001110010mmmmm001001nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FCMEQ(HReg rd, HReg rn, ImmConstFZero)
{
    emit<"0101111011111000110110nnnnnddddd", "d", "n">(rd, rn);
}
void FCMEQ(VReg_4H rd, VReg_4H rn, ImmConstFZero)
{
    emit<"0000111011111000110110nnnnnddddd", "d", "n">(rd, rn);
}
void FCMEQ(VReg_8H rd, VReg_8H rn, ImmConstFZero)
{
    emit<"0100111011111000110110nnnnnddddd", "d", "n">(rd, rn);
}
void FCMGE(HReg rd, HReg rn, HReg rm)
{
    emit<"01111110010mmmmm001001nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FCMGE(VReg_4H rd, VReg_4H rn, VReg_4H rm)
{
    emit<"00101110010mmmmm001001nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FCMGE(VReg_8H rd, VReg_8H rn, VReg_8H rm)
{
    emit<"01101110010mmmmm001001nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FCMGE(HReg rd, HReg rn, ImmConstFZero)
{
    emit<"0111111011111000110010nnnnnddddd", "d", "n">(rd, rn);
}
void FCMGE(VReg_4H rd, VReg_4H rn, ImmConstFZero)
{
    emit<"0010111011111000110010nnnnnddddd", "d", "n">(rd, rn);
}
void FCMGE(VReg_8H rd, VReg_8H rn, ImmConstFZero)
{
    emit<"0110111011111000110010nnnnnddddd", "d", "n">(rd, rn);
}
void FCMGT(HReg rd, HReg rn, HReg rm)
{
    emit<"01111110110mmmmm001001nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FCMGT(VReg_4H rd, VReg_4H rn, VReg_4H rm)
{
    emit<"00101110110mmmmm001001nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FCMGT(VReg_8H rd, VReg_8H rn, VReg_8H rm)
{
    emit<"01101110110mmmmm001001nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FCMGT(HReg rd, HReg rn, ImmConstFZero)
{
    emit<"0101111011111000110010nnnnnddddd", "d", "n">(rd, rn);
}
void FCMGT(VReg_4H rd, VReg_4H rn, ImmConstFZero)
{
    emit<"0000111011111000110010nnnnnddddd", "d", "n">(rd, rn);
}
void FCMGT(VReg_8H rd, VReg_8H rn, ImmConstFZero)
{
    emit<"0100111011111000110010nnnnnddddd", "d", "n">(rd, rn);
}
void FCMLE(HReg rd, HReg rn, ImmConstFZero)
{
    emit<"0111111011111000110110nnnnnddddd", "d", "n">(rd, rn);
}
void FCMLE(VReg_4H rd, VReg_4H rn, ImmConstFZero)
{
    emit<"0010111011111000110110nnnnnddddd", "d", "n">(rd, rn);
}
void FCMLE(VReg_8H rd, VReg_8H rn, ImmConstFZero)
{
    emit<"0110111011111000110110nnnnnddddd", "d", "n">(rd, rn);
}
void FCMLT(HReg rd, HReg rn, ImmConstFZero)
{
    emit<"0101111011111000111010nnnnnddddd", "d", "n">(rd, rn);
}
void FCMLT(VReg_4H rd, VReg_4H rn, ImmConstFZero)
{
    emit<"0000111011111000111010nnnnnddddd", "d", "n">(rd, rn);
}
void FCMLT(VReg_8H rd, VReg_8H rn, ImmConstFZero)
{
    emit<"0100111011111000111010nnnnnddddd", "d", "n">(rd, rn);
}
void FCMP(HReg rn, HReg rm)
{
    emit<"00011110111mmmmm001000nnnnn00000", "n", "m">(rn, rm);
}
void FCMP(HReg rn, ImmConstFZero)
{
    emit<"0001111011100000001000nnnnn01000", "n">(rn);
}
void FCMPE(HReg rn, HReg rm)
{
    emit<"00011110111mmmmm001000nnnnn10000", "n", "m">(rn, rm);
}
void FCMPE(HReg rn, ImmConstFZero)
{
    emit<"0001111011100000001000nnnnn11000", "n">(rn);
}
void FCSEL(HReg rd, HReg rn, HReg rm, Cond cond)
{
    emit<"00011110111mmmmmcccc11nnnnnddddd", "d", "n", "m", "c">(rd, rn, rm, cond);
}
void FCVTAS(WReg wd, HReg rn)
{
    emit<"0001111011100100000000nnnnnddddd", "d", "n">(wd, rn);
}
void FCVTAS(XReg xd, HReg rn)
{
    emit<"1001111011100100000000nnnnnddddd", "d", "n">(xd, rn);
}
void FCVTAS(HReg rd, HReg rn)
{
    emit<"0101111001111001110010nnnnnddddd", "d", "n">(rd, rn);
}
void FCVTAS(VReg_4H rd, VReg_4H rn)
{
    emit<"0000111001111001110010nnnnnddddd", "d", "n">(rd, rn);
}
void FCVTAS(VReg_8H rd, VReg_8H rn)
{
    emit<"0100111001111001110010nnnnnddddd", "d", "n">(rd, rn);
}
void FCVTAU(WReg wd, HReg rn)
{
    emit<"0001111011100101000000nnnnnddddd", "d", "n">(wd, rn);
}
void FCVTAU(XReg xd, HReg rn)
{
    emit<"1001111011100101000000nnnnnddddd", "d", "n">(xd, rn);
}
void FCVTAU(HReg rd, HReg rn)
{
    emit<"0111111001111001110010nnnnnddddd", "d", "n">(rd, rn);
}
void FCVTAU(VReg_4H rd, VReg_4H rn)
{
    emit<"0010111001111001110010nnnnnddddd", "d", "n">(rd, rn);
}
void FCVTAU(VReg_8H rd, VReg_8H rn)
{
    emit<"0110111001111001110010nnnnnddddd", "d", "n">(rd, rn);
}
void FCVTMS(WReg wd, HReg rn)
{
    emit<"0001111011110000000000nnnnnddddd", "d", "n">(wd, rn);
}
void FCVTMS(XReg xd, HReg rn)
{
    emit<"1001111011110000000000nnnnnddddd", "d", "n">(xd, rn);
}
void FCVTMS(HReg rd, HReg rn)
{
    emit<"0101111001111001101110nnnnnddddd", "d", "n">(rd, rn);
}
void FCVTMS(VReg_4H rd, VReg_4H rn)
{
    emit<"0000111001111001101110nnnnnddddd", "d", "n">(rd, rn);
}
void FCVTMS(VReg_8H rd, VReg_8H rn)
{
    emit<"0100111001111001101110nnnnnddddd", "d", "n">(rd, rn);
}
void FCVTMU(WReg wd, HReg rn)
{
    emit<"0001111011110001000000nnnnnddddd", "d", "n">(wd, rn);
}
void FCVTMU(XReg xd, HReg rn)
{
    emit<"1001111011110001000000nnnnnddddd", "d", "n">(xd, rn);
}
void FCVTMU(HReg rd, HReg rn)
{
    emit<"0111111001111001101110nnnnnddddd", "d", "n">(rd, rn);
}
void FCVTMU(VReg_4H rd, VReg_4H rn)
{
    emit<"0010111001111001101110nnnnnddddd", "d", "n">(rd, rn);
}
void FCVTMU(VReg_8H rd, VReg_8H rn)
{
    emit<"0110111001111001101110nnnnnddddd", "d", "n">(rd, rn);
}
void FCVTNS(WReg wd, HReg rn)
{
    emit<"0001111011100000000000nnnnnddddd", "d", "n">(wd, rn);
}
void FCVTNS(XReg xd, HReg rn)
{
    emit<"1001111011100000000000nnnnnddddd", "d", "n">(xd, rn);
}
void FCVTNS(HReg rd, HReg rn)
{
    emit<"0101111001111001101010nnnnnddddd", "d", "n">(rd, rn);
}
void FCVTNS(VReg_4H rd, VReg_4H rn)
{
    emit<"0000111001111001101010nnnnnddddd", "d", "n">(rd, rn);
}
void FCVTNS(VReg_8H rd, VReg_8H rn)
{
    emit<"0100111001111001101010nnnnnddddd", "d", "n">(rd, rn);
}
void FCVTNU(WReg wd, HReg rn)
{
    emit<"0001111011100001000000nnnnnddddd", "d", "n">(wd, rn);
}
void FCVTNU(XReg xd, HReg rn)
{
    emit<"1001111011100001000000nnnnnddddd", "d", "n">(xd, rn);
}
void FCVTNU(HReg rd, HReg rn)
{
    emit<"0111111001111001101010nnnnnddddd", "d", "n">(rd, rn);
}
void FCVTNU(VReg_4H rd, VReg_4H rn)
{
    emit<"0010111001111001101010nnnnnddddd", "d", "n">(rd, rn);
}
void FCVTNU(VReg_8H rd, VReg_8H rn)
{
    emit<"0110111001111001101010nnnnnddddd", "d", "n">(rd, rn);
}
void FCVTPS(WReg wd, HReg rn)
{
    emit<"0001111011101000000000nnnnnddddd", "d", "n">(wd, rn);
}
void FCVTPS(XReg xd, HReg rn)
{
    emit<"1001111011101000000000nnnnnddddd", "d", "n">(xd, rn);
}
void FCVTPS(HReg rd, HReg rn)
{
    emit<"0101111011111001101010nnnnnddddd", "d", "n">(rd, rn);
}
void FCVTPS(VReg_4H rd, VReg_4H rn)
{
    emit<"0000111011111001101010nnnnnddddd", "d", "n">(rd, rn);
}
void FCVTPS(VReg_8H rd, VReg_8H rn)
{
    emit<"0100111011111001101010nnnnnddddd", "d", "n">(rd, rn);
}
void FCVTPU(WReg wd, HReg rn)
{
    emit<"0001111011101001000000nnnnnddddd", "d", "n">(wd, rn);
}
void FCVTPU(XReg xd, HReg rn)
{
    emit<"1001111011101001000000nnnnnddddd", "d", "n">(xd, rn);
}
void FCVTPU(HReg rd, HReg rn)
{
    emit<"0111111011111001101010nnnnnddddd", "d", "n">(rd, rn);
}
void FCVTPU(VReg_4H rd, VReg_4H rn)
{
    emit<"0010111011111001101010nnnnnddddd", "d", "n">(rd, rn);
}
void FCVTPU(VReg_8H rd, VReg_8H rn)
{
    emit<"0110111011111001101010nnnnnddddd", "d", "n">(rd, rn);
}
void FCVTZS(WReg wd, HReg rn, ImmRange<1, 32> fbits)
{
    emit<"0001111011011000SSSSSSnnnnnddddd", "d", "n", "S">(wd, rn, 64 - fbits.value());
}
void FCVTZS(XReg xd, HReg rn, ImmRange<1, 64> fbits)
{
    emit<"1001111011011000SSSSSSnnnnnddddd", "d", "n", "S">(xd, rn, 64 - fbits.value());
}
void FCVTZS(WReg wd, HReg rn)
{
    emit<"0001111011111000000000nnnnnddddd", "d", "n">(wd, rn);
}
void FCVTZS(XReg xd, HReg rn)
{
    emit<"1001111011111000000000nnnnnddddd", "d", "n">(xd, rn);
}
void FCVTZS(HReg rd, HReg rn, ImmRange<1, 16> fbits)
{
    emit<"010111110001hbbb111111nnnnnddddd", "d", "n", "hb">(rd, rn, 32 - fbits.value());
}
void FCVTZS(VReg_4H rd, VReg_4H rn, ImmRange<1, 16> fbits)
{
    emit<"000011110001hbbb111111nnnnnddddd", "d", "n", "hb">(rd, rn, 32 - fbits.value());
}
void FCVTZS(VReg_8H rd, VReg_8H rn, ImmRange<1, 16> fbits)
{
    emit<"010011110001hbbb111111nnnnnddddd", "d", "n", "hb">(rd, rn, 32 - fbits.value());
}
void FCVTZS(HReg rd, HReg rn)
{
    emit<"0101111011111001101110nnnnnddddd", "d", "n">(rd, rn);
}
void FCVTZS(VReg_4H rd, VReg_4H rn)
{
    emit<"0000111011111001101110nnnnnddddd", "d", "n">(rd, rn);
}
void FCVTZS(VReg_8H rd, VReg_8H rn)
{
    emit<"0100111011111001101110nnnnnddddd", "d", "n">(rd, rn);
}
void FCVTZU(WReg wd, HReg rn, ImmRange<1, 32> fbits)
{
    emit<"0001111011011001SSSSSSnnnnnddddd", "d", "n", "S">(wd, rn, 64 - fbits.value());
}
void FCVTZU(XReg xd, HReg rn, ImmRange<1, 64> fbits)
{
    emit<"1001111011011001SSSSSSnnnnnddddd", "d", "n", "S">(xd, rn, 64 - fbits.value());
}
void FCVTZU(WReg wd, HReg rn)
{
    emit<"0001111011111001000000nnnnnddddd", "d", "n">(wd, rn);
}
void FCVTZU(XReg xd, HReg rn)
{
    emit<"1001111011111001000000nnnnnddddd", "d", "n">(xd, rn);
}
void FCVTZU(HReg rd, HReg rn, ImmRange<1, 16> fbits)
{
    emit<"011111110001hbbb111111nnnnnddddd", "d", "n", "hb">(rd, rn, 32 - fbits.value());
}
void FCVTZU(VReg_4H rd, VReg_4H rn, ImmRange<1, 16> fbits)
{
    emit<"001011110001hbbb111111nnnnnddddd", "d", "n", "hb">(rd, rn, 32 - fbits.value());
}
void FCVTZU(VReg_8H rd, VReg_8H rn, ImmRange<1, 16> fbits)
{
    emit<"011011110001hbbb111111nnnnnddddd", "d", "n", "hb">(rd, rn, 32 - fbits.value());
}
void FCVTZU(HReg rd, HReg rn)
{
    emit<"0111111011111001101110nnnnnddddd", "d", "n">(rd, rn);
}
void FCVTZU(VReg_4H rd, VReg_4H rn)
{
    emit<"0010111011111001101110nnnnnddddd", "d", "n">(rd, rn);
}
void FCVTZU(VReg_8H rd, VReg_8H rn)
{
    emit<"0110111011111001101110nnnnnddddd", "d", "n">(rd, rn);
}
void FDIV(HReg rd, HReg rn, HReg rm)
{
    emit<"00011110111mmmmm000110nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FDIV(VReg_4H rd, VReg_4H rn, VReg_4H rm)
{
    emit<"00101110010mmmmm001111nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FDIV(VReg_8H rd, VReg_8H rn, VReg_8H rm)
{
    emit<"01101110010mmmmm001111nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMADD(HReg rd, HReg rn, HReg rm, HReg ra)
{
    emit<"00011111110mmmmm0aaaaannnnnddddd", "d", "n", "m", "a">(rd, rn, rm, ra);
}
void FMAX(HReg rd, HReg rn, HReg rm)
{
    emit<"00011110111mmmmm010010nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMAX(VReg_4H rd, VReg_4H rn, VReg_4H rm)
{
    emit<"00001110010mmmmm001101nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMAX(VReg_8H rd, VReg_8H rn, VReg_8H rm)
{
    emit<"01001110010mmmmm001101nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMAXNM(HReg rd, HReg rn, HReg rm)
{
    emit<"00011110111mmmmm011010nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMAXNM(VReg_4H rd, VReg_4H rn, VReg_4H rm)
{
    emit<"00001110010mmmmm000001nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMAXNM(VReg_8H rd, VReg_8H rn, VReg_8H rm)
{
    emit<"01001110010mmmmm000001nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMAXNMP(HReg rd, VReg_2H rn)
{
    emit<"0101111000110000110010nnnnnddddd", "d", "n">(rd, rn);
}
void FMAXNMP(VReg_4H rd, VReg_4H rn, VReg_4H rm)
{
    emit<"00101110010mmmmm000001nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMAXNMP(VReg_8H rd, VReg_8H rn, VReg_8H rm)
{
    emit<"01101110010mmmmm000001nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMAXNMV(HReg rd, VReg_4H rn)
{
    emit<"0000111000110000110010nnnnnddddd", "d", "n">(rd, rn);
}
void FMAXNMV(HReg rd, VReg_8H rn)
{
    emit<"0100111000110000110010nnnnnddddd", "d", "n">(rd, rn);
}
void FMAXP(HReg rd, VReg_2H rn)
{
    emit<"0101111000110000111110nnnnnddddd", "d", "n">(rd, rn);
}
void FMAXP(VReg_4H rd, VReg_4H rn, VReg_4H rm)
{
    emit<"00101110010mmmmm001101nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMAXP(VReg_8H rd, VReg_8H rn, VReg_8H rm)
{
    emit<"01101110010mmmmm001101nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMAXV(HReg rd, VReg_4H rn)
{
    emit<"0000111000110000111110nnnnnddddd", "d", "n">(rd, rn);
}
void FMAXV(HReg rd, VReg_8H rn)
{
    emit<"0100111000110000111110nnnnnddddd", "d", "n">(rd, rn);
}
void FMIN(HReg rd, HReg rn, HReg rm)
{
    emit<"00011110111mmmmm010110nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMIN(VReg_4H rd, VReg_4H rn, VReg_4H rm)
{
    emit<"00001110110mmmmm001101nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMIN(VReg_8H rd, VReg_8H rn, VReg_8H rm)
{
    emit<"01001110110mmmmm001101nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMINNM(HReg rd, HReg rn, HReg rm)
{
    emit<"00011110111mmmmm011110nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMINNM(VReg_4H rd, VReg_4H rn, VReg_4H rm)
{
    emit<"00001110110mmmmm000001nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMINNM(VReg_8H rd, VReg_8H rn, VReg_8H rm)
{
    emit<"01001110110mmmmm000001nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMINNMP(HReg rd, VReg_2H rn)
{
    emit<"0101111010110000110010nnnnnddddd", "d", "n">(rd, rn);
}
void FMINNMP(VReg_4H rd, VReg_4H rn, VReg_4H rm)
{
    emit<"00101110110mmmmm000001nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMINNMP(VReg_8H rd, VReg_8H rn, VReg_8H rm)
{
    emit<"01101110110mmmmm000001nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMINNMV(HReg rd, VReg_4H rn)
{
    emit<"0000111010110000110010nnnnnddddd", "d", "n">(rd, rn);
}
void FMINNMV(HReg rd, VReg_8H rn)
{
    emit<"0100111010110000110010nnnnnddddd", "d", "n">(rd, rn);
}
void FMINP(HReg rd, VReg_2H rn)
{
    emit<"0101111010110000111110nnnnnddddd", "d", "n">(rd, rn);
}
void FMINP(VReg_4H rd, VReg_4H rn, VReg_4H rm)
{
    emit<"00101110110mmmmm001101nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMINP(VReg_8H rd, VReg_8H rn, VReg_8H rm)
{
    emit<"01101110110mmmmm001101nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMINV(HReg rd, VReg_4H rn)
{
    emit<"0000111010110000111110nnnnnddddd", "d", "n">(rd, rn);
}
void FMINV(HReg rd, VReg_8H rn)
{
    emit<"0100111010110000111110nnnnnddddd", "d", "n">(rd, rn);
}
void FMLA(HReg rd, HReg rn, HElem em)
{
    if (em.reg_index() >= 16)
        throw OaknutException{ExceptionType::InvalidCombination};
    emit<"0101111100LMmmmm0001H0nnnnnddddd", "d", "n", "m", "H", "L", "M">(rd, rn, em.reg_index(), em.elem_index() >> 2, (em.elem_index() >> 1) & 1, em.elem_index() & 1);
}
void FMLA(VReg_8B rd, VReg_8B rn, HElem em)
{
    if (em.reg_index() >= 16)
        throw OaknutException{ExceptionType::InvalidCombination};
    emit<"0000111100LMmmmm0001H0nnnnnddddd", "d", "n", "m", "H", "L", "M">(rd, rn, em.reg_index(), em.elem_index() >> 2, (em.elem_index() >> 1) & 1, em.elem_index() & 1);
}
void FMLA(VReg_16B rd, VReg_16B rn, HElem em)
{
    if (em.reg_index() >= 16)
        throw OaknutException{ExceptionType::InvalidCombination};
    emit<"0100111100LMmmmm0001H0nnnnnddddd", "d", "n", "m", "H", "L", "M">(rd, rn, em.reg_index(), em.elem_index() >> 2, (em.elem_index() >> 1) & 1, em.elem_index() & 1);
}
void FMLA(VReg_4H rd, VReg_4H rn, VReg_4H rm)
{
    emit<"00001110010mmmmm000011nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMLA(VReg_8H rd, VReg_8H rn, VReg_8H rm)
{
    emit<"01001110010mmmmm000011nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMLS(HReg rd, HReg rn, HElem em)
{
    if (em.reg_index() >= 16)
        throw OaknutException{ExceptionType::InvalidCombination};
    emit<"0101111100LMmmmm0101H0nnnnnddddd", "d", "n", "m", "H", "L", "M">(rd, rn, em.reg_index(), em.elem_index() >> 2, (em.elem_index() >> 1) & 1, em.elem_index() & 1);
}
void FMLS(VReg_8B rd, VReg_8B rn, HElem em)
{
    if (em.reg_index() >= 16)
        throw OaknutException{ExceptionType::InvalidCombination};
    emit<"0000111100LMmmmm0101H0nnnnnddddd", "d", "n", "m", "H", "L", "M">(rd, rn, em.reg_index(), em.elem_index() >> 2, (em.elem_index() >> 1) & 1, em.elem_index() & 1);
}
void FMLS(VReg_16B rd, VReg_16B rn, HElem em)
{
    if (em.reg_index() >= 16)
        throw OaknutException{ExceptionType::InvalidCombination};
    emit<"0100111100LMmmmm0101H0nnnnnddddd", "d", "n", "m", "H", "L", "M">(rd, rn, em.reg_index(), em.elem_index() >> 2, (em.elem_index() >> 1) & 1, em.elem_index() & 1);
}
void FMLS(VReg_4H rd, VReg_4H rn, VReg_4H rm)
{
    emit<"00001110110mmmmm000011nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMLS(VReg_8H rd, VReg_8H rn, VReg_8H rm)
{
    emit<"01001110110mmmmm000011nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMOV(WReg wd, HReg rn)
{
    emit<"0001111011100110000000nnnnnddddd", "d", "n">(wd, rn);
}
void FMOV(XReg xd, HReg rn)
{
    emit<"1001111011100110000000nnnnnddddd", "d", "n">(xd, rn);
}
void FMOV(HReg rd, WReg wn)
{
    emit<"0001111011100111000000nnnnnddddd", "d", "n">(rd, wn);
}
void FMOV(HReg rd, XReg xn)
{
    emit<"1001111011100111000000nnnnnddddd", "d", "n">(rd, xn);
}
void FMOV(HReg rd, HReg rn)
{
    emit<"0001111011100000010000nnnnnddddd", "d", "n">(rd, rn);
}
void FMOV(HReg rd, FImm8 imm)
{
    emit<"00011110111iiiiiiii10000000ddddd", "d", "i">(rd, imm);
}
void FMOV(VReg_4H rd, FImm8 imm)
{
    emit<"0000111100000vvv111111vvvvvddddd", "d", "v">(rd, imm);
}
void FMOV(VReg_8H rd, FImm8 imm)
{
    emit<"0100111100000vvv111111vvvvvddddd", "d", "v">(rd, imm);
}
void FMSUB(HReg rd, HReg rn, HReg rm, HReg ra)
{
    emit<"00011111110mmmmm1aaaaannnnnddddd", "d", "n", "m", "a">(rd, rn, rm, ra);
}
void FMUL(HReg rd, HReg rn, HElem em)
{
    if (em.reg_index() >= 16)
        throw OaknutException{ExceptionType::InvalidCombination};
    emit<"0101111100LMmmmm1001H0nnnnnddddd", "d", "n", "m", "H", "L", "M">(rd, rn, em.reg_index(), em.elem_index() >> 2, (em.elem_index() >> 1) & 1, em.elem_index() & 1);
}
void FMUL(VReg_8B rd, VReg_8B rn, HElem em)
{
    if (em.reg_index() >= 16)
        throw OaknutException{ExceptionType::InvalidCombination};
    emit<"0000111100LMmmmm1001H0nnnnnddddd", "d", "n", "m", "H", "L", "M">(rd, rn, em.reg_index(), em.elem_index() >> 2, (em.elem_index() >> 1) & 1, em.elem_index() & 1);
}
void FMUL(VReg_16B rd, VReg_16B rn, HElem em)
{
    if (em.reg_index() >= 16)
        throw OaknutException{ExceptionType::InvalidCombination};
    emit<"0100111100LMmmmm1001H0nnnnnddddd", "d", "n", "m", "H", "L", "M">(rd, rn, em.reg_index(), em.elem_index() >> 2, (em.elem_index() >> 1) & 1, em.elem_index() & 1);
}
void FMUL(HReg rd, HReg rn, HReg rm)
{
    emit<"00011110111mmmmm000010nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMUL(VReg_4H rd, VReg_4H rn, VReg_4H rm)
{
    emit<"00101110010mmmmm000111nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMUL(VReg_8H rd, VReg_8H rn, VReg_8H rm)
{
    emit<"01101110010mmmmm000111nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMULX(HReg rd, HReg rn, HReg rm)
{
    emit<"01011110010mmmmm000111nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMULX(VReg_4H rd, VReg_4H rn, VReg_4H rm)
{
    emit<"00001110010mmmmm000111nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMULX(VReg_8H rd, VReg_8H rn, VReg_8H rm)
{
    emit<"01001110010mmmmm000111nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FMULX(HReg rd, HReg rn, HElem em)
{
    if (em.reg_index() >= 16)
        throw OaknutException{ExceptionType::InvalidCombination};
    emit<"0111111100LMmmmm1001H0nnnnnddddd", "d", "n", "m", "H", "L", "M">(rd, rn, em.reg_index(), em.elem_index() >> 2, (em.elem_index() >> 1) & 1, em.elem_index() & 1);
}
void FMULX(VReg_8B rd, VReg_8B rn, HElem em)
{
    if (em.reg_index() >= 16)
        throw OaknutException{ExceptionType::InvalidCombination};
    emit<"0010111100LMmmmm1001H0nnnnnddddd", "d", "n", "m", "H", "L", "M">(rd, rn, em.reg_index(), em.elem_index() >> 2, (em.elem_index() >> 1) & 1, em.elem_index() & 1);
}
void FMULX(VReg_16B rd, VReg_16B rn, HElem em)
{
    if (em.reg_index() >= 16)
        throw OaknutException{ExceptionType::InvalidCombination};
    emit<"0110111100LMmmmm1001H0nnnnnddddd", "d", "n", "m", "H", "L", "M">(rd, rn, em.reg_index(), em.elem_index() >> 2, (em.elem_index() >> 1) & 1, em.elem_index() & 1);
}
void FNEG(HReg rd, HReg rn)
{
    emit<"0001111011100001010000nnnnnddddd", "d", "n">(rd, rn);
}
void FNEG(VReg_4H rd, VReg_4H rn)
{
    emit<"0010111011111000111110nnnnnddddd", "d", "n">(rd, rn);
}
void FNEG(VReg_8H rd, VReg_8H rn)
{
    emit<"0110111011111000111110nnnnnddddd", "d", "n">(rd, rn);
}
void FNMADD(HReg rd, HReg rn, HReg rm, HReg ra)
{
    emit<"00011111111mmmmm0aaaaannnnnddddd", "d", "n", "m", "a">(rd, rn, rm, ra);
}
void FNMSUB(HReg rd, HReg rn, HReg rm, HReg ra)
{
    emit<"00011111111mmmmm1aaaaannnnnddddd", "d", "n", "m", "a">(rd, rn, rm, ra);
}
void FNMUL(HReg rd, HReg rn, HReg rm)
{
    emit<"00011110111mmmmm100010nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FRECPE(HReg rd, HReg rn)
{
    emit<"0101111011111001110110nnnnnddddd", "d", "n">(rd, rn);
}
void FRECPE(VReg_4H rd, VReg_4H rn)
{
    emit<"0000111011111001110110nnnnnddddd", "d", "n">(rd, rn);
}
void FRECPE(VReg_8H rd, VReg_8H rn)
{
    emit<"0100111011111001110110nnnnnddddd", "d", "n">(rd, rn);
}
void FRECPS(HReg rd, HReg rn, HReg rm)
{
    emit<"01011110010mmmmm001111nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FRECPS(VReg_4H rd, VReg_4H rn, VReg_4H rm)
{
    emit<"00001110010mmmmm001111nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FRECPS(VReg_8H rd, VReg_8H rn, VReg_8H rm)
{
    emit<"01001110010mmmmm001111nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FRECPX(HReg rd, HReg rn)
{
    emit<"0101111011111001111110nnnnnddddd", "d", "n">(rd, rn);
}
void FRINTA(HReg rd, HReg rn)
{
    emit<"0001111011100110010000nnnnnddddd", "d", "n">(rd, rn);
}
void FRINTA(VReg_4H rd, VReg_4H rn)
{
    emit<"0010111001111001100010nnnnnddddd", "d", "n">(rd, rn);
}
void FRINTA(VReg_8H rd, VReg_8H rn)
{
    emit<"0110111001111001100010nnnnnddddd", "d", "n">(rd, rn);
}
void FRINTI(HReg rd, HReg rn)
{
    emit<"0001111011100111110000nnnnnddddd", "d", "n">(rd, rn);
}
void FRINTI(VReg_4H rd, VReg_4H rn)
{
    emit<"0010111011111001100110nnnnnddddd", "d", "n">(rd, rn);
}
void FRINTI(VReg_8H rd, VReg_8H rn)
{
    emit<"0110111011111001100110nnnnnddddd", "d", "n">(rd, rn);
}
void FRINTM(HReg rd, HReg rn)
{
    emit<"0001111011100101010000nnnnnddddd", "d", "n">(rd, rn);
}
void FRINTM(VReg_4H rd, VReg_4H rn)
{
    emit<"0000111001111001100110nnnnnddddd", "d", "n">(rd, rn);
}
void FRINTM(VReg_8H rd, VReg_8H rn)
{
    emit<"0100111001111001100110nnnnnddddd", "d", "n">(rd, rn);
}
void FRINTN(HReg rd, HReg rn)
{
    emit<"0001111011100100010000nnnnnddddd", "d", "n">(rd, rn);
}
void FRINTN(VReg_4H rd, VReg_4H rn)
{
    emit<"0000111001111001100010nnnnnddddd", "d", "n">(rd, rn);
}
void FRINTN(VReg_8H rd, VReg_8H rn)
{
    emit<"0100111001111001100010nnnnnddddd", "d", "n">(rd, rn);
}
void FRINTP(HReg rd, HReg rn)
{
    emit<"0001111011100100110000nnnnnddddd", "d", "n">(rd, rn);
}
void FRINTP(VReg_4H rd, VReg_4H rn)
{
    emit<"0000111011111001100010nnnnnddddd", "d", "n">(rd, rn);
}
void FRINTP(VReg_8H rd, VReg_8H rn)
{
    emit<"0100111011111001100010nnnnnddddd", "d", "n">(rd, rn);
}
void FRINTX(HReg rd, HReg rn)
{
    emit<"0001111011100111010000nnnnnddddd", "d", "n">(rd, rn);
}
void FRINTX(VReg_4H rd, VReg_4H rn)
{
    emit<"0010111001111001100110nnnnnddddd", "d", "n">(rd, rn);
}
void FRINTX(VReg_8H rd, VReg_8H rn)
{
    emit<"0110111001111001100110nnnnnddddd", "d", "n">(rd, rn);
}
void FRINTZ(HReg rd, HReg rn)
{
    emit<"0001111011100101110000nnnnnddddd", "d", "n">(rd, rn);
}
void FRINTZ(VReg_4H rd, VReg_4H rn)
{
    emit<"0000111011111001100110nnnnnddddd", "d", "n">(rd, rn);
}
void FRINTZ(VReg_8H rd, VReg_8H rn)
{
    emit<"0100111011111001100110nnnnnddddd", "d", "n">(rd, rn);
}
void FRSQRTE(HReg rd, HReg rn)
{
    emit<"0111111011111001110110nnnnnddddd", "d", "n">(rd, rn);
}
void FRSQRTE(VReg_4H rd, VReg_4H rn)
{
    emit<"0010111011111001110110nnnnnddddd", "d", "n">(rd, rn);
}
void FRSQRTE(VReg_8H rd, VReg_8H rn)
{
    emit<"0110111011111001110110nnnnnddddd", "d", "n">(rd, rn);
}
void FRSQRTS(HReg rd, HReg rn, HReg rm)
{
    emit<"01011110110mmmmm001111nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FRSQRTS(VReg_4H rd, VReg_4H rn, VReg_4H rm)
{
    emit<"00001110110mmmmm001111nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FRSQRTS(VReg_8H rd, VReg_8H rn, VReg_8H rm)
{
    emit<"01001110110mmmmm001111nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FSQRT(HReg rd, HReg rn)
{
    emit<"0001111011100001110000nnnnnddddd", "d", "n">(rd, rn);
}
void FSQRT(VReg_4H rd, VReg_4H rn)
{
    emit<"0010111011111001111110nnnnnddddd", "d", "n">(rd, rn);
}
void FSQRT(VReg_8H rd, VReg_8H rn)
{
    emit<"0110111011111001111110nnnnnddddd", "d", "n">(rd, rn);
}
void FSUB(HReg rd, HReg rn, HReg rm)
{
    emit<"00011110111mmmmm001110nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FSUB(VReg_4H rd, VReg_4H rn, VReg_4H rm)
{
    emit<"00001110110mmmmm000101nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void FSUB(VReg_8H rd, VReg_8H rn, VReg_8H rm)
{
    emit<"01001110110mmmmm000101nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void SCVTF(HReg rd, WReg wn, ImmRange<1, 32> fbits)
{
    emit<"0001111011000010SSSSSSnnnnnddddd", "d", "n", "S">(rd, wn, 64 - fbits.value());
}
void SCVTF(HReg rd, XReg xn, ImmRange<1, 64> fbits)
{
    emit<"1001111011000010SSSSSSnnnnnddddd", "d", "n", "S">(rd, xn, 64 - fbits.value());
}
void SCVTF(HReg rd, WReg wn)
{
    emit<"0001111011100010000000nnnnnddddd", "d", "n">(rd, wn);
}
void SCVTF(HReg rd, XReg xn)
{
    emit<"1001111011100010000000nnnnnddddd", "d", "n">(rd, xn);
}
void SCVTF(HReg rd, HReg rn, ImmRange<1, 16> fbits)
{
    emit<"010111110001hbbb111001nnnnnddddd", "d", "n", "hb">(rd, rn, 32 - fbits.value());
}
void SCVTF(VReg_4H rd, VReg_4H rn, ImmRange<1, 16> fbits)
{
    emit<"000011110001hbbb111001nnnnnddddd", "d", "n", "hb">(rd, rn, 32 - fbits.value());
}
void SCVTF(VReg_8H rd, VReg_8H rn, ImmRange<1, 16> fbits)
{
    emit<"010011110001hbbb111001nnnnnddddd", "d", "n", "hb">(rd, rn, 32 - fbits.value());
}
void SCVTF(HReg rd, HReg rn)
{
    emit<"0101111001111001110110nnnnnddddd", "d", "n">(rd, rn);
}
void SCVTF(VReg_4H rd, VReg_4H rn)
{
    emit<"0000111001111001110110nnnnnddddd", "d", "n">(rd, rn);
}
void SCVTF(VReg_8H rd, VReg_8H rn)
{
    emit<"0100111001111001110110nnnnnddddd", "d", "n">(rd, rn);
}
void UCVTF(HReg rd, WReg wn, ImmRange<1, 32> fbits)
{
    emit<"0001111011000011SSSSSSnnnnnddddd", "d", "n", "S">(rd, wn, 64 - fbits.value());
}
void UCVTF(HReg rd, XReg xn, ImmRange<1, 64> fbits)
{
    emit<"1001111011000011SSSSSSnnnnnddddd", "d", "n", "S">(rd, xn, 64 - fbits.value());
}
void UCVTF(HReg rd, WReg wn)
{
    emit<"0001111011100011000000nnnnnddddd", "d", "n">(rd, wn);
}
void UCVTF(HReg rd, XReg xn)
{
    emit<"1001111011100011000000nnnnnddddd", "d", "n">(rd, xn);
}
void UCVTF(HReg rd, HReg rn, ImmRange<1, 16> fbits)
{
    emit<"011111110001hbbb111001nnnnnddddd", "d", "n", "hb">(rd, rn, 32 - fbits.value());
}
void UCVTF(VReg_4H rd, VReg_4H rn, ImmRange<1, 16> fbits)
{
    emit<"001011110001hbbb111001nnnnnddddd", "d", "n", "hb">(rd, rn, 32 - fbits.value());
}
void UCVTF(VReg_8H rd, VReg_8H rn, ImmRange<1, 16> fbits)
{
    emit<"011011110001hbbb111001nnnnnddddd", "d", "n", "hb">(rd, rn, 32 - fbits.value());
}
void UCVTF(HReg rd, HReg rn)
{
    emit<"0111111001111001110110nnnnnddddd", "d", "n">(rd, rn);
}
void UCVTF(VReg_4H rd, VReg_4H rn)
{
    emit<"0010111001111001110110nnnnnddddd", "d", "n">(rd, rn);
}
void UCVTF(VReg_8H rd, VReg_8H rn)
{
    emit<"0110111001111001110110nnnnnddddd", "d", "n">(rd, rn);
}

// FEAT_LRCPC3

void LDAP1(List<DElem, 1> tlist, XRegSp addr_n)
{
    emit<"0Q00110101000001100001nnnnnttttt", "t", "QSz", "n">(tlist.m_base.reg_index(), tlist.m_base.elem_index(), addr_n);
}
void LDAPUR(BReg rt, XRegSp addr_n, SOffset<9, 0> offset = 0)
{
    emit<"00011101010iiiiiiiii10nnnnnttttt", "t", "n", "i">(rt, addr_n, offset);
}
void LDAPUR(HReg rt, XRegSp addr_n, SOffset<9, 0> offset = 0)
{
    emit<"01011101010iiiiiiiii10nnnnnttttt", "t", "n", "i">(rt, addr_n, offset);
}
void LDAPUR(SReg rt, XRegSp addr_n, SOffset<9, 0> offset = 0)
{
    emit<"10011101010iiiiiiiii10nnnnnttttt", "t", "n", "i">(rt, addr_n, offset);
}
void LDAPUR(DReg rt, XRegSp addr_n, SOffset<9, 0> offset = 0)
{
    emit<"11011101010iiiiiiiii10nnnnnttttt", "t", "n", "i">(rt, addr_n, offset);
}
void LDAPUR(QReg rt, XRegSp addr_n, SOffset<9, 0> offset = 0)
{
    emit<"00011101110iiiiiiiii10nnnnnttttt", "t", "n", "i">(rt, addr_n, offset);
}
void STL1(List<DElem, 1> tlist, XRegSp addr_n)
{
    emit<"0Q00110100000001100001nnnnnttttt", "t", "QSz", "n">(tlist.m_base.reg_index(), tlist.m_base.elem_index(), addr_n);
}
void STLUR(BReg rt, XRegSp addr_n, SOffset<9, 0> offset = 0)
{
    emit<"00011101000iiiiiiiii10nnnnnttttt", "t", "n", "i">(rt, addr_n, offset);
}
void STLUR(HReg rt, XRegSp addr_n, SOffset<9, 0> offset = 0)
{
    emit<"01011101000iiiiiiiii10nnnnnttttt", "t", "n", "i">(rt, addr_n, offset);
}
void STLUR(SReg rt, XRegSp addr_n, SOffset<9, 0> offset = 0)
{
    emit<"10011101000iiiiiiiii10nnnnnttttt", "t", "n", "i">(rt, addr_n, offset);
}
void STLUR(DReg rt, XRegSp addr_n, SOffset<9, 0> offset = 0)
{
    emit<"11011101000iiiiiiiii10nnnnnttttt", "t", "n", "i">(rt, addr_n, offset);
}
void STLUR(QReg rt, XRegSp addr_n, SOffset<9, 0> offset = 0)
{
    emit<"00011101100iiiiiiiii10nnnnnttttt", "t", "n", "i">(rt, addr_n, offset);
}

// FEAT_SHA3

void BCAX(VReg_16B rd, VReg_16B rn, VReg_16B rm, VReg_16B ra)
{
    emit<"11001110001mmmmm0aaaaannnnnddddd", "d", "n", "m", "a">(rd, rn, rm, ra);
}
void EOR3(VReg_16B rd, VReg_16B rn, VReg_16B rm, VReg_16B ra)
{
    emit<"11001110000mmmmm0aaaaannnnnddddd", "d", "n", "m", "a">(rd, rn, rm, ra);
}
void RAX1(VReg_2D rd, VReg_2D rn, VReg_2D rm)
{
    emit<"11001110011mmmmm100011nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void XAR(VReg_2D rd, VReg_2D rn, VReg_2D rm, Imm<6> rotate_amount)
{
    emit<"11001110100mmmmmiiiiiinnnnnddddd", "d", "n", "m", "i">(rd, rn, rm, rotate_amount);
}

// FEAT_SHA512

void SHA512H(QReg rd, QReg rn, VReg_2D rm)
{
    emit<"11001110011mmmmm100000nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void SHA512H2(QReg rd, QReg rn, VReg_2D rm)
{
    emit<"11001110011mmmmm100001nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void SHA512SU0(VReg_2D rd, VReg_2D rn)
{
    emit<"1100111011000000100000nnnnnddddd", "d", "n">(rd, rn);
}
void SHA512SU1(VReg_2D rd, VReg_2D rn, VReg_2D rm)
{
    emit<"11001110011mmmmm100010nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}

// FEAT_SM3

void SM3PARTW1(VReg_4S rd, VReg_4S rn, VReg_4S rm)
{
    emit<"11001110011mmmmm110000nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void SM3PARTW2(VReg_4S rd, VReg_4S rn, VReg_4S rm)
{
    emit<"11001110011mmmmm110001nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
void SM3SS1(VReg_4S rd, VReg_4S rn, VReg_4S rm, VReg_4S ra)
{
    emit<"11001110010mmmmm0aaaaannnnnddddd", "d", "n", "m", "a">(rd, rn, rm, ra);
}
void SM3TT1A(VReg_4S rd, VReg_4S rn, SElem em)
{
    emit<"11001110010mmmmm10ii00nnnnnddddd", "d", "n", "m", "i">(rd, rn, em.reg_index(), em.elem_index());
}
void SM3TT1B(VReg_4S rd, VReg_4S rn, SElem em)
{
    emit<"11001110010mmmmm10ii01nnnnnddddd", "d", "n", "m", "i">(rd, rn, em.reg_index(), em.elem_index());
}
void SM3TT2A(VReg_4S rd, VReg_4S rn, SElem em)
{
    emit<"11001110010mmmmm10ii10nnnnnddddd", "d", "n", "m", "i">(rd, rn, em.reg_index(), em.elem_index());
}
void SM3TT2B(VReg_4S rd, VReg_4S rn, SElem em)
{
    emit<"11001110010mmmmm10ii11nnnnnddddd", "d", "n", "m", "i">(rd, rn, em.reg_index(), em.elem_index());
}

// FEAT_SM4

void SM4E(VReg_4S rd, VReg_4S rn)
{
    emit<"1100111011000000100001nnnnnddddd", "d", "n">(rd, rn);
}
void SM4EKEY(VReg_4S rd, VReg_4S rn, VReg_4S rm)
{
    emit<"11001110011mmmmm110010nnnnnddddd", "d", "n", "m">(rd, rn, rm);
}
