#include <stdio.h>
#include <string.h>

// ----- FUNCTIONS HERE -----
//Main Menu Items
int displayMenu();
void titleInfo();

int main()
{
    displayMenu();

    return 0;
}

//Main Menu Items
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
    scanf("%d", choice);

    return choice;
}

//TITLE 
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
    printf("\n\t| USER LOGIN :         |");
    printf("\n\t| ENTER STUDENT NUMBER |");
    scanf("%d", &studentNumber);
    printf("\n\t|----------------------|");
}