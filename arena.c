//
// Created by user on 2/26/24.
//

#include "arena.h"

typedef struct Chain {
    struct ArenaBlock* firstBlock;
    struct Chain* nextChain;
} Chain;

Chain* firstChain = NULL;

ArenaBlock* GetBlock() {
    ArenaBlock* block;

    if (firstChain == NULL) {
        block = malloc(sizeof(ArenaBlock));
        block->next = NULL;
        return block;
    }

    block = firstChain->firstBlock;
    firstChain->firstBlock = block->next;

    if (firstChain->firstBlock == NULL)
        firstChain = firstChain->nextChain;

    return block;
}

Arena* NewArena() {
    Arena* arena = malloc(sizeof(Arena));

    arena->firstBlock = GetBlock();
    arena->currentBlock = arena->firstBlock;
    arena->currentPointer = &(arena->firstBlock->data);

    return arena;
}

void FreeArena(Arena* arena) {
    Chain* newChain = malloc(sizeof(Chain));

    newChain->firstBlock = arena->firstBlock;
    newChain->nextChain = firstChain;

    firstChain = newChain;
}

void* AllocateInArena(Arena* arena, size_t size) {
    if (arena->currentPointer + size > (void*)arena->currentBlock + sizeof(ArenaBlock)) {
        ArenaBlock* block = GetBlock();
        arena->currentBlock->next = block;
        arena->currentBlock = block;
        arena->currentPointer = &(block->data);
    }

    void* memory = arena->currentPointer;
    arena->currentPointer += size;
    return memory;
}
