#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int StudentNumber;
    char firstName[50];
    char middleName[50];
    char lastName[50];
    int age;
    int grade;
    char email[50];
    char birthDate[20];
    char sex[10];
    char course[50];
    char address[100];
    // Additional fields for address
    char barangay[50];
    char city[50];
    char streetNumber[50];
    struct Student* next;
};

// Function prototypes
void addStudent(struct Student** head, int studentNumber);
void displayStudents(struct Student* head);
int authenticateAdmin(char* adminName, char* adminPass);
void enterStudentDetails(struct Student* student);
void displayStudentsInTable(struct Student* head);
void searchStudent(struct Student* head, int studentNumber);

// Other function prototypes
int displayMenu();
void titleInfo();
void userLogin();
void adminLogin();

int main()
{
    int choice;
    struct Student* studentList = NULL;

    do
    {
        choice = displayMenu();

        switch (choice)
        {
        case 1:
            userLogin();
            break;
        case 2:
            adminLogin(&studentList);
            break;
        default:
            printf("Invalid Input! Select [1] or [2]\n");
            break;
        }
    } while (choice != 0);

    printf("Program has Terminated Successfully!\n");

    return 0;
}

int displayMenu()
{
    int choice;

    titleInfo();
    printf("\n\t|----------------------|");
    printf("\n\t| Select Login :       |");
    printf("\n\t| [1] USER             |");
    printf("\n\t| [2] ADMINISTRATOR    |");
    printf("\n\t|----------------------|");
    printf("\n SELECT: ");
    scanf("%d", &choice);

    return choice;
}

void titleInfo()
{
    printf("==========================================");
    printf("\n======= STUDENT INFORMATION SYSTEM =======");
    printf("\n========================================");
}

void userLogin()
{
    int studentNumber;

    printf("\n\t|----------------------|");
    printf("\n\t|--- STUDENT LOGIN --- |");
    printf("\n\t| ENTER STUDENT NUMBER |");
    printf("\n\t|----------------------|");
    printf("\n ENTER: ");
    scanf("%d", &studentNumber);
}

void adminLogin(struct Student** studentList)
{
    char adminName[20];
    char adminPass[20];

    printf("\n\t|-----------------------|");
    printf("\n\t|  --- ADMIN LOGIN ---  |");
    printf("\n\t| ENTER ADMIN USER NAME |");
    printf("\n\t|-----------------------|");
    printf("\n USER NAME: ");
    scanf("%s", adminName);

    printf("\n\t|-----------------------|");
    printf("\n\t| ENTER ADMIN PASSWORD  |");
    printf("\n\t|-----------------------|");
    printf("\n PASSWORD : ");
    scanf("%s", adminPass);

    if (authenticateAdmin(adminName, adminPass))
    {
        printf("\nAuthentication Successful! Welcome, %s!\n", adminName);

        int adminChoice;

        do
        {
            printf("\n\t|-------------------------|");
            printf("\n\t|   ADMINISTRATOR MENU   |");
            printf("\n\t| [1] Add Student        |");
            printf("\n\t| [2] Display Students   |");
            printf("\n\t| [3] Search Student     |");
            printf("\n\t| [0] Logout             |");
            printf("\n\t|-------------------------|");
            printf("\n SELECT: ");
            scanf("%d", &adminChoice);

            switch (adminChoice)
            {
            case 1:
            {
                int studentNumber;
                printf("\n\t|----------------------|");
                printf("\n\t|  --- ADD STUDENT --- |");
                printf("\n\t| ADD STUDENT NUMBER   |");
                printf("\n\t|----------------------|");
                printf("\n ENTER : ");
                scanf("%d", &studentNumber);
                addStudent(studentList, studentNumber);
                break;
            }
            case 3:
            {
                int studentNumber;
                printf("\n\t|-------------------------|");
                printf("\n\t|   SEARCH STUDENT        |");
                printf("\n\t| Enter Student Number    |");
                printf("\n\t|-------------------------|");  
                printf("\n STUDENT TO BE SEARCHED : ");
                scanf("%d", &studentNumber);
                searchStudent(*studentList, studentNumber);
                break;
            }
            case 2:
                displayStudentsInTable(*studentList);
                break;
            case 0:
                printf("\nLogging out...\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
                break;
            }

        } while (adminChoice != 0);
    }
    else
    {
        printf("\nAuthentication Failed! Invalid username or password.\n");
    }
}

void addStudent(struct Student** head, int studentNumber)
{
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));

    if (!newStudent)
    {
        printf("\n Memory allocation failed for adding student.");
        return;
    }

    newStudent->StudentNumber = studentNumber;
    newStudent->next = *head;

    printf("\nEnter details for Student %d:\n", studentNumber);
    enterStudentDetails(newStudent);

    *head = newStudent;

    printf("\n Student No. %d has been successfully added!\n", studentNumber);
}

void enterStudentDetails(struct Student* student)
{
    printf("First Name: ");
    scanf("%s", student->firstName);

    fflush(stdin);

    printf("Middle Name: ");
    scanf("%s", student->middleName);

    fflush(stdin);

    printf("Last Name: ");
    scanf("%s", student->lastName);

    fflush(stdin);

    printf("Age: ");
    scanf("%d", &student->age);

    fflush(stdin);

    printf("Grade: ");
    scanf("%d", &student->grade);

    fflush(stdin);

    printf("Email: ");
    scanf("%s", student->email);

    fflush(stdin);

    printf("Birth Date: ");
    scanf("%s", student->birthDate);

    fflush(stdin);

    printf("Sex: ");
    scanf("%s", student->sex);

    fflush(stdin);

    printf("Course: ");
    scanf("%s", student->course);

    fflush(stdin);

    printf("Address: ");
    scanf("%s", student->address);

    fflush(stdin);

    printf("Barangay: ");
    scanf("%s", student->barangay);

    fflush(stdin);

    printf("City: ");
    scanf("%s", student->city);

    fflush(stdin);

    printf("Street Number: ");
    scanf("%s", student->streetNumber);

    fflush(stdin);
}

void searchStudent(struct Student* head, int studentNumber)
{
    struct Student* foundStudent = NULL;

    // Search for the student
    while (head != NULL)
    {
        if (head->StudentNumber == studentNumber)
        {
            foundStudent = head;
            break;
        }
        head = head->next;
    }

    if (foundStudent != NULL)
    {
        // Display student details in a table format
        printf("\n=== SEARCHED STUDENT DETAILS ===\n");
        printf("| %-15s | %-30s | %-5s | %-5s | %-30s |\n", "Student ID", "Name", "Age", "Grade", "Email");
        printf("|-----------------|--------------------------------|-------|-------|--------------------------------|\n");

        char nameBuffer[150];  // Buffer for concatenated name
        strcpy(nameBuffer, foundStudent->firstName);
        strcat(nameBuffer, " ");
        strcat(nameBuffer, foundStudent->middleName);
        strcat(nameBuffer, " ");
        strcat(nameBuffer, foundStudent->lastName);

        char emailBuffer[50];  // Buffer for email
        strcpy(emailBuffer, foundStudent->email);

        printf("| %-15d | %-30s | %-5d | %-5d | %-30s |\n",
               foundStudent->StudentNumber,
               nameBuffer,
               foundStudent->age,
               foundStudent->grade,
               emailBuffer);
    }
    else
    {
        // If the loop completes, the student was not found
        printf("\nStudent with ID %d not found.\n", studentNumber);
    }
}

void displayStudentsInTable(struct Student* head)
{
    printf("\n=== STUDENT LIST ===\n");
    printf("| %-15s | %-30s | %-5s | %-5s | %-30s |\n", "Student ID", "Name", "Age", "Grade", "Email");
    printf("|-----------------|--------------------------------|-------|-------|--------------------------------|\n");

    while (head != NULL)
    {
        printf("| %-15d | %-30s | %-5d - | %-5d | %-30s |\n",
               head->StudentNumber,
               strcat(strcat(strcat(head->firstName, " "), head->middleName), head->lastName),
               head->age,
               head->grade,
               head->email);
        head = head->next;
    }
}

int authenticateAdmin(char* adminName, char* adminPass)
{
    const char* correctAdminName = "admin";
    const char* correctAdminPass = "admin123";

    if (strcmp(adminName, correctAdminName) == 0 && strcmp(adminPass, correctAdminPass) == 0)
    {
        return 1;
    }

    return 0;
}
