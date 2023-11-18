# Dynamic Memory Allocation in C

![C Dynamic Memory Allocation](./C%20Memory%20Allocation.png "Dynamic Memory Allocation in C")

- Static memory allocation happens in the **STACK**. The user cannot manually free
  stack memory.

- Dynamic memory allocation happens in the **HEAP**. The user has to free this type of
  memory by themselves.

- If "malloc", "calloc" and "realloc" functions fail to returns a memory which may happen
  for not having the requested amount of memory, they return a NULL pointer. So it's good
  to have a NULL pointer check while using these functions.

- AVOID doing pointer arithmetic whenever possible. It's good to know about them, but only
  apply them when they happen to offer the simpler and cleaner solution. Typically pointer
  arithmetic produces hard to read and potentially dangerous code. Use the indexing
  operator '[]' is much easier to read.
