#include "serviceHead/teacher_service.h"
teache_head_p initial_Teacher_List(){
    teache_head_p head_point = (teach_head_p)malloc(sizeof(teacher_head_p));
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
teacher_p create_teacher(teach_head_p head,enum BOOLEAN_USE HAS_MAX_CLASSES) {

    if (head == NULL) {
        printf("An unexpected error has been created,");
        printf(" please save your work and exit this program.\n");
        return NULL;
    }
    teacher_p temp_teacher = head->next;
    teacher_p new_teacher = (teacher_p) malloc(sizeof(teacher));
    if (new_teacher == NULL) {
        printf("Warning: Your computer has not enough free memory,");
        printf("Please save your work and exit this program.\n");
        return NULL;
    }
    new_teacher->next = NULL;
    new_teacher = set_grade(new_grade, head, HAS_CLASSES_INPUT);
    while (temp_teacher->next != NULL) {
        temp_teacher = temp_teacher->next;
    }

    temp_teacher->next = new_teacher;
    printf("That's alright.Returning to the main menu\n");
    return new_teacher;
}
teacher_p set_teacher(teacher_p teacher, teach_head_p head){
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
    char switch_number;
    printf("Please enter your name");
    fgets(Name,10,stdin);
    fflush(stdin);
    strcpy(teacher->name,name);
    printf("Please enter your work number");
    fgets(number,10,stdin);
    fflush(stdin);
    teacher->work_number=atol(work_number);
    printf("Please enter your email");
    fgets(Email,10,stdin);
    fflush(stdin);
    strcpy(teacher->email,email);
    printf("Please enter your cell-phone number");
    fgets(phone_number,10,stdin);
    fflush(stdin);
    strcpy(teacher->phone_number,cell_phone);
    printf("Please enter the subject you teach");
    scanf("%c",&switch_number);
    fflush(stdin);
    switch (switch_number) {
        case '0':
            teacher->subject = ADVANCED_MATHEMATICS;
            break;
        case '1':
            teacher->subject = ENGLISH;
            break;
        case '2':
            teacher->subject = C_PROGRAM_LANGUAGE;
            break;
        case '3':
            teacher->subject = PHYSICAL_EDUCATION;
            break;
        case '4':
            teacher->subject = PYHTON;
            break;
    }
    printf("Press any key to create class uid");
    getchar()
    create_uid(char *uid);
    strcpy(teacher->classes_uid,classes_uid);
    return teacher;
}



