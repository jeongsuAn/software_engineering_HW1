// Class : PurchaseHistoryCollection
// Description: This is a PurchaseHistory collection class. (구매 내역 collection)
// Created: 2022/5/28 11:00 pm
// Author: Jiyeon Baek
// mail: etety@g.hongik.ac.kr
#include <vector>
#include "Product.h"

class PurchaseHistoryCollection
{
private:
    vector<Product> v;

public:
    vector<Product>::iterator findFirstIdx();
    vector<Product>::iterator getNext(vector<Product>::iterator it);
    vector<Product>::iterator findLastIdx();
    void addPurchaseHistory(Product p);
};