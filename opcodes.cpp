#include "opcodes.hpp"

namespace opcodes{

    // One-byte opcode maps

    extern const std::set<std::uint8_t> add_ops = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x83};
    extern const std::set<std::uint8_t> push_ops = {0x50, 0x6A, 0x68};
    extern const std::set<std::uint8_t> pop_ops = {0x8F, 0x1F, 0x07};
    extern const std::set<std::uint8_t> and_ops = {0x24, 0x21, 0x22, 0x20};
    extern const std::set<std::uint8_t> cmp_ops = {0x3C, 0x3D, 0x38, 0x39};
    extern const std::set<std::uint8_t> mov_ops = {0x88, 0x89, 0x8A, 0x8B};
    extern const std::set<std::uint8_t> or_ops = {0x0C, 0x0D, 0x08, 0x09};
    extern const std::set<std::uint8_t> xor_ops ={0x30, 0x31, 0x34, 0x35};

    // Two-byte opcode maps (first opcode is 0x0F)

    extern const std::set<std::uint8_t> bsf_ops = {0xBC};
    extern const std::set<std::uint8_t> bsr_ops = {0xBD};

    // Three-byte opcode combinations are not supported

}