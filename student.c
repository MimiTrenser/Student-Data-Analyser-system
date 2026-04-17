#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "student.h"

static student students[MAX_STUDENTS] = {0};
static uint32_t studentCount = 0;

bool studentDeleteByName(uint8_t* pucName)
{
    printf("Deleting student by name: %s\n", pucName);

    return STATUS_SUCCESS;
}
bool studentGetSortedByRoll(void)
{
    printf("Getting students sorted by roll number\n");


    return STATUS_SUCCESS;
}

bool studentGetSortedByName(void)
{
    printf("Getting students sorted by name\n");



    return STATUS_SUCCESS;
}

bool studentGetSortedByRank(void)
{
    printf("Getting students sorted by rank\n");


    return STATUS_SUCCESS;
}

bool studentGetName(char* pName)
{
    if(pName == NULL)
    {
        return STATUS_ERROR;
    }

}

bool studentAdd(student* pstInfo)
{
    if(pstInfo == NULL)
    {
        return STATUS_ERROR;
    }

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
bool studentCalcGrades(student* pstInfo, uint8* pucSum)
{

}
bool studentUpdateRank(void)
{

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
}
bool studentDeleteByRoll(uint32_t ulRoll)
{
}
bool studentDeleteAll(void)
{
}