//
// Created by 86189 on 2021/5/19.
//

#ifndef CODEFIELD_COUNSELLOR_SERVICE_H
#define CODEFIELD_COUNSELLOR_SERVICE_H
#include "utils/tool.h"
#include "setting.h"
#include <stdio.h>
#include <stdlib.h>
#include "operate_file.h"
#include "entity/counsellors.h"


enum OPERATE find_counsellor(counsellor_head_p headP, enum SELECT select);
enum OPERATE find_counsellor_by_work_number(counsellor_head_p headP);
enum OPERATE find_counsellor_by_name(counsellor_head_p headP);
enum OPERATE delete_counsellor(counsellor_head_p headP, enum SELECT select);
enum OPERATE delete_counsellor_by_work_number(counsellor_head_p headP);
enum OPERATE delete_counsellor_by_name(counsellor_head_p headP);
enum OPERATE add_counsellor(counsellor_head_p headP);
enum OPERATE update_counsellor(counsellor_head_p headP, enum SELECT select);
enum OPERATE update_counsellor_by_name(counsellor_head_p headP);
enum OPERATE update_counsellor_by_work_number(counsellor_head_p headP);
counsellor_head_p initial_counsellor_List();

#endif //CODEFIELD_COUNSELLOR_SERVICE_H
