/*
    QUESTION STEM:
    WAP IN C TO DELETE THE ELEMENT IN A LINKED LIST FROM
    a) AT THE BEGINNING
    b) AT THE END
    c) BETWEEN 2 NODES
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node* nextAddressPtr;
};

struct node* createLinkedList(int length, int data[])
{
    struct node* head = NULL;
    struct node* currentPos = NULL;

    for (int i = 0; i < length; i++)
    {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->value = data[i];
        newNode->nextAddressPtr = NULL;

        if (head == NULL)
        {
            head = newNode;
            currentPos = newNode;
        }
        else
        {
            currentPos->nextAddressPtr = newNode;
            currentPos = newNode;
        }
    }
    return head;
}

void removeFromEnd(struct node* head)
{
    struct node* currentPos = head;
    while (currentPos->nextAddressPtr->nextAddressPtr != NULL)
    {
        currentPos = currentPos->nextAddressPtr;
    }
    currentPos->nextAddressPtr = NULL;    
}

struct node* removeFromBeginning(struct node* head)
{
    struct node* currentPos = head;
    head = currentPos->nextAddressPtr;
    return head;
}

void removeFromBetween(struct node* head, int valueBeforeDel)
{
    struct node* currentPos = head;
    while (currentPos->value != valueBeforeDel)
    {
        currentPos = currentPos->nextAddressPtr;
    }
    
    currentPos->nextAddressPtr = currentPos->nextAddressPtr->nextAddressPtr;
}

void printLinkedList(struct node* head)
{
    struct node* currenPos = head;
    while (currenPos != NULL)
    {
        printf("%d ", currenPos->value);
        currenPos = currenPos->nextAddressPtr;
    }
    
}

int main()
{
    int data[] = {1,2,3,4,5,6,7,8,9,10}, length = sizeof(data)/sizeof(data[0]);
    struct node* head = createLinkedList(length, data);

    // Printing original Linked List
    printLinkedList(head);
    printf("\n");

    // Performing Operations
    struct node* newhead = removeFromBeginning(head);
    removeFromEnd(newhead);
    removeFromBetween(newhead, 6);

    // Printing new Linked List
    printLinkedList(newhead);

    return 0;
}