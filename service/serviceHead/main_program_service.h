/**
 * @file main_program_service.h
 * @author @Loritas
 * @brief provides the main program function interface
 * @version 0.1
 * @date 2021-05-18
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef MAIN_PROGRAM_SERVICE_H
#define MAIN_PROGRAM_SERVICE_H
#include "users_service.h"
#include "student_service.h"
#include "teacher_service.h"
#include "guidance_director_service.h"
#include "class_service.h"
#include "grade_service.h"
#include "counsellor_service.h"

enum OPERATE login_account(users_head_p head, USER *user);

enum OPERATE administrator_system(users_head_p head, USER user);
enum OPERATE teacher_system(users_head_p head, USER user);
enum OPERATE counsellor_system(users_head_p head, USER user);
enum OPERATE guidance_director_system(users_head_p head, USER user);

enum OPERATE users_function(users_head_p head, USER user);
enum OPERATE grade_function(grade_head_p head, USER user);
enum OPERATE class_function(class_head_p head, USER user, grade_head_p grade_h);
enum OPERATE student_function(stu_head_p head, USER user);
enum OPERATE teacher_function(teach_head_p head, USER user);
#endif //MAIN_PROGRAM_SERVICE_H
