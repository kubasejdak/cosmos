////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       17.07.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
//////////////////////////////////////////////////////////////////////////////////////////////// 

#ifndef ARMCORTEX_A_H
#define ARMCORTEX_A_H

#include <hal/cpu.h>

namespace HAL {

class ARMCortexA : public CPU {
public:
    ARMCortexA();
};

} // namespace HAL

#endif