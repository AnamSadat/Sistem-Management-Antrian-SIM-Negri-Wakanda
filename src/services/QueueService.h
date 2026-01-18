#ifndef QUEUE_SERVICE_H
#define QUEUE_SERVICE_H

#include "../models/Node.h"
#include <iostream>
using namespace std;

class QueueService {
private:
    Node* head;
    Node* tail;
    Node* front;
    Node* rear;

    // Insert di depan (VIP)
    void insertDepan(string nama, string nik, string alamat, 
                     string jenisKelamin, string jenisSim, string noHp);
    
    // Insert di belakang (Regular)
    void insertBelakang(string nama, string nik, string alamat, 
                        string jenisKelamin, string jenisSim, string noHp);

public:
    QueueService();
    
    bool isEmpty();
    
    // Enqueue regular
    void enqueue(string nama, string nik, string alamat, 
                 string jenisKelamin, string jenisSim, string noHp);
    
    // Enqueue VIP (depan)
    void enqueueDepan(string nama, string nik, string alamat, 
                      string jenisKelamin, string jenisSim, string noHp);
    
    // Dequeue (ambil dari depan)
    Node* dequeue();
    
    // Lihat semua antrian
    void lihatAntrian();
    
    // Lihat antrian paling depan
    void lihatAntrianDepan();
    
    // Hapus berdasarkan NIK
    void deleteByNik(string inputNik);
    
    // Cari berdasarkan NIK atau No HP
    void search(string input);
    
    // Update data berdasarkan NIK
    void updateData(string inputNik);
    
    // Statistik
    void statistik();
    
    // Getter untuk head (dibutuhkan untuk pembayaran)
    Node* getHead() { return head; }
};

#endif
