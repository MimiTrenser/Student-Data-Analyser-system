/* student.c - student data logic and calculations */
/*
* Copyright (c) 2026 Trenser Technology Solutions (P) Ltd
*/
/*
modification history --------------------
08april26, Updated coding standards
*/
/*
DESCRIPTION
This module is for student data logic and calculations
INCLUDE FILES: student.h
*/

/* includes */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

#define MAX_GRADE_A 90
#define MAX_GRADE_B 80
#define MAX_GRADE_C 70
#define MAX_GRADE_D 40

static student *students = NULL;
static uint32_t studentCount = 0;

/*******************************************************************************
*
* freeStudent - The function [freeStudent] will free student
*
*/
void freeStudent(student *stData)
{
    if(stData != NULL)
    {
        free(stData->address);
        stData->address = NULL;
    }
}

/*******************************************************************************
*
* freeAllStudents - The function [freeAllStudents] will free all students 
*
*/
bool freeAllStudents(void)
{
    if(students != NULL)
    {
        for(uint32_t i = 0; i < studentCount; i++)
        {
            freeStudent(&students[i]);
        }

        free(students);
        students = NULL;
        studentCount = 0;

        return STATUS_SUCCESS;
    }

    return STATUS_ERROR;;
}

/*******************************************************************************
*
* studentGetSortedByRoll - The function [studentGetSortedByRoll] will sort 
*students by roll no.
*/
bool studentGetSortedByRoll(void)
{
    printf("Getting students sorted by roll number\n");

    if(studentCount == 0)
    {
        return STATUS_ERROR;
    }

    for(uint32_t i = 0; i < studentCount - 1; i++)
    {
        for(uint32_t j = 0; j < studentCount - i - 1; j++)
        {
            if(students[j].rollNumber > students[j + 1].rollNumber)
            {
                student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    for(uint32_t i = 0; i < studentCount; i++)
    {
        printf("Roll Number: %u\n", students[i].rollNumber);
    }


    return STATUS_SUCCESS;
}

/*******************************************************************************
*
* studentGetSortedByName - The function [studentGetSortedByName] will sort 
*students by name.
*/
bool studentGetSortedByName(void)
{
    printf("Getting students sorted by name\n");

    if(studentCount == 0)
    {
        return STATUS_ERROR;
    }

    for(uint32_t i = 0; i < studentCount - 1; i++)
    {
        for(uint32_t j = 0; j < studentCount - i - 1; j++)
        {
            if(strncmp(students[j].name, students[j + 1].name, MAX_NAME_LENGTH) > 0)
            {
                student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    for(uint32_t i = 0; i < studentCount; i++)
    {
        printf("Name: %s\n", students[i].name);
    }

    return STATUS_SUCCESS;
}

/*******************************************************************************
*
* studentGetSortedByRank - The function [studentGetSortedByRank] will sort 
*students by rank.
*/
bool studentGetSortedByRank(void)
{
    printf("Getting students sorted by rank\n");

    if(studentCount == 0)
    {
        return STATUS_ERROR;
    }

    for(uint32_t i = 0; i < studentCount - 1; i++)
    {
        for(uint32_t j = 0; j < studentCount - i - 1; j++)
        {
            if(students[j].rank > students[j + 1].rank)
            {
                student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    for(uint32_t i = 0; i < studentCount; i++)
    {
        printf("Rank of %s: %u\n",students[i].name, students[i].rank);
    }


    return STATUS_SUCCESS;
}

/*******************************************************************************
*
* studentGetName - The function [studentGetName] will get student name
*/
bool studentGetName(char* pName)
{
    if(pName == NULL)
    {
        return STATUS_ERROR;
    }

    for(uint32_t i = 0; i < studentCount; i++)
    {
        if(strncmp(pName, students[i].name, MAX_NAME_LENGTH) == 0)
        {
            return STATUS_SUCCESS;
        }
        else
        {
            return STATUS_ERROR;
        }
    }

    return STATUS_SUCCESS;
}

/*******************************************************************************
*
* studentAdd - The function [studentAdd] will add student name
*/
bool studentAdd(student* pstInfo)
{
    if(pstInfo == NULL)
    {
        return STATUS_ERROR;
    }

    if(studentCount >= MAX_STUDENTS)
    {
        return STATUS_ERROR;
    }

    student *studentsData = (student*)realloc(students, (studentCount + 1) * sizeof(student));

    if (studentsData == NULL)
    {
        return STATUS_ERROR;
    }

    students = studentsData;
    students[studentCount] = *pstInfo;

    if(pstInfo->address != NULL)
    {
        students[studentCount].address = malloc(strlen(pstInfo->address) + 1);

        if (students[studentCount].address == NULL)
        {
            return STATUS_ERROR;
        }

        strncpy(students[studentCount].address, pstInfo->address, strlen(pstInfo->address) + 1);
    }

    else 
    {
        students[studentCount].address = NULL;
    }

    studentCount++;

    return STATUS_SUCCESS;
}

/*******************************************************************************
*
* studentCalcAverage - The function [studentCalcAverage] will add student avg
* marks
*/
bool studentCalcAverage(student* pstInfo, float* pfAvg)
{
    if(pstInfo == NULL || pfAvg == NULL)
    {
        return STATUS_ERROR;
    }

    *pfAvg = (float)pstInfo->sumMarks / MAX_SUBJECTS;

    return STATUS_SUCCESS;
}

/*******************************************************************************
*
* studentCalcSum - The function [studentCalcSum] will calculate sum of marks
*/
bool studentCalcSum(student* pstInfo, uint32_t* pulSum)
{
    if(pstInfo == NULL || pulSum == NULL)
    {
        return STATUS_ERROR;
    }

    *pulSum = 0;

    for(int i = 0; i < MAX_SUBJECTS; i++)
    {
        *pulSum += pstInfo->marks[i];
    }

    return STATUS_SUCCESS;
}

/*******************************************************************************
*
* studentCalcGrades - The function [studentCalcGrades] will calculate
* grade of each student
*/
bool studentCalcGrades(student* pstInfo, uint8_t* pucSum)
{
    if(pstInfo == NULL || pucSum == NULL)
    {
        return STATUS_ERROR;
    }

    for(int i = 0; i < MAX_SUBJECTS; i++)
    {
        if(pstInfo->marks[i] >= MAX_GRADE_A)
        {
            snprintf(pstInfo->grades[i], MAX_GRADE_LENGTH, "A");
        }
        else if(pstInfo->marks[i] >= MAX_GRADE_B)
        {
            snprintf(pstInfo->grades[i], MAX_GRADE_LENGTH, "B");
        }
        else if(pstInfo->marks[i] >= MAX_GRADE_C)
        {
            snprintf(pstInfo->grades[i], MAX_GRADE_LENGTH, "C");
        }
        else if(pstInfo->marks[i] >= MAX_GRADE_D)
        {
            snprintf(pstInfo->grades[i], MAX_GRADE_LENGTH, "D");
        }
        else
        {
            snprintf(pstInfo->grades[i], MAX_GRADE_LENGTH, "F");
        }
    }

    return STATUS_SUCCESS;
}

/*******************************************************************************
*
* studentUpdateRank - The function [studentUpdateRank] will calculate
* rank of each student
*/
bool studentUpdateRank(void)
{
    for(uint8_t i = 0; i < studentCount; i++)
    {
        students[i].rank = 1;

        for(uint8_t j = 0; j < studentCount; j++)
        {
            if(students[j].sumMarks > students[i].sumMarks)
            {
                students[i].rank++;
            }
        }

        printf("Rank for student %s is: %d\n", students[i].name, students[i].rank);
    }

    return STATUS_SUCCESS;
}

/*******************************************************************************
*
* studentGetCount - The function [studentGetCount] will calculate
* count of student
*/
bool studentGetCount(uint32_t* pulCount)
{
    if(pulCount == NULL)
    {
        return STATUS_ERROR;
    }

    *pulCount = studentCount;

    return STATUS_SUCCESS;
}

/*******************************************************************************
*
* studentGetAvgMarksOfSubjects - The function [studentGetAvgMarksOfSubjects] 
* will calculate avg marks of sunjects
*/
bool studentGetAvgMarksOfSubjects(uint8_t* pucAvgMarks)
{
    if(pucAvgMarks == NULL)
    {
        return STATUS_ERROR;
    }

    if(studentCount == 0)
    {
        *pucAvgMarks = 0;

        return STATUS_SUCCESS;
    }

    for(uint32_t i = 0; i < studentCount; i++)
    {
        for(uint32_t j = 0; j < MAX_SUBJECTS; j++)
        {
            *pucAvgMarks += students[i].marks[j];
        }
    }

    *pucAvgMarks /= (studentCount * MAX_SUBJECTS);

    return STATUS_SUCCESS;
}

/*******************************************************************************
*
* studentDeleteByName - The function [studentDeleteByName] will delete data by
* name
*/
bool studentDeleteByName(uint8_t* pucName)
{
    if(pucName == NULL)
    {
        return STATUS_ERROR;
    }

    for(uint32_t i = 0; i < studentCount; i++)
    {
        if(strncmp((char*)pucName, (char*)students[i].name, MAX_NAME_LENGTH) == 0)
        {
            freeStudent(&students[i]);

            for(uint32_t j = i; j < studentCount - 1; j++)
            {
                students[j] = students[j + 1];
            }
            studentCount--;

            return STATUS_SUCCESS;
        }
    }

    return STATUS_ERROR;

}

/*******************************************************************************
*
* studentDeleteByRoll - The function [studentDeleteByRoll] will delete data by
* roll no
*/
bool studentDeleteByRoll(uint32_t ulRoll)
{
    if(ulRoll == 0)
    {
        return STATUS_ERROR;
    }
    for(uint32_t i = 0; i < studentCount; i++)
    {
        if(students[i].rollNumber == ulRoll)
        {
            for(uint32_t j = i; j < studentCount - 1; j++)
            {
                students[j] = students[j + 1];
            }
            studentCount--;

            return STATUS_SUCCESS;
        }
    }

    return STATUS_ERROR;
}

/*******************************************************************************
*
* studentDeleteAll - The function [studentDeleteAll] will delete whole data
*/
bool studentDeleteAll(void)
{
    if(freeAllStudents())
    {
        return STATUS_SUCCESS;
    }

    return STATUS_ERROR;
}