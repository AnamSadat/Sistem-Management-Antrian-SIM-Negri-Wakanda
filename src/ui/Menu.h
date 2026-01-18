#ifndef MENU_H
#define MENU_H

#include "../services/QueueService.h"
#include "../services/RiwayatService.h"
#include "../services/PaymentService.h"
#include "../utils/InputHelper.h"

class Menu {
private:
    QueueService queueService;
    RiwayatService riwayatService;
    PaymentService paymentService;
    
    void tampilkanMenu();
    void daftarAntrian();
    void daftarVIP();
    void konfirmasiPembayaran();
    void lihatAntrian();
    void cekAntrianDepan();
    void hapusData();
    void cariData();
    void updateData();
    void tampilkanStatistik();
    void lihatRiwayat();
    void resetRiwayat();

public:
    Menu();
    void run();
};

#endif
