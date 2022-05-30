// Class : checkPurchaseHistoryUI
// Description: This is a checkPurchaseHistory boundary class.
// Created: 2022/5/30 10:00 pm
// Author: Jiyeon Baek
// mail: etety39@g.hongik.ac.kr

#include <iostream>
#include <vector>
#include "Product.h"
#include "PurchaseHistoryCollection.h"

class checkPurchaseHistoryUI
{
public:
    checkPurchaseHistoryUI(User u, FILE *out_fp);
    void enable(PurchaseCollection PHC, FILE *out_fp);
};