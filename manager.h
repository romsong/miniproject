#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    char name[20]; // 제품 이름
    char space[20]; // 제품 원산지
    char simple_ex[30]; // 제품에 대한 간단한 설명
    char delivery[10]; // 배달방법
    int price; // 가격
    int unit; // 판매단위
}Product;

// CRUD
int selectMenu(); // 메뉴선택 창
int addProduct(Product *p); // 하나의 데이터 추가하는 기능
void readProduct(Product *p); // 하나의 데이터 조회하는 기능
int updateProduct(Product *p[], int index); // 하나의 데이터 수정하는 기능
void listProduct(Product *p[], int count); // 리스트로 조회하는 기능
int selectDataNo(Product *p[], int count); // 번호를 선택 하는 기능
void saveData(Product *p[], int count);
int loadData(Product *p[]);
void search_price(Product *p[], int count);





