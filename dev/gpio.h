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

#ifndef GPIO_H
#define GPIO_H

#include "device_manager.h"

#include <fs/device.h>

#include <type_traits>

#define PIN_MASK(gpioPinNo)     ((std::uint32_t) (1 << gpioPinNo))

namespace Device::GPIO {

// Each pin has following description:
// - id      - unique number defining processor pin (ex. sequence number)
// - portNo  - corresponding GPIO port number
// - pinNo   - pin number within corresponding GPIO port
typedef struct {
    int portNo;
    int pinNo;
} PinMux_t;

extern PinMux_t pinmux[];
extern int pinmuxSize;

enum class Function {
    _0,
    _1,
    _2,
    _3,
    _4,
    _5,
    _6,
    _7
};

enum class Direction {
    Input,
    Output
};

enum class Resitor {
    None,
    PullUp,
    PullDown
};

template <int N>
class IGPIO : public Filesystem::Device<N> {
public:
    virtual void reset() = 0;
    virtual void enable() = 0;
    virtual void disable() = 0;

    virtual bool setFunction(int id, Function function) = 0;
    virtual void setDirection(int pinNo, Direction direction) = 0;
    virtual void setResistor(int id, Resitor resistor) = 0;

    virtual std::uint32_t read() = 0;
    virtual bool write(std::uint32_t value) = 0;
    virtual bool writePin(int pinNo, bool state) = 0;
};

template <typename T>
using IsGPIO = typename std::enable_if_t<std::is_base_of<IGPIO<T::count()>, T>::value, T>;

template <typename T, typename = IsGPIO<T>>
class GPIOPin {
public:
    GPIOPin(int id)
        : GPIOPin((typename T::id_type) pinmux[id].portNo, pinmux[id].pinNo)
    {
    }

    GPIOPin(typename T::id_type id, int pinNo)
        : m_gpio(DeviceManager<T>::get(id))
        , m_pinNo(pinNo)
        , m_id(-1)
    {
        for (int i = 0; i < pinmuxSize; ++i) {
            if (pinmux[i].portNo == static_cast<int>(id) && pinmux[i].pinNo == pinNo) {
                m_id = i;
                break;
            }
        }
    }

    bool setFunction(Function function)
    {
        return m_gpio.setFunction(m_id, function);
    }

    void setDirection(Direction direction)
    {
        m_gpio.setDirection(m_pinNo, direction);
    }

    void setResistor(Resitor resistor)
    {
        m_gpio.setResistor(m_id, resistor);
    }

    bool read()
    {
        return (bool) (m_gpio.read() & PIN_MASK(m_pinNo));
    }

    bool write(bool state)
    {
        return m_gpio.writePin(m_pinNo, state);
    }

    void toggle()
    {
        volatile bool state = read();
        write(!state);
    }

private:
    IGPIO<T::count()>& m_gpio;
    //int m_pin;
    int m_pinNo;
    int m_id;
};

} // namespace Device::GPIO

#endif
