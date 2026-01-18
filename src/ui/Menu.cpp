#include "Menu.h"

Menu::Menu() : paymentService(&queueService, &riwayatService) {}

void Menu::tampilkanMenu() {
    cout << "================================================================\n";
    cout << "----------------------------------------------------------------\n";
    cout << "\t       Pendaftaran SIM Negara Wakanda 2023\n";
    cout << "                   1. Daftar Antrian\n";
    cout << "                   2. VIP\n";
    cout << "                   3. Konfirmasi Pembayaran\n";
    cout << "                   4. Lihat antrian\n";
    cout << "                   5. Cek antrian paling depan\n";
    cout << "                   6. Hapus data dalam antrian\n";
    cout << "                   7. Mencari data dalam antrian\n";
    cout << "                   8. Pembaruan data dalam antrian\n";
    cout << "                   9. Tampilkan statistik\n";
    cout << "                   10. Exit\n";
    cout << "                   11. Riwayat\n";
    cout << "                   12. Reset Riwayat\n";
    cout << "----------------------------------------------------------------\n";
    cout << "================================================================\n";
}

void Menu::daftarAntrian() {
    InputHelper::clearScreen();
    cout << "----------------------------------------------------------------\n";
    cout << "                       Masukan data diri\n";
    cout << "----------------------------------------------------------------\n";
    
    string nama, nik, alamat, jenisKelamin, jenisSim, noHp;
    InputHelper::inputDataPeserta(nama, nik, alamat, jenisKelamin, jenisSim, noHp);
    queueService.enqueue(nama, nik, alamat, jenisKelamin, jenisSim, noHp);
    
    InputHelper::pause();
    InputHelper::clearScreen();
}

void Menu::daftarVIP() {
    InputHelper::clearScreen();
    cout << "----------------------------------------------------------------\n";
    cout << "                      Masukan Data Diri\n";
    cout << "----------------------------------------------------------------\n";
    
    string nama, nik, alamat, jenisKelamin, jenisSim, noHp;
    InputHelper::inputDataPeserta(nama, nik, alamat, jenisKelamin, jenisSim, noHp);
    queueService.enqueueDepan(nama, nik, alamat, jenisKelamin, jenisSim, noHp);
    
    InputHelper::pause();
    InputHelper::clearScreen();
}


void Menu::konfirmasiPembayaran() {
    InputHelper::clearScreen();
    paymentService.prosesPembayaran();
    InputHelper::pause();
    InputHelper::clearScreen();
}

void Menu::lihatAntrian() {
    InputHelper::clearScreen();
    queueService.lihatAntrian();
    InputHelper::pause();
    InputHelper::clearScreen();
}

void Menu::cekAntrianDepan() {
    InputHelper::clearScreen();
    queueService.lihatAntrianDepan();
    InputHelper::pause();
    InputHelper::clearScreen();
}

void Menu::hapusData() {
    InputHelper::clearScreen();
    if (queueService.isEmpty()) {
        cout << "----------------------------------------------------------------\n";
        cout << "                     Antrian masih Kosong\n";
        cout << "----------------------------------------------------------------\n";
    } else {
        string inputNik;
        cout << "----------------------------------------------------------------\n";
        cout << "                  Masukan NIK anda : "; cin >> inputNik;
        cout << "----------------------------------------------------------------\n";
        InputHelper::clearScreen();
        queueService.deleteByNik(inputNik);
    }
    InputHelper::pause();
    InputHelper::clearScreen();
}

void Menu::cariData() {
    InputHelper::clearScreen();
    if (queueService.isEmpty()) {
        cout << "----------------------------------------------------------------\n";
        cout << "                      Antrian masih Kosong\n";
        cout << "----------------------------------------------------------------\n";
    } else {
        string input;
        cout << "Masukan NIK/Nomor HP : ";
        cin >> input;
        InputHelper::clearScreen();
        queueService.search(input);
    }
    InputHelper::pause();
    InputHelper::clearScreen();
}

void Menu::updateData() {
    InputHelper::clearScreen();
    if (queueService.isEmpty()) {
        cout << "----------------------------------------------------------------\n";
        cout << "                       Antrian masih Kosong\n";
        cout << "----------------------------------------------------------------\n";
    } else {
        string inputNik;
        cout << "----------------------------------------------------------------\n";
        cout << "                         Pembaruan data\n";
        cout << "================================================================\n\n";
        cout << "                         Masukan NIK anda: ";
        cin >> inputNik;
        InputHelper::clearScreen();
        queueService.updateData(inputNik);
    }
    InputHelper::pause();
    InputHelper::clearScreen();
}

void Menu::tampilkanStatistik() {
    InputHelper::clearScreen();
    queueService.statistik();
    InputHelper::pause();
    InputHelper::clearScreen();
}

void Menu::lihatRiwayat() {
    InputHelper::clearScreen();
    riwayatService.lihatRiwayat();
    InputHelper::pause();
    InputHelper::clearScreen();
}

void Menu::resetRiwayat() {
    InputHelper::clearScreen();
    riwayatService.resetRiwayat();
    InputHelper::pause();
    InputHelper::clearScreen();
}

void Menu::run() {
    int pilihan = 0;
    
    while (pilihan != 10) {
        tampilkanMenu();
        cout << "Pilih Menu (1-12): ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:  daftarAntrian(); break;
            case 2:  daftarVIP(); break;
            case 3:  konfirmasiPembayaran(); break;
            case 4:  lihatAntrian(); break;
            case 5:  cekAntrianDepan(); break;
            case 6:  hapusData(); break;
            case 7:  cariData(); break;
            case 8:  updateData(); break;
            case 9:  tampilkanStatistik(); break;
            case 10:
                InputHelper::clearScreen();
                cout << "================================================================\n";
                cout << "----------------------------------------------------------------\n";
                cout << "                       Terima kasihhhh\n";
                cout << "----------------------------------------------------------------\n";
                cout << "================================================================\n";
                break;
            case 11: lihatRiwayat(); break;
            case 12: resetRiwayat(); break;
            default:
                cout << "----------------------------------------------------------------\n";
                cout << "                     Pilihan tidak valid\n";
                cout << "----------------------------------------------------------------\n";
                InputHelper::pause();
                InputHelper::clearScreen();
        }
    }
}
