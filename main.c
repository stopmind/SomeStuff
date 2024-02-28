#include <stdio.h>
#include <string.h>
#include "arena.h"

int main() {
    Arena* arena = NewArena();
    char* string = AllocateInArena(arena, sizeof(char) * 14);
    strcpy(string, "Hello, World!\n");

    printf(string);

    FreeArena(arena);
    return 0;
}
