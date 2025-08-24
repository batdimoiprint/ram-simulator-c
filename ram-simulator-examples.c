#include <stdio.h>
int mem[256] = {0};

int write_memory(int addr, int value)
{
    return mem[addr] = value;
}

int read_memory(int addr)
{
    printf("%d", mem[addr]);
    return mem[addr];
}

int load_block(int start_addr, int values[], int length)
{
    for (int i = 0; i < length; i++)
    {
        write_memory(start_addr + i, values[i]);
    }
}

int main()
{
    int arrVal[] = {5, 9, 12};
    int length = sizeof(arrVal) / sizeof(arrVal[0]);

    write_memory(10, 42);
    read_memory(10);

    load_block(20, arrVal, length);
    
    read_memory(20);
    read_memory(21);
    read_memory(22);
}
