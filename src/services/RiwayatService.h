#ifndef RIWAYAT_SERVICE_H
#define RIWAYAT_SERVICE_H

#include "../models/Node.h"
#include <iostream>
#include <cstring>
using namespace std;

class RiwayatService {
private:
    static const int MAX_RIWAYAT = 100;
    Riwayat riwayatAntrian[MAX_RIWAYAT];
    char hargaSim[MAX_RIWAYAT][100];
    int bayar[MAX_RIWAYAT];
    int uangKembali[MAX_RIWAYAT];
    int jumlahRiwayat;

public:
    RiwayatService();
    
    bool isEmpty();
    bool isFull();
    int getJumlahRiwayat();
    
    // Tambah riwayat
    void tambahRiwayat(string nama, string nik, string alamat, 
                       string jenisKelamin, string jenisSim, string noHp,
                       const char* harga, int uangBayar, int kembalian);
    
    // Lihat semua riwayat
    void lihatRiwayat();
    
    // Reset semua riwayat
    void resetRiwayat();
};

#endif
