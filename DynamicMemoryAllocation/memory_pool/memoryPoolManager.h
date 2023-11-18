#include<stdlib.h>
#include<stdbool.h> // Required for using "bool" type.

#ifndef MEM_POOL_MANAGER_H
#define MEM_POOL_MANAGER_H

typedef struct MemoryPoolBlock
{
  void* data;
  bool isAllocated;
  size_t size;
  // Must use the "struct" keyword while self-referencing.
  struct MemoryPoolBlock* next;
} MemoryPoolBlock;

typedef struct MemoryPoolManager
{
  size_t poolSize;
  size_t memoryBlockSize;
  __uint32_t memoryBlockCount;
  MemoryPoolBlock* head;
} MemoryPoolManager;

typedef enum {
    MEMORY_POOL_INIT_ERROR,
    MEMORY_POOL_DESTROY_ERROR,
    MEMORY_POOL_ALLOC_ERROR,
    MEMORY_POOL_OK
} MemoryPoolStatus;

MemoryPoolStatus initMemoryPool(MemoryPoolManager** pool, size_t memoryBlockSize, __uint32_t memoryBlockCount);

MemoryPoolStatus destroyMemoryPool(MemoryPoolManager* pool);

MemoryPoolStatus allocateMemoryFromPool(MemoryPoolManager* pool, MemoryPoolBlock** block);

MemoryPoolStatus freeMemoryFromPool(MemoryPoolManager* pool, MemoryPoolBlock* block);

void printMemoryPoolBlockSizes(MemoryPoolManager* pool);

void printBlockSize(MemoryPoolBlock* block);

#endif
