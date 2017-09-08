# 编译静态链接库libhello.a
add_library(hello hello.cpp)

# 编译可执行文件和设置链接库（注意顺序）
add_executable(main main.cpp)
target_link_libraries(main hello)

link_directories("/usr/local/boost_1_65_0/libs")
add_definitions(-DBOOST_LOG_DYN_LINK)
add_executable(boostlog boost_log.cpp)
target_link_libraries(boostlog boost_log boost_system boost_thread boost_filesystem)
