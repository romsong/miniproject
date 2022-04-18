#include"manager.h"

int main(void)
{
    int count=0, menu;
    int index=0;
    int no, deletok;
    Product *p[100];
   
    count=loadData(p);
    index=count;

    while(1) // while의 종료조건을 1로 함으로써 계속 실행되도록 함(하지만 1. 종료 조건인 menu==0일때 나가도록 조정해도 좋을 듯, 2. swicth문으로 관리해도 좋을 듯)
    {
        menu=selectMenu();

        if(menu==0)
            break;
        if(menu==1 || menu==3 || menu==4) // list가 아직 추가가 안 되었으므로 이 메뉴들을 실행하면 할 것이 없음
            if(count==0)
                continue;

        if(menu==1)
		listProduct(p, index);	
        else if(menu==2)
        {
#ifdef DEBUG
	printf("=>DEBUGMODE\n");
#endif 
            p[index]=(Product *)malloc(sizeof(Product)); // 그때마다 메모리를 할당함
            count+=addProduct(p[index++]); // add를 하면 count에 수를 하나씩 증가시킴 영상 다시확인해봐 어쩔 때는 뭐햐고 하는거
        }
        else if(menu==3)
        {
#ifdef DEBUG
	printf("=>DEBUGMODE\n");
#endif
            no=selectDataNo(p, index);
            if(no==0)
            {
                printf("=>취소됨!\n");
                continue;
            }

            updateProduct(&p[no-1], index); // no는 순수 list의 번호이므로 index로는 한번을 줄여줘야 함
        }
        else if(menu==4)
        {
            no=selectDataNo(p, index);
            if(no==0)
            {
                printf("=>취소됨!\n");
                continue;
            }

            printf("정말로 삭제하시겠습니까? (삭제: 1)");
            scanf("%d", &deletok);

            if(deletok==1)
            {
                if(p[no-1]) // 아마도 index에 벗어난 값이 입력되면 if문이 안되는 것이다
                    free(p[no-1]);
                p[no-1]=NULL;
                count--;
            }
        }
	else if(menu==5)
        {
            saveData(p, index);
        }
    } 

    return 0;
}
