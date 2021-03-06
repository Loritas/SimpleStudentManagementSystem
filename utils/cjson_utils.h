/**
 * @file cjson_utils.h
 * @author @Loritas
 * @brief cjson tools
 * @version 0.1
 * @date 2021-05-12
 *
 * @copyright Copyright (c) 2021
 *
 */
// todo: finish cjson_utils
#ifndef CJSON_UTILS_H
#define CJSON_UTILS_H
#include "service/serviceHead/users_service.h"
#include "entity/grade.h"
#include "entity/student.h"
#include "entity/classes.h"
#include "cJSON.h"


enum OPERATE parsing_user_data(char *json_data, void *struct_pointer);
enum OPERATE parsing_grade_data(char *json_data, void *struct_pointer);

enum OPERATE save_user_data(char *target_data, void *struct_pointer);
enum OPERATE save_grade_data(char *target_data, void *struct_pointer);
enum OPERATE save_class_data(char *target_data, void *struct_pointer);
enum OPERATE save_student_data(char *target_data, void *struct_pointer);

#endif //CJSON_UTILS_H
