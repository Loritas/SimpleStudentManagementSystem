/**
 * @file counsellors.h
 * @author @Little-Red-Riding-Hood
 * @brief provides interface for creating a list about counsellor
 * @version 0.1
 * @date 2021-05-17
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef COUNSELLORS_H
#define COUNSELLORS_H
#include "service/serviceHead/setting.h"

typedef struct counsellors{
    char uid[24];
    char classes_uid[3][20];
    long work_number;
    char phone_number[12];
    char email[33];
    char name[20];
    enum BOOLEAN_USE HAS_MAX_CLASS;
    struct counsellors *next;
}counsellors, *counsellor_p;

typedef struct counsellors_head_pointer{
    enum BOOLEAN_USE isHead;
    struct counsellors *next;
}counsellors_head_pointer, *counsellor_head_p;

#endif //_COUNSELLORS_H
