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
teacher_p create_teacher(teach_head_p head, enum BOOLEAN_USE HAS_MAX_CLASSES) {

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
    char *get_name = name;

    char work_number[10];
    char *get_number = work_number;

    char email[10];
    char *get_email = email;

    char cell_phone[10];
    char *phone_number = cell_phone;

    char my_uid[24];
    char *uid = my_uid;

    char switch_number;

    printf("Please enter your name\n");
    while (true) {
        fgets(get_name, 10, stdin);
        fflush(stdin);
        int i ;
        printf("Please press enter.");
        scanf("%d",&i);
        if{
            i = 13;
            strcpy(director->name, name);
            break;
        }
    }

    printf("Please enter your work number\n");
    fgets(number, 10, stdin);
    fflush(stdin);
    while (true){
        if(strlen(work_number) == 9){
            printf("Enter successfully\n Please press any key to continue\n");
            getchar();
            break;
        }else{
            printf("The number you input must be a 9-digit number. \nPlease enter again!\n");
            gets(get_number, 10, stdin);
            fflush(stdin);
        }
    }
    teacher->work_number = atol(work_number);

    printf("Please enter your email\n");
    fgets(Email,10,stdin);
    fflush(stdin);
    strcpy(teacher->email, email);

    printf("Please enter your cell-phone number\n");
    fgets(phone_number,10,stdin);
    fflush(stdin);
    while (true){
        if(strlen(cell_phone) == 9){
            printf("Enter successfully\n Please press any key to continue\n");
            getchar();
            break;
        }else{
            printf("The number you input must be a 9-digit number. \nPlease enter again!\n");
            fgets(phone_number, 10, stdin);
            fflush(stdin);
        }
    }
    strcpy(teacher->phone_number, cell_phone);

    while(true) {
        printf("Please enter the subject you teach\n");
        scanf("%c", &switch_number);
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
            default:
                printf("Please input a legal serial.");
                break;
        }
    }
    create_uid(char *uid);
    strcpy(teacher->uid, classes_uid);
    return teacher;
}
void query_single_class(teacher_p teacher, class_head_p head){
    char class_uid[24];
    char* uid = class_uid;

    class_p class = head->next;
    if(head == NULL)
    {
        printf("Error press any key to exit")
        getchar();
        exit(0);
    }

    if(class == NULL)
    {
        printf("There isn't any class to query.\nPress any key to exit");
        getchar();
        exit(0);
    }

    printf("Please enter the class you want to query.");
    fgets(uid,23,stdin);
    fflush(stdin);
    while(true)
    {
        if(strlen(class_uid) == 23)
        {
            printf("Ok, there isn't wrong with your enter.");
            break;
        }
        else
            fgets(uid,23,stdin);
            fflush(stdin);
    }

    while (true){
        if(strcmp(class_uid, teacher->classes_uid) == 0)
        {
            break;
        }
        teacher = teacher->next;
        if(teacher == NULL)
        {
            printf("The class you want to query isn't under your teaching.");
        }
    }

    while (true){
        if(strcmp(class_uid, class->uid) == 0)
        {
            break;
        }
        class = class->next;
        if(class == NULL)
        {
            printf("The class you want to query hasn't existed");
        }
    }
    printf("The class number %ld\n", class->class_number);
    for(int i =0;i < 5;i++)
    {
        printf("The class %d subject aver %f" ,i+1, class->subject_aver[i][0] );
    }
    printf("The class general aver %f", class->general_aver);
    printf("The class general gpa %f", class->general_gpa);
}


