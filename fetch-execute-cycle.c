#include <stdio.h>
// Memory - 2 byte words
short mem[256] = {0};

// Registers
short A = 0;
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

// Add bounds checking function
int check_bounds(int addr, const char* operation)
{
    if (addr < 0 || addr >= 256) {
        printf("Segmentation fault: %s address %d out of range [0..255]\n", operation, addr);
        return 0; // Invalid
    }
    return 1; // Valid
}

// Fetch-Execute Cycle
void fetch_execute_cycle()
{

    while (1)
    {
        // Check PC bounds before fetch
        if (!check_bounds(PC, "PC")) return;
        
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
            if (!check_bounds(operand, "LOAD")) return;
            A = mem[operand];
            break;
        // ADD
        case 2:
            if (!check_bounds(operand, "ADD")) return;
            A += mem[operand];
            break;
        // STORE
        case 3:
            if (!check_bounds(operand, "STORE")) return;
            mem[operand] = A;
            break;
        case 4:
            if (!check_bounds(operand, "SUB")) return;
            A -= mem[operand];
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
    // Test program: load, add, subtract, store
    mem[0] = make_instruction(1, 12);   // LOAD A,[12]
    mem[1] = make_instruction(2, 13);   // ADD A,[13]
    mem[2] = make_instruction(4, 15);   // SUB A,[15] (test opcode 4)
    mem[3] = make_instruction(3, 14);   // STORE [14],A
    mem[4] = make_instruction(1, 300);  // LOAD A,[300] (bounds test)
    mem[5] = make_instruction(255, 0);  // HALT

    // Test values
    mem[12] = 10;
    mem[13] = 5;
    mem[15] = 3;

    fetch_execute_cycle();

    // Print final values
    printf("Value at mem[12]: %d\n", mem[12]);
    printf("Value at mem[13]: %d\n", mem[13]);
    printf("Value at mem[14]: %d\n", mem[14]);
    printf("Value at mem[15]: %d\n", mem[15]);
}