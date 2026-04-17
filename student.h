#ifndef STUDENT_H
#define STUDENT_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define MAX_SUBJECTS 10
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 200
#define MAX_GRADE_LENGTH 2

typedef struct 
{
    char name[MAX_NAME_LENGTH];
    uint32_t rollNumber;
    uint8_t marks[MAX_SUBJECTS];
    char* address;
    uint16_t sumMarks;
    float averageMarks;
    char grades[MAX_SUBJECTS][MAX_GRADE_LENGTH];
    uint32_t rank;
} student;

typedef enum
{
    STATUS_ERROR,
    STATUS_SUCCESS
}status;


bool studentAdd(student* pstInfo);
bool studentCalcAverage(student* pstInfo, float* pfAvg);
bool studentCalcSum(student* pstInfo, uint32_t* pulSum);
bool studentCalcGrades(student* pstInfo, uint8_t* pucSum);
bool studentUpdateRank(void);
bool studentGetCount(uint32_t* pulCount);
bool studentGetAvgMarksOfSubjects(uint8_t* pucAvgMarks);
bool studentGetSortedByRoll(void);
bool studentGetSortedByName(void);
bool studentGetSortedByRank(void);
bool studentGetName(char* pName);
bool studentDeleteByName(uint8_t * pucName);
bool studentDeleteByRoll(uint32_t ulRoll);
bool studentDeleteAll(void);

#endif