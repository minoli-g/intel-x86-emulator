#include "input_reader.hpp"
#include "opcodes.hpp"
#include "operations/all_operations.hpp"

#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char *argv[]) {
    std::cout<<"Emulation started"<<"\n";

    InputReader ir = InputReader(argv[1]);

    std::vector<uint8_t> incoming_opcodes;

    while (ir.fileRemaining()){
       //std::cout<<std::to_string(ir.nextByte())<<"\n";

       incoming_opcodes.push_back(ir.nextByte());

       // Test for opcodes which need extra bytes

       // Detect which operation is being referred to  and execute it
       if (opcodes::add_ops.count(incoming_opcodes[0])){

            //Call the add function
            add(&ir, incoming_opcodes);
       }

       // Operation is finished - clear the opcode vector to receive new ones
       incoming_opcodes.clear();
    }
}