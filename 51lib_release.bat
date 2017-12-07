@echo off

echo 51lib_release folder update

copy .\Objects\51lib.LIB .\51lib_release\ /Y
xcopy .\core\inc .\51lib_release\inc\core\ /D /Y

setlocal
set LIB_HEADER_FILE=.\51lib_release\inc\51lib.h

echo /* site:https://github.com/daishitong/51lib */ > %LIB_HEADER_FILE%
echo #ifndef __51LIB_H__ >> %LIB_HEADER_FILE%
echo #define __51LIB_H__ >> %LIB_HEADER_FILE%
echo. >> %LIB_HEADER_FILE%

echo // core header files >> %LIB_HEADER_FILE%
for /r .\51lib_release\inc\core\ %%f in (*.*) do ((echo #include "core\%%~nxf") >> %LIB_HEADER_FILE%)

echo. >> %LIB_HEADER_FILE%
echo #endif //__51LIB_H__  >> %LIB_HEADER_FILE%

REM pause