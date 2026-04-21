/* menu.c - all menus and user interaction */
/*
* Copyright (c) 2026 Trenser Technology Solutions (P) Ltd
*/
/*
modification history --------------------
08april26, Updated coding standards
*/
/*
DESCRIPTION
This module is main menu for collecting data from students
INCLUDE FILES: Sensor.h
*/

/* includes */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"
#include "menu.h"

#define ROLL_NUMBER_LENGTH 20U

typedef bool (*MenuFunction)(void);
typedef bool (*ListFunction)(void);
typedef bool (*DeleteFunction)(void);

MenuFunction mainMenuFunctions[] =
                                    {
                                        menuAddStudent,
                                        menuStudentOverview,
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

/*******************************************************************************
*
* menuDeleteByName - The function [menuDeleteByName] will read the name to
* delete and invoke [studentDeleteByName]
*/
bool menuDeleteByName(void)
{

    printf("Enter the name to delete: ");

    char name[MAX_NAME_LENGTH] = {0};

    if(fgets(name, sizeof(name), stdin) != NULL)
    {
        size_t length = strcspn(name, "\n");
        name[length] = '\0';
    }
    else
    {
        return STATUS_ERROR;
    }

    if(studentDeleteByName((uint8_t*)name))
    {
        SUCCESS("Student deleted successfully.\n");
    }
    else
    {
        ERROR("Failed to delete student.\n");

        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*******************************************************************************
*
* menuDeleteByRoll - The function [menuDeleteByRoll] will read the roll no to
* delete and invoke [menuDeleteByRoll]
*/
bool menuDeleteByRoll(void)
{
    uint32_t rollNumber = 0;
    char rollNumberStr[ROLL_NUMBER_LENGTH] = {0};

    printf("Enter the roll number to delete: ");

    if(fgets(rollNumberStr, sizeof(rollNumberStr), stdin) != NULL)
    {
        size_t length = strcspn(rollNumberStr, "\n");
        rollNumberStr[length] = '\0';
        rollNumber = (uint32_t)strtoul(rollNumberStr, NULL, 10);
    }
    else
    {
        return STATUS_ERROR;
    }

    if(studentDeleteByRoll(rollNumber))
    {
        SUCCESS("Student deleted successfully.\n");
    }
    else
    {
        ERROR("Failed to delete student.\n");

        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*******************************************************************************
*
* menuDeleteAll - The function [menuDeleteAll] will delete all students data
*/
bool menuDeleteAll(void)
{
    printf("Confirmation for deleting all students (y/n): ");

    char confirmation = 0;
    char confirmationStr[CONFIRMATION_STR_LENGTH] = {0};

    if(fgets(confirmationStr, sizeof(confirmationStr), stdin) != NULL)
    {
        size_t length = strcspn(confirmationStr, "\n");
        confirmation = (length > 0) ? confirmationStr[0] : 0;
    }
    else
    {
        return STATUS_ERROR;
    }

    if((confirmation == 'y') || (confirmation == 'Y'))
    {
        if(studentDeleteAll())
        {
            INFO("All students deleted successfully.\n");
        }
        else
        {
            ERROR("Failed to delete all students.\n");

            return STATUS_ERROR;
        }
    }
    else
    {
        INFO("Deletion of all students cancelled.\n");
    }

    return STATUS_SUCCESS;
}

/*******************************************************************************
*
* menuListSearchByName - The function [menuListSearchByName] will read the name
* to search and invoke [studentGetName]
*/
bool menuListSearchByName(void)
{
    printf("Enter the name to search: ");

    char name[MAX_NAME_LENGTH] = {0};

    if(fgets(name, sizeof(name), stdin) != NULL)
    {
        size_t length = strcspn(name, "\n");
        name[length] = '\0';
    }
    else
    {
        return STATUS_ERROR;
    }

    if(studentGetName(name) == 0)
    {
        ERROR("No students found.\n");

        return STATUS_ERROR;
    }
    else
    {
        SUCCESS("Student found : %s\n", name);
    }

    return STATUS_SUCCESS;
}

/*******************************************************************************
*
* menuListSortByName - The function [menuListSortByName] will sort students by
*  name and invoke [studentGetSortedByName]
*/
bool menuListSortByName(void)
{
    printf("Sorting students by name\n");

    if(studentGetSortedByName())
    {
        SUCCESS("Students sorted by name successfully.\n");
    }
    else
    {
        ERROR("Failed to sort students by name or No students to sort\n");

        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*******************************************************************************
*
* menuListSortByRoll - The function [menuListSortByRoll] will sort students by
* roll no and invoke [studentGetSortedByRoll]
*/
bool menuListSortByRoll(void)
{
    printf("Sorting students by roll number\n");

    if(studentGetSortedByRoll())
    {
        SUCCESS("Students sorted by roll number successfully.\n");
    }
    else
    {
        ERROR("Failed to sort students by roll number.\n");

        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*******************************************************************************
*
* menuListSortByRank - The function [menuListSortByRank] will sort students by
* rank and invoke [studentGetSortedByRank]
*/
bool menuListSortByRank(void)
{
    printf("Sorting students by rank\n");

    if(studentGetSortedByRank())
    {
        INFO("Students sorted by rank successfully.\n");
    }
    else
    {
        ERROR("Failed to sort students by rank.\n");

        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*******************************************************************************
*
* menuStudentOverview - The function [menuStudentOverview] will give how many 
*students are added & their average marks and invokes [studentGetCount] and
* [studentGetAvgMarksOfSubjects].
*/
bool menuStudentOverview(void)
{
    printf("Student Overview\n");

    uint32_t pulCount = 0;
    uint8_t pucAvgMarks = 0;

    if(studentGetCount(&pulCount))
    {
        INFO("Total number of students: %u\n", pulCount);
    }
    else
    {
        ERROR("Failed to get student count.\n");

        return STATUS_ERROR;
    }

    if(studentGetAvgMarksOfSubjects(&pucAvgMarks))
    {
        INFO("Average marks of subjects: %u\n", pucAvgMarks);
    }
    else
    {
        ERROR("Failed to get average marks of subjects.\n");

        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*******************************************************************************
*
* menuAddStudent - The function [menuAddStudent] will Ask name, roll number, 
* Marks of 10 subjects, student Address(Dyanamic size), calc sum of marks, 
* average, grades and invokes [studentCalcSum], [studentCalcAverage], 
*[studentCalcGrades], [studentAdd] and [studentUpdateRank]
*/
bool menuAddStudent(void)
{
    char choice = 'y';
    char buffer[BUFFER_SIZE] = {0};
    char choiceStr[CHOICE_STR_LENGTH] = {0};
    int c = 0;
    int character = 0;

    while(choice == 'y' || choice == 'Y')
    {
        student stInfo = {0};

        printf("Enter student details:\n");
        printf("Name: ");

        if(fgets(buffer, sizeof(stInfo.name), stdin) != NULL)
        {
            size_t length = strcspn(buffer, "\n");
            buffer[length] = '\0';
            strncpy(stInfo.name, buffer, sizeof(stInfo.name) - 1);
            stInfo.name[sizeof(stInfo.name) - 1] = '\0';
        }
        else
        {
            return STATUS_ERROR;
        }

        while ((c = getchar()) != '\n' && c != EOF) { }

        printf("Roll Number: ");

        if(fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            size_t length = strcspn(buffer, "\n");
            buffer[length] = '\0';
            stInfo.rollNumber = (uint32_t)strtoul(buffer, NULL, 10);
        }
        else
        {
            return STATUS_ERROR;
        }
        printf("Enter %d subjects marks:\n", MAX_SUBJECTS);

        for(uint8_t i = 0; i < MAX_SUBJECTS; i++)
        {

            if(fgets(buffer, sizeof(buffer), stdin) != NULL)
            {
                size_t length = strcspn(buffer, "\n");
                buffer[length] = '\0';
                stInfo.marks[i] = (uint8_t)strtoul(buffer, NULL, 10);
            }
            else
            {
                return STATUS_ERROR;
            }
        }

        

        while((character = getchar()) != '\n' && character != EOF);

        char stInfoAddress[MAX_ADDRESS_LENGTH] = {0};

        printf("Address: ");

        if(fgets(stInfoAddress, sizeof(stInfoAddress), stdin) != NULL)
        {
            stInfoAddress[strcspn(stInfoAddress, "\n")] = '\0';
        }
        else
        {
            return STATUS_ERROR;
        }

        stInfo.address = malloc(strlen(stInfoAddress) + 1);

        if(stInfo.address == NULL)
        {
            return STATUS_ERROR;
        }

        strncpy(stInfo.address, stInfoAddress, strlen(stInfoAddress) + 1);

        if(studentCalcSum(&stInfo, &stInfo.sumMarks))
        {
            INFO("Sum of marks for student %s is : %u\n", stInfo.name, stInfo.sumMarks);
        }
        else
        {
            ERROR("Failed to calculate sum of marks.\n");

            return STATUS_ERROR;
        }

        if(studentCalcAverage(&stInfo, &stInfo.averageMarks))
        {
            INFO("Average marks for student %s is : %.2f\n", stInfo.name, stInfo.averageMarks);
        }
        else
        {
            ERROR("Failed to calculate average marks.\n");

            free(stInfo.address);

            return STATUS_ERROR;
        }

        if(studentCalcGrades(&stInfo, (uint8_t*)&stInfo.sumMarks))
        {
            for(uint8_t i = 0; i < MAX_SUBJECTS; i++)
            {
                INFO("Grade for subject %d: %s\n", i + 1, stInfo.grades[i]);
            }
        }
        else
        {
            ERROR("Failed to calculate grades.\n");

            return STATUS_ERROR;
        }

        if(studentAdd(&stInfo))
        {
            INFO("Student added successfully.\n");
        }
        else
        {
            ERROR("Failed to add student.\n");

            free(stInfo.address);

            return STATUS_ERROR;
        }

        if(studentUpdateRank())
        {
            SUCCESS("Database rank updated successfully.\n");
        }
        else
        {
            ERROR("Failed to update rank.\n");

            return STATUS_ERROR;
        }

        free(stInfo.address);

        printf("Again need to add new student details (y/n): ");

        if(fgets(choiceStr, sizeof(choiceStr), stdin) != NULL)
        {
            size_t length = strcspn(choiceStr, "\n");
            choice = (length > 0) ? choiceStr[0] : 0;
        }
        else
        {
            return STATUS_ERROR;
        }
    }

    INFO("Returning to main menu.\n");

    return STATUS_SUCCESS;
}

/*******************************************************************************
*
* menuListStudent - The function [menuListStudent] will invoke [listMenuFunctions]
*/
bool menuListStudent(void)
{
        printf("List Student Menu\n");
        printf("1. Search by Name\n");
        printf("2. Sort by Name\n");
        printf("3. Sort by Roll number\n");
        printf("4. Sort by Rank\n");

        uint8_t choice = 0;
        char choiceStr[CHOICE_STR_LENGTH] = {0};

        if(fgets(choiceStr, sizeof(choiceStr), stdin) != NULL)
        {
            size_t length = strcspn(choiceStr, "\n");
            choiceStr[length] = '\0';
            choice = (uint8_t)strtoul(choiceStr, NULL, 10);
        }
        else
        {
            return STATUS_ERROR;
        }

        if(choice < 1 || choice > LIST_MENU_SIZE)
        {
            ERROR("Invalid choice. Please try again.\n");
        }
        else
        {
            listMenuFunctions[choice - 1]();
        }

        return STATUS_SUCCESS;
}

/*******************************************************************************
*
* menuDeleteStudent - The function [menuDeleteStudent] will invoke [deleteMenuFunctions]
*/
bool menuDeleteStudent(void)
{
        printf("Delete Student Menu\n");
        printf("1. Delete by Name\n");
        printf("2. Delete by Roll number\n");
        printf("3. Delete All\n");

        uint8_t choice = 0;
        char choiceStr[CHOICE_STR_LENGTH] = {0};

        if(fgets(choiceStr, sizeof(choiceStr), stdin) != NULL)
        {
            size_t length = strcspn(choiceStr, "\n");
            choiceStr[length] = '\0';
            choice = (uint8_t)strtoul(choiceStr, NULL, 10);
        }
        else
        {
            return STATUS_ERROR;
        }

        if(choice < 1 || choice > DELETE_MENU_SIZE)
        {
            ERROR("Invalid choice. Please try again.\n");
        }
        else
        {
            deleteMenuFunctions[choice - 1]();
        }

        return STATUS_SUCCESS;
}

/*******************************************************************************
*
* menuMain - The function [menuMain] will invoke [mainMenuFunctions]
*/
bool menuMain() 
{

    uint8_t choice = 0;
    char choiceStr[CHOICE_STR_LENGTH] = {0};

    printf("\n");
    printf("Welcome to the Student Management System, choose your choice \n");
    printf("1. Add Student\n");
    printf("2. Student Overview\n");
    printf("3. List Student\n");
    printf("4. Delete Student\n");

    if(fgets(choiceStr, sizeof(choiceStr), stdin) != NULL)
    {
        size_t length = strcspn(choiceStr, "\n");
        choiceStr[length] = '\0';
        choice = (uint8_t)strtoul(choiceStr, NULL, BASE);
    }
    else
    {
        return STATUS_ERROR;
    }

    if(choice < 1 || choice > MAIN_MENU_SIZE)
    {
        ERROR("Invalid choice, Please try again.\n");

        return STATUS_ERROR;
    }
    else
    {
        mainMenuFunctions[choice - 1]();
    }

    return STATUS_SUCCESS; 
}