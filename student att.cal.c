
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stuName[20][30];
int presentAttendance[20] = {0};
int absentAttendance[20] = {0};
int indexNumber = 0;

void checkAttendance() {
    int i;
    printf("\nTotal Present | Total Absent\n");
    for (i = 0; i < indexNumber; i++) {
        printf("%s %d %d\n", stuName[i], presentAttendance[i], absentAttendance[i]);
    }
}

void addstudent() {
    int i, num, add;
    if (indexNumber == 0) {
        printf("Enter how many students you want to add: ");
        fflush(stdin);
        scanf("%d", &num);
        for (i = 0; i < num; i++) {
            printf("\nEnter %d student name to add in attendance register: ", i + 1);
            fflush(stdin);
            gets(stuName[i]);
            indexNumber++;
        }
    }
    else {
        printf("Enter how many students you want to add: ");
        fflush(stdin);
        scanf("%d", &num);
        add = indexNumber + num;
        for (i = indexNumber; i < add; i++) {
            printf("\nEnter %d student name to add in attendance register: ", i + 1);
            fflush(stdin);
            gets(stuName[i]);
            indexNumber++;
        }
    }
}

void removeStudent() {
    char name[30];
    printf("\nEnter student name to remove: ");
    fflush(stdin);
    gets(name);
    for (int i = 0; i < indexNumber; i++) {
        if (strcmp(name, stuName[i]) == 0) {
            for (int j = i; j < indexNumber; j++) {
                strcpy(stuName[j], stuName[j + 1]);
                presentAttendance[i] = presentAttendance[i + 1];
                absentAttendance[i] = absentAttendance[i + 1];
            }
            indexNumber--;
            printf("\n%s student is removed\n", name);
            break;
        }
        else if (i == indexNumber - 1) {
            printf("This name is not exits\n");
        }
    }
}

void takeAttendance() {
    int i;
    char ch;
    printf("\nEnter y for present and N for absent\n");
    for (i = 0; i < indexNumber; i++) {
        repeat:
        printf("%d. %s is present: ", i + 1, stuName[i]);
        fflush(stdin);
        scanf("%c", &ch);
       if(ch=='Y'||ch=='y')
       {
        presentAttendance[i]+=1;
       } 
       else if (ch=='N'||ch=='n')
       {
      absentAttendance [i]+=1;
       }
      else
      {
     printf("Invalid charcter Try again\n");
     goto repeat;
     }
   }
}

int main()
{
int choose;
do
{
printf("\nMain Menu\n");
printf("Enter 1 for add student\n");
printf("Enter 2 for take attendance\n");
printf("Enter 3 for cheak attendance\n");
printf("Enter 4 for remove student\n");
printf("Enter 5 for exit\n");
printf("Please choose any menu: ");
fflush(stdin);
scanf("%d",&choose);
switch(choose)
{
case 1:
addstudent();
break;
case 2:
takeAttendance();
break;
case 3:
checkAttendance();
break;
case 4:
removeStudent();
break;
case 5:
exit(0);
break;
default:
printf("Invalid choice! Try again.\n");
break;
}
} while (choose != 5);

return 0;
}

