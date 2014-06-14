@echo off
REM RUN MAKEFILE FOR UNIT TESTS
make -f "build/makefile-unittests.gcc"
REM RUN UNIT TESTS, DISPLAY RESULTS AND SAVE RETURN VALUE
"bin/unittests.exe"
REM IF RETURN VALUE OF UNIT TEST PROGRAM IS 1 RUN MAKEFILE FOR PROJECT
@if "%ERRORLEVEL%" == "1" goto BUILD
echo.
echo Build Failed
goto END
:BUILD
REM RUN MAKEFILE FOR PROJECT
	make -f "build/makefile-libraryapp.gcc"
	goto END
:END