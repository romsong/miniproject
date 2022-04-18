#include"manager.h"

int selectMenu() // 메뉴선택 창
{
    int menu;

    printf("\n*** 점수계산기 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("0. 종료\n");

    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);

    return menu;
}

int addProduct(Product *p) // 하나의 데이터 추가하는 기능
{
    printf("제품 이름을 입력하세요: ");
    scanf("%s" ,p->name);

    printf("원산지를 입력하세요: ");
    scanf("%s" ,p->space);

    printf("제품에 대한 간략한 설명을 입력하세요: ");
    scanf("%s" ,p->simple_ex);

    printf("제품 가격을 입력하세요: ");
    scanf("%d" ,&p->price);
    
    printf("판매단위를 입력하세요: ");
    scanf("%d" ,&p->unit);

    printf("배달 방법을 입력하세요: ");
    scanf("%s" ,p->delivery);
    
    return 1;
}

void readProduct(Product *p) // 하나의 데이터 조회하는 기능
{
    printf("%s %s %s %d %d %s\n", p->name, p->space, p->simple_ex, p->price, p->unit, p->delivery);
}

int updateProduct(Product *p[], int index) // 하나의 데이터 수정하는 기능
{
	index--;
    printf("제품 이름을 입력하세요: ");
    scanf("%s" ,p[index]->name);

    printf("원산지를 입력하세요: ");
    scanf("%s" ,p[index]->space);

    printf("제품에 대한 간략한 설명을 입력하세요: ");
    scanf("%s" ,p[index]->simple_ex);

    printf("제품 가격을 입력하세요: ");
    scanf("%d" ,&p[index]->price);
    
    printf("판매단위를 입력하세요: ");
    scanf("%d" ,&p[index]->unit);

    printf("배달 방법을 입력하세요: ");
    scanf("%s" ,p[index]->delivery);

    printf("수정 완료하였습니다!\n");
    
    return 1;
}

void listProduct(Product *p[], int count) // 리스트로 조회하는 기능
{
    int i;

    printf("Name |  Country of origin | explanation |  price | Unit of sale | Delivery method \n");
    printf("================================================================================= \n");

    for(i=0; i<count; i++)
    {
        if(p[i]==NULL)
            continue;
        printf("%d ", i+1);
        readProduct(p[i]);
    }
    printf("\n");
}

int selectDataNo(Product *p[], int count) // 번호를 선택 하는 기능
{
    int no;

    listProduct(p, count);
    printf("번호는 (취소 : 0)? ");
    scanf("%d", &no);

    return no;
}

void saveData(Product *p[], int count)
{
    int i;

    FILE *fp;
    fp=fopen("product.txt", "wt");

    for(i=0; i<count; i++)
    {
        if(p[i]==NULL)
            continue;
        fprintf(fp, "%s %s %s %d %d %s\n", p[i]->name, p[i]->space, p[i]->simple_ex, p[i]->price, p[i]->unit, p[i]->delivery);
    }

    fclose(fp);
    printf("=> 저장됨! ");
}

int loadData(Product *p[])
{
    int count=0, i=0;
    FILE *fp;

    fp=fopen("product.txt", "rt");
    for(i=0; i<100; i++)
    {
        fscanf(fp, "%s", p[i]->name);
        if(feof(fp))
            break;
        fscanf(fp, "%s", p[i]->space);
        fscanf(fp, "%s", p[i]->simple_ex);
        fscanf(fp, "%d", p[i]->price);
        fscanf(fp, "%d", p[i]->unit);
        fscanf(fp, "%s", p[i]->delivery);
    }
    fclose(fp);
    printf("=> 로딩 성공!\n");

    return i;
}

void search_price(Product *p[], int count) // 가격을 찾는 기능
{
    int i, price;

    printf("검색할 가격을 입력하세요: ");
    scanf("%d", &price);

    for(i=0; i<count; i++)
    {
        if(p[i]->price==price)
            redaProduct(p[i]);
    }
}
