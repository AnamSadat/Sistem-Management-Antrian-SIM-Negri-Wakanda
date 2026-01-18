#ifndef PAYMENT_SERVICE_H
#define PAYMENT_SERVICE_H

#include "QueueService.h"
#include "RiwayatService.h"
#include <iostream>
using namespace std;

class PaymentService {
private:
    QueueService* queueService;
    RiwayatService* riwayatService;
    
    int getHargaSim(string jenisSim);

public:
    PaymentService(QueueService* qs, RiwayatService* rs);
    
    // Proses pembayaran
    void prosesPembayaran();
};

#endif
