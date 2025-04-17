@echo off
echo Installation de LibMIKAI pour Windows...

:: Vérification de l'installation de CMake
where cmake >nul 2>nul
if %ERRORLEVEL% neq 0 (
    echo CMake n'est pas installé. Veuillez l'installer depuis https://cmake.org/download/
    pause
    exit /b 1
)

:: Vérification de l'installation de MinGW
where gcc >nul 2>nul
if %ERRORLEVEL% neq 0 (
    echo MinGW n'est pas installé. Veuillez l'installer depuis https://www.mingw-w64.org/
    pause
    exit /b 1
)

:: Création du dossier de build
if not exist build mkdir build
cd build

:: Configuration avec CMake
cmake .. -G "MinGW Makefiles"

:: Compilation
mingw32-make

echo.
echo Installation terminée !
echo Pour tester l'exemple, exécutez : examples\termux_example.exe
pause 