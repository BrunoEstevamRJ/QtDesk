add_executable(QtDeskTests
    test_taskservice.cpp
)

target_include_directories(QtDeskTests PRIVATE ../src)

target_link_libraries(QtDeskTests PRIVATE
    Qt6::Test
)

add_test(NAME QtDeskTests COMMAND QtDeskTests)

