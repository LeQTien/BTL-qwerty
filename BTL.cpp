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
	char chon, c;
	int restart;
	do{
		restart=0;
		system("cls");
		printf("----------MENU----------\n");
		printf("1. Tro choi moi\n");
		printf("2. Huong dan choi\n");
		printf("0. Thoat\n");
		fflush(stdin);
		chon=getch();
		switch(chon){
			case '1':
			    while(1){
			        KhoiTao();
			        inOSo();
			        while(1){
			            if (kiemTraKetThuc()){
			            	system("cls");
			            	printf("Chuc mung ban da chien thang\n\n");
			                break; 
			            }
			            int i = getch();
			            DiChuyen(i);
			            inOSo();
			        };
			        printf("Nhan phim 'c' de reset game\n");
			        printf("Nhan phim bat ki de thoat");
			        c = getch();
			        if (!(c=='C' || c=='c')){
			        	system("cls");
			        	printf("Hen gap lai ban lan sau\n");
			            break;
					}
			    }
			    return 0;
			break;
			
			case '2':
				do{
					system("cls");
					printf("Dung cac phim mui ten de di chuyen cac con so\n");
					printf("Sap xep cac con so sao cho mang tao thanh mot mang cac chu so lien tiep nhu ben duoi\n");
					printf("\t 1 2 3\n\t 4 5 6\n\t 7 8\n");
					printf("Nhan y de quay lai menu");
					fflush(stdin);
					c = getch();
					if(c == 'y'){
						restart = 1;
					}
				}while(c!='y');
				break;
				
			case '0':
				system("cls");
				printf("Hen gap lai ban lan sau\n");
			break;
			return 0;
		}
	}while(restart == 1);
}



