# CMake 最低版本要求
cmake_minimum_required(VERSION 3.10)

# 项目名（可改）
project(StudentDemo)

# 生成可执行程序：add_executable(程序名 源文件1 源文件2 ...)
# 新增 .cpp 文件时，在后面追加文件名
add_executable(app main.cpp Student.cpp)
