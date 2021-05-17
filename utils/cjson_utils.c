/**
 * @file cjson_utils.c
 * @author @Loritas
 * @brief cjson tools
 * @version 0.1
 * @date 2021-05-12
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "cjson_utils.h"


enum OPERATE_FILE parsing_user_data(char *json_data, void *struct_pointer){
    users_head_p usersHeadP = (users_head_p) struct_pointer;
    USER temp;
    cJSON *root = cJSON_Parse(json_data);
    if (root == NULL){
        cJSON_Delete(root);
        return FAILED;
    }
    cJSON *users_item = cJSON_GetObjectItem(root, "users");
    if (users_item == NULL){
        cJSON_Delete(users_item);
        return FAILED;
    }
    int len = cJSON_GetArraySize(users_item);
    for (int i = 0; i < len; i++){
        cJSON *get_user = cJSON_GetArrayItem(users_item, i);
        USER user = (USER) malloc(sizeof(users));
        if (get_user == NULL){
            cJSON_Delete(get_user);
            return FAILED;
        }
        if (user == NULL){
            printf("Warning: System memory is low, please check your computer memory.\n");
            return FAILED;
        }

        cJSON *account = cJSON_GetObjectItem(get_user, "account");
        cJSON *work_number = cJSON_GetObjectItem(get_user, "work_number");
        cJSON *password = cJSON_GetObjectItem(get_user, "password");
        cJSON *user_role = cJSON_GetObjectItem(get_user, "user_role");
        if (account == NULL || work_number == NULL || password == NULL || user_role == NULL){
            cJSON_Delete(account);
            cJSON_Delete(work_number);
            cJSON_Delete(password);
            cJSON_Delete(user_role);
            return FAILED;
        }

        char *user_account = cJSON_Print(account);
        char *user_work_number = cJSON_Print(work_number);
        char *user_password = cJSON_Print(password);
        char *users_role = cJSON_Print(user_role);

//        printf("%s\n%s\n%s\n%s\n", user_account, user_password, user_work_number, users_role);

        char *check_1 = NULL;
        char *check_2 = NULL;

        user->account = strtol(user_account, &check_1, 10);
        if (strcmp(check_1, "\0") != 0){
            printf("Warning: The data read is illegal, please check your data file!\n");
            printf("Target: users_data.json - account\n");
            return FAILED;
        }

        user->work_number = strtol(user_work_number, &check_2, 10);
        if (strcmp(check_2, "\0") != 0){
            printf("Warning: The data read is illegal, please check your data file!\n");
            printf("Target: users_data.json - work_number\n");
            return FAILED;
        }

        user->USER_ROLE = atoi(users_role);
        if (user->USER_ROLE > -2 || user->USER_ROLE < -5){
            printf("Warning: The data read is illegal, please check your data file!\n");
            printf("Target: users_data.json - user_role\n");
            return FAILED;
        }

        int k = 0, l = 1;
        while (user_password[l] != '\"' && k < 33){
            user->password[k++] = user_password[l++];
        }
        if (user_password[l] != '\"'){
            printf("Warning: The data read is illegal, please check your data file!\n");
            printf("Target: users_data.json - password\n");
            return FAILED;
        }

        if (i == 0){
            usersHeadP->next = user;
            user->next = NULL;
            temp = user;
        } else{
            temp->next = user;
            user->next = NULL;
            temp = temp->next;
        }

//        cJSON_Delete(account);
//        cJSON_Delete(work_number);
//        cJSON_Delete(password);
//        cJSON_Delete(user_role);
//        cJSON_Delete(get_user);
    }
    return SUCCESS;
}