#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

int s[9]={1,2,3,4,5,6,7,8,0};
int x = 2, y = 2;

void inOSo(){
    system("cls");
    for(int i = 0;i<=8;i++){
        int v = s[i];
        if (v)
            printf("%d ",v);
        else
            printf("  ");
        if ((i+1)%3 == 0)
            printf("\n");
    }
}

bool kiemTraKetThuc(){
    for(int i = 0;i<8;i++)
        if (s[i]!=i+1)
            return 0;
    return 1;
}

int layChiSoOTrong(){
    return x*3+y;
}

void HoanVi(int i){
    int o = layChiSoOTrong();
    int t = s[o];
    s[o]=s[o+i];
    s[o+i]=t;
}

void Len(){
    if (x>0){
        HoanVi(-3);
        x--;
    }
}

void Xuong(){
    if (x<2){
        HoanVi(3);
        x++;
    }
}

void Trai(){
    if(y>0){
        HoanVi(-1);
        y--;
    }
}


void Phai(){
    if(y<2){
        HoanVi(1);
        y++;
    }
}




void KhoiTao(){
    srand((unsigned int)time(0));
    for(int i = 0;i<=200;i++){
        int r = rand()%4;
        if (r==0) Len();
        if (r==1) Xuong();
        if (r==2) Trai();
        if (r==3) Phai();
    }
}

void DiChuyen(int i){
    if (i == 75) Phai();
    if (i == 77) Trai();
    if (i == 72) Xuong();
    if (i == 80) Len();

}

int main(){
	
	int chon ;
	do{
		system("cls");
		printf("\t----------MENU----------\n");
		printf("\t 1. Tro choi moi\n");
		printf("\t 2. Huong dan choi\n");
		printf("\t 0. Thoat \n");
		scanf("%d", &chon);
		
		switch(chon){
			case 1:
			    while(1){
			        KhoiTao();
			        inOSo();
			        while(1){
			              if (kiemTraKetThuc()){
			                printf("\n\tChuc mung ban da thang\n");
			                break; 
			            }
			            int i = getch();
			            DiChuyen(i);
			            inOSo();
			        };
			        int c;
			        printf("Nhan phim 'c' de reset game...\n");
			        printf("Nhan phim bat ki de thoat");
			        c = getch();
			        if (!(c=='C' || c=='c'))
			            break;
			        

			    }
			    return 0;
			break;
			
			case 2:
				system("cls");
				printf("Dung W A S D de di chuyen cac con so\n");
				printf("Sap xep cac con so sao cho mang tao thanh mot mang cac chu so lien tiep\n");
				printf("\t 1, 2, 3\n\t 4, 5, 6\n\t 7, 8\n");
			break;
			
			default:
				printf("Ket thuc tro choi \n");
			break;
		}
	
		printf("Quay lai (Nhap y/n)");
		char c ;
		fflush(stdin);
		scanf("%c", &c);
		if(c == 'y'){
			chon = -1;
		}else{
			printf("Tam biet!");
		}
		  
	}while(chon != 1 && chon != 2 && chon !=3 && chon != 0);

}


