#include<stdio.h>
#include<string.h>

int main(){
    int n;
    printf("Enter Student Number: ");
    scanf("%d",&n);        while((getchar())!='\n');
    struct student{
        char name[40];int rollno; char grade; float gp;};
    struct student students[n];

    for (int k=0; k<n;++k){
        printf("Enter Student %d name: ",k+1);
        fgets(students[k].name,40,stdin);

        students[k].name[strcspn(students[k].name,"\n")] = '\0';




        printf("Enter Student %d Roll number: ",k+1);
        int rn; scanf("%d",&rn); students[k].rollno = rn;

        while((getchar())!='\n');

        printf("Enter Student %d grade: ",k+1);
        char grade; scanf("%c",&grade); students[k].grade = grade;

        while((getchar())!='\n');

        printf("Enter Student %d GPA: ",k+1);
        float gpa; scanf("%f",&gpa); students[k].gp = gpa;

        while((getchar())!='\n');
    }
    

    for (int i=0;i<n;++i){
        printf("Student 1 is %s with roll number:  %d, he got grade %c and overall GPA %.2f \n\n",students[i].name,students[i].rollno,students[i].grade,students[i].gp);
    }

    
}