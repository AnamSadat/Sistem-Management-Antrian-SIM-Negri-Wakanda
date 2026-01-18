#include "PaymentService.h"
#include "../utils/InputHelper.h"
#include <cstdlib>

PaymentService::PaymentService(QueueService* qs, RiwayatService* rs) {
    queueService = qs;
    riwayatService = rs;
}

int PaymentService::getHargaSim(string jenisSim) {
    if (jenisSim == "a") return 750000;
    if (jenisSim == "b") return 500000;
    if (jenisSim == "c") return 300000;
    return 0;
}

void PaymentService::prosesPembayaran() {
    if (queueService->isEmpty()) {
        cout << "           -----------------------------------------\n";
        cout << "           |           Antrian masih kosong        |\n";
        cout << "           -----------------------------------------\n";
        return;
    }
    
    if (riwayatService->isFull()) {
        cout << "Riwayat Penuh\n";
        cout << "Mohon reset riwayat dulu\n";
        return;
    }
    
    Node* peserta = queueService->getHead();
    string dNama = peserta->nama;
    string dNik = peserta->nik;
    string dAlamat = peserta->alamat;
    string dJenisKelamin = peserta->jenisKelamin;
    string dJenisSim = peserta->jenisSim;
    string dNoHp = peserta->noHp;
    
    int hargaSIM = getHargaSim(dJenisSim);
    
    if (hargaSIM == 0) {
        cout << "                    Jenis SIM tidak valid" << endl;
        return;
    }
    
    cout << "----------------------------------------------------------------\n";
    if (dJenisSim == "a") {
        cout << "          SIM anda adalah A dengan harga Rp.750.000" << endl;
    } else if (dJenisSim == "b") {
        cout << "          SIM anda adalah B dengan harga Rp.500.000" << endl;
    } else {
        cout << "          SIM anda adalah C dengan harga Rp.300.000" << endl;
    }
    cout << "           -----------------------------------------\n";

    int uangBayar = 0;
    int uangKembali = 0;
    int sisaKurang = 0;
    int bayarSementara = 0;
    bool kurang = false;
    
    while (true) {
        int inputBayar;
        cout << "                 Masukkan uang bayar: ";
        cin >> inputBayar;
        
        if (kurang) {
            uangKembali = inputBayar - sisaKurang;
            uangBayar = inputBayar + bayarSementara;
            if (uangKembali >= 0) break;
        } else {
            bayarSementara = inputBayar;
            uangBayar = inputBayar;
            uangKembali = inputBayar - hargaSIM;
        }
        
        if (uangKembali < 0) {
            sisaKurang = -uangKembali;
            uangKembali = 0;
            cout << "           -----------------------------------------\n";
            cout << "                       Kurang: " << sisaKurang << endl;
            cout << "            Uang kurang silahkan tambah yang kurang\n";
            kurang = true;
            InputHelper::pause();
        } else {
            break;
        }
    }
    
    // Proses dequeue
    queueService->dequeue();
    
    InputHelper::clearScreen();
    cout << "           -----------------------------------------\n";
    cout << "                     Pembayaran berhasil" << endl;
    cout << "                  Uang kembalian anda : " << uangKembali << endl;
    cout << "           -----------------------------------------\n";
    
    // Simpan ke riwayat
    char hargaStr[20];
    sprintf(hargaStr, "%d", hargaSIM);
    riwayatService->tambahRiwayat(dNama, dNik, dAlamat, dJenisKelamin, dJenisSim, dNoHp,
                                   hargaStr, uangBayar, uangKembali);
}
