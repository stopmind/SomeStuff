//
// Created by user on 2/26/24.
//

#ifndef ARENA_H
#define ARENA_H

#include <stdint.h>
#include <malloc.h>

typedef struct ArenaBlock {
    struct ArenaBlock* next;
    char data[2048];
} ArenaBlock;

typedef struct {
    ArenaBlock* firstBlock;
    ArenaBlock* currentBlock;
    void* currentPointer;
} Arena;

Arena* NewArena();
void FreeArena(Arena* arena);
void* AllocateInArena(Arena* arena, size_t size);

#endif //ARENA_H
