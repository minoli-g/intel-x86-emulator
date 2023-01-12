TODO - add explanations for all test cases

## Test case explanations:

Starting register values are those given in the project brief.

```multi-ops/``` folder contains the test cases with multiple operations one after the other. 

1. ```add0483.txt```

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

```single-ops/``` folder contains the test cases where only one opcode is tested at a time.
Some of these cases need some register/memory values to be set beforehand (in main.cpp)

1. ```add00.txt``` 

    Prerequisite - ```mem.write(0xbf8db148, 0x5);```
    
    Reads a memory address from SIB byte

