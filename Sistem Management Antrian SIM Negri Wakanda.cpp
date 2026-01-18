#include <iostream> // untuk mengaktifkan cout, cin dan endl
#include <string.h> // untuk mengaktifkan tipe data karakter
using namespace std;

// Node dalam linked list
struct Node{
    string nama; 
    string nik;
    string alamat; 
    string jenisKelamin;
    string jenisSim;
    string noHp; //deklarasi tipe data string/ karakter
    Node *next; // deklarasi pointer next
};

struct queue{
    Node *front;
    Node *rear;
};

struct Riwayat{
    string Nama;
    string Nik;
    string Alamat;
    string JenisKelamin;
    string JenisSim;
    string NoHp;
};

//deklarasi global
Node *head, *tail, *front, *rear; // deklarasi variabel pointer head, tail, front dan rear
char hargaSim[100][100];
const int maxRiwayat = 100;
int jumlahRiwayat = 0;
int bayar[100]; 
int uangKembali[100];
Riwayat riwayatAntrian[100];

// inisialisasi awal bahwa head dan tail bernilai NULL
void init(){
    head = front = tail = rear = NULL; //deklarasi variabel pointer bernilai NULL
}

//pengecekan apakah antrian kosong atau tidak?
bool isEmpty(){
    return tail == NULL ; //deklarasi tail sebagai NULL
}

bool isEmptyRiwayat(){
    return jumlahRiwayat == 0;
}

// tambah riwayat pembayaran
void tambahRiwayat(
    string nama, 
    string nik, 
    string alamat, 
    string jenisKelamin, 
    string jenisSim, 
    string noHp
    ){
    if(jumlahRiwayat == maxRiwayat){
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
    jumlahRiwayat++;
    cout << "                   Riwayat telah ditamabahkan\n";
    cout << "           -----------------------------------------\n";
}

// hapus semua riwayat pembayaran
void resetRiwayat(){
    if(isEmptyRiwayat()){
        cout << "           ------------------------------\n";
        cout << "                  Riwayat Kosong\n";
        cout << "           ------------------------------\n";
        return;
    } 

    for(int i = 0; i < jumlahRiwayat; i++){
        riwayatAntrian[i].Nama = " ";
        riwayatAntrian[i].Nik = " ";
        riwayatAntrian[i].Alamat = " ";
        riwayatAntrian[i].JenisKelamin = " ";
        riwayatAntrian[i].JenisSim = " ";
        riwayatAntrian[i].NoHp = " ";
    }
    jumlahRiwayat = 0; // Set jumlah riwayat kembali ke 0 untuk menunjukkan bahwa semua data telah dihapus.
    cout << "------------------------------\n";
    cout << "    Semua riwayat telah dihapus\n";
    cout << "------------------------------\n";
}

// tambah antrian depan(VIP)
void insertDepan(
    string nama, 
    string nik, 
    string alamat, 
    string jenisKelamin, 
    string jenisSim, 
    string noHp
    ){
    // pembuatan node baru
    Node *baru;
    baru = new Node;
    // input data node dari hasil input manual menggunakan parameter
    baru->nama = nama;
    baru->nik = nik;
    baru->alamat = alamat;
    baru->jenisKelamin = jenisKelamin;
    baru->jenisSim = jenisSim;
    baru->noHp = noHp;
    // pengkondisian antrian kosong atau tidak
    if(isEmpty()){
        head = tail = baru; //menjadikan head dan tail berada di node baru
        tail->next = NULL; //tail yang menunjuk ke node selanjutnya adalah null
    }else{ 
        baru->next = head; // memasukan node baru ke antrian depan
        head = baru; // deklarasi head berada di node baru
    }
    cout << "           -----------------------------------------\n";
    cout << "           |           Data Peserta Masuk          |\n";
    cout << "           -----------------------------------------\n";
}

// tambah antrian belakang(Regular)
void insertBelakang(
    string nama, 
    string nik, 
    string alamat, 
    string jenisKelamin, 
    string jenisSim, 
    string noHp
    ){
    //Membuat Node baru
    Node *baru;
    baru = new Node;
    // input data node dari hasil input manual menggunakan parameter
    baru->nama = nama;
    baru->nik = nik;
    baru->alamat = alamat;
    baru->jenisKelamin = jenisKelamin;
    baru->jenisSim = jenisSim;
    baru->noHp = noHp;
    // pengkondisian antrian kosong atau tidak
    if(isEmpty()){
        head = tail = baru;
        tail->next = NULL; //tail menunjuk node selanjutnya bernilai NULL
    }else{
        tail->next = baru; //tail menunjuk node selanjutnya bernilai node baru
        tail = baru; // posisi tail dipindahkan ke node baru
    }
    cout << "           -----------------------------------------\n";
    cout << "           |          Data Peserta Masuk           |\n";
    cout << "           -----------------------------------------\n";
}

// proses penambahan antrian dalam queue
void enqueue(
    string nama, 
    string nik, 
    string alamat, 
    string jenisKelamin, 
    string jenisSim, 
    string noHp
    ){
    insertBelakang(nama, nik, alamat, jenisKelamin, jenisSim, noHp);
    front = head; //front diposisikan berada dihead
    rear = tail; //rear diposisikan berada ditail
}

// proses pengambilan antrian dalam queue
void enqueueDepan(
    string nama, 
    string nik, 
    string alamat, 
    string jenisKelamin, 
    string jenisSim, 
    string noHp
    ){
    insertDepan(nama, nik, alamat, jenisKelamin, jenisSim, noHp);
    front = head;
    rear = tail;
}

// pembayaran sekaligus antrian depan dihapus
void pembayaran() {
    if(jumlahRiwayat == maxRiwayat){
        cout << "Riwayat Penuh\n";
        cout << "Mohon reset riwayat dulu\n";
        return;
    }

    // deklarasi variabel pointer hapus berada dihead
    Node *hapus = head; 
    string dNama = hapus->nama;
    string dNik = hapus->nik;
    string dAlamat = hapus->alamat;
    string dJenisKelamin = hapus->jenisKelamin;
    string dJenisSim = hapus->jenisSim;
    string dNoHp = hapus->noHp;
    int hargaSIM = 0;
    cout << "----------------------------------------------------------------\n";
    // pengecekkan jenis sim
    if (hapus->jenisSim == "a") {
        cout << "          SIM anda adalah A dengan harga Rp.750.000" << endl;
        hargaSIM = 750000;
    } else if (hapus->jenisSim == "b") {
        cout << "          SIM anda adalah B dengan harga Rp.500.000" << endl;
        hargaSIM = 500000;
    } else if (hapus->jenisSim == "c") {
        cout << "          SIM anda adalah C dengan harga Rp.300.000" << endl;
        hargaSIM = 300000;
    } else {
        cout << "                    Jenis SIM tidak valid" << endl;
        return;
    }
    
    int sisaKurang; //deklarasi variabel integer
    int bayarSementara[100];  
    bool benar = false;
    cout << "           -----------------------------------------\n";
    //bagian pembayaran
    while(true){
        cout << "                 Masukkan uang bayar: ";
        cin >> bayar[jumlahRiwayat];

        if(benar){ //cek kondisi variabel benar bernilai true
            uangKembali[jumlahRiwayat] = bayar[jumlahRiwayat] - sisaKurang; 
            bayar[jumlahRiwayat] += bayarSementara[jumlahRiwayat];
            if(uangKembali[jumlahRiwayat] >= hargaSIM) break;
        }

        //proses hitung
        bayarSementara[jumlahRiwayat] = bayar[jumlahRiwayat]; //disimpan divariabel bayarSementara untuk antisipasi pembayaran kurang
        uangKembali[jumlahRiwayat] = bayar[jumlahRiwayat] - hargaSIM; //deklarasi pengurangan

        if(uangKembali[jumlahRiwayat] < 0){ 
            sisaKurang =  -uangKembali[jumlahRiwayat];
            uangKembali[jumlahRiwayat] = 0;
            bayar[jumlahRiwayat] = 0; 
            cout << "           -----------------------------------------\n";
            cout << "                       Kurang: " << sisaKurang << endl;
            cout << "            Uang kurang silahkan tambah yang kurang\n";
            benar = true; //mengubah nilai benar menjadi true
            system("pause");
        }else{ //kondisi ketika uang cukup
            break;
        }
    }
    cout << "           =========================================\n\n";
    cout << "           =========================================\n";
    // jika sim a dan uang bayar lebih besar sama dengan 750.000
    if (hapus->jenisSim == "a") {
        system("cls"); //clear tampilan
        strcpy(hargaSim[jumlahRiwayat], "750000");
        cout << "           -----------------------------------------\n";
        cout << "                     Pembayaran berhasil" << endl;
        cout << "                  Uang kembalian anda : " << uangKembali[jumlahRiwayat] << endl;
        cout << "           -----------------------------------------\n";
        if(head == tail){ // jika node hanya satu
            head = tail = NULL;
            tambahRiwayat(dNama, dNik, dAlamat, dJenisKelamin, dJenisSim, dNoHp);
            return;
        }
        head = head->next; // memindahkan head ke node selanjutnya
        delete hapus; //menghapus node
    } else if (hapus->jenisSim == "b") { // jika sim b dan uang bayar lebih besar sama dengan 500.000
        uangKembali[jumlahRiwayat] = bayar[jumlahRiwayat] - 500000; //deklarasi type data variabel  uangKembali adalah integer dan diberi nilai input bayar dikurangi 500.000
        system("cls");
        strcpy(hargaSim[jumlahRiwayat], "500000");
        cout << "                     Pembayaran berhasil" << endl;
        cout << "                  Uang kembalian anda : " << uangKembali[jumlahRiwayat] << endl;
        cout << "           -----------------------------------------\n";
        if(head == tail){
            head = tail = NULL;
            tambahRiwayat(dNama, dNik, dAlamat, dJenisKelamin, dJenisSim, dNoHp);
            return;
        }
        head = head->next;
        delete hapus;
    } else if (hapus->jenisSim == "c") { // jika sim c dan uang bayar lebih besar sama dengan 300.000
        uangKembali[jumlahRiwayat] = bayar[jumlahRiwayat] - 300000; //deklarasi type data variabel  uangKembali adalah integer dan diberi nilai input bayar dikurangi 300.000
        system("cls");
        strcpy(hargaSim[jumlahRiwayat], "300000");
        cout << "                     Pembayaran berhasil" << endl;
        cout << "                  Uang kembalian anda : " << uangKembali[jumlahRiwayat] << endl;
        cout << "           -----------------------------------------\n";
        if(head == tail){
            head = tail = NULL;
            tambahRiwayat(dNama, dNik, dAlamat, dJenisKelamin, dJenisSim, dNoHp);
            return;
        }
        head = head->next;
        delete hapus;
    } else {
        cout << "                      Uang tidak cukup\n";
        cout << "             Mohon lakukan pembayaran dengan benar" << endl;
        cout << "           -----------------------------------------\n";
    }
    tambahRiwayat(dNama, dNik, dAlamat, dJenisKelamin, dJenisSim, dNoHp);
}

void lihatRiwayat(){
    if(jumlahRiwayat == 0){
        cout << "------------------------------\n";
        cout << "      Tidak ada riwayat\n";
        cout << "------------------------------\n";
        return;
    }
    
    cout << "------------------------------\n";
    cout << "      Riwayat Pembayaran\n";

    for(int i = 0; i < jumlahRiwayat; i++){
        cout << "------------------------------\n";
        cout <<"Nama           : " << riwayatAntrian[i].Nama << endl;
        cout <<"NIK            : " << riwayatAntrian[i].Nik << endl;
        cout <<"Alamat         : " << riwayatAntrian[i].Alamat << endl;
        cout <<"Jenis Kelamin  : " << riwayatAntrian[i].JenisKelamin << endl;
        cout <<"Jenis SIM      : " << riwayatAntrian[i].JenisSim << endl;
        cout <<"Nomor HP       : " << riwayatAntrian[i].NoHp << endl;
        cout <<"Harga SIM      : " << hargaSim[i] << endl;
        cout <<"Uang bayar     : " << bayar[i] << endl;
        cout <<"Uang Kembalian : " << uangKembali[i] << endl;
    }
    cout << "------------------------------\n";
}

//operasi pengambilan antrian dari queue
void dequeue(){
    if(isEmpty()){
        cout << "           -----------------------------------------\n";
        cout << "           |           Antrian masih kosong        |\n";
        cout << "           -----------------------------------------\n";
    }else{
        pembayaran();
        front = head; //front diposisikan dihead
    }
}

//lihat antrian
void lihatAntrian(){
    Node *bantu = head; //deklarasi pointer bantu dengan diposisikan dihead
    int count = 1; // deklarasi variabel count diberi nilai 1

    if(isEmpty()){
        cout << "----------------------------------------------------------------\n";
        cout << "                    Antrian Masih Kosong\n";  
        cout << "----------------------------------------------------------------\n";
    }else{
        // melakukan iterasi ke setiap node menggunakan pointer bantu, selama bantu tidak sama dengan NULL maka iterasi tetap dilakukan
        while(bantu != NULL){
            cout << "----------------------------------------------------------------\n";
            cout << count++ << ".|" << "\t"<< "Nama          : " <<  bantu->nama << endl; //increment count untuk nomor antrian
            cout << "  |" << "\t" << "NIK           : " << bantu->nik << endl;
            cout << "  |" << "\t" << "Alamat        : " << bantu->alamat << endl;
            cout << "  |" << "\t" << "Jenis Kelamin : " << bantu->jenisKelamin << endl;
            cout << "  |" << "\t" << "Jenia SIM     : " << bantu->jenisSim << endl;
            cout << "  |" << "\t" << "Nomor HP      : " << bantu->noHp << endl;
            bantu = bantu->next;
        }
        cout << "----------------------------------------------------------------\n";
    }
}

// antrian paling depan
void lihatAntrianDepan(){
    if (isEmpty()){
        cout << "----------------------------------------------------------------\n";
        cout << "                   Antrian Masih Kosong\n";
        cout << "----------------------------------------------------------------\n";
    }else{
        cout << "----------------------------------------------------------------\n";
        cout << "                   Antrian Depan Saat ini\n\n"; // melihat antrian paling depan dengan head menunjuk ke data peserta
        cout << "                   Nama          : " << front->nama << endl;
        cout << "                   NIK           : " << front->nik << endl;
        cout << "                   Alamat        : " << front->alamat << endl;
        cout << "                   Jenis Kelamin : " << front->jenisKelamin << endl;
        cout << "                   Jenis SIM     : " << front->jenisSim << endl;
        cout << "                   Nomor HP      : " << front->noHp << endl;
        cout << "----------------------------------------------------------------\n";
    }
}

// hapus data dengan nik
void deleteNik(string inputNik){
    Node *hapus = head;
    Node *bantu = head;
    Node *sebelum = NULL; // Menyimpan node sebelumnya dengan deklarasi awal adalah null
    bool ditemukan = false; //deklarasi variabel ditemukan dengan tipe data bool yang bernilai false

    if(head == tail){ //kasus ketika antrian hanya 1
        if(hapus->nik == inputNik){
            head = tail = NULL;
            cout << "----------------------------------------------------------------\n";
            cout << "|                    Data telah dihapus                        |\n";
            cout << "----------------------------------------------------------------\n";
            return;
        }else{
            cout << "----------------------------------------------------------------\n";
            cout << "|                   Data tidak ditmukan                        |\n";
            cout << "----------------------------------------------------------------\n";
            return;
        }
    }
    
    while(bantu != NULL){
        if(bantu->nik == inputNik){
            hapus = bantu;
            ditemukan = true;
            break;
        }
        sebelum = bantu;
        bantu = bantu->next;
    }

    if(ditemukan){
        if(hapus == head){ // kasus ketika hapus adalah head / hapus bagian depan
            head = head->next;
            delete hapus;
        }else if(hapus == tail){ // Kasus ketika hapus adalah tail / hapus bagian belakang
            tail = sebelum;
            tail->next = NULL;
            delete hapus;
        }else{ // Kasus ketika hapus berada di tengah / hapus bagian tengah
            bantu = hapus->next;
            sebelum->next = bantu;
            delete hapus;
        }
        cout << "----------------------------------------------------------------\n";
        cout << "|                     Data telah dihapus                       |\n";
        cout << "----------------------------------------------------------------\n";
    }else{
        cout << "----------------------------------------------------------------\n";
        cout << "|                    Data tidak ditemukan                      |\n";
        cout << "----------------------------------------------------------------\n";
    }
}

// mencari data dengan nik atau nomor hp menggunakan input manual
void search(string input){
    Node *bantu = head;
    bool ditemukan = false;

    if(isEmpty()){
        cout << "----------------------------------------------------------------\n";
        cout << "                     Antrian masih kosong\n";
        cout << "----------------------------------------------------------------\n";
    }else{
        while(bantu != NULL){
            if(bantu->nik == input || bantu->noHp == input){
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
        if(!ditemukan){ // jika ditemukan bernilai tidak true
            cout << "----------------------------------------------------------------\n";
            cout << "|                   Data tidak ditemukan                       |\n";
            cout << "----------------------------------------------------------------\n";
        }
    }
}

// pembaruan data dengan input nik
void pembaruanData(string inputNik){
    Node *bantu = head;
    bool ditemukan = false;
    system("cls");
    //melakukan iterasi selama bantu tidak null, maka iterasi berlanjut
    while(bantu!=NULL){
        if(bantu->nik == inputNik){
            cout << "----------------------------------------------------------------\n";
            cout << "|                          Data Anda                           |\n";
            cout << "----------------------------------------------------------------\n";
            cout << "Nama          : " << bantu->nama << endl;
            cout << "NIK           : " << bantu->nik << endl;
            cout << "Alamat        : " << bantu->alamat << endl;
            cout << "Jenis SIM     : " << bantu->jenisSim << endl;
            cout << "Jenis Kelamin : " << bantu->jenisKelamin << endl;
            cout << "No Hp         : " << bantu->noHp<< endl;
            ditemukan=true;
            break;
        }
        bantu = bantu->next;
    }
    cout << endl;
    cout << "----------------------------------------------------------------\n";
    cout << "|                        Pilih kategori                        |\n";
    cout << "----------------------------------------------------------------\n";
    cout << "\t 1. Ubah Satu data\n";
    cout << "\t 2. Ubah semua data\n";
    cout << "\t 3. Cancel\n";
    int pilihanData;
    cout << "Masukan Pilihan(1/2) : "; cin >> pilihanData;
    system("cls");
    cin.ignore();
    if(pilihanData == 1){
        string dataUbah;
        cout << "----------------------------------------------------------------\n";
        cout << "|                          Pilih Data                          |\n";
        cout << "----------------------------------------------------------------\n";
        cout << " - nama\n";
        cout << " - nik\n";
        cout << " - alamat\n";
        cout << " - jenis kelamin\n";
        cout << " - jenis sim\n";
        cout << " - no hp\n";
        cout << "Note : Masukan sesuai tulisan diatas\n";
        cout << "Masukan Data yang ingin di ubah : "; getline(cin, dataUbah);
        system("cls");
        cout << "----------------------------------------------------------------\n";
        cout << "|                         Data Update                          |\n";
        cout << "----------------------------------------------------------------\n";
        if(dataUbah == "nama"){
            cout << "Masukan Data baru : "; getline(cin, bantu->nama);
        }else if(dataUbah == "nik"){
            cout << "Masukan Data baru : "; getline(cin, bantu->nik);
        }else if(dataUbah == "alamat"){
            cout << "Masukan Data baru : "; getline(cin, bantu->alamat);
        }else if(dataUbah == "jenis kelamin"){
            cout << "Masukan Data baru : "; getline(cin, bantu->jenisKelamin);
                while(bantu->jenisKelamin != "l" && bantu->jenisKelamin != "p"){
                    cout << "----------------------------------------------------------------\n"; 
                cout << "Maaf jenis tidak valid\n";
                cout << "----------------------------------------------------------------\n";
                cout << "                  Jenis Kelamin (l/p)  : "; getline(cin, bantu->jenisKelamin);
                }
        }else if(dataUbah == "jenis sim"){
            cout << "Masukan Data Baru : "; getline(cin, bantu->jenisSim);
                while(bantu->jenisSim != "a" && bantu->jenisSim != "b" && bantu->jenisSim != "c"){
                cout << "----------------------------------------------------------------\n"; 
                cout << "Maaf jenis tidak valid\n";
                cout << "----------------------------------------------------------------\n";
                cout << "                  Jenis SIM (a/b/c)  : "; getline(cin, bantu->jenisSim);
                }
        }else if(dataUbah == "no hp"){
            cout << "Masukan data baru : "; getline(cin, bantu->noHp);
        }else{
            cout << "Data tidak valid\n";
        }
        cout << "----------------------------------------------------------------\n";
        cout << "|                   Data berhasil di ubah                      |\n";
        cout << "----------------------------------------------------------------\n";
    }else if(pilihanData == 2){
        system("cls");
        cin.ignore(); 
        cout << "                  Nama               : "; getline(cin, bantu->nama);
        cout << "                  NIK                : "; getline(cin, bantu->nik);
        cout << "                  Alamat             : "; getline(cin, bantu->alamat);
        cout << "                  Jenis Kelamin (l/p): "; getline(cin, bantu->jenisKelamin);
        cout << "                  Jenis SIM (a/b/c)  : "; getline(cin, bantu->jenisSim);
        //ketika sim bukan a,b, dan c, maka input ulang
        while(bantu->jenisSim != "a" && bantu->jenisSim != "b" && bantu->jenisSim != "c"){
            cout << "----------------------------------------------------------------\n"; 
            cout << "Maaf jenis tidak valid\n";
            cout << "----------------------------------------------------------------\n";
            cout << "                  Jenis SIM (a/b/c)  : "; getline(cin, bantu->jenisSim);
        }
        cout << "                  Nomor HP           : "; getline(cin, bantu->noHp); 
        cout << "----------------------------------------------------------------\n";
        cout << "|                   Data berhasil diubah                       |\n";
        cout << "----------------------------------------------------------------\n";
    }else if(pilihanData == 3){
        cout << "----------------------------------------------------------------\n";
        cout << "|                       Terima Kasih                           |\n";
        cout << "----------------------------------------------------------------\n";
        return;
    }else{
        cout << "----------------------------------------------------------------\n";
        cout << "|             Mohon masukan pilihan dengan benar               |\n";
        cout << "----------------------------------------------------------------\n";
    }

    // jika ditemukan tidak bernilai true
    if(!ditemukan){
        cout << "----------------------------------------------------------------\n";
        cout << "                   Data tidak ditemukan\n";
        cout << "----------------------------------------------------------------\n";
    }
}

// lihat data statistik dari jenis kelamin dan jenis sim
void statistik(){
    Node *bantu = head;
    int jumlahLakilaki = 0; //jumlahPerempuan = 0, jumlahSimA = 0, jumlahSimB = 0, jumlahSimC = 0;
    int jumlahPerempuan = 0;
    int jumlahSimA = 0;
    int jumlahSimB = 0;
    int jumlahSimC = 0;

    if(isEmpty()){
        cout << "----------------------------------------------------------------\n";
        cout << "                    Antrian masih kosong\n";
        cout << "----------------------------------------------------------------\n";
        return;
    }else{
        while(bantu != NULL){
            //kasus jika jenis kelamin ada laki-laki atau perempuan, maka increment
            if(bantu->jenisKelamin == "l"){
                jumlahLakilaki++;
            }else if(bantu->jenisKelamin == "p"){
                jumlahPerempuan++;
            }
            //kasus jika jenis sim ada a, b, dan c, maka increment
            if(bantu->jenisSim == "a"){
                jumlahSimA++;
            }else if(bantu->jenisSim == "b"){
                jumlahSimB++;
            }else if (bantu->jenisSim == "c"){
                jumlahSimC++;
            }
            bantu = bantu->next;
        }
    }
        cout << "----------------------------------------------------------------\n";   
        cout << "             Statistik Jenis Kelamin dan Jenis SIM\n";
        cout << "----------------------------------------------------------------\n";
        cout << "                Jumlah peserta Laki-laki  : " << jumlahLakilaki << endl;
        cout << "                Jumlah peserta Perempuan  : " << jumlahPerempuan << endl;
        cout << "----------------------------------------------------------------\n";
        cout << "                      Jumalah SIM A : " << jumlahSimA << endl;
        cout << "                      Jumalah SIM B : " << jumlahSimB << endl;
        cout << "                      Jumalah SIM C : " << jumlahSimC << endl;
        cout << "----------------------------------------------------------------\n";
}

// program utama / awal program berjalan
int main(){
    int pilihan = 0;
    string nama, nik, alamat, jenisKelamin, jenisSim, noHp, inputNik, input;
    // ketika pilihan adalah 10 maka berhenti
    while(pilihan != 10){
        // pilih:
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
        cout << "Pilih Menu (1-12): ";
        cin >> pilihan;
        // pencocokan input pilihan yang diminta
        switch (pilihan){
            case 1:
                system("cls");
                cout << "----------------------------------------------------------------\n";
                cout << "                       Masukan data diri\n";
                cout << "----------------------------------------------------------------\n";
                // berfungsi untuk membersihkan karakter newline (\n) dari buffer input
                cin.ignore();
                //getline berfungsi untuk katakter yang mempunyai spasi
                cout << "                  Nama               : "; getline(cin, nama);
                cout << "                  NIK                : "; getline(cin, nik);
                cout << "                  Alamat             : "; getline(cin, alamat);
                cout << "                  Jenis Kelamin (l/p): "; getline(cin, jenisKelamin);
                while(jenisKelamin != "p" && jenisKelamin != "l"){
                    cout << "----------------------------------------------------------------\n";
                    cout << "                  Maaf jenis tidak valid\n";
                    cout << "----------------------------------------------------------------\n";
                    cout << "                 Jenis Kelamin          : "; getline(cin, jenisKelamin);
                }
                cout << "                  Jenis SIM (a/b/c)  : "; getline(cin, jenisSim);
                // melakukan iterasi selama sim bukan a, b, dan c
                while(jenisSim != "a" && jenisSim != "b" &&  jenisSim != "c"){
                    cout << "----------------------------------------------------------------\n";
                    cout << "                  Maaf jenis tidak valid\n";
                    cout << "----------------------------------------------------------------\n";
                    cout << "                 Jenis SIM          : "; getline(cin, jenisSim);
                }
                cout << "                  Nomor HP           : "; getline(cin, noHp);
                enqueue(nama, nik, alamat, jenisKelamin, jenisSim, noHp);
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                cout << "----------------------------------------------------------------\n";
                cout << "                      Masukan Data Diri\n";
                cout << "----------------------------------------------------------------\n";
                cin.ignore();
                cout << "                   Nama               : "; getline(cin, nama);
                cout << "                   NIK                : "; getline(cin, nik);
                cout << "                   Alamat             : "; getline(cin, alamat);
                cout << "                   Jenis Kelamin (l/p): "; getline(cin, jenisKelamin);
                cout << "                   Jenis SIM (a/b/c)  : "; getline(cin, jenisSim);
                while(jenisSim != "a" && jenisSim != "b" && jenisSim != "c"){
                    cout << "----------------------------------------------------------------\n";
                    cout << "                     Maaf jenis tidak valid\n";
                    cout << "----------------------------------------------------------------\n";
                    cout << "                   Jenis SIM          : "; getline(cin, jenisSim);
                }
                cout << "                   Nomor HP           : "; getline(cin, noHp);
                enqueueDepan(nama, nik, alamat, jenisKelamin, jenisSim, noHp);
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                dequeue();
                system("pause");
                system("cls");               
                break;             
            case 4:
                system("cls");
                lihatAntrian();
                system("pause");
                system("cls");
                break;
            case 5:
                system("cls");
                lihatAntrianDepan();
                system("pause");
                system("cls");
                break;
            case 6:
                system("cls");
                if(isEmpty()){
                    cout << "----------------------------------------------------------------\n";
                    cout << "                     Antrian masih Kosong\n";
                    cout << "----------------------------------------------------------------\n";
                }else{
                    cout << "----------------------------------------------------------------\n";
                    cout << "                  Masukan NIK anda : "; cin >> inputNik;
                    cout << "----------------------------------------------------------------\n";
                    system("cls");
                    deleteNik(inputNik);
                }
                system("pause");
                system("cls");
                break;
            case 7:
                system("cls");
                if(isEmpty()){
                    cout << "----------------------------------------------------------------\n";
                    cout << "                      Antrian masih Kosong\n";
                    cout << "----------------------------------------------------------------\n";
                }else{
                    cout << "Masukan NIK/Nomor HP : ";
                    cin >> input;
                    system("cls");
                    search(input);
                }
                system("pause");
                system("cls");
                break;
            case 8:
                system("cls");
                if(isEmpty()){
                    cout << "----------------------------------------------------------------\n";
                    cout << "                       Antrian masih Kosong\n";
                    cout << "----------------------------------------------------------------\n";
                }else{
                    cout << "----------------------------------------------------------------\n";
                    cout << "                         Pembaruan data\n";
                    cout << "================================================================\n\n";
                    cout << "                         Masukan NIK anda: ";
                    cin >> inputNik;
                    system("cls");
                    pembaruanData(inputNik);
                }
                system("pause");
                system("cls");
                break;
            case 9:
                system("cls");
                statistik();
                system("pause");
                system("cls");
                break;
            case 10:
            system("cls");
                cout << "================================================================\n";
                cout << "----------------------------------------------------------------\n";
                cout << "                       Terima kasihhhh\n";
                cout << "----------------------------------------------------------------\n";
                cout << "================================================================\n";
                break;
            case 11:
            system("cls");
                lihatRiwayat();
                system("pause");
                system("cls");
                break;
            case 12:
            system("cls");
                resetRiwayat();
                system("pause");
                system("cls");
                break;
            default:
                cout << "----------------------------------------------------------------\n";
                cout << "                     Pilihan tidak valid\n";
                cout << "----------------------------------------------------------------\n";
                system("pause");
                system("cls");
        }
    }
    return 0;
}