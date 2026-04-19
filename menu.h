/* menu.h - main menu declararions */
/*
* Copyright (c) 2026 Trenser Technology Solutions (P) Ltd
*/
/*
modification history --------------------
08april26, Updated coding standards
*/
/*
DESCRIPTION
This module is for header inclusion for menu.c
*/

/* includes */
#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdbool.h>

#define INFO(fmt, ...)    printf("[INFO] " fmt "\n", ##__VA_ARGS__)
#define ERROR(fmt, ...)   printf("[ERROR] " fmt "\n", ##__VA_ARGS__)
#define SUCCESS(fmt, ...) printf("[SUCCESS] " fmt "\n", ##__VA_ARGS__)


bool menuMain();
bool menuStudentOverview(void);
bool menuAddStudent(void);
bool menuListStudent(void);	
bool menuDeleteStudent(void);
bool menuListSearchByName(void);
bool menuListSortByName(void);
bool menuListSortByRoll(void);
bool menuListSortByRank(void);
bool menuDeleteByName(void);
bool menuDeleteByRoll(void);
bool menuDeleteAll(void);


#endif