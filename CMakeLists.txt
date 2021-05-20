cmake_minimum_required(VERSION 3.17)
project(classdesign1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)
include_directories(data)
include_directories(entity)
include_directories(service)
include_directories(service/serviceHead)
include_directories(utils)

add_executable(classdesign1
        .idea/.gitignore
        .idea/classdesign1.iml
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        data/users_data.json
        entity/administrator.h
        entity/grades.h
        service/serviceHead/operate_file.h
        service/serviceHead/setting.h
        service/serviceHead/users.h
        service/operate_file.c
        service/users.c
        utils/cJSON.c
        utils/cJSON.h
        utils/cjson_utils.c
        utils/cjson_utils.h
        utils/tool.c
        utils/tool.h
        README.md
        StartSystem.c entity/counsellors.h entity/classes.h entity/head_teachers.h service/grade_service.c service/serviceHead/grade_service.h service/serviceHead/guidance_director_service.h service/guidance_director_service.c service/serviceHead/teacher_service.h service/teacher_service.c)
