#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "student.h"

#define MAX_GRADE_A 90
#define MAX_GRADE_B 80
#define MAX_GRADE_C 70
#define MAX_GRADE_D 40

static student students[MAX_STUDENTS] = {0};
static uint32_t studentCount = 0;

bool studentGetSortedByRoll(void)
{
    printf("Getting students sorted by roll number\n");

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

bool studentGetSortedByName(void)
{
    printf("Getting students sorted by name\n");
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

bool studentGetSortedByRank(void)
{
    printf("Getting students sorted by rank\n");

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
        printf("Rank: %u\n", students[i].rank);
    }


    return STATUS_SUCCESS;
}

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

bool studentAdd(student* pstInfo)
{
    if(pstInfo == NULL)
    {
        return STATUS_ERROR;
    }

    if(studentCount >= MAX_STUDENTS)
    {
        printf("Maximum student limit reached, Cannot add more students.\n");
        return STATUS_ERROR;
    }

    memcpy(&students[studentCount], pstInfo, sizeof(student));
    studentCount++;

    return STATUS_SUCCESS;
}
bool studentCalcAverage(student* pstInfo, float* pfAvg)
{
    if(pstInfo == NULL || pfAvg == NULL)
    {
        return STATUS_ERROR;
    }

    *pfAvg = (float)pstInfo->sumMarks / MAX_SUBJECTS;

    return STATUS_SUCCESS;
}
bool studentCalcSum(student* pstInfo, uint32_t* pulSum)
{
    if(pstInfo == NULL || pulSum == NULL)
    {
        return STATUS_ERROR;
    }

    for(int i = 0; i < MAX_SUBJECTS; i++)
    {
        *pulSum += pstInfo->marks[i];
    }

    return STATUS_SUCCESS;
}
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
            snprintf(&pstInfo->grades[i], MAX_GRADE_LENGTH, "A");
        }
        else if(pstInfo->marks[i] >= MAX_GRADE_B)
        {
            snprintf(&pstInfo->grades[i], MAX_GRADE_LENGTH, "B");
        }
        else if(pstInfo->marks[i] >= MAX_GRADE_C)
        {
            snprintf(&pstInfo->grades[i], MAX_GRADE_LENGTH, "C");
        }
        else if(pstInfo->marks[i] >= MAX_GRADE_D)
        {
            snprintf(&pstInfo->grades[i], MAX_GRADE_LENGTH, "D");
        }
        else
        {
            snprintf(&pstInfo->grades[i], MAX_GRADE_LENGTH, "F");
        }
    }

    return STATUS_SUCCESS;
}
bool studentUpdateRank(void)
{
    for(uint32_t i = 0; i < studentCount; i++)
    {
        students[i].rank = 1;

        for(uint32_t j = 0; j < studentCount; j++)
        {
            if(students[j].sumMarks > students[i].sumMarks)
            {
                students[i].rank++;
            }
        }
        students[i].rank = students[i].rank;
    }

    return STATUS_SUCCESS;
}

bool studentGetCount(uint32_t* pulCount)
{
    if(pulCount == NULL)
    {
        return STATUS_ERROR;
    }

    *pulCount = studentCount;

    return STATUS_SUCCESS;
}
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

bool studentDeleteByName(uint8_t* pucName)
{
    if(pucName == NULL)
    {
        return STATUS_ERROR;
    }
    for(uint32_t i = 0; i < studentCount; i++)
    {
        if(strncmp(pucName, students[i].name, MAX_NAME_LENGTH) == 0)
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
bool studentDeleteByRoll(uint32_t ulRoll)
{
    if(ulRoll == NULL)
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
bool studentDeleteAll(void)
{
    studentCount = 0;
    return STATUS_SUCCESS;
}