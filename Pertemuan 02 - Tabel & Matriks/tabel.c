/************************************/
/* Program   : tabel.c */
/* Deskripsi : realisasi body modul Tabel */
/* NIM/Nama  : 24060122120031 - Bintang Syafrian Rizal */
/* Tanggal   : 9 September 2023*/
/***********************************/
#include <stdio.h>
#include <stdlib.h>
#include "tabel.h"

void createTable (Tabel *T){
    //Kamus Lokal
    int i;

    //Algoritma
    for (i = 1; i<=10; i++){
        (*T).wadah[i]=-999;
    }
    (*T).size = 0;
}

void printTable (Tabel T){
    //Kamus Lokal
    int i;

    //Algoritma 
    for (i = 1; i<=10; i++){
        printf("%d \n", T.wadah[i]);
    }
}

void viewTable (Tabel T){
    //Kamus Lokal
    int i;

    //Algoritma
    for (i = 1; i <= T.size; i++){
        printf("%d \n", T.wadah[i]);
    }
}

int getSize (Tabel T){
    //Kamus Lokal

    //Algoritma
    return T.size;
}

int countEmpty (Tabel T){
    //Kamus Lokal

    //Algoritma
    return 10 - T.size;
}

boolean isEmptyTable (Tabel T){
    //Kamus Lokal

    //Algoritma
    return T.size == 0;
}

boolean isFullTable (Tabel T){
    //Kamus Lokal

    //Algoritma
    return T.size == 10;
}

void populate1(Tabel *T, int N) {
    /* Kamus Lokal */
    int X;
    /* Algoritma */
    while (N > 0) {
        scanf("%d", &X);
        if (X > 0) {
            (*T).size++;
            (*T).wadah[(*T).size] = X;
            N--;
        } else {
            printf("Masukan tidak boleh kurang dari 0! Silahkan Input Ulang: \n");
        }
    }
}

void searchX1 (Tabel T, int X, int *Pos){
    //Kamus Lokal
    int i;

    //Algoritma
    for (i = 1; i<=10; i++){
        if (T.wadah[i] == X){
            *Pos = i;
        }
    }
}

void countX (Tabel T, int x, int *Byk){
    //Kamus Lokal
    int i;

    //Algoritma
    for (i = 1; i <= 10; i++){
        if (T.wadah[i] == x){
            *Byk += 1;
        }
    }
}

int SumEl (Tabel T){
    //Kamus Lokal
    int i, sum=0;

    //Algoritma
    for (i = 1; i <= T.size; i++){
        sum += T.wadah[i];
    }
    return sum;
}

int AverageEl (Tabel T){
    //Kamus Lokal
    int avg=0;

    //Algoritma
    avg += SumEl(T)/T.size;
    return avg;
}

int getMaxEl (Tabel T){
    //Kamus Lokal
    int i, maxValue;

    //Algoritma
    maxValue = T.wadah[1];

    for (i = 1; i <= T.size ; i++){
        if (T.wadah[i] > maxValue){
            maxValue = T.wadah[i];
        }
    }
    return maxValue;
}

int getMinEl (Tabel T){
    //Kamus Lokal
    int i, minValue;
    minValue = T.wadah[1];

    //Algoritma
    for (i = 1 ; i <= T.size ; i++){
        if (T.wadah[i] < minValue){
            minValue = T.wadah[i];
        }
    }
    return minValue;
}

void populate2(Tabel *T) {
    /* Kamus Lokal */
    int X;
    boolean check;
    /* Algoritma */
    check = true;
    while (!isFullTable(*T) && check) {
        scanf("%d", &X);
        if (X > 0) {
            (*T).size++;
            (*T).wadah[(*T).size] = X;
        } else {
            check = false;
        }
    }
}


void addXTable (Tabel *T, int X){
    //kamus lokal

    //algoritma
    (*T).wadah[(*T).size+1] = X;
    (*T).size +=1;
}

void delXTable(Tabel *T, int X) {
    /* Kamus Lokal */
    int i, j;
    boolean check;
    /* Algoritma */
    if (isEmptyTable(*T)) {
        printf("Tabel kosong\n");
    } else {
        i = 1;
        check = false;
        while (i <= (*T).size && !check) {
            if ((*T).wadah[i] == X) {
                for (j = i; j < (*T).size; j++) {
                    (*T).wadah[j] = (*T).wadah[j + 1];
                }
                (*T).wadah[(*T).size] = -999;
                (*T).size--;
                check = true;
            }
            i++;
        }
    }
}

void delAllXTable(Tabel *T, int X) {
    /* Kamus Lokal */
    int i, j;
    /* Algoritma */
    if (isEmptyTable(*T)) {
        printf("Tabel kosong\n");
    } else {
        for (i = 1; i <= (*T).size; i++) {
            if ((*T).wadah[i] == X) {
                for (j = i; j < (*T).size; j++) {
                    (*T).wadah[j] = (*T).wadah[j + 1];
                }
                (*T).wadah[(*T).size] = -999;
                (*T).size--;
                i--;
            }
        }
    }
}
    
int Modus (Tabel T){
    //Kamus Lokal
    int i, j, mod;
    int max = 0;

    //Algoritma
    for (i=1 ; i <= T.size ; i++){
        int count = 0;
        for (j=1 ; j<=T.size ; j++){
            if (T.wadah[i] == T.wadah[j]){
                count++;
            }
        }
        if (count > max){
            max = count;
            mod = T.wadah[i];
        }
    }
    return mod;
}