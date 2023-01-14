## Test case explanations:

Starting register values are those given in the project brief.

```multi-ops/``` folder contains the test cases with multiple operations one after the other. 

9 out of 24 possible memory addressing forms are covered in these test cases, including 3 forms of an SIB byte.

1. ```test-00.txt```

- Operation 1 - ```83 C0 05```

            Opcode - 83 (Add Imm8 to rm32)
            Modrm - C0 (Reg = EAX, RM reg = EAX)
            Imm8 - 05
            Result - EAX set to bf8db149

- Operation 2 - ```04 08```

            Opcode - 04 (Add Imm8 to AL)
            Imm8 - 08
            Result - EAX set to bf8db151 (AL result propagates up to EAX)

2. ```test-01.txt```

- Operation 1 - ```89 08 ```

            Opcode - 89 (Mov r/m32, r32)
            Modrm - 08 (Reg = ECX, RM memory location = [EAX value])
            Result - Write 88c5cffb to memory location bf8db144

- Operation 2 - ```83 82 36 C7 E1 49 01```

            Opcode - 83 (Add r/m32, Imm8)
            Modrm - 82 (Reg = EAX, RM mem = [EDX value + disp32])
            Disp32 - 36C7E149 ( Calcuating RM mem = bf8db144 )
            Imm8 - 01
            Result - Write 88c5cffc to memory location bf8db144

- Operation 3 - ```39 1C 05 00 00 00 00```

            Opcode - 39 (Cmp r/m32, r32)
            Modrm - 1C (Reg = EBX, RM mem = SIB addr)
            SIB - 05 (Effective addr = [EAX value + disp32])
            Disp32 - 0
            Result - Compare 88c5ffc to ae5ff4. Sets SF=0 and PF=1

- Operation 4 - ```8B 10```

            Opcode - 8B (Mov r32, r/m32)
            Modrm - 10 (Reg = EDX, RM memory location = [EAX value])
            Result - Set EDX to value 88c5ffc

- Operation 5 - ```50 18```

            Opcode - 50 (Push r32)
            Modrm - 18 (Reg = EBX, RM memory location = [EAX value])
            Result - Decrement stack pointer (ESP) by 4, write ae5ff4 to memory location bf8db0b8

- Operation 6 - ```35 FF FF FF F0```

            Opcode - 35 (XOR EAX, imm32)
            Imm32 - FF FF FF F0
            Result - Set EAX to value 40724eb4

3. ```test-02.txt```

- Operation 1 - ```25 00 00 F1 00```

            Opcode - 25 (AND EAX, imm32)
            Imm32 - FF FF FF F0
            Result - Set EAX to value bf8db140

- Operation 2 - ```50 40```

            Opcode - 50 (Push r32)
            Modrm - 40 (Reg = EAX)
            Result - Decrement stack pointer (ESP) by 4, write bf8db140 to memory location bf8db0b8

- Operation 3 - ```89 5D 2C```

            Opcode - 89 (MOve r32 to r/m32)
            Modrm - 5D (Reg = EBX, RM memory location = [EBP value + disp8])
            Disp8 - 2C
            Result - Write value ae5ff4 to memory location bf8db144

- Operation 4 - ```0F BD 50 04```

            Opcode - BD (Bit scan reverse r32, r/m32)
            Modrm - 50 (Reg = EDX, RM memory location = [EAX value + disp8])
            Disp8 - 04 (Memory location = bf8db144)
            Result - Set EDX to decimal value 23 (hex value 17)

- Operation 5 - ```8F 84 37 00 00 00 2E```

            Opcode - 8F (Pop to r/m32)
            Modrm - 84 (RM memory location = SIB addr + disp32)
            SIB - 37 (Effective addr = [ESI + EDI])
            Disp32 - 2F (Memory location = 9a0ccf)
            Result - Write bf8db140 to memory location 9a0ccf

- Operation 6 - ```0F BC 4C 56 01```

            Opcode - BC (Bit scan forward r32, r/m32)
            Modrm - 4C (Reg = ECX, RM memory location = SIB addr + disp8)
            SIB - 56 (Effective addr = [EDX value * 2 + ESI])
            Disp8 - 01 (Memory location = 9a0ca0 + 2E + 01 = 9a0ccf)
            Result - Write 6 to ECX

- Operation 7 - ```09 8E 00 00 00 2F```

            Opcode - 09 (OR r/m32, r32)
            Modrm - 8E (Reg = ECX, RM memory location = [ESI value + disp32])
            Disp32 - 2F (Memory location = 9a0ca0 + 2F = 9a0ccf)
            Result - Write bf8db146 to memory location 9a0ccf


```single-ops/``` folder contains the test cases where only one opcode is tested at a time.
Some of these cases need some register/memory values to be set beforehand (in main.cpp)

1. ```add00.txt``` 

    Prerequisite - ```mem.write(0xbf8db148, 0x5);```
    
    Reads a memory address from SIB byte

