/*
* 소프트웨어공학 <HW 3 :  Detailed Design & Implementation – 의류 쇼핑 사이트>
* 
* File name : main.cpp
* File created by B711169 정다은
*/

// 헤더 선언
#include <stdio.h>
#include <string.h>
#include "User.h"
#include "Product.h"
#include "ProductCollection.h"

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void doTask();
void join();
void program_exit();

// 변수 선언
FILE* in_fp, * out_fp;

int main()
{
    // 파일 입출력을 위한 초기화
    FILE* in_fp = fopen(INPUT_FILE_NAME, "r+");
    FILE* out_fp = fopen(OUTPUT_FILE_NAME, "w+");

    //...

        doTask();

    //...

        return 0;
}





/*
* MainController
* Author : B711169 정다은
*/
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
            case 1:   // "1.1. 회원가입“ 메뉴 부분
            {  join(); break;  }
            case 2:
            { withdraw();  break; }
            }
        }
        case 2:
        {
            switch (menu_level_2)
            {
            case 1:   // "1.1. 회원가입“ 메뉴 부분
            {  login();  break; }
            case 2:
            {  logout();  break;  }
            }
        }
        case 3:
        {
            switch (menu_level_2)
            {
            case 1:   // "1.1. 회원가입“ 메뉴 부분
            {  enrollProduct();  break; }
            case 2:
            {  showMySellingProducts();  break;  }
            case 3:
            {  showSoldoutProducts();  break;  }
            }
        }
        case 4:
        {
            switch (menu_level_2)
            {
            case 1:   // "1.1. 회원가입“ 메뉴 부분
            {  showProductDetails();  break; }
            case 2:
            {  buy();  break;  }
            case 3:
            {  showPurchaseList();  break;  }
            case 4:
            {  saveAvgSatisfaction();  break;  }
            }
        }
        case 5:
        {
            switch (menu_level_2)
            {
            case 1:   // "1.1. 회원가입“ 메뉴 부분
            {  salesStatistics();  break; }
            }
        }
        case 6:
        {
            switch (menu_level_2)
            {
            case 1:   // "1.1. 회원가입“ 메뉴 부분
            {  program_exit();  is_program_exit = 1;  break; }
            }
        }
        }
        return;
    }
}

// 1.1 회원가입
void join()
{
    char user_type[MAX_STRING], name[MAX_STRING], SSN [MAX_STRING],
        address[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];

    // 입력 형식 : 이름, 주민번호, ID, Password를 파일로부터 읽음
    fscanf(in_fp, "%s %s %s %s", name, SSN, ID, password);



    // 출력 형식
    fprintf(out_fp, "1.1. 회원가입\n");
    fprintf(out_fp, "%s %s %s %s\n", name, SSN, ID, password);
}

// 1.2 회원탈퇴
void withdraw()
{

}
// 2.1 로그인
void login()
{
    char ID[MAX_STRING], password[MAX_STRING];
    // 입력 형식 : 이름, 주민번호, ID, Password를 파일로부터 읽음
    fscanf(in_fp, "%s %s", ID, password);


    // 출력 형식
    fprintf(out_fp, "2.1 로그인\n");
    fprintf(out_fp, "%s %s\n", ID, password);
}
// 2.2 로그아웃
void logout() {

}
/*
* 3.1 판매 의류 등록
* Author : B711169 정다은
*/
void enrollProduct()
{
    char product_name[MAX_STRING], manufacturer[MAX_STRING];
    int price, quantity;
    // 입력 형식 : 이름, 주민번호, ID, Password를 파일로부터 읽음
    fscanf(in_fp, "%s %s %d %d", product_name, manufacturer, price, quantity);

    User user;

    string pName = product_name;
    string manufacturer = manufacturer;
    Product p(pName, manufacturer, price, quantity);
 
    user.getmySalesCollection().addProduct(p);

    // 출력 형식
    fprintf(out_fp, "3.1 판매 의류 등록\n");
    fprintf(out_fp, "%s %s %d %d\n", product_name, manufacturer, price, quantity);

}
/*
* 3.2 등록 상품 조회 ( 판매중 + 품절 ALL )
* Author : B711169 정다은
*/
void showMySellingProducts()
{
    fprintf(out_fp, "3.2 등록 상품 조회\n");

    User user;

    vector<Product> v = user.getmySalesCollection().getList();
    vector<Product>::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++) {
        string product_name = (*iter).getproductName();
        string manufacturer = (*iter).getmanufacturer();
        int price = (*iter).getprice();
        int quantity = (*iter).getquantity();
        fprintf(out_fp, "%s %s %d %d\n", product_name, manufacturer, price, quantity);
    }
}

/*
* 3.3 판매 완료 상품 조회
* Author : B711169 정다은
*/
void showSoldoutProducts()
{
    fprintf(out_fp, "3.3 판매 완료 상품 조회\n");

    User user;

    vector<Product> v = user.getmySalesCollection().getList();
    vector<Product>::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++) {
        // 품절인 것만 출력
        if (!(*iter).getSalesState())
        {
            string product_name = (*iter).getproductName();
            string manufacturer = (*iter).getmanufacturer();
            int price = (*iter).getprice();
            int quantity = (*iter).getquantity();
            fprintf(out_fp, "%s %s %d %d\n", product_name, manufacturer, price, quantity);
        }
    }
}

// 4.1 상품 정보 검색
void showProductDetails()
{
    char SellerID[MAX_STRING], product_name[MAX_STRING], manufacturer[MAX_STRING];
    int price, quantity;
    // 입력 형식 : 이름, 주민번호, ID, Password를 파일로부터 읽음
    fscanf(in_fp, "%s", product_name);


    // 출력 형식
    fprintf(out_fp, "4.1 상품 정보 검색\n");
    fprintf(out_fp, "%s %s %s %d %d", SellerID, product_name, manufacturer, price, quantity);
}

// 4.2 상품 구매
void buy()
{
    // quantity--; soldQuantity++;
    // if(quantity == 0) salesState = false;    // 품절
}

// 4.3 상품 구매 내역 조회
void showPurchaseList()
{

}

// 4.4 상품 구매만족도 평가
void saveAvgSatisfaction()
{

}

/*
* 5.1 판매 상품 통계 ( 현재까지 판매한 '모든 상품'에 대한 총액 및 평균 구매만족도 )
* Author : B711169 정다은
*/
void salesStatistics()
{
    User user;

    vector<Product> v = user.getmySalesCollection().getList();
    vector<Product>::iterator iter;

    // 출력 형식
    fprintf(out_fp, "5.1 판매 상품 통계\n");
    
    for (iter = v.begin(); iter != v.end(); iter++) {
        string productName = (*iter).getInfoForStatistics().productName;
        int totalProfit = (*iter).getInfoForStatistics().totalProfit;
        int avgSatisfaction = (*iter).getInfoForStatistics().avgSatisfaction;
        fprintf(out_fp, "%s %d %d\n", productName, totalProfit, avgSatisfaction);
    }

}

// 6.1 시스템 종료
void program_exit()
{

}