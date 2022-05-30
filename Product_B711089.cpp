#include "Product_B711089.h"

string Product::getSellerID()
{
    return sellerID;
}
string Product::getproductName()
{
    return productName;
}
string Product::getmanufacturer()
{
    return manufacturer;
}
int Product::getprice()
{
    return price;
}
int Product::getquantity()
{
    return quantity;
}

bool Product::getSalesState()
{
    // 판매중: true, 품절: false
    return salesState;
}

// Product getProductByName(string productName)
//{

//}

void Product::savePurchaseSatisfaction(int score)
{
    scores.push_back(score);
}

double Product::avgSatisfaction(){
    int total = accumulate(scores.begin(), scores.end(), 0);
    return double(total / scores.size());
}

void Product::getItemDetails()
{
}

statisticsDTO getInfoForStatistics()
{
    sDTO s;
    s.productName = this->getproductName();

    s.totalProfit = soldQuantity * price;

    int avgSatisfaction = 0;
    for (vector<int>::iterator iter = scores.begin(); iter != scores.end(); iter++)
    {
        avgSatisfaction += *iter;
    }
    avgSatisfaction /= soldQuantity;

    s.avgSatisfaction = avgSatisfaction;

    return s;
}