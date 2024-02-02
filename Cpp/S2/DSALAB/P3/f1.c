#include <stdio.h>

const int size = 100;
int Stack[size];
int top = -1;

int checkEmpty() {
    if (top==-1) return 1;
    else return 0;
}
int checkFull() {
    if (top == size - 1) return 1;
    else return 0;
}

void push(int value) {
    if (checkFull()) printf("Stack Overflow");
    else Stack[++top] = value;
}

void pop(){
    if (checkEmpty()) printf("Stack Underflow");
    else top--;
}

int peek() {
    if (checkEmpty()) {printf("Stack is empty\n");return -1;}
    else return Stack[top];
}

void printStack() {
    if (checkEmpty()) printf("Stack is empty\n");
    else{
      printf("Stack: \n");
      for (int i = 0; i <= top; ++i) {
          printf("%d ", Stack[i]);
      }
      printf("\n");
    }
}

// Test the stack implementation
int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    printStack();
    pop();
    printStack();
    int val = peek();
    printf("%d\n",val);
    pop();
    printStack();
    
    return 0;
}
