#include <stdio.h>
// Memory
int mem[256] = {0};

// Registers
int A = 0;
int PC = 0;

// upper 8 bits opcode, lower 8 bits operand
int make_instruction(int opcode, int operand)
{
    return (opcode << 8) | operand;
}

// upper 8 bits opcode
int get_opcode(int instruction)
{
    return (instruction >> 8) & 0xFF;
}

// lower 8 bits operand
int get_operand(int instruction)
{
    return instruction & 0xFF;
}

// Fetch-Execute Cycle
void fetch_execute_cycle()
{

    while (1)
    {
        // Fetch instruction at Program Counter
        int instruction = mem[PC];

        // Decode opcode and operand
        int opcode = get_opcode(instruction);
        int operand = get_operand(instruction);

        // Execute
        switch (opcode)
        {
        // LOAD
        case 1:
            A = mem[operand];
            break;
        // ADD
        case 2:
            A += mem[operand];
            break;
        // STORE
        case 3:
            mem[operand] = A;
            break;
        case 255:

            return;

        default:
            printf("Unknown opcode\n");
            return;
        }

        // Show the value of A after each step
        printf("PC: %d A: %d\n", PC, A);
        // Increment Program Counter
        PC++;
    }
}

void main()
{
    // Program to load, add, and store
    mem[0] = make_instruction(1, 12);
    mem[1] = make_instruction(2, 13);
    mem[2] = make_instruction(3, 14);
    mem[3] = make_instruction(255, 0);

    // Add values on 12 and 13
    mem[12] = 7;
    mem[13] = 4;

    fetch_execute_cycle();

    // Print final values from 12 to 14
    printf("Value at mem[12]: %d \n", mem[12]);
    printf("Value at mem[12]: %d\n", mem[13]);
    printf("Final Value at mem[14]: %d\n", mem[14]); // The addr 14 should be 11 :>
}