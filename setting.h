/**
 * @file setting.h
 * @author @Loritas
 * @brief provides an interface for each setting
 * @version 0.1
 * @date 2021-03-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

enum STRING_TYPE{
    PASSWORD,
    TELEPHONE_NUMBER,
    EMAIL,
    WORK_NUMBER,
    ACCOUNT
};

enum BOOLEAN_USE{
    TRUE_RES,
    FALSE_RES,
    IS_FIRST_USER,
    NOT_FIRST_USER
};