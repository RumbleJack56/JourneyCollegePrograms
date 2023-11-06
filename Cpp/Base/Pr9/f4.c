#include<stdio.h>
#include<string.h>
int main(){
    struct u_stud{
        int id;
        char std_dept[30];
    };
    struct d_stud{
        char stud_name[30];
        struct u_stud us;
        char grade[3];
    };
    struct d_stud ds;
    strcpy(ds.stud_name,"Ujjwal");
    ds.us = {1,"Electronics"};
    ds.grade[0] = 'a';
    ds.grade[1] = 'b';
    ds.grade[2] = 'c';
    printf("%s   %d    %s   %c %c %c",ds.stud_name,ds.us.id,ds.us.std_dept,ds.grade[0],ds.grade[1],ds.grade[2]);
}