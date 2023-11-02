// SPDX-FileCopyrightText: Copyright (c) 2022 merryhime <https://mary.rs>
// SPDX-License-Identifier: MIT

// FEAT_ASMv8p2

void BFC(WReg wd, Imm<5> lsb, Imm<5> width)
{
    if (width.value() == 0 || width.value() > (32 - lsb.value()))
        throw OaknutException{ExceptionType::InvalidBitWidth};
    emit<"0011001100rrrrrrssssss11111ddddd", "d", "r", "s">(wd, (~lsb.value() + 1) & 31, width.value() - 1);
}
void BFC(XReg xd, Imm<6> lsb, Imm<6> width)
{
    if (width.value() == 0 || width.value() > (64 - lsb.value()))
        throw OaknutException{ExceptionType::InvalidBitWidth};
    emit<"1011001101rrrrrrssssss11111ddddd", "d", "r", "s">(xd, (~lsb.value() + 1) & 63, width.value() - 1);
}

// FEAT_LRCPC3

void LDAPR(WReg wt, XRegSp xn, PostIndexed, ImmConst<4>)
{
    emit<"1001100111000000000010nnnnnttttt", "t", "n">(wt, xn);
}
void LDAPR(XReg xt, XRegSp xn, PostIndexed, ImmConst<8>)
{
    emit<"1101100111000000000010nnnnnttttt", "t", "n">(xt, xn);
}
void LDIAPP(WReg wt1, WReg wt2, XRegSp xn)
{
    emit<"10011001010uuuuu000110nnnnnttttt", "t", "u", "n">(wt1, wt2, xn);
}
void LDIAPP(WReg wt1, WReg wt2, XRegSp xn, PostIndexed, ImmConst<8>)
{
    emit<"10011001010uuuuu000010nnnnnttttt", "t", "u", "n">(wt1, wt2, xn);
}
void LDIAPP(XReg xt1, XReg xt2, XRegSp xn)
{
    emit<"11011001010uuuuu000110nnnnnttttt", "t", "u", "n">(xt1, xt2, xn);
}
void LDIAPP(XReg xt1, XReg xt2, XRegSp xn, PostIndexed, ImmConst<16>)
{
    emit<"11011001010uuuuu000010nnnnnttttt", "t", "u", "n">(xt1, xt2, xn);
}
void STILP(WReg wt1, WReg wt2, XRegSp xn)
{
    emit<"10011001000uuuuu000110nnnnnttttt", "t", "u", "n">(wt1, wt2, xn);
}
void STILP(WReg wt1, WReg wt2, XRegSp xn, PreIndexed, ImmConst<-8>)
{
    emit<"10011001000uuuuu000010nnnnnttttt", "t", "u", "n">(wt1, wt2, xn);
}
void STILP(XReg xt1, XReg xt2, XRegSp xn)
{
    emit<"11011001000uuuuu000110nnnnnttttt", "t", "u", "n">(xt1, xt2, xn);
}
void STILP(XReg xt1, XReg xt2, XRegSp xn, PreIndexed, ImmConst<-16>)
{
    emit<"11011001000uuuuu000010nnnnnttttt", "t", "u", "n">(xt1, xt2, xn);
}
void STLR(WReg wt, XRegSp xn, PreIndexed, ImmConst<-4>)
{
    emit<"1001100110000000000010nnnnnttttt", "t", "n">(wt, xn);
}
void STLR(XReg xt, XRegSp xn, PreIndexed, ImmConst<-8>)
{
    emit<"1101100110000000000010nnnnnttttt", "t", "n">(xt, xn);
}

// FEAT_RAS

void ESB()
{
    emit<"11010101000000110010001000011111">();
}

// FEAT_SPE

void PSB()
{
    emit<"11010101000000110010001000111111">();
}
