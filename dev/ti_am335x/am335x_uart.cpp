////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       21.08.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#include "am335x_uart.h"
#include "am335x_clock.h"

namespace Device {

AM335x_UART::AM335x_UART(AM335x_UARTId_t id)
    : m_id(id)
{
    init();
}

void AM335x_UART::init()
{
    AM335x_Clock clockManager;
    clockManager.initUart(m_id)
}

} // namespace Device
