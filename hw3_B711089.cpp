// 헤더 선언
#include <stdio.h>
#include <string.h>

// 상수 선언
#define MAX_STRING 32
#define NUMBER_OF_PRODUCT 100
#define NUMBER_OF_PURCHASE_HISTORY 100
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void doTask();
void join();
//void program_exit();

// 변수 선언
FILE *in_fp, *out_fp;

// Class : Product
// Description: This is a Product class. (상품)
// Created: 2022/5/28 11:00 pm
// Author: Jiyeon Baek
// mail: etety@g.hongik.ac.kr
class Product
{
protected:
    bool saleState;

    typedef struct pd
    {
        char sellerID[MAX_STRING], productName[MAX_STRING], productionCompanyName[MAX_STRING];  // 판매자ID, 상품 이름, 제작회사명
        double price, avgPurchaseSatisfaction;  // 가격, 평균 구매 만족도
        int quantity, soldQuantity, satisfactionQuantity;   // 재고, 남은수량, 구매만족도조사횟수
    } productTable;
    int size = 0;   // 테이블 사이즈
    productTable table[NUMBER_OF_PRODUCT];  // 테이블

public:
    int savePurchaseSatisfaction(char* productName, int score);
    void getItemDetails();

    char* getSellerID(int idx){ return table[idx].sellerID; }
    char* getProductName(int idx){ return table[idx].productName; }
    char* getProductionCompanyName(int idx){ return table[idx].productionCompanyName; }
    double getPrice(int idx){ return table[idx].price; }
    double getAvgPurchaseSatisfaction(int idx){ return table[idx].avgPurchaseSatisfaction; }
    int getQuantity(int idx){ return table[idx].quantity; }
    int getSoldQuantity(int idx){ return table[idx].soldQuantity; }
    int getSatisfactionQuantity(int idx){ return table[idx].satisfactionQuantity; }
};

// Class : PurchaseHistory
// Description: This is a PurchaseHistory class. (구매 내역)
// Created: 2022/5/28 11:00 pm
// Author: Jiyeon Baek
// mail: etety@g.hongik.ac.kr
class PurchaseHistory
{
private:
    char sellerID[MAX_STRING], productName[MAX_STRING], productionCompanyName[MAX_STRING];  // 판매자ID, 상품 이름, 제작회사명
    double price, avgPurchaseSatisfaction;  // 가격, 평균 구매 만족도
    int quantity;   // 남은수량

public:
    void setHistoryDetail(char *sellerID, char *productName, char *productionCompanyName, double price, int quantity);
    void getHistoryDetail();

    char* getSellerID(){ return sellerID; }
    char* getProductName(){ return productName; }
    char* getProductionCompanyName(){ return productionCompanyName; }
    double getPrice(){ return price; }
    double getAvgPurchaseSatisfaction(){ return avgPurchaseSatisfaction; }
    int getQuantity(){ return quantity; }
};

// Class : PurchaseHistoryCollection
// Description: This is a PurchaseHistory collection class. (구매 내역 collection)
// Created: 2022/5/28 11:00 pm
// Author: Jiyeon Baek
// mail: etety@g.hongik.ac.kr
class PurchaseHistoryCollection
{
private:
    // PurchaseHistory *cur;
    // PurchaseHistoryCollection *head = NULL;
    // PurchaseHistoryCollection *prev, *next;
    int size = 0;
    PurchaseHistory* phList[NUMBER_OF_PURCHASE_HISTORY];
public:
    int findFirst();
    int getNext(int idx);
    void addPurchaseHistory(int idx);

    int getSize(){ return size; }
    PurchaseHistory* getPurchaseHistory(int idx){ return phList[idx]; }
};

// 클래스 인스턴스 생성
Product p;
PurchaseHistoryCollection PHC;

// Product 멤버 함수 정의
// 구매만족도 상품에 저장
int Product::savePurchaseSatisfaction(char* productName, int score)
{
    // productTable* ptr = head;
    // while (head != NULL)
    // {
    //     if (strcmp(productName, ptr->productName) == 0)
    //     {
    //         double prevTotalSatisfaction = ptr->avgPurchaseSatisfaction * ptr->satisfactionQuantity;
    //         ptr->satisfactionQuantity++;
    //         prevTotalSatisfaction += score;
    //         ptr->avgPurchaseSatisfaction = prevTotalSatisfaction / ptr->satisfactionQuantity;
    //         break;
    //     }
    // }

    for(int i = 0;i<size;i++){
        if (strcmp(productName, table[i].productName) == 0)
        {
            double prevTotalSatisfaction = table[i].avgPurchaseSatisfaction * table[i].satisfactionQuantity;
            table[i].satisfactionQuantity++;
            prevTotalSatisfaction += score;
            table[i].avgPurchaseSatisfaction = prevTotalSatisfaction / table[i].satisfactionQuantity;
            return i;   // 해당 상품의 인덱스 리턴
        }
    }
}

// PurchaseHistory 멤버함수 정의
// 구매 내역 상세 정보 set
void PurchaseHistory::setHistoryDetail(char *newSellerID, char *newProductName, char *newProductionCompanyName, double newPrice, int newQuantity)
{
    strcpy(sellerID, newSellerID);
    strcpy(productName, newProductName);
    strcpy(productionCompanyName, newProductionCompanyName);
    price = newPrice;
    avgPurchaseSatisfaction = 0;
    quantity = newQuantity;
}
// 구매 내역 상세 정보 get
void PurchaseHistory::getHistoryDetail()
{
    // 상품 결제 시 화면에 판매자ID, 상품명 출력
}

// PurchaseHistoryCollection 멤버함수 정의
int PurchaseHistoryCollection::findFirst()
{
    if(size > 0){
        return 0;
    }
    else{
        return -1;
    }
}

int PurchaseHistoryCollection::getNext(int idx)
{
    if(idx + 1 < size){
        return idx + 1;
    }
    else{
        return -1;
    }
}

void PurchaseHistoryCollection::addPurchaseHistory(int idx)
{
    // 이전에 검색된 상품 정보 갖고 와서 구매 내역에 넣어줌
    PurchaseHistory *newPH;
    newPH = new PurchaseHistory;
    newPH->setHistoryDetail(p.getSellerID(idx), p.getProductName(idx), p.getProductionCompanyName(idx), p.getPrice(idx), p.getQuantity(idx));
    phList[size++] = newPH;
}



// 상품 결제 Function (4.2)
// Function : void productPayment()
// Description: This is a function for buying product.
// Parameters :  X
// Return Value : X
// Created: 2022/5/28 11:00 pm
// Author: Jiyeon Baek
void productPayment()
{
    char sellerID[MAX_STRING], productName[MAX_STRING];

    // 입력 형식 : 입력값 없음

    // 해당 기능 수행
    // 결제
    // 새로운 구매 내역 생성
    // PHC.addPurchaseHistory(idx);    // idx는 4.1에서 검색된 상품의 인덱스
    // 검색됐던 상품 정보 (판매자ID, 상품명)
    // sellerID = ?;
    // productName = ?;

    // 출력 형식
    fprintf(out_fp, "4.2. 상품 구매\n");
    fprintf(out_fp, "%s %s\n", p.getSellerID(idx), p.getProductName(idx));
}

// 구매 내역 조회 Function (4.3)
// Function : void checkPurchaseHistory()
// Description: This is a function for check customer's purchase history.
// Parameters :  X
// Return Value : X
// Created: 2022/5/28 11:00 pm
// Author: Jiyeon Baek
void checkPurchaseHistory()
{
    char sellerID[MAX_STRING], productName[MAX_STRING], productionCompanyName[MAX_STRING];
    int price, quantity;
    double avgPurchaseSatisfaction;

    // 입력 형식 : 입력값 없음

    // 해당 기능 수행

    // 출력 형식
    fprintf(out_fp, "4.3. 상품 구매 내역 조회\n");
    for(int i = PHC.findFirst();i < PHC.getSize();i = PHC.getNext(i)){
        // [판매자ID] [상품명] [제작회사명] [가격] [남은수량] [평균 구매만족도] 출력
        PurchaseHistory* phPtr;
        phPtr = PHC.getPurchaseHistory(i);
        fprintf(out_fp, "%s %s %s %lf %d %lf", phPtr->getSellerID(), phPtr->getProductName(), phPtr->getProductionCompanyName(), phPtr->getPrice(), phPtr->getQuantity(), phPtr->getAvgPurchaseSatisfaction());
    }
}
// 구매 만족도 평가 Function (4.4 상품명 구매만족도)
// Function : void PurchaseSatisfaction()
// Description: This is a function for assess customer's purchase satisfaction about the product.
// Parameters :  X
// Return Value : X
// Created: 2022/5/28 11:00 pm
// Author: Jiyeon Baek
void PurchaseSatisfaction()
{
    char sellerID[MAX_STRING], productName[MAX_STRING];
    double satisfaction;

    // 입력 형식 : 상품명, 구매만족도를 파일로부터 읽음
    fscanf(in_fp, "%s %lf", productName, &satisfaction);

    // 해당 기능 수행
    // 해당 상품의 평균 구매만족도 다시 계산하여 저장
    int idx = p.savePurchaseSatisfaction(productName, satisfaction);

    // 출력 형식
    fprintf(out_fp, "4.3. 상품 구매 만족도 평가\n");
    fprintf(out_fp, "%s %s %lf\n", p.getSellerID(idx), productName, satisfaction);
}

void doTask()
{
    // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    while (!is_program_exit)
    {
        // 입력파일에서 메뉴 숫자 2개를 읽기
        fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);

        // 메뉴 구분 및 해당 연산 수행
        switch (menu_level_1)
        {
        case 1:
        {
            switch (menu_level_2)
            {
            case 1: // "1.1. 회원가입“ 메뉴 부분
            {
                // join() 함수에서 해당 기능 수행
                join();

                break;
            }
            case 2:
            {
                break;
            }
            }
        }
        case 2:
        {
            switch (menu_level_2)
            {
            case 1: // "1.1. 회원가입“ 메뉴 부분
            {
                break;
            }
            case 2:
            {
                break;
            }
            }   
        }

        case 4:
        {
            switch (menu_level_2)
            {
            case 2: // "4.2. 상품 구매“ 메뉴 부분
            {
                // productPayment() 함수에서 해당 기능 수행
                productPayment();
                break;
            }
            case 3: // "4.3. 상품 구매 내역 조회“ 메뉴 부분
            {
                // checkPurchaseHistory() 함수에서 해당 기능 수행
                checkPurchaseHistory();
                break;
            }
            case 4: // "4.4. 상품 구매만족도 평가“ 메뉴 부분
            {
                // PurchaseSatisfaction() 함수에서 해당 기능 수행
                PurchaseSatisfaction();
                break;
            }
            }
        }

        case 7:
        {
            switch (menu_level_2)
            {
            case 2: // "6.1. 종료“ 메뉴 부분
            {
                //program_exit();
                is_program_exit = 1;
                break;
                ;
            }
            }
        }
        }
        }
    }


int main()
{
    // 파일 입출력을 위한 초기화
    FILE *in_fp = fopen(INPUT_FILE_NAME, "r+");
    FILE *out_fp = fopen(OUTPUT_FILE_NAME, "w+");

    doTask();

    return 0;
}