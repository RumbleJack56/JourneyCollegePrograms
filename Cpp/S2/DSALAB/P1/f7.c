//Matrix addition
#include<stdio.h>
int main(){
  int p,q,r,s;

  retry: 
  printf("Enter two numbers as dimension of matrix 1 (with spaces): ");
  scanf("%d %d",&p,&q);     while((getchar())!='\n');
  
  printf("Enter two numbers as dimension of matrix 2 (with spaces): ");
  scanf("%d %d",&r,&s);     while((getchar())!='\n');

  if (q!=r){
    printf("The Matrices cannot be multiplied!! want to try again? (y/n) : ");
    if (getchar()=='y'){
      goto retry;
    }
    else {
      printf("Quitting");
      return -1;
    }
  }

  int arr1[p][q],arr2[r][s],arr3[p][s];

  //Gets the Input of Matrix 1
  printf("Matrix 1:\n");
  for (int a=0;a<p;++a){
    for (int b=0;b<q;++b){
      printf("Enter number of row %d and column %d: ",a+1,b+1);
      scanf("%d",&arr1[a][b]);   while((getchar())!='\n');
    }
  }

  //Gets the input of Matrix 2
  printf("Matrix 2:\n");
  for (int a=0;a<r;++a){
    for (int b=0;b<s;++b){
      printf("Enter number of row %d and column %d: ",a+1,b+1);
      scanf("%d",&arr2[a][b]);   while((getchar())!='\n');
    }
  }
  //Initialises matrix 3 with zeros
  for (int a=0;a<p;++a){for (int b=0;b<s;++b){arr3[a][b]=0;}}

  //Prints Matrices
  printf("Matrices are : \n");
  for (int a=0;a<p;++a){
    for (int b=0;b<q;++b){
      printf("%3d ",arr1[a][b]);
    }
    printf("\n");
  }
  printf("\n\n");
  for (int a=0;a<r;++a){
    for (int b=0;b<s;++b){
      printf("%3d ",arr2[a][b]);
    }
    printf("\n");
  }
  printf("\n\n");

  // Multiply Matrices
  for(int k=0;k<p;++k){
    for (int m=0;m<s;++m){
      for (int n=0;n<q;++n){
        arr3[k][m] += arr1[k][n]*arr2[n][m];
      }
    }
  }
  //Prints added Matrix
  printf("Multiplied Matrix\n");
  for (int a=0;a<p;++a){
    for (int b=0;b<s;++b){
      printf("%3d ",arr3[a][b]);
    }
    printf("\n");
  }
  }



