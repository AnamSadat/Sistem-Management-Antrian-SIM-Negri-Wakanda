#include "RiwayatService.h"

RiwayatService::RiwayatService() {
    jumlahRiwayat = 0;
}

bool RiwayatService::isEmpty() {
    return jumlahRiwayat == 0;
}

bool RiwayatService::isFull() {
    return jumlahRiwayat == MAX_RIWAYAT;
}

int RiwayatService::getJumlahRiwayat() {
    return jumlahRiwayat;
}

void RiwayatService::tambahRiwayat(string nama, string nik, string alamat,
                                    string jenisKelamin, string jenisSim, string noHp,
                                    const char* harga, int uangBayar, int kembalian) {
    if (isFull()) {
        cout << "------------------------------\n";
        cout << "       Riwayat Penuh\n";
        cout << "------------------------------\n";
        return;
    }
    
    riwayatAntrian[jumlahRiwayat].Nama = nama;
    riwayatAntrian[jumlahRiwayat].Nik = nik;
    riwayatAntrian[jumlahRiwayat].Alamat = alamat;
    riwayatAntrian[jumlahRiwayat].JenisKelamin = jenisKelamin;
    riwayatAntrian[jumlahRiwayat].JenisSim = jenisSim;
    riwayatAntrian[jumlahRiwayat].NoHp = noHp;
    strcpy(hargaSim[jumlahRiwayat], harga);
    bayar[jumlahRiwayat] = uangBayar;
    uangKembali[jumlahRiwayat] = kembalian;
    jumlahRiwayat++;
    
    cout << "                   Riwayat telah ditambahkan\n";
    cout << "           -----------------------------------------\n";
}

void RiwayatService::lihatRiwayat() {
    if (isEmpty()) {
        cout << "------------------------------\n";
        cout << "      Tidak ada riwayat\n";
        cout << "------------------------------\n";
        return;
    }
    
    cout << "------------------------------\n";
    cout << "      Riwayat Pembayaran\n";
    
    for (int i = 0; i < jumlahRiwayat; i++) {
        cout << "------------------------------\n";
        cout << "Nama           : " << riwayatAntrian[i].Nama << endl;
        cout << "NIK            : " << riwayatAntrian[i].Nik << endl;
        cout << "Alamat         : " << riwayatAntrian[i].Alamat << endl;
        cout << "Jenis Kelamin  : " << riwayatAntrian[i].JenisKelamin << endl;
        cout << "Jenis SIM      : " << riwayatAntrian[i].JenisSim << endl;
        cout << "Nomor HP       : " << riwayatAntrian[i].NoHp << endl;
        cout << "Harga SIM      : " << hargaSim[i] << endl;
        cout << "Uang bayar     : " << bayar[i] << endl;
        cout << "Uang Kembalian : " << uangKembali[i] << endl;
    }
    cout << "------------------------------\n";
}

void RiwayatService::resetRiwayat() {
    if (isEmpty()) {
        cout << "           ------------------------------\n";
        cout << "                  Riwayat Kosong\n";
        cout << "           ------------------------------\n";
        return;
    }
    
    for (int i = 0; i < jumlahRiwayat; i++) {
        riwayatAntrian[i].Nama = " ";
        riwayatAntrian[i].Nik = " ";
        riwayatAntrian[i].Alamat = " ";
        riwayatAntrian[i].JenisKelamin = " ";
        riwayatAntrian[i].JenisSim = " ";
        riwayatAntrian[i].NoHp = " ";
    }
    jumlahRiwayat = 0;
    
    cout << "------------------------------\n";
    cout << "    Semua riwayat telah dihapus\n";
    cout << "------------------------------\n";
}
