/**
    This source code comes from chapter 1 of "Real-Time C++" 4ed by Christopher
    Kormanyos.
 */

#include <cstdint>

#include "mcal_reg.h"

class Led {
  public:
    using Port = std::uint8_t;
    using BVal = std::uint8_t;

    Led (const Port port, const BVal bval)
          : port_{port}, bval_{bval} {
        // Set the port pin value to low.
        *reinterpret_cast<volatile BVal*>(port_) &= static_cast<BVal>(~bval_);

        // Set the port pin direction to output.

        // Note that the address of the port direction register is one less than
        // the address of the port value register.
        const Port port_direction = port_ - 1u;

        *reinterpret_cast<volatile BVal*>(port_direction) |= bval_;
    }

    void toggle () const {
        // Toggle the LED via direct memory access.
        *reinterpret_cast<volatile BVal*>(port_) ^= bval_;
    }

  private:
    const Port port_;
    const BVal bval_;
};

namespace {
// Create led_b5 on portb.5.
const Led led_b5{mcal::reg::portb, mcal::reg::bval5};
}  // namespace

int main () {
    for (;;) {
        led_b5.toggle();
    }
}
