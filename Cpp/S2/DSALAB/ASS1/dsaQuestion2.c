/*
    QUESTION STEM:
    WAP IN C TO INSERT AN ELEMENT IN A LL:
        a) AT THE END
        b) AT THE START
        c) BETWEEN TWO NODES
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node* nextAddressPointer;
};

struct node* createLinkedList(int data[], int length)
{
    int* arrayPtr = data;
    struct node* head = NULL;
    struct node* currentPos = NULL;

    for (int i = 0; i < length; i++)
    {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->value = *(arrayPtr+i);
        newNode->nextAddressPointer = NULL;

        if (head==NULL)
        {
            head = newNode;
            currentPos = newNode;
        }
        else
        {
            currentPos->nextAddressPointer = newNode;
            currentPos = newNode;
        }
    }
    return head;
}

void insertElementAtEnd(struct node* head, int valueToBeInserted)
{
    struct node* posCheck = head;
    struct node* nodeAdded = (struct node*)malloc(sizeof(struct node));
    nodeAdded->value = valueToBeInserted;
    nodeAdded->nextAddressPointer = NULL;

    /*What I was doing - I was checking is the posCheck pointer is NULL or not. And by the time it was NULL, it was already at the end of the LL.
    So the node was not added properly. Now I am checking if the next address is NULL. If it is, then I am modifying it to store the address of the new
    node. This helps to add the node properly*/

    while (posCheck->nextAddressPointer != NULL)
    {
        posCheck = posCheck->nextAddressPointer;
    }

    posCheck->nextAddressPointer = nodeAdded;
    
}

struct node* insertElementAtStart(struct node* head, int valueToBeInserted)
{
    struct node* nodeAdded = (struct node*)malloc(sizeof(struct node));
    nodeAdded->value = valueToBeInserted;
    nodeAdded->nextAddressPointer = head;
    head = nodeAdded;

    return head;
}

void insertElementInBetween(struct node* head, int valueToBeInserted, int valueBeforeInsertion)
{
    struct node* currentPos = head;
    while (currentPos->value != valueBeforeInsertion)
    {
        currentPos = currentPos->nextAddressPointer;
    }

    struct node* nodeAdded = (struct node*)malloc(sizeof(struct node));
    nodeAdded->value = valueToBeInserted;
    nodeAdded->nextAddressPointer = currentPos->nextAddressPointer;
    currentPos->nextAddressPointer = nodeAdded;
}

void printLinkedList(struct node* head)
{
    struct node* currentPos = head;
    while (currentPos != NULL)
    {
        printf("%d\t", currentPos->value);
        currentPos = currentPos->nextAddressPointer;
    }
}

int main()
{
    int data[] = {1,2,3,4,5}, length = sizeof(data)/sizeof(data[0]);
    struct node* head = createLinkedList(data, length);
    printf("We will add 0 at the start and 6 at the end of the Linked List. Also we will add 4 again after 4\n");
    printLinkedList(head);
    printf("\n");
    struct node* newhead = insertElementAtStart(head, 0);
    insertElementAtEnd(newhead, 6);
    insertElementInBetween(newhead, 4, 4);
    printLinkedList(newhead);
}