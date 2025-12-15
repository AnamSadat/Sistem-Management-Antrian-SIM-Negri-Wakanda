# Sistem Management Antrian SIM Negara Wakanda

Program berbasis C++ untuk mengelola antrian pendaftaran SIM menggunakan struktur data **Linked List** dan **Queue**.

## Fitur Utama

| No  | Menu                  | Deskripsi                                       |
| --- | --------------------- | ----------------------------------------------- |
| 1   | Daftar Antrian        | Mendaftar antrian reguler (masuk dari belakang) |
| 2   | VIP                   | Mendaftar antrian prioritas (masuk dari depan)  |
| 3   | Konfirmasi Pembayaran | Proses pembayaran dan hapus antrian terdepan    |
| 4   | Lihat Antrian         | Menampilkan seluruh data antrian                |
| 5   | Cek Antrian Depan     | Melihat peserta yang sedang dilayani            |
| 6   | Hapus Data            | Menghapus data berdasarkan NIK                  |
| 7   | Cari Data             | Mencari data berdasarkan NIK atau No HP         |
| 8   | Pembaruan Data        | Mengubah data peserta dalam antrian             |
| 9   | Statistik             | Menampilkan statistik jenis kelamin & jenis SIM |
| 10  | Exit                  | Keluar dari program                             |
| 11  | Riwayat               | Melihat riwayat pembayaran                      |
| 12  | Reset Riwayat         | Menghapus semua riwayat pembayaran              |

## Struktur Data

### Node (Data Peserta)

```cpp
struct Node {
    string nama;
    string nik;
    string alamat;
    string jenisKelamin;  // l = laki-laki, p = perempuan
    string jenisSim;      // a, b, atau c
    string noHp;
    Node *next;
};
```

### Harga SIM

| Jenis SIM | Harga      |
| --------- | ---------- |
| SIM A     | Rp 750.000 |
| SIM B     | Rp 500.000 |
| SIM C     | Rp 300.000 |

## Konsep yang Digunakan

- **Single Linked List** - Menyimpan data peserta secara dinamis
- **Queue (Antrian)** - Implementasi FIFO untuk antrian reguler
- **Priority Queue** - Antrian VIP masuk dari depan (insertDepan)

## Fungsi-Fungsi Utama

| Fungsi                | Keterangan                                   |
| --------------------- | -------------------------------------------- |
| `init()`              | Inisialisasi pointer head, tail, front, rear |
| `isEmpty()`           | Cek apakah antrian kosong                    |
| `enqueue()`           | Tambah antrian reguler (belakang)            |
| `enqueueDepan()`      | Tambah antrian VIP (depan)                   |
| `dequeue()`           | Proses pembayaran & hapus antrian depan      |
| `lihatAntrian()`      | Tampilkan semua antrian                      |
| `lihatAntrianDepan()` | Tampilkan antrian terdepan                   |
| `deleteNik()`         | Hapus data berdasarkan NIK                   |
| `search()`            | Cari data berdasarkan NIK/No HP              |
| `pembaruanData()`     | Update data peserta                          |
| `statistik()`         | Tampilkan statistik                          |
| `tambahRiwayat()`     | Simpan riwayat pembayaran                    |
| `lihatRiwayat()`      | Tampilkan riwayat pembayaran                 |
| `resetRiwayat()`      | Hapus semua riwayat                          |

## Cara Kompilasi & Menjalankan

```bash
g++ "Sistem Management Antrian SIM Negri Wakanda.cpp" -o antrian_sim
./antrian_sim
```

## Catatan

- Program menggunakan `system("cls")` untuk clear screen (khusus Windows)
- Maksimal riwayat yang dapat disimpan: 100 data
