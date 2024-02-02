//Matrix addition
#include<stdio.h>
int main(){
  int p,q;
  printf("Enter two numbers as dimension of matrices (with spaces): ");
  scanf("%d %d",&p,&q);     while((getchar())!='\n');
  
  int arr1[p][q],arr2[p][q],arr3[p][q];

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
  for (int a=0;a<p;++a){
    for (int b=0;b<q;++b){
      printf("Enter number of row %d and column %d: ",a+1,b+1);
      scanf("%d",&arr2[a][b]);   while((getchar())!='\n');
    }
  }

  //Prints Matrices
  printf("Matrices are : \n");
  for (int a=0;a<p;++a){
    for (int b=0;b<q;++b){
      printf("%3d ",arr1[a][b]);
    }
    printf("\n");
  }
  printf("\n\n");
  for (int a=0;a<p;++a){
    for (int b=0;b<q;++b){
      printf("%3d ",arr2[a][b]);
    }
    printf("\n");
  }
  printf("\n\n");

  // Adds Matrices
  for(int k=0;k<p;++k){
    for (int m=0;m<q;++m){
      arr3[k][m] = arr1[k][m]+arr2[k][m];
    }
  }
  //Prints added Matrix
  printf("Added Matrix\n");
  for (int a=0;a<p;++a){
    for (int b=0;b<q;++b){
      printf("%3d ",arr3[a][b]);
    }
    printf("\n");
  }
  }