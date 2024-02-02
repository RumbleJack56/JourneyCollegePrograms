#include<stdio.h>
#include<stdlib.h>

struct Node{
  int val;
  Node* next;
};

int size=100;
Node* head = (Node*)(calloc(1,sizeof(Node)));
int top=-1;

int checkEmpty() {return (top==-1);}
int checkFull() {return (top==size-1);}

Node* push(Node* curr_head,int val){
  if (checkFull()) {printf("OverFlow");return curr_head;}
  Node* newHead = (Node*)(calloc(1,sizeof(Node)));
  newHead->val = val;
  newHead->next = curr_head;
  top++;
  return newHead;
}

Node* pop(Node* curr_head){
  if (checkEmpty()) {printf("Underflow ");return curr_head;}
  Node* newHead = curr_head->next;
  top--;
  free(curr_head);
  return newHead;
}

int peek(Node* curr_head){
  if (checkEmpty()) {printf("Underflow ");return -1;}
  return curr_head->val;
}

void printStack(Node* cptr){
  if (checkEmpty()) printf("Underflow ");
  else{
    printf("Stack:");
    while(cptr!=NULL){
      printf("%d\n",cptr->val);
      cptr=cptr->next;
    }
  }
}

int main(){

  head = push(head,10);
  head = push(head,20);
  head = push(head,30);
  printf("%d\n",peek(head));

  // printStack(head);
  head = push(head,40);
  head = push(head,50);
  printf("%d\n",peek(head));
  
  // printStack(head);
  head = pop(head);
  printf("%d\n",peek(head));
  
  // printStack(head);
  head = pop(head);
  head = pop(head);
  printf("%d\n",peek(head));
  head = pop(head);
  printf("%d\n",peek(head));
  // printStack(head);
  head = pop(head);
  printf("%d\n",peek(head));
  head = pop(head);
  return 0;
}