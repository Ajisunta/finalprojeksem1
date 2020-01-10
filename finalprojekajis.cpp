#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

#ifdef _cplusplus_
  #include <cstdlib>
#else
  #include <stdlib.h>
#endif

struct stc_hp{
	char hp[77];   	
	char kode[69];
	char stock[8];		
	char merek[20];
	char price[30];	
}listhp[100];					

void CLEAR_SCREEN(){
	if (system("CLS")) system("clear");
};

FILE	*f_menu;

char PRINT_TABLE_HEAD(){
	printf("================================================================================\n");
	printf("| %-2s | %-15s | %-9s | %-10s | %-18s | %-10s |\n", "No", "Nama hp", "Barcode hp", "Stock hp", "harga hp", "merek");
	printf("================================================================================\n");
}

char PRINT_TABLE_BODY(int number, char* hp, char* kode, char* stock, char* merek, char* price){
	printf("| %-2d | %-15s | %-9s | %-10s | Rp. %-18s |  %-10s |\n", number, hp, kode, stock, price, merek);
}

char PRINT_TABLE_FOOTER(){
	printf("================================================================================\n");
	printf("================================================================================\n");
}

void READ_DEFAULT(){
	int i = 0;
	FILE *f_listhp = fopen("data.txt", "r");
	while((fscanf(f_listhp, "%s %s %s %s %s", &listhp[i].hp, &listhp[i].kode, &listhp[i].stock, &listhp[i].price,  &listhp[i].merek))!=EOF){
		
		i++;
	}
}

void READ_BY_DEFAULT(){
	READ_DEFAULT();
	
	int i = 0;
//	int size = sizeof(listhp)/sizeof(listhp[0]);
	PRINT_TABLE_HEAD();	
	for(i = 0; i < sizeof(f_menu); i++) {
		PRINT_TABLE_BODY(i+1, listhp[i].hp, listhp[i].kode, listhp[i].stock, listhp[i].merek, listhp[i].price);
	}
	PRINT_TABLE_FOOTER();
}

void READ_BY_NAME(){
	READ_DEFAULT();
	
	int j, i;
	char hp_temp[69], kode_temp[69], stock_temp[69], merek_temp[69], price_temp[69];
//	int size = sizeof(listhp)/sizeof(listhp[0]);
	PRINT_TABLE_HEAD();
	
	for(i=0; i<sizeof(f_menu); i++){
		for(j=i+1; j<=sizeof(f_menu); j++){
			if(strcmp(listhp[i].hp, listhp[j].hp)>0){
				strcpy(hp_temp, listhp[i].hp);
            	strcpy(listhp[i].hp, listhp[j].hp);
            	strcpy(listhp[j].hp, hp_temp);
            	
            	strcpy(kode_temp, listhp[i].kode);
            	strcpy(listhp[i].kode, listhp[j].kode);
            	strcpy(listhp[j].kode, kode_temp);
            	
            	strcpy(stock_temp, listhp[i].stock);
            	strcpy(listhp[i].stock, listhp[j].stock);
            	strcpy(listhp[j].stock, stock_temp);
            	
            	strcpy(merek_temp, listhp[i].merek);
            	strcpy(listhp[i].merek, listhp[j].merek);
            	strcpy(listhp[j].merek, merek_temp);
            	
            	strcpy(price_temp, listhp[i].price);
            	strcpy(listhp[i].price, listhp[j].price);
            	strcpy(listhp[j].price, price_temp);
			}
		}
	}
	
	for(i=1; i<=sizeof(f_menu); i++){
		PRINT_TABLE_BODY(i, listhp[i].hp, listhp[i].kode, listhp[i].stock, listhp[i].merek, listhp[i].price);
	}
	
	PRINT_TABLE_FOOTER();
}

void READ_BY_PRICE(){
	READ_DEFAULT();
	
	int j, i, pinjam, pinjam2;
	char hp_temp[69], kode_temp[69], stock_temp[69], merek_temp[69], price_temp[69];
//	int size = sizeof(listhp)/sizeof(listhp[0]);
	PRINT_TABLE_HEAD();
	
	for(i=0; i<sizeof(f_menu); i++){
		for(j=i+1; j<=sizeof(f_menu); j++){
			if(strcmp(listhp[i].price, listhp[j].price)>0){
				strcpy(hp_temp, listhp[i].hp);
            	strcpy(listhp[i].hp, listhp[j].hp);
            	strcpy(listhp[j].hp, hp_temp);
            	
            	strcpy(kode_temp, listhp[i].kode);
            	strcpy(listhp[i].kode, listhp[j].kode);
            	strcpy(listhp[j].kode, kode_temp);
            	
            	strcpy(stock_temp, listhp[i].stock);
            	strcpy(listhp[i].stock, listhp[j].stock);
            	strcpy(listhp[j].stock, stock_temp);
            	
            	strcpy(merek_temp, listhp[i].merek);
            	strcpy(listhp[i].merek, listhp[j].merek);
            	strcpy(listhp[j].merek, merek_temp);
            	
            	strcpy(price_temp, listhp[i].price);
            	strcpy(listhp[i].price, listhp[j].price);
            	strcpy(listhp[j].price, price_temp);
			}
		}
	}
	
	for(i=1; i<=sizeof(f_menu); i++){
		PRINT_TABLE_BODY(i, listhp[i].hp, listhp[i].kode, listhp[i].stock, listhp[i].merek, listhp[i].price);
	}
	
	PRINT_TABLE_FOOTER();
}

void SEARCH_listhp(){
	READ_DEFAULT();
	
	char keyword[69];
//	int size = sizeof(listhp)/sizeof(listhp[0]);
	int i, status;
	
	printf("Masukan kode hp: ");
	scanf("%s", &keyword);
	
	status = 0;
	for(i=0; i<sizeof(f_menu); i++){
		if(strcasecmp(keyword, listhp[i].kode) == 0){
			printf("\nNama hp: %s", listhp[i].hp);
			printf("\nKode hp: %s", listhp[i].kode);
			printf("\nStock: %s", listhp[i].stock);
			printf("\nmerek: %s", listhp[i].merek);
			printf("\nharga: %s", listhp[i].price);
			status = 1;
			break;
		}
	}
	
	if(status == 0){
		printf("\nnotfound");
	}
}


void MAIN_MENU(){
	printf("1. List hp\n");
	printf("2. Cari hp\n");
	printf("3. Urutkan hp\n");
	printf("4. Tambah Hp\n");
	printf("5. Keluar\n");
}

void SORT_MENU(){
	char anw_user;
	do{
		CLEAR_SCREEN();
		printf("1. Urutkan Berdasarkan nama hp \n");
		printf("2. Urutkan Berdasarkan harga\n");
		printf("3. Kembali\n");
		
		do{
			printf("\nMasukan Pilihanmu [1..3]");
			anw_user = getche();
			
		}while((anw_user!='1')&&(anw_user!='2')&&(anw_user!='3'));
		switch(anw_user){
			case '1': CLEAR_SCREEN(); READ_BY_NAME(); break;
			case '2': CLEAR_SCREEN(); READ_BY_PRICE(); break;
		};
		if(anw_user!='3')
			getche();
	}while(anw_user!='3');
}

void ADD_DATA() {
	int i = 0;
	char ch_repeat;
	do{
		CLEAR_SCREEN();
//		SHOW_DATA();
		
		f_menu = fopen("data.txt","a");
		printf("Pengisian Data HP");
		printf("\nInput HP Name :"); fflush(stdin);gets(listhp[i].hp);
		printf("\nInput Kode hp :"); fflush(stdin);gets(listhp[i].kode);
		printf("\nInput stock:"); fflush(stdin);gets(listhp[i].stock);
		printf("\nInput merek:"); fflush(stdin);gets(listhp[i].merek);
		printf("\nInput price:"); fflush(stdin);gets(listhp[i].price);
		
		fprintf(f_menu, "%s %s %s %s %s\n",listhp[i].hp, listhp[i].kode, listhp[i].stock, listhp[i].price, listhp[i].merek);
		do {
			fflush(stdin);
			printf("Apakah anda ingin menambah data item lagi ? [Y/N] : ");
			ch_repeat = getche();
		}while ((ch_repeat!='y')&&(ch_repeat!='Y')&&(ch_repeat!='n')&&(ch_repeat!='N'));
		fclose(f_menu);
	}while ((ch_repeat=='y')||(ch_repeat=='Y'));
}

int main(){
	char anw_user;
	do{
		CLEAR_SCREEN();
		printf("TOKO HP BINUSIAN\n\n");
		MAIN_MENU();
		
		do{
			fflush(stdin);
			printf("\nMasukan pilihan mu [1..5]");
			anw_user = getche();
			
		}while((anw_user!='1')&&(anw_user!='2')&&(anw_user!='3')&&(anw_user!='4')&&(anw_user!='5'));
		switch(anw_user){
			case '1': CLEAR_SCREEN(); READ_BY_DEFAULT(); break;
			case '2': CLEAR_SCREEN(); SEARCH_listhp(); break;
			case '3': CLEAR_SCREEN(); SORT_MENU(); break;
			case '4': CLEAR_SCREEN(); ADD_DATA(); break;
		};
		if(anw_user!='5')
			getche();
	}while(anw_user!='5');
}
