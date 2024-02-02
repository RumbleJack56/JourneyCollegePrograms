#include<stdio.h>
int main(){
    int arr[] = {2123,1234,44,3,35,12};
    FILE* fptr = fopen("prac1.txt","w");
    int arrlen = sizeof(arr)/sizeof(arr[0]);
    for (int k=0;k<arrlen;++k){
        fprintf(fptr,"%d\n",arr[k]);
    }
    fclose(fptr);

    FILE* fptr2= fopen("prac1.txt","r");
    int no_lines=0;
    while(1==1){
        char c = fgetc(fptr2);
        if (c=='\n'){no_lines++;}
        else if (c==EOF){break;}
    }
    int numStream[no_lines];
    rewind(fptr2);
    for (int k=0;k<no_lines;++k){
        fscanf(fptr2,"%d",&numStream[k]);
    }

    for (int k=0;k<no_lines;++k){
        printf("%d\n",numStream[k]);
    }
}