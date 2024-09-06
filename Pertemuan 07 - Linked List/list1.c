/* File : list1.c */
/* Deskripsi : Body list berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060122120031 - Bintang Syafrian Rizal*/
/* Tanggal : 04 - 11 - 2023*/

#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

void CreateList (List1 *L){
    //Kamus Lokal

    //Algoritma
    First(*L) = NIL;
}

boolean IsEmptyList (List1 L){
    //Kamus Lokal

    //Algoritma
        return First(L) == NIL;
}

void PrintList (List1 L){
    //Kamus Lokal
    address P;
    P = First(L);

    //Algoritma 
    while (P != NIL){
        printf("%c", info(P));
        P = next(P);
    }
    printf("\n");
}

int NbElm (List1 L){
    //Kamus Lokal
    address P;
    int count=0;

    //Algoritma;
    P = First(L);
    while (P != NIL){
        count++;
        P = next(P);
    }
    return count;
}

void Alokasi (address *P){
    //Kamus Lokal

    //Algoritma
    *P = (address)malloc(sizeof(ElmList));
}

void Dealokasi (address *P){
    //Kamus Lokal

    //Algoritma
    free(*P);
}

void InsertVFirst (List1 *L, infotype V){
    //Kamus Lokal
    address P;
    Alokasi(&P);

    //Algoritma
    if (P != NIL){
        info(P) = V;
        next(P) = First(*L);
        First(*L) = P;
    }
}

void InsertVLast (List1 *L, infotype V){
    //Kamus Lokal
    address P;
    address Last;
    Alokasi(&P);

    //Algoritma
    if (First(*L) == NIL){
        InsertVFirst(L, V);
    }
    else{
        Last = First(*L);
        while (next(Last)!=NIL){
            Last = next(Last);
        }
        next(Last)= P;
        info(P) = V;
        next(P) = NIL;
    }
}

void DeleteVFirst(List1 *L, infotype *V) {
    // Kamus Lokal
    address P;

    // Algoritma
    P = First(*L);
    if (!IsEmptyList(*L)) {
        *V = info(P);
        First(*L) = next(P);
        printf("Elemen yang dihapus: %c\n", *V);
        Dealokasi(&P);
    } else {
        printf("List Kosong!\n");
    }
}

void DeleteVLast(List1 *L, infotype *V) {
    // Kamus Lokal
    address P, Last;

    // Algoritma
    P = First(*L);

    if (IsEmptyList(*L)) {
        printf("List Kosong!\n");
        return;
    }

    if (next(P) == NIL) { // Only one element in the list
        *V = info(P);
        printf("Elemen yang dihapus: %c\n", *V);
        First(*L) = NIL;
        Dealokasi(&P);
    } else {
        while (next(next(P)) != NIL) {
            P = next(P);
        }
        Last = next(P);
        *V = info(Last);
        printf("Elemen yang dihapus: %c\n", *V);
        next(P) = NIL;
        Dealokasi(&Last);
    }
}



void SearchX (List1 L, infotype X, address *A){
    //Kamus Lokal
    address P;
    boolean found;

    //Algoritma
    *A = NIL;
    P = First(L);
    found = false;

    while (P != NIL && !found){
        if (info(P) == X){
            found = true;
            *A = P;
        }
        P = next(P);
        printf("Huruf ditemukan!\n");
    }
    if (!found){
        A = NIL;
        printf("Huruf yang dicari tidak ditemukan!\n");
    }
}

void UpdateX(List1 *L, infotype X, infotype Y) {
	//Kamus Lokal
	address P;

	//Algoritma
	SearchX(*L, X, &P);
	if (P != NIL) {
		info(P) = Y;
	}
}

void Invers(List1 *L) {
	//Kamus Lokal
	address P;
	List1 Temp;
	
    //Algoritma
	CreateList(&Temp);
	P = First(*L);
	while (P != NIL) {
		InsertVFirst(&Temp, info(P));
		P = next(P);
	}
	*L = Temp;
}

int CountX (List1 L, infotype X){
    //Kamus Lokal
    address P;
    int count;

    //Algoritma
    P = First(L);
    count = 0;
    while (P != NIL){
        if (info(P) == X){
            count++;
        }
        P = next(P);
    }
    return count;
}

float FrekuensiX(List1 L, infotype X){
    return (float)CountX(L, X)/NbElm(L);
}

char Modus(List1 L){
    //Kamus Lokal
    address P;
    char modus;
    int max;

    //Algoritma 
    P = First(L);
    max = 0;
    while (P != NIL){
        if (CountX(L, info(P)) > max){
            max = CountX(L,info(P));
            modus = info(P);
        }
        P = next(P);
    }
    return modus;
}

void SearchAllX(List1 L, infotype X){
    //Kamus Lokal
    address P;
    
    //Algoritma
    P = First(L);
    while (P != NIL){
        if (info(P) == X){
            printf("Posisi Alamat: %p\n", P);
        }
        P = next(P);
    }
    printf("\n");
}

void InsertVAfter (List1 *L, infotype V, infotype VA){
    //Kamus Lokal
    address P, Prev;
    
    //Algoritma
    Alokasi(&P);
    if (P != NIL){
        info(P) = VA;
        SearchX(*L, V, &Prev);
        if (Prev != NIL){
            next(P) = next(Prev);
            next(Prev) = P;
        }
    }    
}