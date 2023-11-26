#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 50

struct Student
{
    int StudentNumber;
    char firstName[MAX_STRING_LENGTH];
    char middleName[MAX_STRING_LENGTH];
    char lastName[MAX_STRING_LENGTH];
    int age;
    int grade;
    char email[MAX_STRING_LENGTH];
    char birthDate[MAX_STRING_LENGTH];
    char sex[MAX_STRING_LENGTH];
    char course[MAX_STRING_LENGTH];
    char address[MAX_STRING_LENGTH];
    char barangay[MAX_STRING_LENGTH];
    char city[MAX_STRING_LENGTH];
    char streetNumber[MAX_STRING_LENGTH];
    struct Student* next;
};

// Functions input and output
void addStudent(struct Student** head, int studentNumber);
void displayStudents(struct Student* head);
int authenticateAdmin(char* adminName, char* adminPass);
void enterStudentDetails(struct Student* student);
void displayStudentsInTable(struct Student* head);
void searchStudent(struct Student* head, int studentNumber);
void modifyStudent(struct Student** head, int studentNumber);

// Menu Functions
int displayMenu();
void titleInfo();
void userLogin();
void adminLogin();

//For File Handling - Double check
void saveStudentsToFile(struct Student* head);
struct Student* loadStudentsFromFile();

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
        case 0:
            printf("Logging Out.....");
        default:
            printf("Logout Out Successful!\n");
            break;
        }
    } while (choice != 0);

    printf("----- Program has Terminated Successfully! ----- \n");

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
    printf("\n\t| [0] LOGOUT           |");
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

/*----- USER FUNCTIONALITIES -----*/
void userLogin()
{
    int studentNumber;

    printf("\n\t|----------------------|");
    printf("\n\t|--- STUDENT LOGIN --- |");
    printf("\n\t|------------------------|");
    printf("\n\t| ENTER STUDENT NUMBER |");
    printf("\n\t|----------------------|");
    printf("\n ENTER: ");
    scanf("%d", &studentNumber);
}

/* ----- ADMIN FUNCTIONALITIES ----- */
void adminLogin(struct Student** studentList)
{
    char adminName[20];
    char adminPass[20];

    printf("\n\t|-----------------------|");
    printf("\n\t|  --- ADMIN LOGIN ---  |");
    printf("\n\t|------------------------|");
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
            printf("\n\t|--------------------------|");
            printf("\n\t|    ADMINISTRATOR MENU    |");
            printf("\n\t|--------------------------|");
            printf("\n\t| [1] Add Student          |");
            printf("\n\t| [2] Display Students     |");
            printf("\n\t| [3] Search Student       |");
            printf("\n\t| [4] Modify Student Record|");
            printf("\n\t| [0] Logout               |");
            printf("\n\t|--------------------------|");
            printf("\n SELECT: ");
            scanf("%d", &adminChoice);

            switch (adminChoice)
            {
            case 1:
            {
                int studentNumber;
                printf("\n\t|----------------------|");
                printf("\n\t|  --- ADD STUDENT --- |");
                printf("\n\t|------------------------|");
                printf("\n\t| ADD STUDENT NUMBER   |");
                printf("\n\t|----------------------|");
                printf("\n ENTER : ");
                scanf("%d", &studentNumber);
                addStudent(studentList, studentNumber);
                break;
            }
            case 2:
                displayStudentsInTable(*studentList);
                break;
            case 3:
            {
                int studentNumber;
                printf("\n\t|-------------------------|");
                printf("\n\t|   SEARCH STUDENT        |");
                printf("\n\t|------------------------|");
                printf("\n\t| Enter Student Number    |");
                printf("\n\t|-------------------------|");  
                printf("\n STUDENT TO BE SEARCHED : ");
                scanf("%d", &studentNumber);
                searchStudent(*studentList, studentNumber);
                break;
            }
            case 4:
                {
                    int modifyStudentNumber;
                    printf("\n\t|-----------------------|");
                    printf("\n\t| --- MODIFY STUDENT ---|");
                    printf("\n\t| ENTER STUDENT NUMBER  |");
                    printf("\n\t|-----------------------|");
                    printf("\n ENTER : ");
                    scanf("%d", &modifyStudentNumber);
                    modifyStudent(studentList, modifyStudentNumber);
                    break;
                }
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
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Middle Name: ");
    scanf("%s", student->middleName);
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Last Name: ");
    scanf("%s", student->lastName);
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Age: ");
    scanf("%d", &student->age);
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Grade: ");
    scanf("%d", &student->grade);
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Email: ");
    scanf("%s", student->email);
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Birth Date: ");
    scanf("%s", student->birthDate);
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Sex: ");
    scanf("%s", student->sex);
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Course: ");
    scanf("%s", student->course);
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Address: ");
    scanf("%s", student->address);
    while ((c = getchar()) != '\n' && c != EOF);
}

void searchStudent(struct Student* head, int studentNumber)
{
    struct Student* foundStudent = NULL;

    // Search for the student number rito
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
        // Display students
        //okay na rito pantay na table
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
        // Printf student not found  - error trapping i2
        printf("\nStudent with ID %d not found.\n", studentNumber);
    }
}

void displayStudentsInTable(struct Student* head)
{
    printf("\n=== STUDENT LIST ===\n");
    printf("| %-15s | %-30s | %-5s | %-5s | %-30s | %-30s |\n", "Student ID", "Name", "Age", "Grade", "Email", "Address");
    printf("|-----------------|--------------------------------|-------|-------|--------------------------------|--------------------------------|\n");

    while (head != NULL)
    {
        /*
        Temporary buffers for concatenation
        */
        char fullName[150];
        strcpy(fullName, head->firstName);
        strcat(fullName, " ");
        strcat(fullName, head->middleName);
        strcat(fullName, " ");
        strcat(fullName, head->lastName);

        char emailBuffer[50];
        strcpy(emailBuffer, head->email);

        printf("| %-15d | %-30s | %-5d | %-5d | %-30s | %-30s |\n",
               head->StudentNumber,
               fullName,
               head->age,
               head->grade,
               emailBuffer,
               head->address);

        head = head->next;
    }
}

//TO FIX: SKIPPING LINES
void modifyStudent(struct Student** head, int studentNumber)
{
    struct Student* current = *head;

    while (current != NULL)
    {
        if (current->StudentNumber == studentNumber)
        {
            printf("\n=== MODIFY STUDENT ===\n");
            printf("| %-20s | %-40s |\n", "Field", "Current Value");
            printf("|----------------------|------------------------------------------|\n");
            printf("| %-20s | %-40d |\n", "Student ID", current->StudentNumber);
            printf("| %-20s | %-40s |\n", "Current First Name", current->firstName);
            printf("| %-20s | %-40s |\n", "Current Middle Name", current->middleName);
            printf("| %-20s | %-40s |\n", "Current Last Name", current->lastName);
            printf("| %-20s | %-40d |\n", "Current Age", current->age);
            printf("| %-20s | %-40d |\n", "Current Grade", current->grade);
            printf("| %-20s | %-40s |\n", "Current Email", current->email);
            printf("| %-20s | %-40s |\n", "Current Birth Date", current->birthDate);
            printf("| %-20s | %-40s |\n", "Current Sex", current->sex);
            printf("| %-20s | %-40s |\n", "Current Course", current->course);
            printf("| %-20s | %-40s |\n", "Current Address", current->address);
            printf("|----------------------|------------------------------------------|\n");

            // Clear input buffer after reading integers
            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            // Get new values
            printf("Enter New First Name: ");
            fgets(current->firstName, sizeof(current->firstName), stdin);
            current->firstName[strcspn(current->firstName, "\n")] = '\0';  // Remove trailing newline

            printf("Enter New Middle Name: ");
            fgets(current->middleName, sizeof(current->middleName), stdin);
            current->middleName[strcspn(current->middleName, "\n")] = '\0';

            printf("Enter New Last Name: ");
            fgets(current->lastName, sizeof(current->lastName), stdin);
            current->lastName[strcspn(current->lastName, "\n")] = '\0';

            printf("Enter New Age: ");
            scanf("%d", &current->age);

            printf("Enter New Grade: ");
            scanf("%d", &current->grade);

            // Clear input buffer after reading integers
            while ((c = getchar()) != '\n' && c != EOF);

            printf("Enter New Email: ");
            fgets(current->email, sizeof(current->email), stdin);
            current->email[strcspn(current->email, "\n")] = '\0';

            printf("Enter New Birth Date: ");
            fgets(current->birthDate, sizeof(current->birthDate), stdin);
            current->birthDate[strcspn(current->birthDate, "\n")] = '\0';

            printf("Enter New Sex: ");
            fgets(current->sex, sizeof(current->sex), stdin);
            current->sex[strcspn(current->sex, "\n")] = '\0';

            printf("Enter New Course: ");
            fgets(current->course, sizeof(current->course), stdin);
            current->course[strcspn(current->course, "\n")] = '\0';

            printf("Enter New Address: ");
            fgets(current->address, sizeof(current->address), stdin);
            current->address[strcspn(current->address, "\n")] = '\0';

            printf("\nStudent information updated successfully!\n");
            return;
        }
        current = current->next;
    }

    // If the loop completes, the student was not found
    printf("\nStudent with ID %d not found.\n", studentNumber);
}


int authenticateAdmin(char* adminName, char* adminPass)
{
    //default admin username & password 
    const char* correctAdminName = "admin";
    const char* correctAdminPass = "admin123";

    if (strcmp(adminName, correctAdminName) == 0 && strcmp(adminPass, correctAdminPass) == 0)
    {
        return 1;
    }

    return 0;
}
