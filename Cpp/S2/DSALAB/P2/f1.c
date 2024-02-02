#include<stdio.h>
#include<stdlib.h>

struct Node{
  int val;
  int row;
  int col;
  Node* next;
};

int main(){
  int arr[10][10];
  printf("Enter Sparse Matrix (10x10): \n");

  for (int m=0;m<5;++m){
    printf("Row %d: \n",m+1);
    for (int n=0;n<5;++n){
      int val;
      scanf("%d",&val);
      arr[m][n] = val;
    }
  }

  // implementing sparse array

  Node* head = (Node*)malloc(sizeof(Node));
  Node* curptr = head;
  for (int m=0;m<5;++m){
    for (int n=0;n<5;++n){
      if (arr[m][n]!=0){
        curptr->val=arr[m][n];
        curptr->row=m;
        curptr->col=n;
        curptr->next = (Node*)calloc(1,sizeof(Node));
        curptr = curptr->next;
      }
    }
  }
  curptr = head;
  while (curptr->next!=NULL){
    if (curptr->val!=0) printf("Row: %-5d Col: %-5d Value: %-5d\n",curptr->row,curptr->col,curptr->val);
    curptr = curptr->next;
  }


}