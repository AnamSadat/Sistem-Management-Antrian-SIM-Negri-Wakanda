@echo off
echo Compiling Sistem Antrian SIM...

if not exist output mkdir output

g++ -std=c++11 -Wall -static -I src ^
    src/main.cpp ^
    src/ui/Menu.cpp ^
    src/services/QueueService.cpp ^
    src/services/RiwayatService.cpp ^
    src/services/PaymentService.cpp ^
    src/utils/InputHelper.cpp ^
    -o output/SistemAntrianSIM.exe

if %ERRORLEVEL% EQU 0 (
    echo Build successful!
    echo Run: output\SistemAntrianSIM.exe
) else (
    echo Build failed!
)
