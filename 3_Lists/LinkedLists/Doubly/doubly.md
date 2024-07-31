# Doubly Linked List

A doubly linked list is essentially the same as a linked list but the node structure is slightly different as now there is a node that points to the previous node as well as the next node.

Notes:
Now the start and end of the list are represented by nullptrs.

## Doubly Linked List Node

```cpp
class DoublyNode {
    int data;
    DoublyNode* prev;
    DoublyNode* next;

    // Constructor
    DoublyNode(int value, DoublyNode* pNode, DoublyNode* nNode)
        : data(value), prev(pNode), next(nNode) {}

    // Destructor
    ~DoublyNode ()

};
```

### Singly vs. Doubly

If a size parameter is implemented for the LinkedList class the delete and insert time for a linked list can be cut in half if a size parameter included in the list class as the iteration through the list can start from the closer size to the insert index. This said the space per node is increased as now two pointers must be stored in each node. \

### Time Complexity of Operations

|        | Singly       | Doubly       |
| ------ |------------- | ------------ |
| Search | O(n)         | O(n)         |
| Insert | O(n)         | O(n)         |
| Delete | O(n)         | O(n)         |
| Space  | Less (1 ptr) | More (2 ptr) |

**Note:**
The time complexity for insert and delete for doubly is half of the list but in terms of big O they have the same complexity.
