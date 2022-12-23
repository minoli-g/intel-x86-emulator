#include "stack.hpp"
#include "../modrm.hpp"
#include "../instr_utils.hpp"

void push_50(InputReader* ir, RegisterBank* rb, Memory* mem){

    // Push r32
    uint8_t modrm = ir->nextByte();
    std::string r32 = getRegFromIndex(getReg(modrm), REG_32);
    uint32_t reg_value = rb->get(r32);
    mem->push_stack(reg_value, rb, 4);
}

void push_6A(InputReader* ir, RegisterBank* rb, Memory* mem){

    // Push imm8
    uint8_t imm8 = (uint8_t) getImm8(ir);
    mem->push_stack(imm8, rb, 1);
}
void push_68(InputReader* ir, RegisterBank* rb, Memory* mem){

    // Push imm32
    uint32_t imm32 = (uint32_t) getImm32(ir);
    mem->push_stack(imm32, rb, 4);
}

void push(InputReader* ir, RegisterBank* rb, Memory* mem, uint8_t opcode){

    switch(opcode){
        case 0x50:
            push_50(ir, rb, mem);
            break;
        case 0x6A:
            push_6A(ir, rb, mem);
            break;
        case 0x68:
            push_68(ir, rb, mem);
            break;
        default:
            std::cout<< "Unsupported push opcode \n";
    }

}

void pop_8F(InputReader* ir, RegisterBank* rb, Memory* mem){

    // Pop into rm32
    uint8_t modrm = ir->nextByte();
    uint32_t pop_value = mem->pop_stack(rb, 4);

    if (isRMReg(modrm)){
        std::string rm32 = getRMReg(modrm, REG_32);
        rb->set(rm32, pop_value);
    }
    else{
        uint32_t rm_mem = getRMMemLocation(modrm, rb, ir);
        mem->write(rm_mem, pop_value);
    }
}

void pop_1F(InputReader* ir, RegisterBank* rb, Memory* mem){

    // Pop into DS
    uint16_t pop_value = mem->pop_stack(rb, 2);
    rb->set("DS", pop_value);
}
void pop_07(InputReader* ir, RegisterBank* rb, Memory* mem){

    // Pop into ES
    uint16_t pop_value = mem->pop_stack(rb, 2);
    rb->set("ES", pop_value);
}

void pop(InputReader* ir, RegisterBank* rb, Memory* mem, uint8_t opcode){

    switch(opcode){
        case 0x8F:
            pop_8F(ir, rb, mem);
            break;
        case 0x1F:
            pop_1F(ir, rb, mem);
            break;
        case 0x07:
            pop_07(ir, rb, mem);
            break;
        default:
            std::cout<< "Unsupported push opcode \n";
    }

}