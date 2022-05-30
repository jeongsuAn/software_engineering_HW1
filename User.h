/*
* File name : User.h
* File created by B711169 ¡§¥Ÿ¿∫
*/

#include <string>
#include "Product.h"
#include "ProductCollection.h"
using namespace std;

class User {       // The class

private:
    string name;
    double residentRegistrationNumber; // Access specifier
    string ID;
    string password;

    ProductCollection mySalesCollection;
    //ProductCollection soldoutCollection;

public:
    void createID(string userDB, string name, string residentRegistrationNumber, string ID, string pw)
    {

    }
    void checkLogin(string ID, string pw)
    {
    }

    void withdrawalUser(string id)
    {

    }

    ProductCollection getmySalesCollection()
    {

    }

    //ProductCollection getSoldoutCollection()
    //{

    //}
};
