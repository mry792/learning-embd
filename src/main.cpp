#include <avr/cpufunc.h>

#include "avr.hpp"

constexpr auto led_pin = avr::Pin_B::Bitset::bit<5u>();


void delay () {
    for (std::uint8_t i = 0u; i < 255u; ++i) {
        for (std::uint8_t j = 0u; j < 255u; ++j) {
            for (std::uint8_t k = 0u; k < 30u; ++k) {
                _NOP();
            }
        }
    }
}


int main () {
    avr::Data_Direction_B::set_bits(led_pin);

    while (true) {
        avr::Pin_B::clear_bits(led_pin);
        delay();

        avr::Pin_B::set_bits(led_pin);
        delay();
    }
}
