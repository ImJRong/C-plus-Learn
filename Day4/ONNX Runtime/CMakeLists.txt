# 最低 CMake 版本
cmake_minimum_required(VERSION 3.10)

# 项目名
project(OnnxDemo)   

# ONNX Runtime 安装位置（换电脑只改这一行）
set(ORT_ROOT "D:/onnxruntime/onnxruntime-win-x64-1.31.0")

# 生成可执行程序（新增 .cpp 文件时在 test.cpp 后面追加）
add_executable(app test.cpp)

# 头文件路径
target_include_directories(app PRIVATE "${ORT_ROOT}/include")

# 链接库
target_link_libraries(app PRIVATE "${ORT_ROOT}/lib/onnxruntime.lib")
