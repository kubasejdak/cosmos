////////////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2017, Kuba Sejdak <kuba.sejdak@gmail.com>
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
////////////////////////////////////////////////////////////////////////////////////

#ifndef AM335X_UART_REGS_H
#define AM335X_UART_REGS_H

#include <os/utils.h>

#include <cstdint>

namespace Device::UART {

////////////////////////////////////////////////////////////////////////////////////
// REGISTER DEFINITIONS
////////////////////////////////////////////////////////////////////////////////////

typedef union {
    struct {
        std::uint16_t THR : 8;
        std::uint16_t _reserved : 8;
    };

    std::uint16_t value;
} UART_THR_t;

typedef union {
    struct {
        std::uint16_t CLOCK_LSB : 8;
        std::uint16_t _reserved : 8;
    };

    std::uint16_t value;
} UART_DLL_t;

typedef union {
    struct {
        std::uint16_t RHRIT : 1;
        std::uint16_t THRIT : 1;
        std::uint16_t LINESTSIT : 1;
        std::uint16_t MODEMSTSIT : 1;
        std::uint16_t SLEEPMODE : 1;
        std::uint16_t XOFFIT : 1;
        std::uint16_t RTSIT : 1;
        std::uint16_t CTSIT : 1;
        std::uint16_t _reserved : 8;
    };

    std::uint16_t value;
} UART_IER_t;

typedef union {
    struct {
        std::uint16_t CLOCK_MSB : 6;
        std::uint16_t _reserved : 10;
    };

    std::uint16_t value;
} UART_DLH_t;

typedef union {
    struct {
        std::uint16_t SWFLOWCONTROL : 4;
        std::uint16_t ENHANCEDEN : 1;
        std::uint16_t SPECIALCHARDETECT : 1;
        std::uint16_t AUTORTSEN : 1;
        std::uint16_t AUTOCTSEN : 1;
        std::uint16_t _reserved : 8;
    };

    std::uint16_t value;
} UART_EFR_t;

typedef union {
    struct {
        std::uint16_t FIFO_EN : 1;
        std::uint16_t RX_FIFO_CLEAR : 1;
        std::uint16_t TX_FIFO_CLEAR : 1;
        std::uint16_t DMA_MODE : 1;
        std::uint16_t TX_FIFO_TRIG : 2;
        std::uint16_t RX_FIFO_TRIG : 2;
        std::uint16_t _reserved : 8;
    };

    std::uint16_t value;
} UART_FCR_t;

typedef union {
    struct {
        std::uint16_t CHAR_LENGTH : 2;
        std::uint16_t NB_STOP : 1;
        std::uint16_t PARITY_EN : 1;
        std::uint16_t PARITY_TYPE1 : 1;
        std::uint16_t PARITY_TYPE2 : 1;
        std::uint16_t BREAK_EN : 1;
        std::uint16_t DIV_EN : 1;
        std::uint16_t _reserved : 8;
    };

    std::uint16_t value;
} UART_LCR_t;

typedef union {
    struct {
        std::uint16_t RXFIFOE : 1;
        std::uint16_t RXOE : 1;
        std::uint16_t RXPE : 1;
        std::uint16_t RXFE : 1;
        std::uint16_t RXBI : 1;
        std::uint16_t TXFIFOE : 1;
        std::uint16_t TXSRE : 1;
        std::uint16_t RXFIFOSTS : 1;
        std::uint16_t _reserved : 8;
    };

    std::uint16_t value;
} UART_LSR_t;

typedef union {
    struct {
        std::uint16_t MODESELECT : 3;
        std::uint16_t IRSLEEP : 1;
        std::uint16_t SETTXIR : 1;
        std::uint16_t SCT : 1;
        std::uint16_t SIPMODE : 1;
        std::uint16_t FRAMEENDMODE : 1;
        std::uint16_t _reserved : 8;
    };

    std::uint16_t value;
} UART_MDR1_t;

typedef union {
    struct {
        std::uint16_t DMAMODECTL : 1;
        std::uint16_t DMAMODE2 : 2;
        std::uint16_t TXEMPTYCTLIT : 1;
        std::uint16_t RXCTSDSRWAKEUPENABLE : 1;
        std::uint16_t DSRIT : 1;
        std::uint16_t TXTRIGGRANU1 : 1;
        std::uint16_t RXTRIGGRANU1 : 1;
        std::uint16_t _reserved : 8;
    };

    std::uint16_t value;
} UART_SCR_t;

typedef union {
    struct {
        std::uint16_t AUTOIDLE : 1;
        std::uint16_t SOFTRESET : 1;
        std::uint16_t ENAWAKEUP : 1;
        std::uint16_t IDLEMODE : 2;
        std::uint16_t _reserved : 11;
    };

    std::uint16_t value;
} UART_SYSC_t;

typedef union {
    struct {
        std::uint16_t RESETDONE : 1;
        std::uint16_t _reserved : 15;
    };

    std::uint16_t value;
} UART_SYSS_t;

////////////////////////////////////////////////////////////////////////////////////
// REGISTER ADDRESSES
////////////////////////////////////////////////////////////////////////////////////

#define UART_0_BASE                      0x44e09000
#define UART_1_BASE                      0x48022000
#define UART_2_BASE                      0x48024000
#define UART_3_BASE                      0x481a6000
#define UART_4_BASE                      0x481a8000
#define UART_5_BASE                      0x481aa000

#define UART_THR(UART_BASE)              REGISTER(UART_THR_t, (UART_BASE + 0x0))
#define UART_DLL(UART_BASE)              REGISTER(UART_DLL_t, (UART_BASE + 0x0))
#define UART_IER(UART_BASE)              REGISTER(UART_IER_t, (UART_BASE + 0x4))
#define UART_DLH(UART_BASE)              REGISTER(UART_DLH_t, (UART_BASE + 0x4))
#define UART_EFR(UART_BASE)              REGISTER(UART_EFR_t, (UART_BASE + 0x8))
#define UART_FCR(UART_BASE)              REGISTER(UART_FCR_t, (UART_BASE + 0x8))
#define UART_LCR(UART_BASE)              REGISTER(UART_LCR_t, (UART_BASE + 0xc))
#define UART_LSR(UART_BASE)              REGISTER(UART_LSR_t, (UART_BASE + 0x14))
#define UART_MDR1(UART_BASE)             REGISTER(UART_MDR1_t, (UART_BASE + 0x20))
#define UART_SCR(UART_BASE)              REGISTER(UART_SCR_t, (UART_BASE + 0x40))
#define UART_SYSC(UART_BASE)             REGISTER(UART_SYSC_t, (UART_BASE + 0x54))
#define UART_SYSS(UART_BASE)             REGISTER(UART_SYSS_t, (UART_BASE + 0x58))

} // namespace Device::UART

#endif
