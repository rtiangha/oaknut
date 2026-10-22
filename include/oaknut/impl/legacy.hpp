// SPDX-License-Identifier: MIT
//
// Compile-time switches that restore the behavior of the original oaknut, one change at a time.
// Define OAKNUT_LEGACY_ALL to restore everything at once (the object layout then matches the
// original oaknut exactly, too).
#pragma once

#ifdef OAKNUT_LEGACY_ALL
#    define OAKNUT_LEGACY_XPTR          // xptr() never throws; MOVP2R/ADR/ADRP use xptr() as before
#    define OAKNUT_LEGACY_REG_CHECKS    // register index checked only by assert(); WspReg reports 64 bits
#    define OAKNUT_LEGACY_ELEM_BOUNDS   // old (loose) element index bounds, BElem esize 2
#    define OAKNUT_LEGACY_ALIGN         // align() works on the offset only
#    define OAKNUT_LEGACY_LABEL_BASE    // ADRP-to-label page delta uses buffer offsets (base 0)
#    define OAKNUT_LEGACY_SET_OFFSET    // set_offset() accepts negative offsets
#    define OAKNUT_NO_WEND              // no set_wend()/CodeBufferFull; policy layout identical to original
#endif
