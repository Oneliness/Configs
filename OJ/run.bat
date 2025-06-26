@echo off
if not exist input.txt (
    echo file not exist
    exit /b
)

set fileName=%1
set fileNameWithoutExt=%2

rem 这里设定是否用 GDB
set USE_GDB=0

g++ "%fileName%" -std=c++17 -O0 -Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-but-set-variable -Wno-unused-variable -g -o "%fileNameWithoutExt%" -DDEBUG=1

if errorlevel 1 (
    echo.
    exit /b 1
)

type input.txt
echo.
echo.

if "%USE_GDB%"=="1" (
    echo Starting GDB...
    echo run ^< input.txt > gdb_commands.txt
    gdb "%fileNameWithoutExt%.exe" -x gdb_commands.txt
) else (
    echo ^=^>
    "%fileNameWithoutExt%.exe" < input.txt
)
