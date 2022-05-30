#include "ProductPaymentUI.h"

productPaymentUI::productPayment(FILE *o_fp, Product p)
{
    out_fp = o_fp;
    sellerID = p.getSellerID();
    productName = p.getproductName();

    enable(out_fp);
}

void productPaymentUI::enable(FILE *out_fp)
{
    // 출력 형식
    fprintf(out_fp, "4.2. 상품 구매\n");
    fprintf(out_fp, "%s %s\n", sellerID, productName);
}