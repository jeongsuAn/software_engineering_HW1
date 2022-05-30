#include "ProductPayment.h"

productPayment::productPayment(FILE *out_fp, Product p)
{
    PurchaseHistoryCollection PHC;
    PHC.addPurchaseHistory(p);
    productPaymentUI ppUI(out_fp, p);
}