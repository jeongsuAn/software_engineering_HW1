/*
* File name : ProductCollection.h
* File created by B711169 ¡§¥Ÿ¿∫
*/

#include <string>
#include <vector>
using namespace std;

class ProductCollection {       // The class

private:
	vector<Product> v;
public:
	Product findFirst()
	{
		return v.front();
	}
	vector<Product>::iterator findFirstIdx()
	{
		return v.begin();
	}

	//Product getNext(vector<Product>::iterator it)
	//{
	//	next(it, 1);
	//	return *it;

	//}

	vector<Product> getList()
	{
		return v;
	}

	void addProduct(Product p) 
	{
		v.push_back(p);
	}

};
