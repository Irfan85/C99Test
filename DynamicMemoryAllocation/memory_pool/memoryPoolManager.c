#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h> // Required for using the "memset" function
#include "memoryPoolManager.h"

MemoryPoolStatus initMemoryPool(MemoryPoolManager** pool, size_t memoryBlockSize, __uint32_t memoryBlockCount)
{
  if(memoryBlockCount == 0) return MEMORY_POOL_INIT_ERROR;

  // Allocate required memory for the pool struct
  *pool = (MemoryPoolManager*)malloc(sizeof(MemoryPoolManager));

  if(*pool == NULL) return MEMORY_POOL_INIT_ERROR;

  // Allocate memory for storing the MEMORY BLOCK STRUCTURES
  MemoryPoolBlock* blocks = (MemoryPoolBlock*)malloc(sizeof(MemoryPoolBlock) * memoryBlockCount);

  if(blocks == NULL) return MEMORY_POOL_INIT_ERROR;

  size_t poolSize = memoryBlockSize * memoryBlockCount;

  // Allocate the memory chunks that will be managed by the pool. This is where our data will be stored.
  void* start = (void*)malloc(poolSize);

  if(start == NULL) return MEMORY_POOL_INIT_ERROR;

  (*pool)->memoryBlockCount = memoryBlockCount;
  (*pool)->memoryBlockSize = memoryBlockSize;
  (*pool)->poolSize = poolSize;
  (*pool)->head = blocks;

  void *currentChunk = start, *nextChunk = NULL;

  MemoryPoolBlock *currentBlock = blocks, *nextBlock = NULL;

  for(size_t i = 0; i < memoryBlockCount; i++)
  {
    // Assign a chunks to their respective memory blocks
    currentBlock->data = currentChunk;

    if(i == memoryBlockCount - 1)
    {
      // Last block
      nextChunk = NULL;
      nextBlock = NULL;
    }
    else
    {
      nextChunk = currentChunk + memoryBlockSize;
      nextBlock = currentBlock + sizeof(MemoryPoolBlock);
    }

    currentBlock->next = nextBlock;
    currentBlock->size = memoryBlockSize;
    currentBlock->isAllocated = false;

    currentChunk = nextChunk;
    currentBlock = nextBlock;
  }

  return MEMORY_POOL_OK;
}

MemoryPoolStatus destroyMemoryPool(MemoryPoolManager* pool)
{
  if(pool != NULL && pool->head != NULL)
  {
    free(pool->head->data);
    free(pool->head);
    free(pool);

    return MEMORY_POOL_OK;
  }

  return MEMORY_POOL_DESTROY_ERROR;
}

MemoryPoolStatus allocateMemoryFromPool(MemoryPoolManager* pool, MemoryPoolBlock** block)
{
  if(pool == NULL || block == NULL) return MEMORY_POOL_ALLOC_ERROR;

  if(pool->head != NULL)
  {
    MemoryPoolBlock* currentBlock = pool->head;

    while(currentBlock)
    {
      if(currentBlock->isAllocated == false)
      {
        currentBlock->isAllocated = true;
        *block = currentBlock;

        return MEMORY_POOL_OK;
      }
      else {
        currentBlock = currentBlock->next;
      }
    }
  }

  return MEMORY_POOL_ALLOC_ERROR;
}

MemoryPoolStatus freeMemoryFromPool(MemoryPoolManager* pool, MemoryPoolBlock* block)
{
  if(pool == NULL || block == NULL) return MEMORY_POOL_DESTROY_ERROR;

  if(pool->head != NULL)
  {
    MemoryPoolBlock* currentBlock = pool->head;

    while(currentBlock)
    {
      if(currentBlock == block)
      {
        currentBlock->isAllocated = false;

        // For avoiding memory leak, we'll set the data that's about to be deleted to 0.
        memset(currentBlock->data, 0, pool->memoryBlockSize);

        return MEMORY_POOL_OK;
      }
      else
      {
        currentBlock = currentBlock->next;
      }
    }
  }

  return MEMORY_POOL_DESTROY_ERROR;
}

void printMemoryPoolBlockSizes(MemoryPoolManager* pool)
{
  if(pool == NULL) return;

  MemoryPoolBlock* currentBlock = pool->head;

  while (currentBlock != NULL)
  {
    printBlockSize(currentBlock);
    currentBlock = currentBlock->next;
  }

  printf("\n");
}

void printBlockSize(MemoryPoolBlock* block)
{
  // The "t" format specifier represents the difference between two pointer locations.
  printf("[%td | %d] => ", block->next && block->next->data ? block->next->data - block->data : block->size, block->isAllocated);
}
