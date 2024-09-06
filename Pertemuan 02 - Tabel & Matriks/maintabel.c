/************************************/
/* Program   : mainTabel.c */
/* Deskripsi : aplikasi driver modul Tabel */
/* NIM/Nama  : 24060122120031 - Bintang Syafrian Rizal */
/* Tanggal   : 9 September 2023*/
/***********************************/
#include "tabel.c"
#include "tabel.h"
#include <stdio.h>

int main(){
    //Kamus Main
    Tabel T;
    int N;

    //Algoritma
	printf("Create Table :\n");
    createTable(&T);
    
	printf("T.wadah :\n");
    printTable(T);

    if (isEmptyTable(T)){
        printf("Apakah tabel kosong: True\n");
    }
    
    if (isFullTable(T)){
        printf("Apakah tabel penuh: True\n");
    }

	printf("Masukkan batas N Populate: ");
    scanf("%d", &N);

	printf("\nIsi Populate 1(T, 7) :\n");
    populate1(&T, N);
	// 1 2 2 3 3 4 4

	printf("\nIsi Populate 2(T) :\n");
	populate2(&T);
	// 4 2 1 4 0 9 8
    
	printf("Tabel setelah di Populate 2: \n");
	viewTable(T);

	printf("\nisEmptyTable(T) :\n%s\n", (isEmptyTable(T) ? "true" : "false\n"));

	printf("\nisFullTable(T) :\n%s\n", (isFullTable(T) ? "true" : "false\n"));

	getSize(T);
    printf("Size dari tabel adalah: %d\n", getSize(T));
    countEmpty(T);
    printf("Banyak elemen yang belum terisi yaitu: %d\n", countEmpty(T));
	
    int Pos;
    searchX1(T, 2, &Pos);
    printf("Elemen X berada dalam wadah: %d\n", Pos);

    int Byk;
    countX (T, 4, &Byk);
    printf("Elemen X dalam wadah berjumlah sebanyak: %d\n", Byk);

    printf("Sum dari isi wadah tabel yaitu: %d\n", SumEl(T));

   
    printf("Rata - rata dari isi wadah tabel yaitu: %d\n", AverageEl(T));

    
    printf("Nilai maksimum dari tabel yaitu: %d\n", getMaxEl(T));

   
    printf("Nilai minimum dari tabel yaitu: %d", getMinEl(T));

	printf("\ndelXTabel(T, 4) :\n");
	delXTable(&T, 4);
    printf("Tabel setelah elemen X dihapus: \n");
	printTable(T);
    
	printf("\naddXTabel(T, 4) :\n");
	addXTable(&T, 99);
    printf("Tabel setelah ditambahkan elemen X: \n");
	printTable(T);

	printf("\ndelAllXTabel(T, 2) :\n");
	delAllXTable(&T, 2);
    printf("Tabel setelah semua elemen X dihapus: \n");
	printTable(T);

	printf("\nModus(T) :\n%d\n", Modus(T));

	return 0;
}