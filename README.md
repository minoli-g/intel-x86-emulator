## About 

This project emulates the instruction decoding of an x86 processor.

Supported instructions / opcodes are as follows:

    ADD: 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x83
    PUSH: 0x50, 0x6A, 0x68
    POP: 0x8F, 0x1F, 0x07
    AND: 0x25, 0x24, 0x21, 0x22, 0x20
    CMP: 0x3C, 0x3D, 0x38, 0x39
    MOV: 0x88, 0x89, 0x8A, 0x8B
    OR: 0x0C, 0x0D, 0x08, 0x09
    XOR: 0x30, 0x31, 0x34, 0x35
    BSF: 0xBC
    BSR: 0xBD


## Requirements
- C++ 17 
- Makefile utility

## Build
```make```

This generates an executable file with the name "main"

## Run

Provide the path to the input file as an argument to main. 

E.g.-
```main inputs/multi-ops/test-01.txt```


The emulator should produce an output that looks like this:
```
----Emulation started----

89 - MOV r/m32,r32
Read value bf8db144 from register EAX
Read value 88c5cffb from register ECX
Set value of memory location bf8db144 to 88c5cffb
--------------------------
83 - Add imm8 to r/m32 
Read value 88c5cffb from register ECX
Read value 88c5cffb from memory location bf8db144
Read Imm8 data decimal value 1
Set value of memory location bf8db144 to 88c5cffc
--------------------------
39 - Compare r/m32, r32 
Read value bf8db144 from register EAX
Effective addr of SIB byte 5 is bf8db144
Read value 88c5cffc from memory location bf8db144
Read value ae5ff4 from register EBX
--------------------------
8B - MOV r32,r/m32
Read value bf8db144 from register EAX
Read value 88c5cffc from memory location bf8db144
Set value of register EDX to 88c5cffc
--------------------------
50 - Push r32 
Read value ae5ff4 from register EBX
Pushing data ae5ff4 to stack
Read value bf8db0bc from register ESP
Set value of memory location bf8db0b8 to ae5ff4
Set value of register ESP to bf8db0b8
--------------------------
35 - XOR EAX, imm32
Read value bf8db144 from register EAX
Read Imm32 data decimal value -16
Set value of register EAX to 40724eb4
--------------------------

----Emulation complete----

-------REGISTER DUMP-------
---General purpose registers:---
EAX : 40724eb4  EBX : ae5ff4    ECX : 88c5cffb  EDX : 88c5cffc
AX : 4eb4       BX : 5ff4       CX : cffb       DX : cffc
AH : 4e BH : 5f CH : cf DH : cf
AL : b4 BL : f4 CL : fb DL : fc

---Other registers:---
EBP : bf8db118
EDI : 0
EFLAGS : 207
EIP : 8048354
ESI : 9a0ca0
ESP : bf8db0b8

---Flags:---
AC : 0  AF : 0  CF : 1  DF : 0  ID : 0  IF : 1  NT : 0  OF : 0  PF : 1  RF : 0  SF : 0  TF : 0  VIF : 0 VIP : 0 VM : 0  ZF : 0

-------MEMORY DUMP------- 
bf8db0b8 : ae5ff4       bf8db144 : 88c5cffc
```


## Test cases

Test cases are available in the ```inputs/``` folder. 

The ```inputs/guide.md``` file provides an overview of the test cases and their expected results.