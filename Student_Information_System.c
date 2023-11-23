#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a student
struct Student 
{
    int StudentNumber;
    struct Student* next;
};


//Prototype Functions 
void addStudent(struct Student **head, int studentNumber);

// admin authentication function
int authenticateAdmin(char *adminName, char *adminPass);

// ----- FUNCTIONS HERE -----
// Main Menu Items
int displayMenu(); //mainMenu
void titleInfo();  //title 
void userLogin();  //user login function
void adminLogin(); //admin login prompt

// === MAIN FUNCTION ===
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
            adminLogin();
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

// ===== USER PROMPT =====
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

// ===== ADMIN PROMPT =====
void adminLogin()
{
    struct Student *studentList = NULL;
    char adminName[20];
    char adminPass[20];

    // Admin username input
    printf("\n\t|-----------------------|");
    printf("\n\t|  --- ADMIN LOGIN ---  |");
    printf("\n\t| ENTER ADMIN USER NAME |");
    printf("\n\t|-----------------------|");
    printf("\n USER NAME: ");
    scanf("%s", adminName);

    // Admin password input
    printf("\n\t|-----------------------|");
    printf("\n\t| ENTER ADMIN PASSWORD  |");
    printf("\n\t|-----------------------|");
    printf("\n PASSWORD : ");
    scanf("%s", adminPass);

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
                {
                    int studentNumber;
                    printf("\n\t|----------------------|");
                    printf("\n\t|  --- ADD STUDENT --- |");
                    printf("\n\t| ADD STUDENT NUMBER   |");
                    printf("\n\t|----------------------|");
                    printf("\n ENTER : ");
                    scanf("%d", &studentNumber);
                    addStudent(&studentList, studentNumber);
                    break;
                }
            case 2:
                // Display students
                // to be added
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
void addStudent(struct Student **head, int studentNumber)
{
    // Creating new student node here
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));

    if (!newStudent)
    {
        printf("\n Memory allocation failed for adding student.");
        return;
    }

    newStudent->StudentNumber = studentNumber;
    newStudent->next = *head;

    *head = newStudent;

    printf("\n Student No. %d has been successfully added!", studentNumber);
}

// Admin authentication
int authenticateAdmin(char *adminName, char *adminPass)
{
    // Admin user name and password
    const char *correctAdminName = "admin";
    const char *correctAdminPass = "admin123";

    // Checking credentials
    if (strcmp(adminName, correctAdminName) == 0 && strcmp(adminPass, correctAdminPass) == 0)
    {
        return 1; // Authentication successful
    }

    return 0; // Authentication failed
}
