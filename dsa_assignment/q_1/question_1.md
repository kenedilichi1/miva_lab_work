# How Are The Linked List Operations Managed In Memory?

Linked list operations are managed in memory through dynamic allocation of non-contiguous memory blocks (called nodes), which are then logically connected using pointers. This dynamic approach allows the list to grow or shrink at runtime without needing to shift elements in memory.

When you call new Node(), the operating system finds an available pocket of memory large enough to hold the data and a pointer. The "management" of these nodes relies entirely on pointers. To insert a node, you simply update the memory address stored in the next pointer of the preceding node to point to the new node's heap address.

Because these nodes are manually allocated on the heap, they do not disappear when a function ends (unlike local variables on the Stack). This necessitates manual deallocation using the delete operator; otherwise, the memory remains "claimed" even if the program loses the pointer to it, resulting in a memory leak.