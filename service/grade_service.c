/**
 * @file grade.c
 * @author @Little-Red-Riding-Hood
 * @brief check, delete and update the messages of grade
 * @version 0.1
 * @date 2021-05-17
 *
 * @copyright Copyright (c) 2021
 *
 */

/**
 * @author @Little-Red-Riding-Hood
 * @brief Function for initial grade list
 * @date 2021-3-14
 *
 * @return head_point for grade list
 */
#include "serviceHead/grade_service.h"
grade_head_p initial_Grade_List(){
    grade_head_p head_point = (grade_head_p)malloc(sizeof(grade_head));

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
/**
 * @author Little-Red-Riding-Hood
 * @brief set the properties of grade
 * @date 2021-5-18
 *
 * @param HAS_CLASSES_INPUT whether it is the first time to create grade
 *
 * @return GRADE entity
 */
grade_p create_grade(grade_head_p head,enum BOOLEAN_USE HAS_MAX_CLASSES_INPUT){

    if (head == NULL)
    {
        printf("An unexpected error has been created,");
        printf(" please save your work and exit this program.\n");
        return NULL;
    }
    grade_p  temp_grade = head->next;

    grade_p new_grade = (grade_p)malloc(sizeof(grade));

    if (new_grade == NULL)
    {
        printf("Warning: Your computer has not enough free memory,");
        printf("Please save your work and exit this program.\n");
        return NULL;
    }
    new_grade->next = NULL;

    new_grade = set_grade(new_grade, head, HAS_CLASSES_INPUT);

    while(temp_grade->next != NULL){
        temp_grade = temp_grade->next;
    }

    temp_grade->next = new_grade;
    printf("That's alright.Returning to the main menu\n");
    return new_grade;
}
grade_p set_grade(grade_p grade, grade_head_p head){
    char grade_number[4];
    char *quantity = grade_number;

    char class_total[10];
    char *class_amount = class_total;

    char grade_uid[24];
    char *uid = grade_uid;

        printf("There is no grade.You must create one at first \nAnd your character must be an administrator.\nPress any key to continue.\n");
        getchar();

        printf("Please input the grade number.It should be a four-digit-number.\n");
        fgets(quantity, 4, stdin);
        fflush(stdin);

        while (true)
        {
            if(strlen(grade_number) == 4 && atol(grade_number) > 0) {
                grade->grade_number = atol(grade_number);
                printf("Ok. There's nothing wrong with your grade number.\n");
                break;
            } else{
                printf("The grade number you enter must be a four-digit-number and positive number. \nPlease enter again!");
                fgets(quantity, 4, stdin);
                fflush(stdin);
            }
        }

        printf("Please input the classes' amounts of the grade.\n");
        fgets(class_amount, 10, stdin);
        fflush(stdin);
        while (true){
            if(atol(class_total) > 0){
                grade->class_total = atol(class_total);
                printf("Ok. There's nothing wrong with classes' amounts.\n");
                break;
            }else{
                printf("The classes' amounts of the grade must be positive number. \nPlease enter again! ");
                gets(class_amount, 10, stdin);
                fflush(stdin);
            }
        }

        create_uid(char *uid);
        strcpy(grade->uid, grade_uid);
    }
    return grade;
}
void update_grade (grade_head_p head)
{
    char update_number[5];
    char *get_number = update_number;

    char update_temp[5];
    char *temp = update_temp;

    char class_total[10];
    char *get_class = class_total;

    int judge = 0;
    printf("Please input the number of the grade you want to change");
    fgets(get_number, 4, stdin);
    fflush(stdin);
    while (true){
        if(atol(update_number) > 0 && strlen(update_number) == 4){
            printf("Enter successfully\nPlease press any key to continue\n");
            getchar();
            break;
        }else{
            printf("The number you input must be a four-digit and positive number. \nPlease enter again! ");
            gets(get_number, 10, stdin);
            fflush(stdin);
        }
    }

    grade_p temp_grade = head->next;

    while (temp_grade != NULL) {
        judge = 1;
        if (temp_grade->grade_number == atol(update_number)) {
            printf("Please enter the number you want to replace the old one.");
            fgets(temp, 4, stdin);
            fflush(stdin);
            while (true){
                if(atol(update_number) > 0 && strlen(update_number) == 4){
                    printf("Enter successfully\nPlease press any key to continue\n");
                    getchar();
                    break;
                }else{
                    printf("The number you input must be a four-digit and positive number. \nPlease enter again! ");
                    gets(get_number, 10, stdin);
                    fflush(stdin);
                }
            }

            temp_grade->grade_number = atol(update_temp);
            printf("Change successfully!");
        }

        temp_grade = temp_grade->next;
    }

        if(judge == 0)
        {
            printf("The grade you input hasn't existed!");
        }
}
void delete_grade(grade_head_p head){
    grade_p temp_grade, del_grade;
    int judge = 0;
    char grade_number[5];
    char *get_number = grade_number;

    if(head->next == NULL)
    {
        printf("Error! There isn't any grade to delete!");
        return;
    }
    temp_grade = head->next;
    del_grade = temp_grade;

    printf("Please input the number of the grade you want to delete");
    fgets(get_number,4,stdin);
    fflush(stdin);
    while (true)
    {
        if(strlen(grade_number) == 4 && atol(grade_number) > 0) {
            printf("Ok. There's nothing wrong with your input the program will continue soon.\n");
            break;
        } else{
            printf("The grade number you enter must be a four-digit-number and positive number. \nPlease enter again!");
            fgets(quantity, 4, stdin);
            fflush(stdin);
        }
    }

    while(del_grade)
    {
        if (del_grade->grade_number == atol(grade_number))
        {
            judge = 1;
            temp_grade = del_grade->next;
            free(del_grade);
            printf("Delete successfully!");
            break;
        }
        temp_grade = del_grade;
        del_grade = del_grade->next;
    }
    if (judge == 0)
        printf("The grade you input hasn't existed! ")
}

