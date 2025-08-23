#include <stdio.h>
// Memory
int mem[256] = {0};

// Registers
int A = 0;
int PC = 0;

// upper 8 bits opcode, lower 8 bits operand
int make_instruction(int opcode, int operand ){
    return (opcode <<8) | operand;
}

int get_opcode(instruction){
    return (instruction >> 8) & 0xFF;
}

int get_operand(instruction){
    return instruction & 0xFF;
}


void fetch_execute_cycle(){

    while (1)
    {
        int instruction = mem[PC];

        int opcode = get_opcode(instruction)

    }
    
}

void main(){
    mem[0] = make_instruction(1,12);
    printf("%d", mem[0]);
}