#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NONE_230301120095
#define MAX_STUDENTS 1000
#define MAX_NAME_LENGTH 30
#define MAX_SUBJECTS 6

//this type def define the the structure of model 
typedef struct {
    int rollNumber;
    char name[MAX_NAME_LENGTH];
    int presentAttendance[MAX_SUBJECTS];
    int absentAttendance[MAX_SUBJECTS];
 }Student;
Student students[MAX_STUDENTS];
int indexNumber ;
// first fuction to add person/student 
void addStudent() {
	int i;
    if (indexNumber == MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return;
    }
    printf("Enter student ID number: ");
    scanf("%d", &students[indexNumber].rollNumber);
    getchar(); 
    printf("Enter student name: ");
    fgets(students[indexNumber].name, MAX_NAME_LENGTH, stdin);
    students[indexNumber].name[strcspn(students[indexNumber].name, "\n")] = 0; 
    for ( i = 0; i < MAX_SUBJECTS; i++) {
        students[indexNumber].presentAttendance[i] = 0;
        students[indexNumber].absentAttendance[i] = 0;
    }
    indexNumber++;
}

//the  function to chake attendance
void checkAttendance() {
    int i, j; 
    printf("\n\t\t Roll No | Name | Total Present | Total Absent\t\t\n");
    for (i = 0; i < indexNumber; i++) {
        int totalPresent = 0, totalAbsent = 0;
        for (j = 0; j < MAX_SUBJECTS; j++) {
            totalPresent += students[i].presentAttendance[j];
            totalAbsent += students[i].absentAttendance[j];
        }
        printf("%d\t\t%s\t\t %d\t\t%d\n", students[i].rollNumber, students[i].name, totalPresent, totalAbsent);
    }
}


void removeStudent() {
	int i,j;
    int rollNo;
    printf("Enter student roll number to remove: ");
    scanf("%d", &rollNo);
    getchar();
    for (i = 0; i < indexNumber; i++) {
        if (students[i].rollNumber == rollNo) {
            for ( j = i; j < indexNumber - 1; j++) {
                memcpy(&students[j], &students[j + 1], sizeof(Student));
            }
            indexNumber--;
            printf("\nStudent with roll number %d is removed\n", rollNo);
            return;
        }
    }
    printf("Student with roll number %d not found.\n", rollNo);
}

void takeAttendance() {
	int i,j;
    char ch;
    printf("\nEnter Y for present and N for absent\n");
    for (i = 0; i < indexNumber; i++) {
        printf("%d. %s:\n", students[i].rollNumber, students[i].name);
        for ( j = 0; j < MAX_SUBJECTS; j++) {
            printf("Subject %d is present: ", j + 1);
            ch = getchar(); 
            getchar(); 
            if (ch == 'Y' || ch == 'y') {
                students[i].presentAttendance[j]++;
            } else if (ch == 'N' || ch == 'n') {
                students[i].absentAttendance[j]++;
            } else {
                printf("Try again.\n");
                j--; 
            }
        }
    }
}

void showStudents() {
	int i,j;
    printf("\n\t\t Roll No | Name\t\t\n");
    for ( i = 0; i < indexNumber; i++) {
        printf("%d\t\t%s\n", students[i].rollNumber, students[i].name);
    }
}

void showIndividualSubjectAttendance() {
	int i,j;
    int rollNo;
    printf("Enter student roll number: ");
    scanf("%d", &rollNo);
    getchar(); 
    for ( i = 0; i < indexNumber; i++) {
        if (students[i].rollNumber == rollNo) {
            printf("\nAttendance for student %s (Roll No: %d):\n", students[i].name, students[i].rollNumber);
            for ( j = 0; j < MAX_SUBJECTS; j++) {
                printf("Subject %d: Present - %d, Absent - %d\n", j + 1, students[i].presentAttendance[j], students[i].absentAttendance[j]);
            }
            return;
        }
    }
    printf("Student with roll number %d not found.\n", rollNo);
}

void showTotalSubjectAttendance() {
	int i,j;
    int totalPresent[MAX_SUBJECTS] = {0};
    int totalAbsent[MAX_SUBJECTS] = {0};
    for ( i = 0; i < indexNumber; i++) {
        for (j = 0; j < MAX_SUBJECTS; j++) {
            totalPresent[j] += students[i].presentAttendance[j];
            totalAbsent[j] += students[i].absentAttendance[j];
        }
    }
    printf("\nTotal Subject Attendance:\n");
    for ( i = 0; i < MAX_SUBJECTS; i++) {
        printf("Subject %d: Present - %d, Absent - %d\n", i + 1, totalPresent[i], totalAbsent[i]);
    }
}

int main() {
    int choose;
    do {
        printf("\n\t\t\t\t<------------------------Welcome to our system-------------------->\n");
        printf("\t1.add student\n");
        printf("\t2.to take attendance\n");
        printf("\t3.to check attendance\n");
        printf("\t4.to remove student\n");
        printf("\t5.to show all registered students\n");
        printf("\t6.to show individual subject attendance for a student\n");
        printf("\t7.to show total subject attendance\n");
        printf("\t8.to exit\n\n");
        printf("Enter the catagorise number : ");
        scanf("%d", &choose);
        getchar(); 
        switch (choose) {
            case 1:
                addStudent();
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
                showStudents();
                break;
            case 6:
                showIndividualSubjectAttendance();
                break;
            case 7:
                showTotalSubjectAttendance();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choose != 8);

    return 0;
}

