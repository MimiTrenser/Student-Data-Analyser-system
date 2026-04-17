#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "student.h"


bool studentGetName(uint8_t* name);
bool studentGetSortedByRoll(void);
bool studentGetSortedByName(void);
bool studentGetSortedByRank(void);
bool menuDeleteByName(void);
bool menuDeleteByRoll(void);
bool menuDeleteAll(void);
bool menuListSearchByName(void);
bool menuListSortByName(void);
bool menuListSortByRoll(void);
bool menuListSortByRank(void);
bool menuStudentOverview(void);
bool menuAddStudent(void);
bool menuListStudent(void);
bool menuDeleteStudent(void);
bool menuMain(void);

typedef bool (*MenuFunction)(void);
typedef bool (*ListFunction)(void);
typedef bool (*DeleteFunction)(void);

MenuFunction mainMenuFunctions[] =
                                    {
                                        menuStudentOverview,
                                        menuAddStudent,
                                        menuListStudent,
                                        menuDeleteStudent
                                    };
ListFunction listMenuFunctions[] =
                                    {
                                        menuListSearchByName, 
                                        menuListSortByName, 
                                        menuListSortByRoll, 
                                        menuListSortByRank
                                    };
DeleteFunction deleteMenuFunctions[] =
                                    {
                                        menuDeleteByName,
                                        menuDeleteByRoll,
                                        menuDeleteAll
                                    };

#define MAIN_MENU_SIZE (sizeof(mainMenuFunctions) / sizeof(MenuFunction))
#define LIST_MENU_SIZE (sizeof(listMenuFunctions) / sizeof(ListFunction))
#define DELETE_MENU_SIZE (sizeof(deleteMenuFunctions) / sizeof(DeleteFunction))

// Delete Student Menu
bool menuDeleteByName(void)
{

    printf("Enter the name to delete: ");

    char name[MAX_NAME_LENGTH];

    scanf("%s", name);

    if(studentDeleteByName((uint8_t*)name))
    {
        printf("Student deleted successfully.\n");
        return STATUS_SUCCESS;
    }
    else
    {
        printf("Failed to delete student.\n");

        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}
bool menuDeleteByRoll(void)
{
    printf("Enter the roll number to delete: ");

    uint32_t rollNumber = 0;

    scanf("%u", &rollNumber);

    if(studentDeleteByRoll(rollNumber))
    {
        printf("Student deleted successfully.\n");
        return STATUS_SUCCESS;
    }
    else
    {
        printf("Failed to delete student.\n");
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}
bool menuDeleteAll(void)
{
    printf("Confirmation for deleting all students (y/n): ");

    char confirmation = 0;

    scanf(" %c", &confirmation);

    if(confirmation == 'y' || confirmation == 'Y')
    {
        if(studentDeleteAll())
        {
            printf("All students deleted successfully.\n");
            return STATUS_SUCCESS;
        }
        else
        {
            printf("Failed to delete all students.\n");
            return STATUS_ERROR;
        }
    }
    else
    {
        printf("Deletion of all students cancelled.\n");
        return STATUS_SUCCESS;
    }

    return STATUS_SUCCESS;
}


bool menuListSearchByName(void)
{
    printf("Enter the name to search: ");

    char name[MAX_NAME_LENGTH];

    scanf("%s", name);

    if(studentGetName(name) == 0)
    {
        printf("No students found.\n");
        return STATUS_ERROR;
    }
    else
    {
        printf("Student found : %s\n", name);
        return STATUS_SUCCESS;
    }

    return STATUS_SUCCESS;
}

bool menuListSortByName(void)
{
    printf("Sorting students by name\n");

    if(studentGetSortedByName())
    {
        printf("Students sorted by name successfully.\n");
        return STATUS_SUCCESS;
    }
    else
    {
        printf("Failed to sort students by name.\n");
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

bool menuListSortByRoll(void)
{
    printf("Sorting students by roll number\n");

    if(studentGetSortedByRoll())
    {
        printf("Students sorted by roll number successfully.\n");
        return STATUS_SUCCESS;
    }
    else
    {
        printf("Failed to sort students by roll number.\n");
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

bool menuListSortByRank(void)
{
    printf("Sorting students by rank\n");

    if(studentGetSortedByRank())
    {
        printf("Students sorted by rank successfully.\n");
        return STATUS_SUCCESS;
    }
    else
    {
        printf("Failed to sort students by rank.\n");
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

bool menuStudentOverview(void)
{
    printf("Student Overview\n");

    uint32_t pulCount = 0;
    uint8_t pucAvgMarks = 0;

    if(studentGetCount(&pulCount))
    {
        printf("Total number of students: %u\n", pulCount);
        return STATUS_SUCCESS;
    }
    else
    {
        printf("Failed to get student count.\n");
        return STATUS_ERROR;
    }

    if(studentGetAvgMarksOfSubjects(&pucAvgMarks))
    {
        printf("Average marks of subjects: %u\n", pucAvgMarks);
        return STATUS_SUCCESS;
    }
    else
    {
        printf("Failed to get average marks of subjects.\n");
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

bool menuAddStudent(void)
{
    student* pstInfo = NULL;

    pstInfo = (student*)malloc(sizeof(student));

    if(pstInfo == NULL)
    {
        printf("Memory allocation failed.\n");
        return STATUS_ERROR;
    }

    printf("Enter student details:\n");
    printf("Name: ");
    scanf("%s", pstInfo->name);
    printf("Roll Number: ");
    scanf("%u", &pstInfo->rollNumber);
    printf("Enter %d subjects marks: ", MAX_SUBJECTS);

    for(int i = 0; i < MAX_SUBJECTS; i++)
    {
        scanf("%hhu", &pstInfo->marks[i]);
    }

    printf("Address: ");
    scanf("%s", pstInfo->address);

    if(studentAdd(pstInfo))
    {
        printf("Student added successfully.\n");
        return STATUS_SUCCESS;
    }
    else
    {
        printf("Failed to add student.\n");
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

bool menuListStudent(void)	// Print the students names based on "List Student menu"
{
        printf("List Student Menu\n");
        printf("1. Search by Name\n");
        printf("2. Sort by Name\n");
        printf("3. Sort by Roll number\n");
        printf("4. Sort by Rank\n");

        uint8_t choice = 0;

        scanf("%hhu", &choice);

        if(choice < 1 || choice > LIST_MENU_SIZE)
        {
            printf("Invalid choice. Please try again.\n");
            return STATUS_ERROR;
        }
        else
        {
            listMenuFunctions[choice - 1]();
        }

        return STATUS_SUCCESS;
}

bool menuDeleteStudent(void)	// Remove the students based on "Delete Student menu"
{
        printf("Delete Student Menu\n");
        printf("1. Delete by Name\n");
        printf("2. Delete by Roll number\n");
        printf("3. Delete All\n");

        uint8_t choice = 0;

        scanf("%hhu", &choice);

        if(choice < 1 || choice > DELETE_MENU_SIZE)
        {
            printf("Invalid choice. Please try again.\n");
            return STATUS_ERROR;
        }
        else
        {
            deleteMenuFunctions[choice - 1]();
        }

        return STATUS_SUCCESS;
}


bool menuMain() 
{
    uint8_t choice = 0;

    printf("Welcome to the Student Management System, choose your choice \n");
    printf("1. Student Overview\n");
    printf("2. Add Student\n");
    printf("3. List Student\n");
    printf("4. Delete Student\n");

    scanf("%hhu", &choice);

    if(choice < 1 || choice > MAIN_MENU_SIZE)
    {
        printf("Invalid choice, Please try again.\n");
        return STATUS_ERROR;
    }
    else
    {
        mainMenuFunctions[choice - 1]();
    }

    return STATUS_SUCCESS; 
}