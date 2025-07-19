#ifndef OPCODES_H
#define OPCODES_H

#include <set>
#include <cstdint>

namespace opcodes{

    // One-byte opcode maps
    extern const std::set<std::uint8_t> add_ops;
    extern const std::set<std::uint8_t> push_ops;
    extern const std::set<std::uint8_t> pop_ops;
    extern const std::set<std::uint8_t> and_ops;
    extern const std::set<std::uint8_t> cmp_ops;
    extern const std::set<std::uint8_t> mov_ops;
    extern const std::set<std::uint8_t> or_ops;
    extern const std::set<std::uint8_t> xor_ops;

    // Two-byte opcode maps (first opcode is 0x0F)
    extern const std::set<std::uint8_t> bsf_ops;
    extern const std::set<std::uint8_t> bsr_ops;

    // Three-byte opcode combinations are not supported
}

#endif