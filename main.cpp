#include "input_reader.hpp"
#include "opcodes.hpp"
#include "operations/all_operations.hpp"
#include "register.hpp"
#include "memory.hpp"

#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char *argv[]) {
    std::cout<<"----Emulation started----"<<"\n\n";
    std::cout << std::hex;

    InputReader ir = InputReader(argv[1]);
    RegisterBank rb = RegisterBank();
    Memory mem = Memory();

    while (ir.fileRemaining()){

       uint8_t opcode1 = ir.nextByte();

        // Test for prefixes / escape opcodes

        switch (opcode1){

            case 0x0f: {

                uint8_t opcode2 = ir.nextByte();

                if (opcode2==0x3A || opcode2==0x38){
                    // No opcodes with three-byte encodings are implemented
                    std::cout << "Error: three-byte opcodes not implemented \n";
                    exit(0);
                }
                else {
                    // Check the opcode maps for two-byte opcodes with 0F byte

                    if (opcodes::bsf_ops.count(opcode2)) {
                        bsf(&ir, &rb, &mem, opcode2);
                    }
                    
                    else if (opcodes::bsr_ops.count(opcode2)) {
                        bsr(&ir, &rb, &mem, opcode2);
                    }

                    else{
                        std::cout << "Error: Unsupported opcode! \n";
                        exit(0);
                    }
                }
                break;
            }
            case 0x66:
                // No opcodes with 66 mandatory prefix have been implemented
                std::cout << "Error: unsupported opcode prefix 66 \n";
                exit(0);
                break;

            case 0xF2:
                // No opcodes with F2 mandatory prefix have been implemented
                std::cout << "Error: unsupported opcode prefix F2 \n";
                exit(0);
                break;

            case 0xF3:
                // No opcodes with F3 mandatory prefix have been implemented
                std::cout << "Error: unsupported opcode prefix F3 \n";
                exit(0);
                break;

            default:

                if (opcodes::add_ops.count(opcode1)){
                    add(&ir, &rb, &mem, opcode1);
                }

                else if (opcodes::and_ops.count(opcode1)){
                    andOp(&ir, &rb, &mem, opcode1);
                }

                else if (opcodes::mov_ops.count(opcode1)){
                    mov(&ir, &rb, &mem, opcode1);
                }

                else if (opcodes::or_ops.count(opcode1)){
                    orOp(&ir, &rb, &mem, opcode1);
                }

                else if (opcodes::push_ops.count(opcode1)){
                    push(&ir, &rb, &mem, opcode1);
                }

                else if (opcodes::pop_ops.count(opcode1)){
                    pop(&ir, &rb, &mem, opcode1);
                }

                // Add other operations below after implementing

                else {
                    std::cout << "Error: Unsupported opcode! \n";
                    exit(0);
                }

        }
    }

    std::cout << "\n----Emulation complete----\n";
    rb.dumpValues();
    mem.dumpValues();
}