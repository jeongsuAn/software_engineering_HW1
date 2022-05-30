#include "CheckPurchaseHistoryUI.h"

CheckPurchaseHistoryUI::checkPurchaseHistoryUI(User u, FILE *out_fp)
{
    PurchaseCollection PHC = u.getPurchaseCollection();
}
void CheckPurchaseHistoryUI::enable(PurchaseCollection PHC, FILE *out_fp)
{
    fprintf(out_fp, "4.3. 상품 구매 내역 조회\n");
    vector<Product>::iterator it = PHC.findFirstIdx();
    Product p;
    while (true)
    {
        p = *it;
        // [판매자ID] [상품명] [제작회사명] [가격] [남은수량] [평균 구매만족도] 출력
        fprintf(out_fp, "%s %s %s %lf %d %lf", p.getSellerID(), p.getProductName(), p.getmanufacturer(), p.getprice(), p.getquantity(), p.avgSatisfaction());
        if (it == PHC.findLastIdx())
            break;
        it = PHC.getNext(it);
    }
}