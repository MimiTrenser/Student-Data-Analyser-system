#ifndef MENU_H
#define MENU_H

#include <stdbool.h>

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