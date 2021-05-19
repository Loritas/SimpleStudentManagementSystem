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
    new_grade = set_grade(new_grade, head,HAS_CLASSES_INPUT);
    while(temp_grade->next != NULL){
        temp_grade = temp_grade->next;
    }

    temp_grade->next = new_grade;
    printf("That's alright.Returning to the main menu\n");
    return new_grade;
}
grade_p set_grade(grade_p grade, grade_head_p head,enum BOOLEAN_USE HAS_CLASSES_INPUT){
    char grade_number[4];
    char *quantity = grade_number;
    char class_total[10];
    char *class_amount = class_total;
    char grade_uid[24];
    char *uid = grade_uid;
    if (HAS_CLASSES_INPUT == FALSE_RES)
    {
        printf("There is no class.You must create one at first \nAnd your character must be an administrator.\nPress any key to continue.");
        getchar();
        printf("Please input the grade number.It should be a four-digit-number.\n");
        fgets(quantity, 4, stdin);
        fflush(stdin);
        strcmp(grade->grade_number,grade_number) ;
        printf("Please input the classes' amounts of the grade.");
        fgets(class_amount, 10, stdin);
        fflush(stdin);
        grade->class_total = atol(class_total);
        printf("Press any key to create the uid")
        getchar();
        create_uid(char *uid);
        strcpy(grade->uid, grade_uid);
    }
    return grade;
}
void update_grade (grade_p p)
{
    char update_number[5];
    char *quantity = update_number;
    char update_temp[5];
    char *temp = update_temp;
    int judge = 0;
    printf("Please input the number of the grade you want to change");
    fgets(quantity, 4, stdin);
    fflush(stdin);
    grade_p pr = p->next;
    while (pr != NULL) {
        judge = 1;
        if (0 == strcmp(pr->grade_number, update_number)) {
            fgets(temp, 4, stdin);
            fflush(stdin);
            strcpy(pr->grade_number, update_temp);
            printf("Change successfully!");
        }
        pr = pr->next;
    }
        if(judge == 0)
        {
            printf("The grade you input hasn't existed!");
        }
}
void delete_grade(grade_p p){
    grade_p pr,pre;
    int judge = 0;
    char grade_number[5];
    char *number = grade_number;
    printf("Please input the number of the grade you want to delete");
    fgets(number,4,stdin);
    fflush(stdin);
    if(p->next == NULL)
    {
        printf("Error! There isn't any grade to delete!");
        return;
    }
    pre = p;
    pr = pre->next;
    while(pr)
    {
        if (0 == strcmp(pr->grade_number, grade_number))
        {
            judge = 1;
            pre->next = pr->next;
            free(pr);
            printf("Delete successfully!");
            break;
        }
        pre = pr;
        pr = pr->next;
    }
    if (judge == 0)
        printf("The grade you input hasn't existed! ")
}
void add_grade(grade_p p){
    char grade_number[5];
    char *number=grade_number;
    char class_total[10];
    char *class_amount = class_total;
    grade_p q = p->next;
    printf("Please enter the grade number you want to add.");
    fgets(number,4,stdin);
    fflush(stdin);
    while (q != NULL)
    {
        if(0 == strcmp(q->grade_number,grade_number))
        {
            printf("The grade you enter has existed");
            break;
        }
        q = q->next;
    }
    if(q == NULL)
    {
        grade_p pr;
        grade_p pr = (grade_p)malloc(sizeof(grade));
        strcmp(pr->grade_number, grade_number);
        printf("Please enter the class amount of the grade");
        fgets(class_amount,10,stdin);
        fflush(stdin);
        pr->class_total = atol(class_total);
        grade_insert(grade_p p, grade_p pr);
    }

}
void grade_insert(grade_p p,grade_p q)
{
    grade_p pr=NULL;
    pr=p;
    q->next=pr->next;
    pr->next=q;
}
