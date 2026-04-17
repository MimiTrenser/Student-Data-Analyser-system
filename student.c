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
}
bool studentCalcSum(student* pstInfo, uint32* pulSum)
{
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



}
bool studentGetAvgMarksOfSubjects(uint8_t* pucAvgMarks)
{
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