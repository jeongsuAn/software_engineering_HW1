/*
* File name : Product.h
* File created by B711169 정다은
*/

#include <string>
using namespace std;

class Product {       // The class

private:
    string sellerID;
    string productName;
    string manufacturer;
    int price;
    int quantity;
    int soldQuantity;
    vector<int> scores;
    //int avgPurchaseSatisfaction;
    bool salesState;

public:
    typedef struct statisticsDTO {
        string productName;
        int totalProfit;
        int avgSatisfaction;
    } sDTO;

    Product(string pname, string manufacturer, int price, int quantity) // default constructor
    {
        this->productName = pname;
        this->manufacturer = manufacturer;
        this->price = price;
        this->quantity = quantity;
    }

    string getSellerID()
    {
        return sellerID;
    }
    string getproductName()
    {
        return productName;
    }
    string getmanufacturer()
    {
        return manufacturer;
    }
    int getprice()
    {
        return price;
    }
    int getquantity()
    {
        return quantity;
    }

    bool getSalesState()
    {
        // 판매중: true, 품절: false
        return salesState;
    }

    //Product getProductByName(string productName)
    //{

    //}

    void savePurchaseSatisfaction(int score)
    {
        scores.push_back(score); 
    }

    void getItemDetails()
    {
    
    }

    statisticsDTO getInfoForStatistics()
    {
        sDTO s;
        s.productName = this->getproductName();

        s.totalProfit = soldQuantity * price;

        int avgSatisfaction = 0;
        for (vector<int>::iterator iter = scores.begin(); iter != scores.end(); iter++) {
            avgSatisfaction += *iter;
        }
        avgSatisfaction /= soldQuantity;

        s.avgSatisfaction = avgSatisfaction;

        return s;
    }
};
