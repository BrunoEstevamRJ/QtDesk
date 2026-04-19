add_executable(test_taskservice
    test_taskservice.cpp

    ${CMAKE_SOURCE_DIR}/src/core/TaskService.cpp
    ${CMAKE_SOURCE_DIR}/src/db/TaskRepository.cpp
    ${CMAKE_SOURCE_DIR}/src/db/Database.cpp
)

target_include_directories(test_taskservice PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(test_taskservice
    Qt6::Core
    Qt6::Sql
)

add_test(NAME TaskServiceTest COMMAND test_taskservice)
