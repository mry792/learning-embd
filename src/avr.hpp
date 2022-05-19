#ifndef LEARNING_EMBD_SRC_AVR_HPP_
#define LEARNING_EMBD_SRC_AVR_HPP_

#include <cstdint>

#include "arche/Register.hpp"

namespace avr {
using Pin_B = arche::Register<0x03 + 0x20, std::uint8_t>;
using Data_Direction_B = arche::Register<0x04 + 0x20, std::uint8_t>;
using Port_B = arche::Register<0x05 + 0x20, std::uint8_t>;
}  // namespace avr

#endif  // LEARNING_EMBD_SRC_AVR_HPP_
