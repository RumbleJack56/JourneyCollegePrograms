#include<stdio.h>
#include<string.h>
int main(){
    union u1
    {
        char name[10];
        int roll;
        float mark;
        char phoneno[53];
        char dept[5];
    } employee;
    employee.roll = 10;
    employee.mark = 9.9;
    printf("Name: %s ,Roll: %d ,Marks: %f ,Phone No.: %s ,Dept: %s\n",employee.name,employee.roll,employee.mark,employee.phoneno,employee.dept);
    printf("%d\n",sizeof(employee));
    strcpy(employee.dept,"cse");
    printf("Name: %s ,Roll: %d ,Marks: %f ,Phone No.: %s ,Dept: %s\n",employee.name,employee.roll,employee.mark,employee.phoneno,employee.dept);
    printf("%d\n",sizeof(employee));
    
}