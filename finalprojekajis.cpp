#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

#ifdef _cplusplus_
  #include <cstdlib>
#else
  #include <stdlib.h>
#endif

struct stc_member{
	char pelajaran[77];   	
	char kode[69];
	char stock[8];		
	char tanggalpinjam[20];
	char terpinjam[30];	
}MEMBRE[6];					

void CLEAR_SCREEN(){
	if (system("CLS")) system("clear");
};

char PRINT_TABLE_HEAD(){
	printf("================================================================================\n");
	printf("| %-2s | %-15s | %-9s | %-10s | %-10s | %-18s |\n", "No", "Nama Pelajaran", "Kode Buku", "Stock Buku", "Terpinjam", "Tanggal Peminjaman");
	printf("================================================================================\n");
}

char PRINT_TABLE_BODY(int number, char* pelajaran, char* kode, char* stock, char* terpinjam, char* tanggalpinjam){
	printf("| %-2d | %-15s | %-9s | %-10s | %-10s | %-18s |\n", number, pelajaran, kode, stock, terpinjam, tanggalpinjam);
}

char PRINT_TABLE_FOOTER(){
	printf("================================================================================\n");
	printf("================================================================================\n");
}

void READ_DEFAULT(){
	int i = 0;
	FILE *f_membre = fopen("data.txt", "r");
	
	while((fscanf(f_membre, "%s %s %s %s %s", &MEMBRE[i].pelajaran, &MEMBRE[i].kode, &MEMBRE[i].stock, &MEMBRE[i].terpinjam,  &MEMBRE[i].tanggalpinjam))!=EOF){
		
		i++;
	}
}

void READ_BY_DEFAULT(){
	READ_DEFAULT();
	
	int i = 0;
	int size = sizeof(MEMBRE)/sizeof(MEMBRE[0]);
	PRINT_TABLE_HEAD();
	
	for(i=0; i<size; i++){
		PRINT_TABLE_BODY(i+1, MEMBRE[i].pelajaran, MEMBRE[i].kode, MEMBRE[i].stock, MEMBRE[i].terpinjam, MEMBRE[i].tanggalpinjam);
	}
	
	PRINT_TABLE_FOOTER();
}

void READ_BY_NAME(){
	READ_DEFAULT();
	
	int j, i;
	char pelajaran_temp[69], kode_temp[69], stock_temp[69], terpinjam_temp[69], tanggalpinjam_temp[69];
	int size = sizeof(MEMBRE)/sizeof(MEMBRE[0]);
	PRINT_TABLE_HEAD();
	
	for(i=0; i<size; i++){
		for(j=i+1; j<=size; j++){
			if(strcmp(MEMBRE[i].pelajaran, MEMBRE[j].pelajaran)>0){
				strcpy(pelajaran_temp, MEMBRE[i].pelajaran);
            	strcpy(MEMBRE[i].pelajaran, MEMBRE[j].pelajaran);
            	strcpy(MEMBRE[j].pelajaran, pelajaran_temp);
            	
            	strcpy(kode_temp, MEMBRE[i].kode);
            	strcpy(MEMBRE[i].kode, MEMBRE[j].kode);
            	strcpy(MEMBRE[j].kode, kode_temp);
            	
            	strcpy(stock_temp, MEMBRE[i].stock);
            	strcpy(MEMBRE[i].stock, MEMBRE[j].stock);
            	strcpy(MEMBRE[j].stock, stock_temp);
            	
            	strcpy(terpinjam_temp, MEMBRE[i].terpinjam);
            	strcpy(MEMBRE[i].terpinjam, MEMBRE[j].terpinjam);
            	strcpy(MEMBRE[j].terpinjam, terpinjam_temp);
            	
            	strcpy(tanggalpinjam_temp, MEMBRE[i].tanggalpinjam);
            	strcpy(MEMBRE[i].tanggalpinjam, MEMBRE[j].tanggalpinjam);
            	strcpy(MEMBRE[j].tanggalpinjam, tanggalpinjam_temp);
			}
		}
	}
	
	for(i=1; i<=size; i++){
		PRINT_TABLE_BODY(i, MEMBRE[i].pelajaran, MEMBRE[i].kode, MEMBRE[i].stock, MEMBRE[i].terpinjam, MEMBRE[i].tanggalpinjam);
	}
	
	PRINT_TABLE_FOOTER();
}

void READ_BY_PINJAM(){
	READ_DEFAULT();
	
	int j, i, pinjam, pinjam2;
	char pelajaran_temp[69], kode_temp[69], stock_temp[69], terpinjam_temp[69], tanggalpinjam_temp[69];
	int size = sizeof(MEMBRE)/sizeof(MEMBRE[0]);
	PRINT_TABLE_HEAD();
	
	for(i=0; i<size; i++){
		for(j=i+1; j<=size; j++){
			if(strcmp(MEMBRE[i].tanggalpinjam, MEMBRE[j].tanggalpinjam)>0){
				strcpy(pelajaran_temp, MEMBRE[i].pelajaran);
            	strcpy(MEMBRE[i].pelajaran, MEMBRE[j].pelajaran);
            	strcpy(MEMBRE[j].pelajaran, pelajaran_temp);
            	
            	strcpy(kode_temp, MEMBRE[i].kode);
            	strcpy(MEMBRE[i].kode, MEMBRE[j].kode);
            	strcpy(MEMBRE[j].kode, kode_temp);
            	
            	strcpy(stock_temp, MEMBRE[i].stock);
            	strcpy(MEMBRE[i].stock, MEMBRE[j].stock);
            	strcpy(MEMBRE[j].stock, stock_temp);
            	
            	strcpy(terpinjam_temp, MEMBRE[i].terpinjam);
            	strcpy(MEMBRE[i].terpinjam, MEMBRE[j].terpinjam);
            	strcpy(MEMBRE[j].terpinjam, terpinjam_temp);
            	
            	strcpy(tanggalpinjam_temp, MEMBRE[i].tanggalpinjam);
            	strcpy(MEMBRE[i].tanggalpinjam, MEMBRE[j].tanggalpinjam);
            	strcpy(MEMBRE[j].tanggalpinjam, tanggalpinjam_temp);
			}
		}
	}
	
	for(i=1; i<=size; i++){
		PRINT_TABLE_BODY(i, MEMBRE[i].pelajaran, MEMBRE[i].kode, MEMBRE[i].stock, MEMBRE[i].terpinjam, MEMBRE[i].tanggalpinjam);
	}
	
	PRINT_TABLE_FOOTER();
}

void SEARCH_MEMBRE(){
	READ_DEFAULT();
	
	char keyword[69];
	int size = sizeof(MEMBRE)/sizeof(MEMBRE[0]);
	int i, status;
	
	printf("Masukan kode buku: ");
	scanf("%s", &keyword);
	
	status = 0;
	for(i=0; i<size; i++){
		if(strcasecmp(keyword, MEMBRE[i].kode) == 0){
			printf("\nNama Pelajaran: %s", MEMBRE[i].pelajaran);
			printf("\nKode Buku: %s", MEMBRE[i].kode);
			printf("\nStock: %s", MEMBRE[i].stock);
			printf("\nTerpinjam: %s", MEMBRE[i].terpinjam);
			printf("\nTanggal Peminjaman Terakhir: %s", MEMBRE[i].tanggalpinjam);
			status = 1;
			break;
		}
	}
	
	if(status == 0){
		printf("\nnotfound");
	}
}


void MAIN_MENU(){
	printf("1. List Pelajaran\n");
	printf("2. Cari Buku\n");
	printf("3. Urutkan Buku\n");
	printf("4. Keluar\n");
}

void SORT_MENU(){
	char anw_user;
	do{
		CLEAR_SCREEN();
		printf("1. Urutkan Berdasarkan Pelajaran \n");
		printf("2. Urutkan Berdasarkan Tanggal Pinjam\n");
		printf("3. Kembali\n");
		
		do{
			printf("\nMasukan Pilihanmu [1..3]");
			anw_user = getche();
			
		}while((anw_user!='1')&&(anw_user!='2')&&(anw_user!='3'));
		switch(anw_user){
			case '1': CLEAR_SCREEN(); READ_BY_NAME(); break;
			case '2': CLEAR_SCREEN(); READ_BY_PINJAM(); break;
		};
		if(anw_user!='3')
			getche();
	}while(anw_user!='3');
}

int main(){
	char anw_user;
	do{
		CLEAR_SCREEN();
		printf("PEMINJAMAN BUKU OFFLINE\n\n");
		MAIN_MENU();
		
		do{
			fflush(stdin);
			printf("\nMasukan pilihan mu [1..4]");
			anw_user = getche();
			
		}while((anw_user!='1')&&(anw_user!='2')&&(anw_user!='3')&&(anw_user!='4'));
		switch(anw_user){
			case '1': CLEAR_SCREEN(); READ_BY_DEFAULT(); break;
			case '2': CLEAR_SCREEN(); SEARCH_MEMBRE(); break;
			case '3': CLEAR_SCREEN(); SORT_MENU(); break;
		};
		if(anw_user!='4')
			getche();
	}while(anw_user!='4');
}
