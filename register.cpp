#include "register.hpp"
#include <iostream>
#include <bitset>

RegisterBank::RegisterBank() {
    
    gen_32_regs = {{"EAX",0}, {"EBX",0}, {"ECX",0}, {"EDX",0}};
    gen_16_regs = {{"AX", 0}, {"BX",0}, {"CX", 0}, {"DX", 0}};
    gen_8h_regs = {{"AH", 0}, {"BH", 0}, {"CH", 0}, {"DH", 0}};
    gen_8l_regs = {{"AL", 0}, {"BL", 0}, {"CL", 0}, {"DL", 0}};
    seg_regs = {{"CS", 0}, {"DS", 0}, {"ES", 0}, {"FS", 0}, {"GS", 0}, {"SS", 0}};
    other_regs = {{"ESI", 0}, {"EDI", 0}, {"EBP", 0}, {"EIP", 0}, {"ESP", 0},{"EFLAGS", 0}};

    flag_bits = {{"CF",0}, {"PF",2}, {"AF",4}, {"ZF",6}, {"SF",7}, {"TF",8}, {"IF",9}, {"DF",10},
                 {"NT",14}, {"RF",16}, {"VM",17}, {"AC",18}, {"VIF",19}, {"VIP",20}, {"ID",21}};
    
    std::cout.setstate(std::ios_base::failbit);  // Mute the outputs for setup period

    this->set("EAX", 0xBF8DB144);
    this->set("EBX", 0xAE5FF4);
    this->set("ECX", 0X88c5cffb);
    this->set("EDX", 0X1);

    this->set("ESI", 0x9a0ca0);
    this->set("EDI", 0x0);
    this->set("EBP", 0xbf8db118);
    this->set("EIP", 0x8048354);
    this->set("ESP", 0xbf8db0bc);

    this->set("CS", 0x73);
    this->set("DS", 0x7B);
    this->set("ES", 0x7B);
    this->set("FS", 0x0);
    this->set("GS", 0xbf8db144);
    this->set("SS", 0xbf8db144);

    this->set("EFLAGS", 0x246);

    std::cout.clear();  // Unmute output
}

void RegisterBank::set(std::string name, std::uint32_t value){

    std::cout << "Set value of register "<< name << " to "<< +value << "\n";

    if (seg_regs.find(name) != seg_regs.end()){
        seg_regs[name] = (uint16_t)value;
        return;
    }
    
    if (other_regs.find(name) != other_regs.end()){
        other_regs[name] = value;
        return;
    }
    
    if (gen_32_regs.find(name) != gen_32_regs.end()){
        gen_32_regs[name] = value;

        gen_16_regs[name.substr(1,2)] = value & 0x0000FFFF;
        gen_8h_regs[name.substr(1,1)+"H"] = (value & 0x0000FF00)>>8;
        gen_8l_regs[name.substr(1,1)+"L"] = value & 0x000000FF;
        return;
    }
    
    if (gen_16_regs.find(name) != gen_16_regs.end()){
        gen_16_regs[name] = (std::uint16_t) value;

        gen_32_regs["E"+name] &= 0xFFFF0000;
        gen_32_regs["E"+name] |= value;

        gen_8h_regs[name.substr(0,1)+"H"] = (value & 0x0000FF00)>>8;
        gen_8l_regs[name.substr(0,1)+"L"] = value & 0x000000FF;
        return;
    }

    if (gen_8h_regs.find(name) != gen_8h_regs.end()){
        gen_8h_regs[name] = (std::uint8_t) value;

        gen_32_regs["E"+name.substr(0,1)+"X"] &= 0xFFFF00FF;
        gen_32_regs["E"+name.substr(0,1)+"X"] |= value << 8;

        gen_16_regs[name.substr(0,1)+"X"] &= 0x00FF;
        gen_16_regs[name.substr(0,1)+"X"] |= value << 8;
        return;
    }

    if (gen_8l_regs.find(name) != gen_8l_regs.end()){
        gen_8l_regs[name] = (std::uint8_t) value;

        gen_32_regs["E"+name.substr(0,1)+"X"] &= 0xFFFFFF00;
        gen_32_regs["E"+name.substr(0,1)+"X"] |= value;

        gen_16_regs[name.substr(0,1)+"X"] &= 0xFF00;
        gen_16_regs[name.substr(0,1)+"X"] |= value;
        return;
    }

    std::cout << "Erroneous register name " << name << "\n";

}

std::uint32_t RegisterBank::get(std::string name){

    uint32_t value;
    
    if (other_regs.find(name) != other_regs.end()){
        value = other_regs[name];
    }
    else if (gen_32_regs.find(name) != gen_32_regs.end()){
        value = gen_32_regs[name];
    }
    else if (gen_16_regs.find(name) != gen_16_regs.end()){
        value = (std::uint32_t) gen_16_regs[name];
    }
    else if (gen_8h_regs.find(name) != gen_8h_regs.end()){
        value = (std::uint32_t) gen_8h_regs[name];
    }
    else if (gen_8l_regs.find(name) != gen_8l_regs.end()){
        value = (std::uint32_t) gen_8l_regs[name];
    }
    else{
        std::cout << "Erroneous register name " << name << "\n";
        exit(0);
    }
    
    std::cout << "Read value "<< +value <<" from register " << name << "\n";
    return value;
}

void RegisterBank::setFlag(std::string flag){
    int index = flag_bits[flag];
    uint32_t eflags_new = get("EFLAGS") | (1<<index);
    set("EFLAGS", eflags_new);
}

void RegisterBank::clearFlag(std::string flag){
    int index = flag_bits[flag];
    uint32_t eflags_new = get("EFLAGS") & (0xFFFF - (1<<index));
    set("EFLAGS", eflags_new);
}

bool RegisterBank::getFlag(std::string flag){
    int index = flag_bits[flag];
    std::bitset<32> b(get("EFLAGS"));
    return (bool) b[index];
}

void RegisterBank::dumpValues(){

    std::cout << "\n-------REGISTER DUMP------- \n";
    std::cout << "---General purpose registers:--- \n";
    for (auto const& [name, reg]: gen_32_regs){
        std::cout << name << " : " << reg << "\t";
    }
    std::cout << "\n";
    for (auto const& [name, reg]: gen_16_regs){
        std::cout << name << " : " <<  reg  << "\t";
    }
    std::cout << "\n";
    for (auto const& [name, reg]: gen_8h_regs){
        std::cout << name << " : " <<  unsigned(reg)  << "\t";
    }
    std::cout << "\n";
    for (auto const& [name, reg]: gen_8l_regs){
        std::cout << name << " : " <<  unsigned(reg)   << "\t";
    }
    std::cout << "\n";
    std::cout << "\n---Other registers:--- \n";
    for (auto const& [name, reg]: other_regs){
        std::cout << name << " : " <<  reg  << "\n";
    }
    std::cout << "\n---Flags:--- \n";
    std::bitset<32> b(get("EFLAGS"));
    for (auto const& [flag, index]: flag_bits){
        std::cout << flag << " : " << +b[index] << "\t";
    }
    std::cout << "\n";
}
