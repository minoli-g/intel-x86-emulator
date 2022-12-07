#include "opcodes.hpp"

namespace opcodes{

    // One-byte opcode maps

    extern const std::set<std::uint8_t> add_ops = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x83};
    // TODO - More operations

    // Two-byte opcode maps (first opcode is 0x0F)

    extern const std::set<std::uint8_t> bsf_ops = {0xBC};

    // Three-byte opcode combinations are not supported

}