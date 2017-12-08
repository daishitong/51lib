@echo off

echo 51lib_release folder update
cd /d %~dp0

xcopy .\Objects\51lib.LIB .\51lib_release\ /D /Y
xcopy .\core\*.h .\51lib_release\inc\core\ /D /Y
xcopy .\bsp\*.h .\51lib_release\inc\bsp\ /D /Y
xcopy .\LICENSE .\51lib_release\ /D /Y
xcopy .\README.md .\51lib_release\ /D /Y

setlocal
set LIB_HEADER_FILE=.\51lib_release\inc\51lib.h

echo /* site:https://github.com/daishitong/51lib */ > %LIB_HEADER_FILE%
echo #ifndef __51LIB_H__ >> %LIB_HEADER_FILE%
echo #define __51LIB_H__ >> %LIB_HEADER_FILE%
echo. >> %LIB_HEADER_FILE%

echo // core header files >> %LIB_HEADER_FILE%
for /r .\51lib_release\inc\core\ %%f in (*.*) do ((echo #include "core\%%~nxf") >> %LIB_HEADER_FILE%)

echo. >> %LIB_HEADER_FILE%

echo // bsp header files >> %LIB_HEADER_FILE%
for /r .\51lib_release\inc\bsp\ %%f in (*.*) do ((echo #include "bsp\%%~nxf") >> %LIB_HEADER_FILE%)

echo. >> %LIB_HEADER_FILE%
echo #endif //__51LIB_H__  >> %LIB_HEADER_FILE%

REM pause