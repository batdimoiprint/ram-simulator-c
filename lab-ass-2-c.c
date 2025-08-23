#include <stdio.h>

int mem[256] = {0};


int A = 0; 
int PC = 0;  

int make_instruction(int opcode, int operand) {
    return (opcode << 8) | operand;  
}

int get_opcode(int instruction) {
    return (instruction >> 8) & 0xFF;  
}

int get_operand(int instruction) {
    return instruction & 0xFF;  
}

void fetch_execute_cycle() {
    
    while (1) {  
        
        int instruction = mem[PC];
        printf("Step %d: PC=%d, Fetched instruction=%d\n", PC+1, PC, instruction);
        
        // 2. DECODE: Extract opcode and operand
        int opcode = get_opcode(instruction);
        int operand = get_operand(instruction);
        printf("  Decoded: opcode=%d, operand=%d\n", opcode, operand);
        
        // 3. EXECUTE: Perform the operation
        switch (opcode) {
            case 1:  // LOAD A,[addr]
                A = mem[operand];
                printf("  Executed: LOAD A,[%d] -> A=%d\n", operand, A);
                break;
                
            case 2:  // ADD A,[addr]
                A = A + mem[operand];
                printf("  Executed: ADD A,[%d] -> A=%d\n", operand, A);
                break;
                
            case 3:  // STORE A,[addr]
                mem[operand] = A;
                printf("  Executed: STORE A,[%d] -> mem[%d]=%d\n", operand, operand, A);
                break;
                
            case 255:  // HALT
                printf("  Executed: HALT - Stopping execution\n");
                return;  // Exit the function
                
            default:
                printf("  Error: Unknown opcode %d\n", opcode);
                return;
        }
        
        // 4. INCREMENT PC: Move to next instruction
        PC++;
        printf("  Register A = %d\n\n", A);
    }
}

int main() {
    // Initialize the program in memory
    printf("Loading program into memory...\n");
    
    // Instructions (combine opcode and operand)
    mem[0] = make_instruction(1, 12);   // LOAD A,[12]
    mem[1] = make_instruction(2, 13);   // ADD A,[13]
    mem[2] = make_instruction(3, 14);   // STORE A,[14]
    mem[3] = make_instruction(255, 0);  // HALT
    
    // Data
    mem[12] = 7;
    mem[13] = 4;
    
    printf("mem[0] = %d (LOAD A,[12])\n", mem[0]);
    printf("mem[1] = %d (ADD A,[13])\n", mem[1]);
    printf("mem[2] = %d (STORE A,[14])\n", mem[2]);
    printf("mem[3] = %d (HALT)\n", mem[3]);
    printf("mem[12] = %d (data)\n", mem[12]);
    printf("mem[13] = %d (data)\n", mem[13]);
    printf("\n");
    
    // Reset registers
    A = 0;
    PC = 0;
    
    // Run the fetch-execute cycle
    fetch_execute_cycle();
    
    // Show final results
    printf("\nFinal Results:\n");
    printf("Register A = %d\n", A);
    printf("mem[14] = %d (should be 11)\n", mem[14]);
    
    return 0;
}