#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

// Node untuk linked list antrian
struct Node {
    string nama;
    string nik;
    string alamat;
    string jenisKelamin;
    string jenisSim;
    string noHp;
    Node* next;
};

// Struct untuk menyimpan riwayat pembayaran
struct Riwayat {
    string Nama;
    string Nik;
    string Alamat;
    string JenisKelamin;
    string JenisSim;
    string NoHp;
};

#endif
