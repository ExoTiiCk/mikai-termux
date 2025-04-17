@echo off
echo Transfert des fichiers vers l'émulateur Android...

:: Vérification de l'installation d'ADB
where adb >nul 2>nul
if %ERRORLEVEL% neq 0 (
    echo ADB n'est pas installé. Veuillez l'installer via Android Studio.
    pause
    exit /b 1
)

:: Création d'un dossier temporaire
if not exist temp mkdir temp
xcopy /E /I /Y source temp\source
xcopy /E /I /Y examples temp\examples
copy install-termux.sh temp\
copy README-TERMUX.md temp\

:: Transfert vers l'émulateur
adb push temp /data/data/com.termux/files/home/mikai

:: Nettoyage
rmdir /S /Q temp

echo.
echo Transfert terminé !
echo Pour continuer :
echo 1. Ouvrez Termux dans l'émulateur
echo 2. Exécutez : cd ~/mikai
echo 3. Exécutez : chmod +x install-termux.sh
echo 4. Exécutez : ./install-termux.sh
pause 