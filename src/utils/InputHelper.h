#ifndef INPUT_HELPER_H
#define INPUT_HELPER_H

#include <iostream>
#include <string>
#include <limits>
using namespace std;

namespace InputHelper {
    // Initialize console
    void initConsole();
    
    // Clear input buffer
    void clearInputBuffer();
    
    // Validasi jenis kelamin (l/p)
    string inputJenisKelamin();
    
    // Validasi jenis SIM (a/b/c)
    string inputJenisSim();
    
    // Input data peserta lengkap
    void inputDataPeserta(string& nama, string& nik, string& alamat, 
                          string& jenisKelamin, string& jenisSim, string& noHp);
    
    // Clear screen
    void clearScreen();
    
    // Pause
    void pause();
}

#endif
