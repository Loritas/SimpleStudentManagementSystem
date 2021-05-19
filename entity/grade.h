/**
 * @file grade.h
 * @author @waterman263
 * @brief 年级的结构体（当前年级（指针）
			  班级总数
			  单科平均分（二维数组）
			  总体平均分
			  总体平均绩点
			  是否已录入班级作为下属（boolean））
 * @version 0.1
 * @date 2021-05-15
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef GRADE_H
#define GRADE_H


typedef struct grade{
    char uid[24];
    char grade_number[5];
    int class_total;
    float subject_aver[5][1];
    float general_aver_score;
    float general_aver_gpa;
    enum BOOLEAN_USE HAS_CLASSES_INPUT;
    struct grade *next;
}grade, *grade_p;

typedef struct grade_head_pointer{
    enum BOOLEAN_USE isHead;
    struct grade *next;
}grade_head_pointer, *grade_head_p;
#endif //_GRADE_H
