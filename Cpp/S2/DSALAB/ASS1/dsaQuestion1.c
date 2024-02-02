/*
    QUESTION STEM:
    WAP IN C TO CREATE A LINKED LIST AND TRAVERSE THE LINKED LIST.
*/

#include <stdio.h>
#include <stdlib.h>

// a pointer of a particular type can traverse a memory space of that length and can access it's information as well.

struct node{
    int data;
    struct node* nextAddress;
};

struct node* makeLinkedList(int values[], int length)
{
    struct node* head = NULL; // Head pointer is always of the type node
    struct node* currentNode = NULL;

    for (int i=0; i<length; i++){
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = values[i];
        newNode->nextAddress = NULL;

        if (head == NULL)
        {
            head = newNode; // Both are pointers so normal assignment operator works.
            currentNode = newNode;
        }
        else
        {
            currentNode->nextAddress = newNode;
            currentNode = newNode;
        }
        
    }

    return head; //Returning head allows us to make the traverse function, which will start from head addree of the LL
}

void traverseLinkedList(struct node* head)
{
    struct node* currentPlace = head;
    // struct node* nectTravelled = NULL;

    while (currentPlace != NULL)
    {
        printf("%d ", currentPlace->data);
        currentPlace = currentPlace->nextAddress;
    }
}

int main()
{
    int numbers[] = {1,2,3,4,5}, length = 5;
    struct node* head = makeLinkedList(numbers, length);
    traverseLinkedList(head);

    return 0;
}