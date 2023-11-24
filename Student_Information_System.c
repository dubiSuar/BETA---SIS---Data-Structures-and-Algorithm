#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 50
#define MAX_STUDENT_SIZE 20

// Structure for a student
struct Student
{
    int StudentNumber;
    char firstName[MAX_STRING_SIZE];
    char middleName[MAX_STRING_SIZE];
    char lastName[MAX_STRING_SIZE];
    int age;
    int grade;
    char email[MAX_STRING_SIZE];
    char studentID[MAX_STRING_SIZE];
    char birthDate[MAX_STRING_SIZE];
    char sex[MAX_STRING_SIZE];
    char course[MAX_STRING_SIZE];
    char address[MAX_STRING_SIZE];
    char city[MAX_STRING_SIZE];
    char barangay[MAX_STRING_SIZE];
    char streetNumber[MAX_STRING_SIZE];
    struct Student* next;
};

// Prototype Functions
void addStudent(struct Student** head, int studentNumber);
void displayStudents(struct Student* head);
int authenticateAdmin(const char* adminName, const char* adminPass);

// Main Menu Items
int displayMenu();
void titleInfo();
void userLogin();
void adminLogin(struct Student** studentList);

// Main Function
int main()
{
    int choice;

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

// Main Menu Items
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

// TITLE
void titleInfo()
{
    printf("==========================================");
    printf("\n======= STUDENT INFORMATION SYSTEM =======");
    printf("\n========================================");
}

// USER PROMPT
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

// ADMIN PROMPT
void adminLogin(struct Student** studentList)
{
    char adminName[MAX_STRING_SIZE];
    char adminPass[MAX_STRING_SIZE];

    // Admin username input
    printf("\n\t|-----------------------|");
    printf("\n\t|  --- ADMIN LOGIN ---  |");
    printf("\n\t| ENTER ADMIN USER NAME |");
    printf("\n\t|-----------------------|");
    printf("\n USER NAME: ");
    fgets(adminName, sizeof(adminName), stdin);
    adminName[strcspn(adminName, "\n")] = '\0'; // Remove newline character

    // Admin password input
    printf("\n\t|-----------------------|");
    printf("\n\t| ENTER ADMIN PASSWORD  |");
    printf("\n\t|-----------------------|");
    printf("\n PASSWORD : ");
    fgets(adminPass, sizeof(adminPass), stdin);
    adminPass[strcspn(adminPass, "\n")] = '\0'; // Remove newline character

    // Authenticate Admin Login
    if (authenticateAdmin(adminName, adminPass))
    {
        printf("\nAuthentication Successful! Welcome, %s!\n", adminName);

        int adminChoice;

        do
        {
            // Admin menu
            printf("\n\t|-------------------------|");
            printf("\n\t|   ADMINISTRATOR MENU   |");
            printf("\n\t| [1] Add Student        |");
            printf("\n\t| [2] Display Students   |");
            printf("\n\t| [0] Logout             |");
            printf("\n\t|-------------------------|");
            printf("\n SELECT: ");
            scanf("%d", &adminChoice);

            switch (adminChoice)
            {
            case 1:
                addStudent(studentList);
                break;
            case 2:
                displayStudents(*studentList);
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

// Add Student Functionality
void addStudent(struct Student** head, int studentNumber)
{
    int i;
    // Creating new student node
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));

    if (!newStudent)
    {
        printf("\n Memory allocation failed for adding student.");
        return;
    }

    newStudent->StudentNumber = studentNumber;
    newStudent->next = *head;

    printf("Enter details for Student %d:\n", studentNumber);
    printf("First Name: ");
    fgets(newStudent->firstName, sizeof(newStudent->firstName), stdin);
    newStudent->firstName[strcspn(newStudent->firstName, "\n")] = '\0'; // Remove newline character

    printf("Middle Name: ");
    fgets(newStudent->middleName, sizeof(newStudent->middleName), stdin);
    newStudent->middleName[strcspn(newStudent->middleName, "\n")] = '\0';

    printf("Last Name: ");
    fgets(newStudent->lastName, sizeof(newStudent->lastName), stdin);
    newStudent->lastName[strcspn(newStudent->lastName, "\n")] = '\0';

    printf("Age: ");
    scanf("%d", &newStudent->age);

    printf("Grade: ");
    scanf("%d", &newStudent->grade);

    printf("Email: ");
    fgets(newStudent->email, sizeof(newStudent->email), stdin);
    newStudent->email[strcspn(newStudent->email, "\n")] = '\0';

    printf("Student ID: ");
    fgets(newStudent->studentID, sizeof(newStudent->studentID), stdin);
    newStudent->studentID[strcspn(newStudent->studentID, "\n")] = '\0';

    printf("Birth Date: ");
    fgets(newStudent->birthDate, sizeof(newStudent->birthDate), stdin);
    newStudent->birthDate[strcspn(newStudent->birthDate, "\n")] = '\0';

    printf("Sex: ");
    fgets(newStudent->sex, sizeof(newStudent->sex), stdin);
    newStudent->sex[strcspn(newStudent->sex, "\n")] = '\0';

    printf("Course: ");
    fgets(newStudent->course, sizeof(newStudent->course), stdin);
    newStudent->course[strcspn(newStudent->course, "\n")] = '\0';

    printf("Address: ");
    fgets(newStudent->address, sizeof(newStudent->address), stdin);
    newStudent->address[strcspn(newStudent->address, "\n")] = '\0';

    printf("City: ");
    fgets(newStudent->city, sizeof(newStudent->city), stdin);
    newStudent->city[strcspn(newStudent->city, "\n")] = '\0';

    printf("Barangay: ");
    fgets(newStudent->barangay, sizeof(newStudent->barangay), stdin);
    newStudent->barangay[strcspn(newStudent->barangay, "\n")] = '\0';

    printf("Street Number: ");
    fgets(newStudent->streetNumber, sizeof(newStudent->streetNumber), stdin);
    newStudent->streetNumber[strcspn(newStudent->streetNumber, "\n")] = '\0';

    *head = newStudent;

    printf("\n Student No. %d has been successfully added!\n", studentNumber);
}

// Display Information
void displayStudents(struct Student* head)
{
    printf("\n=== STUDENT LIST ===\n");
    printf("| %-15s | %-20s |\n", "Student ID", "Other Details");
    printf("|-----------------|----------------------|\n");
    while (head != NULL)
    {
        printf("| %-15d | %-20s |\n", head->StudentNumber, "Add other details here");
        // Add details here other than student ID. e.g., name, courses.
        printf("| %-15s | %-20s |\n", "Name", head->firstName);
        printf("| %-15s | %-20d |\n", "Age", head->age);
        printf("| %-15s | %-20d |\n", "Grade", head->grade);
        // Add other fields in a similar fashion
        head = head->next;
    }
}

// Admin authentication
int authenticateAdmin(const char* adminName, const char* adminPass)
{
    // Admin user name and password
    const char* correctAdminName = "admin";
    const char* correctAdminPass = "admin123";

    // Checking credentials
    if (strcmp(adminName, correctAdminName) == 0 && strcmp(adminPass, correctAdminPass) == 0)
    {
        return 1; // Authentication successful
    }

    return 0; // Authentication failed
}
