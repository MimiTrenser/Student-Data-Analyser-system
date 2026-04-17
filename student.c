#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "student.h"

static student students[];
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

bool studentGetCount(uint32* pulCount)
{
}
bool studentGetAvgMarksOfSubjects(uint8* pucAvgMarks)
{
}

bool studentDeleteByName(uint8* pucName)
{
}
bool studentDeleteByRoll(uint32 ulRoll)
{
}
bool studentDeleteAll(void)
{
}