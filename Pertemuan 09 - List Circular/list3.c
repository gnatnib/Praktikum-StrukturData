/* File : list3.c */
/* Deskripsi : Body list berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060122120031 - Bintang Syafrian Rizal*/
/* Tanggal : 18 - 11 - 2023*/                             

#include <stdio.h>
#include <stdlib.h>
#include "list3.h"

void CreateList (List3 *L){
	//Kamus Lokal

	//Algoritma
	First(*L) = NIL;
}

boolean IsEmptyList(List3 L){
	//Kamus Lokal

	//Algoritma
	return First(L) == NIL;
}

void PrintList (List3 L){
	//Kamus Lokal
	address P;

	//Algoritma
	if (!IsEmptyList(L)){
		P = First(L);
		do {
			printf("%c ", info(P));
			P = next(P);
		}while (P!=First(L));
		printf("\n");
	}
	else{
		printf("List Kosong!");
	}
}

int NbElm(List3 L){
	//Kamus Lokal
	address P;
	int count;

	//Algoritma
	count = 0;
	if (!IsEmptyList(L)) {
		P = First(L);
		do {
			count++;
			P = next(P);
		} while (P != First(L));
	}
	return count;
}

void Alokasi (address *P){
	//Kamus Lokal

	//Algoritma
	(*P) = (address)malloc(sizeof(ElmList3));
}

void Dealokasi (address *P){
	//Kamus Lokal
	
	//Algoritma
	free(*P);
}

void InsertVFirst (List3 *L, infotype V){
	//Kamus Lokal
	address P, last;

	//Algoritma
	Alokasi(&P);
	if (P!=NIL){
		info(P)=V;
		if (!IsEmptyList(*L)){
			last = First(*L);
			while (next(last)!=First(*L)){
				last = next(last);
			}
			next(P)=First(*L);
			next(last)=P;
		}
		else{
			next(P) = P;
		}
		First(*L)=P;
	}
}

void InsertVLast (List3 *L, infotype V){
	//Kamus Lokal
	address P, last;

	//Algoritma
	Alokasi(&P);
	if (P!=NIL){
		info(P)=V;
		if(!IsEmptyList(*L)){
			last = First(*L);
			while (next(last)!=First(*L)){
				last = next(last);
			}
			next(P) = First(*L);
			next(last)=P;
		}
		else{
			next(P) = P;
			First(*L)=P;
		}
	}
}

void DeleteVFirst (List3 *L, infotype *V){
	//Kamus Lokal
	address P, last;

	//Algoritma
	if (!IsEmptyList(*L)){
		P = First(*L);
		(*V) = info(P);
		//Kondisi One Element
		if (First(*L)==next(First(*L))){
			CreateList(L);
		}
		else{
			last = First(*L);
			while (next(last)!=First(*L)){
				last = next(last);
			}
			First(*L) = next(P);
			next(last) = First(*L);
		}
		Dealokasi(&P);
	}
}

// void DeleteVLast (List3 *L, infotype *V){
// 	//Kamus Lokal
// 	address P, last;

// 	//Algoritma
// 	if (!IsEmptyList(*L)) {
// 		P = First(*L);
// 		last = NIL;
// 		while (next(P)!=First(*L)){
// 			last = P;
// 			P = next(P);
// 		}
// 		(*V) = info(P);
// 		if (last==NIL){
// 			CreateList(L);
// 		}
// 		else{
// 			next(last)=First(*L);
// 		}
// 		Dealokasi(&P);
// 	}
// }

void DeleteVLast (List3 *L, infotype *V){
	//Kamus Lokal
	address P, last;

	//Algoritma
	if (!IsEmptyList(*L)) {
		P = First(*L);
		last = NIL;
		while (next(P) != First(*L)){
			last = P;
			P = next(P);
		}
		(*V) = info(P);
		if (last == NIL){
			CreateList(L);
		}
		else{
			next(last)=  First(*L);
		}
		Dealokasi(&P);
	}
}

void DeleteX (List3 *L, infotype X){
	//Kamus Lokal;
	address P, prec;

	//Algoritma
	P = First(*L);
	while (next(P) != First(*L) && info(P)!=X){
		prec = P;
		P = next(P);
	}
	if (info(P) == X){
		if (P == First(*L)){
			DeleteVFirst(L, &X);
		}
		else if (next(P) == First(*L)){
			DeleteVLast(L,&X);
		}
		else{
			next(prec) = next(P);
			Dealokasi(&P);
		}
	}
}

void SearchX (List3 L, infotype X, address *A){
	//Kamus Lokal
	address P;

	//Algoritma
	if (!IsEmptyList(L)){
		*A = NIL;
		P = First(L);
		while (next(P)!=First(L) && info(P)!=X){
			P = next(P);
		}
		if (info(P)==X){
			*A = P;
		}
	}
	else{
		printf("List Kosong");
	}
}

void UpdateX (List3 *L, infotype X, infotype Y){
	//Kamus Lokal
	address P;

	//Algoritma
	SearchX(*L, X, &P);
	if (P!=NIL){
		info(P) = Y;
	}
}

void Invers (List3 *L){
	//Kamus Lokal
	address P;
	List3 store;

	//Algoritma
	CreateList(&store);
	P = First(*L);

	do {
		InsertVFirst(&store, info(P));
		P = next(P);
	} while (P != First(*L));
	*L = store;
}

int CountX (List3 L, infotype X){
	//Kamus Lokal
	address P;
	int count;

	//Algoritma
	count = 0;
	if (!IsEmptyList(L)) {
		P = First(L);
		do {
			if (info(P) == X) {
				count++;
			}
			P = next(P);
		} while (P != First(L));
	}
	return count;
}

float FrekuensiX(List3 L, infotype X){
	//Kamus Lokal

	//Algoritma
	return (float)CountX(L,X)/ (float)NbElm(L);
}

char Modus (List3 L){
	//Kamus Lokal
	address P;
	char modus;
	int max;

	//Algoritma
	modus = ' ';
	if (!IsEmptyList(L)) {
		P = First(L);
		max = 0;
		do {
			if (CountX(L, info(P)) > max) {
				max = CountX(L, info(P));
				modus = info(P);
			}
			P = next(P);
		} while (P != First(L));
	}
	return modus;
}

int CountVocal (List3 L){
	//Kamus Lokal
	address P;
	int count;

	//Algoritma
	if (!IsEmptyList(L)){
		P = First(L);
		while (P!=First(L)){
			if (info(P) == 'A' || info(P) == 'I' || info(P) == 'U' || info(P) == 'E' || info(P) == 'O' || 
				info(P) == 'a' || info(P) == 'i' || info(P) == 'u' || info(P) == 'e' || info(P) == 'o') {
				count++;
			}
			P = next(P);
		}
	}
	return count;
}

int CountNG (List3 L){
	//Kamus Lokal
	address P;
	int count;

	//Algoritma
	count = 0;
	if (!IsEmptyList(L)) {
		P = First(L);
		do {
			if ((info(P) == 'N' && info(next(P)) == 'G') ||
				(info(P) == 'n' && info(next(P)) == 'g')) {
				count++;
			}
			P = next(P);
		} while (P != First(L));
	}
	return count;
}

void InsertVAfterX (List3 *L, infotype X, infotype V){
	//Kamus Lokal
	address P, Q;

	//Algoritma
	Q = First(*L);
	while (next(Q) != First(*L) && info(Q) != X){
		Q = next(Q);
	}
	if (info(Q)==X){
		Alokasi(&P);
		if (P!=NIL){
			info(P) = V;
			next(P) = next(Q);
			next(Q) = P;
		}
	}
}

void InsertVBeforeX (List3 *L, infotype X, infotype V){
	//Kamus Lokal
	address P, Q, prec;

	//Algoritma
	prec = NIL;
	Q = First(*L);
	while (next(Q) != First(*L) && info(Q) != X){
		prec = Q;
		Q = next(Q);
	}
	if (info(Q)==X){
		if (Q==First(*L)){
			InsertVFirst(L,V);
		}
		else{
			Alokasi(&P);
			if (P!=NIL){
				info(P) = V;
				next(P) = Q;
				next(prec) = P;
			}
		}
	}
}

void DeleteVAfterX (List3 *L, infotype X, infotype *V){
	//Kamus Lokal
	address P,Q;

	//Algoritma
	if (!IsEmptyList(*L)){
		Q = First(*L);
		while (next(Q) != First(*L) && info(Q) != X){
			Q = next(Q);
		}
		if (info(Q) == X){
			P = next(Q);
			*V = info(P);
			if (P == First(*L)){
				DeleteVFirst(L,V);
			}
			else if (next(P) == First(*L)){
				DeleteVLast(L,V);
			}
			else{
				next(Q) = next(P);
				Dealokasi (&P);
			}
		}
	}
}

void DeleteVBeforeX (List3 *L, infotype X, infotype *V){
	//Kamus Lokal
	address P, Q, prec;

	//Algoritma
	if (!IsEmptyList(*L)){
		prec = NIL;
		P = NIL;
		Q = First(*L);
		while (next(Q) != First(*L) && info(Q) != X){
			prec = P;
			P = Q;
			Q = next(Q);
		}
		if (info(Q) == X){
			if (Q == First(*L)){
				DeleteVLast(L,V);
			}
			else if (next(Q) == First(*L)){
				DeleteVFirst(L,V);
			}
			else{
				*V = info(P);
				next(prec) = Q;
				Dealokasi(&P);
			}
		}
	}
}

void SearchAllX (List3 L, infotype X){
	//Kamus Lokal
	address P;
	int i;
	boolean found;

	//Algoritma
	found = false;
	if (!IsEmptyList(L)) {
		P = First(L);
		i = 1;
		do {
			if (info(P) == X) {
				printf("Posisi %c berada di indeks ke-: %d\n", X,i);
				found = true;
			}
			P = next(P);
			i++;
		} while (P != First(L));
	}
	if (!found) {
		printf("Tidak ada!");
	}
	printf("\n");
}