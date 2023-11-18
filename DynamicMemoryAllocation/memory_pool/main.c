#include<stdio.h>
#include<stdlib.h>
#include "memoryPoolManager.h"

typedef struct TestStruct
{
  int a;
  long b;
  float c;
  double d;
  char e;
} TestStruct;

// Function decorators
void badMemoryAllocationExample();
void goodMemoryAllocationExample();
void freeTestStruct(TestStruct*);

int main(int argc, char const *argv[])
{
  // Allocating dynamic memory manually has several drawbacks. Each call to "malloc"
  // produces a system call and hence slows down the performance as it has to interact
  // with the operating system. Making such calls fequently also causes FRAGMENTATION in the
  // heap which also slows down performaance. A solution to this problem is to allocate the
  // overall memory that the program might take at once using memory pools. Such pools can be
  // easily created using teh LINKED LIST data structure.

  // Manual (Bad) memory allocation example
  // puts("Memory allocation started");
  // badMemoryAllocationExample();
  // puts("Memory allocation finished");

  // Good memory allocation (Memory Pool) example
  puts("Memory allocation started");
  goodMemoryAllocationExample();
  puts("Memory allocation finished");

  return 0;
}

void badMemoryAllocationExample()
{
  int testBlockCount = 50000000;

  for(size_t i = 0; i < testBlockCount; i++)
  {
    TestStruct* testStruct = (TestStruct*)malloc(sizeof(TestStruct));
    freeTestStruct(testStruct);
  }
}

void goodMemoryAllocationExample()
{
  int testStructCountForEachBlock = 10000000;
  int memoryPoolBlockCount = 5;

  MemoryPoolManager* memoryPoolManager;

  // Instead of allocating 50000000 structs by repeatedly calling "malloc", we're creating a memory pool
  // that will contain 5 memory blocks, each of which will contain 10000000 TestStruct.
  initMemoryPool(&memoryPoolManager, sizeof(TestStruct)*testStructCountForEachBlock, memoryPoolBlockCount);

  printMemoryPoolBlockSizes(memoryPoolManager);

  MemoryPoolBlock *block1, *block2;

  // Allocating block1 first block from the memory pool
  allocateMemoryFromPool(memoryPoolManager, &block1);

  TestStruct* block1Data = (TestStruct*)block1->data;

  // First TestStruct of block1
  block1Data[0].a = 10;
  block1Data[0].b = 20;
  block1Data[0].c = 4.8;
  block1Data[0].d = 8.5;
  block1Data[0].e = 'A';

  // Second TestStruct of block1
  block1Data[1].a = 10;
  block1Data[1].b = 20;
  block1Data[1].c = 4.8;
  block1Data[1].d = 8.5;
  block1Data[1].e = 'A';

  // Allocating block2 from the memory pool
  allocateMemoryFromPool(memoryPoolManager, &block2);

  printMemoryPoolBlockSizes(memoryPoolManager);

  // Destroying block1 and giving it's storage back to the memory pool
  freeMemoryFromPool(memoryPoolManager, block1);

  printMemoryPoolBlockSizes(memoryPoolManager);

  destroyMemoryPool(memoryPoolManager);

  memoryPoolManager = NULL;
}

void freeTestStruct(TestStruct* testStruct)
{
  free(testStruct);
}
