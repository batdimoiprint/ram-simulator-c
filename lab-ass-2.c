#include <stdio.h>
int mem[256] = {0};

int write_memory(int addr, int value)
{
    if (addr < 0 || addr > 255)
    {
        printf("The address is out of range\n");
    }
    else
    {
        return mem[addr] = value;
    }
}

int read_memory(int addr)
{
    if (addr < 0 || addr > 255)
    {
        printf("The address is out of range\n");
    }
    else
    {
        return mem[addr];
    }
}

// lenght parameter is for the values[] 's array length because C is old af
int load_block(int start_addr, int values[], int length)
{
    if (start_addr < 0 || start_addr > 255)
    {
        printf("The address is out of range\n");
    }
    else
    {
        for (int i = 0; i < length; i++)
        {
            write_memory(start_addr + i, values[i]);
        }
    }
}

int main()
{
    // write_memory(10,42);
    // write_memory(10,43);
    // printf("%d",read_memory(10));

    char word[] = "word";
    printf("%d", sizeof(word));
}
