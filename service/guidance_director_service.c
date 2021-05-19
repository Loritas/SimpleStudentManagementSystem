/**
 * @file guidance_director_service.c
 * @author @Little-Red-Riding-Hood
 * @brief check, delete and update the messages of guidance_directors
 * @version 0.1
 * @date 2021-05-19
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "serviceHead/guidance_director_service.h"
director_head_p initial_Director_List(){
    director_head_p head_point = (director_head_p)malloc(sizeof(director_head_pointer));
    if (head_point == NULL)
    {
        printf("Warning: Your computer has not enough free memory,\n");
        printf("please press any key to exit this program.");
        getchar();
        exit(0);
    }
    head_point->isHead = TRUE_RES;
    head_point->next = NULL;
    return head_point;
}
director_p create_director(director_head_p head){
    if (head == NULL){
        printf("An unexpected error has been created,");
        printf(" please save your work and exit this program.\n");
        return NULL;
    }
    director_p new_director = (director_p)malloc(sizeof(director));
    director_p temp_director = head->next;
    if (new_director == NULL){
        printf("Warning: Your computer has not enough free memory,");
        printf(" please save your work and exit this program.\n");
        return NULL;
    }
    new_director->next = NULL;
    while (temp_director->next != NULL){
        temp_director = temp_director->next;
    }

    temp_director->next = new_director;
    printf("That's alright.Returning to the menu\n");
    return new_director;
}
director_p set_director(director_p director, director_head_p head){
    char name[10];
    char *Name=name;
    char work_number[10];
    char *number=work_number;
    char email[10];
    char *Email=email;
    char cell_phone[10];
    char *phone_number = cell_phone;
    char my_uid[24];
    char *uid = my_uid;
    printf("Please enter your name");
    fgets(Name,10,stdin);
    fflush(stdin);
    strcpy(director->name,name);
    printf("Please enter your work number");
    fgets(number,10,stdin);
    fflush(stdin);
    director->work_number=atol(work_number);
    printf("Please enter your email");
    fgets(Email,10,stdin);
    fflush(stdin);
    strcpy(director->email,email);
    printf("Please enter your cell-phone number");
    fgets(phone_number,10,stdin);
    fflush(stdin);
    strcpy(director->phone_number,cell_phone);
    printf("Press any key to create the uid");
    getchar();
    create_uid(char *uid);
    strcpy(director->uid,my_uid);
    return director;
}
void query_my_own_data(director_p director){
    director_p q = director->next;
    char name[10];
    char *Name=name;
    fgets(Name,10,stdin);
    fflush(stdin);
    while(q != NULL)
    {
        if(strcmp(q->name,name) == 0) {
            printf("Name: %s", q->name);
            printf("Work number: %ld", q->work_number);
            printf("Phone number: %s", q->phone_number);
            printf("Email: %s", q->email);
        }
        q = q->next;
    }
    if(q == NULL)
        printf("The message you query hasn't existed");
}
void update_my_own_data(director_p director){
    director_p q = director->next;
    char name[10];
    char *Name=name;
    char email[10];
    char *Email=email;
    char cell_phone[10];
    char *phone_number = cell_phone;
    int choose;
    fgets(Name,10,stdin);
    fflush(stdin);
    while(q != NULL){
        if(strcmp(q->name,name) == 0)
        {
            printf("Which message do you want to update?");
            printf("1.Email      2.Phone number");
            printf("3.Name");
            printf("Press any serial to continue");
            scanf("%d",&choose);
            switch (choose) {
                case 1:
                    printf("Please input your new email");
                    fgets(Email,10,stdin);
                    fflush(stdin);
                    strcpy(q->email,email);
                    printf("Update successfully");
                    break;
                case 2:
                    printf("Please input your new Phone number");
                    fgets(phone_number,10,stdin);
                    fflush(stdin);
                    strcpy(q->phone_number,cell_phone);
                    printf("Update successfully");
                    break;
                case 3:
                    printf("Please input your new name");
                    fgets(Name,10,stdin);
                    fflush(stdin);
                    strcpy(q->name,name);
                    printf("Update successfully");
                    break;
                default:
                    printf("Please input the legal serial");
                    break;
            }
        }
    }
    if(q == NULL)
        printf("The message you want to update hasn't existed!");
}
void query_single_grade(grade_p grade){
    grade_p q = grade->next;
    int judge=0;
    char grade_number[5];
    char *number=grade_number;
    fgets(number,4,stdin);
    fflush(stdin);
    while (q != NULL)
    {
        if(strcmp(grade_number,q->grade_nmuber) == 0)
        {
            judge=1;
            printf("The class amount :%s",q->grade_number);
            for(int i = 0;i < 5;i++) {
                printf("The %d aver :%f",i, q->subject_aver[i][0]);
            }
            printf("The general_aver_score :%f",q->general_aver_score);
            printf("The general_aver_gpa :%f",q->general_aver_gpa);
        }
    }
    if(judge == 0)
        printf("The grade you query hasn't existed");
}
void query_all_grades(grade_p grade){
    grade_p q = grade->next;
    if(q == NULL)
    {
        printf("There isn't any grade to query!");
        return;
    }
    while (q)
    {
            printf("The class amount :%s",q->grade_number);
            for(int i = 0;i < 5;i++) {
                printf("The %d aver :%f",i, q->subject_aver[i][0]);
            }
            printf("The general_aver_score :%f",q->general_aver_score);
            printf("The general_aver_gpa :%f",q->general_aver_gpa);
            q = q->next;
    }
}

