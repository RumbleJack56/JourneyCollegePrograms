#include<stdio.h>
#include<stdlib.h>

struct Node{
  int val;
  Node* next;
};

int main(){
  int n;
  printf("Enter number of values to enter: ");
  scanf("%d",&n); while((getchar())!='\n');
  
  Node* head = (Node*)(calloc(1,sizeof(Node)));
  Node* curptr = head;
  for (int k=0;k<n;++k){
    int v;
    printf("Enter value %d: ",k+1);
    scanf("%d",&v); while((getchar())!='\n');
    curptr->val=v;
    curptr->next = (Node*)(calloc(1,sizeof(Node)));
    curptr=curptr->next;
  }
  printf("Linked List Written, Now reading\n");

  Node* travptr = head;
  int count =1;
  while(travptr->next!=NULL){
    printf("Value at Node %d is %d\n",count,travptr->val);
    count++;
    travptr=travptr->next;
  }
}