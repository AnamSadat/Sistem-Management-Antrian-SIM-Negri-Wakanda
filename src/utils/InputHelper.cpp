#include "InputHelper.h"
#include <cstdlib>
#include <limits>
#include <windows.h>

namespace InputHelper {
    void clearInputBuffer() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    void initConsole() {
        // Ensure console is properly initialized
        SetConsoleOutputCP(CP_UTF8);
        cout.flush();
    }

    string inputJenisKelamin() {
        string jk;
        cout << "                  Jenis Kelamin (l/p): "; 
        getline(cin, jk);
        while (jk != "l" && jk != "p") {
            cout << "----------------------------------------------------------------\n";
            cout << "                  Maaf jenis tidak valid\n";
            cout << "----------------------------------------------------------------\n";
            cout << "                  Jenis Kelamin (l/p): "; 
            getline(cin, jk);
        }
        return jk;
    }

    string inputJenisSim() {
        string sim;
        cout << "                  Jenis SIM (a/b/c)  : "; 
        getline(cin, sim);
        while (sim != "a" && sim != "b" && sim != "c") {
            cout << "----------------------------------------------------------------\n";
            cout << "                  Maaf jenis tidak valid\n";
            cout << "----------------------------------------------------------------\n";
            cout << "                  Jenis SIM (a/b/c)  : "; 
            getline(cin, sim);
        }
        return sim;
    }

    void inputDataPeserta(string& nama, string& nik, string& alamat,
                          string& jenisKelamin, string& jenisSim, string& noHp) {
        clearInputBuffer();
        cout << "                  Nama               : "; getline(cin, nama);
        cout << "                  NIK                : "; getline(cin, nik);
        cout << "                  Alamat             : "; getline(cin, alamat);
        jenisKelamin = inputJenisKelamin();
        jenisSim = inputJenisSim();
        cout << "                  Nomor HP           : "; getline(cin, noHp);
    }

    void clearScreen() {
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        DWORD count;
        DWORD cellCount;
        COORD homeCoords = {0, 0};

        if (hStdOut == INVALID_HANDLE_VALUE) return;
        if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
        
        cellCount = csbi.dwSize.X * csbi.dwSize.Y;
        FillConsoleOutputCharacter(hStdOut, ' ', cellCount, homeCoords, &count);
        FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count);
        SetConsoleCursorPosition(hStdOut, homeCoords);
    }

    void pause() {
        system("pause");
    }
}
