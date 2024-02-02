#include<stdio.h>
#include<stdlib.h>

int slen(char str[]){
    int len = 0;
    while(str[len]!='\0') len++;
    return len;
}

int scmp(char str1[],char str2[]){
    int m = slen(str1)>slen(str2) ? slen(str2) : slen(str1);
    for (int k=0;k<m;++k){
        if (str1[k]>str2[k]){
            return 1;
        }
        else if (str1[k]<str2[k]){
            return -1;
        }
    }
    return 0;
}

void substr(char str[],int L, int R,char dest[]){
    for (int k=L;k<R;++k){
        dest[k-L] = str[k];
    } dest[R-L] = '\0';
}

void uppercase(char str[]){
    for (int k=0;k<slen(str);++k){
        if ((str[k]<='z') && (str[k]>='a')){str[k]-=32;}
    }
}

void lowercase(char str[]){
    for (int k=0;k<slen(str);++k){
        if ((str[k]<='Z') && (str[k]>='A')){str[k]+=32;}
    }
}

void printString(char subs[]){
    for (int k=0;k<slen(subs);++k){
        printf("%c",subs[k]);
    }printf("\n");
}

void sconcat(char s1[],char s2[]){
    int p =slen(s1);
    for(int k=0;k<slen(s2);++k){
        s1[k+p]=s2[k];
    }
}

int main(){
    char str1[] = "Ujjwal\0";
    char str2[] = "Academics\0";
    char str3[] = "Academia of TOMORROW\0";
    printf("%d %d %d \n",slen(str1),slen(str2),slen(str3));
    printf("%d %d \n",scmp(str1,str2),scmp(str2,str3));
    
    char subs[20]; 
    substr(str2,1,6,subs);
    printString(subs);

    printString(str1);
    uppercase(str1);
    printString(str1);


    printString(str3);
    lowercase(str3);
    printString(str3);


    printString(subs);
    printString(str1);
    sconcat(subs,str1);
    printString(subs);
    // for (int k=0;k<sizeof(subs)/sizeof(subs[0]);++k){
    //     printf("%c",subs[k]);
    // }
    return 0;
}
