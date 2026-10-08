@echo off

rem 项目目录
set PROJECT_DIR=D://C++Learning//Day2
rem 生成的exe名
set APP_NAME=app
rem 运行参数(一般空)
set RUN_ARGS=

set CMAKE_EXE=C://Users//RONGG//AppData//Roaming//Python//Python313//Scripts//cmake.exe
set MAKE_EXE=D://mingw64//bin//mingw32-make.exe

chcp 65001 >nul
cd /d %PROJECT_DIR%

echo [1/3] 配置
"%CMAKE_EXE%" -G "MinGW Makefiles" .
if errorlevel 1 (echo 配置失败 & pause & exit /b 1)

echo [2/3] 编译
"%MAKE_EXE%"
if errorlevel 1 (echo 编译失败 & pause & exit /b 1)

echo [3/3] 运行
%APP_NAME%.exe %RUN_ARGS%

pause
