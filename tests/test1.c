//
// Created by lits-user on 2019-08-20.
//

#include "../includes/allocation.h"

int main()
{
    int i;
    char *addr;

    i = 0;
    while (i < 1024)
    {
        addr = (char*)malloc(1024);
        addr[0] = 42;
        i++;
    }
    return (0);
}