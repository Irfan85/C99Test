#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
  int data;
  struct Node* next;
} Node;

typedef struct LinkedList
{
  int count;
  Node* head;
} LinkedList;

// Function decorations
LinkedList* initLinkedList();
void destroyLinkedList(LinkedList*);
void insertNode(LinkedList*, int);
void removeNode(LinkedList*, Node*);
void printLinkedList(LinkedList*);
void printNode(Node*);


int main(int argc, char const *argv[])
{

  // Static structures are stored in the STACK. Dynamic structures are stored in the HEAP.

  LinkedList* myList = initLinkedList();

  if(!myList) return 1;

  insertNode(myList, 1);
  printLinkedList(myList);

  insertNode(myList, 2);
  printLinkedList(myList);

  insertNode(myList, 3);
  printLinkedList(myList);

  destroyLinkedList(myList);

  return 0;
}

LinkedList* initLinkedList()
{
  LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));

  if(list != NULL)
  {
    // The "->" will auto dereference a structure pointer.
    list->count = 0;
    list->head = NULL;
  }

  return list;
}

void destroyLinkedList(LinkedList* list)
{
  if(list == NULL)
  {
    return;
  }

  Node* current = list->head;

  while(current != NULL)
  {
    Node* next = current->next;

    removeNode(list, current);
    current = next;
  }

  free(list);

  puts("The LinkedList has been destroyed.");
}

void printLinkedList(LinkedList* list)
{
  if(list == NULL)
  {
    return;
  }

  Node* current = list->head;

  while(current != NULL)
  {
    printNode(current);

    current = current->next;
  }

  printf("\n");
}

void printNode(Node* node)
{
  printf("[%d] => %s", node->data, node->next ? "" : "NULL");
}

void insertNode(LinkedList* list, int data)
{
  if(list == NULL)
  {
    return;
  }

  Node* newNode = (Node*)malloc(sizeof(Node));

  if(newNode == NULL) return;

  newNode->data = data;
  newNode->next = NULL;

  // In case of initializing multiple pointers in the same line, the pointer
  // notation must go with the variable name.
  Node *current = list->head, *lastNode = NULL;

  while(current)
  {
    lastNode = current;
    current = current->next;
  }

  if(lastNode == NULL)
  {
    // The list is empty and the newNode will be the first node.
    list->head = newNode;
  }
  else
  {
    lastNode->next = newNode;
  }

  list->count++;
}

void removeNode(LinkedList* list, Node* node)
{
  if(list == NULL || list->head == NULL || node == NULL) return;

  if(list->head == node)
  {
    printf("Removing: [%d]\n", node->data);

    Node* next = list->head->next;

    free(list->head);

    list->count--;
    list->head = next;
  }

  Node *current = list->head, *previous = NULL;

  while(current != NULL)
  {
    if(current == node)
    {
      printf("Removing: [%d]\n", current->data);

      previous->next = current->next;

      free(current);
      break;
    }
    else
    {
      {
        previous = current;
        current = current->next;
      }
    }
  }

  list->count--;
}
