cmake_minimum_required(VERSION 3.16)

project(QtDesk VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#>>>>>[ Qt ]<<<<<#
find_package(Qt6 REQUIRED COMPONENTS Widgets Network Sql Test)

#>>>>>[ Enable Qt's automatic features ]<<<<<#
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

#>>>>>[ Main executable ]<<<<<#
add_executable(QtDesk
    src/main.cpp

    src/ui/MainWindow.h
    src/ui/MainWindow.cpp
    src/ui/MainWindow.ui

    src/core/Task.h
    src/core/TaskService.h
    src/core/TaskService.cpp

    src/db/Database.h
    src/db/Database.cpp
    src/db/TaskRepository.h
    src/db/TaskRepository.cpp

    src/net/QuoteClient.h
    src/net/QuoteClient.cpp
)

target_include_directories(QtDesk PRIVATE src)

target_link_libraries(QtDesk PRIVATE
    Qt6::Widgets
    Qt6::Network
    Qt6::Sql
)

#>>>>>>[ Warnings (nice to have) ]<<<<<#
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(QtDesk PRIVATE -Wall -Wextra -Wpedantic)
endif()

#>>>>>[ Tests ]<<<<<#
enable_testing()
add_subdirectory(tests)

