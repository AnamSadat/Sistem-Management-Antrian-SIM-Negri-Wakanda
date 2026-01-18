#include "QueueService.h"
#include "../utils/InputHelper.h"

QueueService::QueueService() {
    head = tail = front = rear = NULL;
}

bool QueueService::isEmpty() {
    return tail == NULL;
}

void QueueService::insertDepan(string nama, string nik, string alamat,
                                string jenisKelamin, string jenisSim, string noHp) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->nik = nik;
    baru->alamat = alamat;
    baru->jenisKelamin = jenisKelamin;
    baru->jenisSim = jenisSim;
    baru->noHp = noHp;
    baru->next = NULL;
    
    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
    cout << "           -----------------------------------------\n";
    cout << "           |           Data Peserta Masuk          |\n";
    cout << "           -----------------------------------------\n";
}

void QueueService::insertBelakang(string nama, string nik, string alamat,
                                   string jenisKelamin, string jenisSim, string noHp) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->nik = nik;
    baru->alamat = alamat;
    baru->jenisKelamin = jenisKelamin;
    baru->jenisSim = jenisSim;
    baru->noHp = noHp;
    baru->next = NULL;
    
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
    cout << "           -----------------------------------------\n";
    cout << "           |          Data Peserta Masuk           |\n";
    cout << "           -----------------------------------------\n";
}


void QueueService::enqueue(string nama, string nik, string alamat,
                           string jenisKelamin, string jenisSim, string noHp) {
    insertBelakang(nama, nik, alamat, jenisKelamin, jenisSim, noHp);
    front = head;
    rear = tail;
}

void QueueService::enqueueDepan(string nama, string nik, string alamat,
                                 string jenisKelamin, string jenisSim, string noHp) {
    insertDepan(nama, nik, alamat, jenisKelamin, jenisSim, noHp);
    front = head;
    rear = tail;
}

Node* QueueService::dequeue() {
    if (isEmpty()) {
        cout << "           -----------------------------------------\n";
        cout << "           |           Antrian masih kosong        |\n";
        cout << "           -----------------------------------------\n";
        return NULL;
    }
    
    Node* hapus = head;
    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
    }
    front = head;
    return hapus;
}

void QueueService::lihatAntrian() {
    Node* bantu = head;
    int count = 1;
    
    if (isEmpty()) {
        cout << "----------------------------------------------------------------\n";
        cout << "                    Antrian Masih Kosong\n";
        cout << "----------------------------------------------------------------\n";
    } else {
        while (bantu != NULL) {
            cout << "----------------------------------------------------------------\n";
            cout << count++ << ".|" << "\t" << "Nama          : " << bantu->nama << endl;
            cout << "  |" << "\t" << "NIK           : " << bantu->nik << endl;
            cout << "  |" << "\t" << "Alamat        : " << bantu->alamat << endl;
            cout << "  |" << "\t" << "Jenis Kelamin : " << bantu->jenisKelamin << endl;
            cout << "  |" << "\t" << "Jenis SIM     : " << bantu->jenisSim << endl;
            cout << "  |" << "\t" << "Nomor HP      : " << bantu->noHp << endl;
            bantu = bantu->next;
        }
        cout << "----------------------------------------------------------------\n";
    }
}

void QueueService::lihatAntrianDepan() {
    if (isEmpty()) {
        cout << "----------------------------------------------------------------\n";
        cout << "                   Antrian Masih Kosong\n";
        cout << "----------------------------------------------------------------\n";
    } else {
        cout << "----------------------------------------------------------------\n";
        cout << "                   Antrian Depan Saat ini\n\n";
        cout << "                   Nama          : " << front->nama << endl;
        cout << "                   NIK           : " << front->nik << endl;
        cout << "                   Alamat        : " << front->alamat << endl;
        cout << "                   Jenis Kelamin : " << front->jenisKelamin << endl;
        cout << "                   Jenis SIM     : " << front->jenisSim << endl;
        cout << "                   Nomor HP      : " << front->noHp << endl;
        cout << "----------------------------------------------------------------\n";
    }
}


void QueueService::deleteByNik(string inputNik) {
    Node* hapus = head;
    Node* bantu = head;
    Node* sebelum = NULL;
    bool ditemukan = false;
    
    if (head == tail) {
        if (hapus->nik == inputNik) {
            head = tail = NULL;
            cout << "----------------------------------------------------------------\n";
            cout << "|                    Data telah dihapus                        |\n";
            cout << "----------------------------------------------------------------\n";
            return;
        } else {
            cout << "----------------------------------------------------------------\n";
            cout << "|                   Data tidak ditemukan                       |\n";
            cout << "----------------------------------------------------------------\n";
            return;
        }
    }
    
    while (bantu != NULL) {
        if (bantu->nik == inputNik) {
            hapus = bantu;
            ditemukan = true;
            break;
        }
        sebelum = bantu;
        bantu = bantu->next;
    }
    
    if (ditemukan) {
        if (hapus == head) {
            head = head->next;
            delete hapus;
        } else if (hapus == tail) {
            tail = sebelum;
            tail->next = NULL;
            delete hapus;
        } else {
            bantu = hapus->next;
            sebelum->next = bantu;
            delete hapus;
        }
        cout << "----------------------------------------------------------------\n";
        cout << "|                     Data telah dihapus                       |\n";
        cout << "----------------------------------------------------------------\n";
    } else {
        cout << "----------------------------------------------------------------\n";
        cout << "|                    Data tidak ditemukan                      |\n";
        cout << "----------------------------------------------------------------\n";
    }
}

void QueueService::search(string input) {
    Node* bantu = head;
    bool ditemukan = false;
    
    if (isEmpty()) {
        cout << "----------------------------------------------------------------\n";
        cout << "                     Antrian masih kosong\n";
        cout << "----------------------------------------------------------------\n";
    } else {
        while (bantu != NULL) {
            if (bantu->nik == input || bantu->noHp == input) {
                cout << "----------------------------------------------------------------\n";
                cout << "                        Data ditemukan\n";
                cout << "----------------------------------------------------------------\n";
                cout << "                    Nama          : " << bantu->nama << endl;
                cout << "                    NIK           : " << bantu->nik << endl;
                cout << "                    Alamat        : " << bantu->alamat << endl;
                cout << "                    Jenis Kelamin : " << bantu->jenisKelamin << endl;
                cout << "                    Jenis SIM     : " << bantu->jenisSim << endl;
                cout << "                    Nomor HP      : " << bantu->noHp << endl;
                cout << "----------------------------------------------------------------\n";
                ditemukan = true;
                return;
            }
            bantu = bantu->next;
        }
        if (!ditemukan) {
            cout << "----------------------------------------------------------------\n";
            cout << "|                   Data tidak ditemukan                       |\n";
            cout << "----------------------------------------------------------------\n";
        }
    }
}


void QueueService::updateData(string inputNik) {
    Node* bantu = head;
    bool ditemukan = false;
    InputHelper::clearScreen();
    
    while (bantu != NULL) {
        if (bantu->nik == inputNik) {
            cout << "----------------------------------------------------------------\n";
            cout << "|                          Data Anda                           |\n";
            cout << "----------------------------------------------------------------\n";
            cout << "Nama          : " << bantu->nama << endl;
            cout << "NIK           : " << bantu->nik << endl;
            cout << "Alamat        : " << bantu->alamat << endl;
            cout << "Jenis SIM     : " << bantu->jenisSim << endl;
            cout << "Jenis Kelamin : " << bantu->jenisKelamin << endl;
            cout << "No Hp         : " << bantu->noHp << endl;
            ditemukan = true;
            break;
        }
        bantu = bantu->next;
    }
    
    if (!ditemukan) {
        cout << "----------------------------------------------------------------\n";
        cout << "                   Data tidak ditemukan\n";
        cout << "----------------------------------------------------------------\n";
        return;
    }
    
    cout << endl;
    cout << "----------------------------------------------------------------\n";
    cout << "|                        Pilih kategori                        |\n";
    cout << "----------------------------------------------------------------\n";
    cout << "\t 1. Ubah Satu data\n";
    cout << "\t 2. Ubah semua data\n";
    cout << "\t 3. Cancel\n";
    int pilihanData;
    cout << "Masukan Pilihan(1/2/3) : "; cin >> pilihanData;
    InputHelper::clearScreen();
    cin.ignore();
    
    if (pilihanData == 1) {
        string dataUbah;
        cout << "----------------------------------------------------------------\n";
        cout << "|                          Pilih Data                          |\n";
        cout << "----------------------------------------------------------------\n";
        cout << " - nama\n - nik\n - alamat\n - jenis kelamin\n - jenis sim\n - no hp\n";
        cout << "Note : Masukan sesuai tulisan diatas\n";
        cout << "Masukan Data yang ingin di ubah : "; getline(cin, dataUbah);
        InputHelper::clearScreen();
        cout << "----------------------------------------------------------------\n";
        cout << "|                         Data Update                          |\n";
        cout << "----------------------------------------------------------------\n";
        
        if (dataUbah == "nama") {
            cout << "Masukan Data baru : "; getline(cin, bantu->nama);
        } else if (dataUbah == "nik") {
            cout << "Masukan Data baru : "; getline(cin, bantu->nik);
        } else if (dataUbah == "alamat") {
            cout << "Masukan Data baru : "; getline(cin, bantu->alamat);
        } else if (dataUbah == "jenis kelamin") {
            bantu->jenisKelamin = InputHelper::inputJenisKelamin();
        } else if (dataUbah == "jenis sim") {
            bantu->jenisSim = InputHelper::inputJenisSim();
        } else if (dataUbah == "no hp") {
            cout << "Masukan data baru : "; getline(cin, bantu->noHp);
        } else {
            cout << "Data tidak valid\n";
            return;
        }
        cout << "----------------------------------------------------------------\n";
        cout << "|                   Data berhasil di ubah                      |\n";
        cout << "----------------------------------------------------------------\n";
    } else if (pilihanData == 2) {
        InputHelper::clearScreen();
        InputHelper::inputDataPeserta(bantu->nama, bantu->nik, bantu->alamat,
                                       bantu->jenisKelamin, bantu->jenisSim, bantu->noHp);
        cout << "----------------------------------------------------------------\n";
        cout << "|                   Data berhasil diubah                       |\n";
        cout << "----------------------------------------------------------------\n";
    } else if (pilihanData == 3) {
        cout << "----------------------------------------------------------------\n";
        cout << "|                       Terima Kasih                           |\n";
        cout << "----------------------------------------------------------------\n";
    } else {
        cout << "----------------------------------------------------------------\n";
        cout << "|             Mohon masukan pilihan dengan benar               |\n";
        cout << "----------------------------------------------------------------\n";
    }
}

void QueueService::statistik() {
    Node* bantu = head;
    int jumlahLakilaki = 0, jumlahPerempuan = 0;
    int jumlahSimA = 0, jumlahSimB = 0, jumlahSimC = 0;
    
    if (isEmpty()) {
        cout << "----------------------------------------------------------------\n";
        cout << "                    Antrian masih kosong\n";
        cout << "----------------------------------------------------------------\n";
        return;
    }
    
    while (bantu != NULL) {
        if (bantu->jenisKelamin == "l") jumlahLakilaki++;
        else if (bantu->jenisKelamin == "p") jumlahPerempuan++;
        
        if (bantu->jenisSim == "a") jumlahSimA++;
        else if (bantu->jenisSim == "b") jumlahSimB++;
        else if (bantu->jenisSim == "c") jumlahSimC++;
        
        bantu = bantu->next;
    }
    
    cout << "----------------------------------------------------------------\n";
    cout << "             Statistik Jenis Kelamin dan Jenis SIM\n";
    cout << "----------------------------------------------------------------\n";
    cout << "                Jumlah peserta Laki-laki  : " << jumlahLakilaki << endl;
    cout << "                Jumlah peserta Perempuan  : " << jumlahPerempuan << endl;
    cout << "----------------------------------------------------------------\n";
    cout << "                      Jumlah SIM A : " << jumlahSimA << endl;
    cout << "                      Jumlah SIM B : " << jumlahSimB << endl;
    cout << "                      Jumlah SIM C : " << jumlahSimC << endl;
    cout << "----------------------------------------------------------------\n";
}
