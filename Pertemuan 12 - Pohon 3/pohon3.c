/* File : pohon3.c */
/* Deskripsi : Body bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060122120031 - Bintang Syafrian Rizal*/
/* Tanggal : 08 - 12 - 2023*/    

#include <stdio.h>
#include <stdlib.h>
#include "pohon3.h"

void Alokasi3 (bintree3 *P){
    //Kamus Lokal

    //Algoritma
    (*P) = (bintree3)malloc(sizeof(node3));
}

void Dealokasi3 (bintree3 *P){
    //Kamus Lokal

    //Algoritma
    free(*P);
}

bintree3 Tree3 (bintree3 A, infotype X, boolean V, bintree3 kiri, bintree3 kanan){
    //Kamus Lokal
    bintree3 P;

    //Algoritma
    Alokasi3(&P);
    if (P!=NIL){
        parent(P)=A;
        info(P)=X;
        left(P)=kiri;
        right(P)=kanan;
        visited(P)=V;
    }
    return P;
}

boolean IsEmptyTree(bintree3 P){
    //Kamus Lokal

    //Algoritma
    return P == NIL;
}

boolean IsDaun(bintree3 P){
    //Kamus Lokal

    //Algoritma
    return IsEmptyTree(left(P)) && IsEmptyTree(right(P));
}

boolean IsBiner(bintree3 P){
    //Kamus Lokal

    //Algoritma
    return !IsEmptyTree(right(P)) && !IsEmptyTree(left(P)) && !IsEmptyTree(P);
}

boolean IsUnerLeft(bintree3 P){
    //Kamus Lokal
    //Algoritma

    return !IsEmptyTree(left(P)) && IsEmptyTree(right(P)) && !IsEmptyTree(P);
}

boolean IsUnerRight(bintree3 P){
    //Kamus Lokal

    //Algoritma
    return !IsEmptyTree(left(P)) && IsEmptyTree(right(P)) && !IsEmptyTree(P);
}

boolean SearchXtree(bintree3 P, infotype X){
    //Kamus Lokal

    //Algoritma
    if(IsEmptyTree(P)){
        return false;
    }else{
        if(info(P)==X){
            return true;
        }else{
            return (SearchXtree(left(P),X)||SearchXtree(right(P),X));
        }
    }
}

void PrintPrefix (bintree3 P){
    //Kamus Lokal

    //Algoritma
    if (P==NIL){
        printf("( )");
    }
    else{
        printf("%c(", info(P));
        PrintPrefix(left(P));
        printf(",");
        PrintPrefix(right(P));
        printf(")");
    }
}

int NbElmTree (bintree3 P){
    //Kamus Lokal

    //Algoritma
    if (IsEmptyTree(P)){
        return 0;
    }
    else{
        return 1 + NbElmTree(left(P)) + NbElmTree(right(P));
    }
}

int NbDaun (bintree3 P){
    //Kamus Lokal

    //Algoritma
    if (IsEmptyTree(P)){
        return 0;
    }
    else if (IsDaun(P)){
        return 1;
    }
    else{
        return NbDaun(left(P)) + NbDaun(right(P));
    }
}

int max2 (int a, int b){
    //Kamus Lokal
    
    //Algoritma
    if (a>b){
        return a;
    }
    else{
        return b;
    }
}

int Tinggi (bintree3 P){
    //Kamus Lokal

    //Algoritma
    if (IsEmptyTree(P)){
        return -1;
    }
    else{
        return 1 + max2(Tinggi(left(P)), Tinggi(right(P)));
    }
}

int Level (bintree3 P){
    //Kamus Lokal

    //Algoritma
    return Tinggi(P) + 1;
}

int CountLevelT(bintree3 P, int T){
    //Kamus Lokal

    //Algoritma
    if (T==0){
        return 0;
    }
    else if (T==1){
        if (IsBiner(P)){
            return 2;
        }
        else if (IsUnerLeft(P) || IsUnerRight(P)){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return CountLevelT(left(P),T-1) + CountLevelT(right(P),T-1);
    }
}

void pconcat (List1 *Asli, List1 Tambahan){
    //Kamus Lokal
    address Last;

    //Algoritma
    if (IsEmptyList(*Asli)){
        (*Asli) = Tambahan;
    }
    else{
        Last = First(*Asli);
        while (next(Last)!=NIL){
            Last = next(Last);
        }
        next(Last)=First(Tambahan);
    }
}

List1 fconcat(List1 Asli, List1 Tambahan){
    //Kamus Lokal
    List1 Baru;
    address P;

    //Algoritma
    CreateList(&Baru);

    P = First(Asli);

    while (P!=NIL){
        InsertVLast(&Baru, info(P));
        P = next(P);
    }

    P = First(Tambahan);
    
    while (P!=NIL){
        InsertVLast(&Baru, info(P));
        P = next(P);
    }
    return Baru;
}

List1 linearPrefix (bintree3 P){
    //Kamus Lokal
    List1 temp;

    //Algoritma
    CreateList(&temp);

    if (P!=NIL){
        InsertVLast(&temp, info(P));
        pconcat(&temp, linearPrefix(left(P)));
        pconcat(&temp, linearPrefix(right(P)));
    }
    return temp;
}

List1 linearPosfix (bintree3 P){
    //Kamus Lokal
    List1 temp;

    //Algoritma
    CreateList(&temp);

    if (P!=NIL){
        pconcat(&temp, linearPrefix(left(P)));
        pconcat(&temp, linearPrefix(right(P)));
        InsertVLast(&temp, info(P));
    }
    return temp;
}

List1 linearInfix (bintree3 P){
    //Kamus Lokal
    List1 temp;

    //Algoritma
    CreateList(&temp);
    if (P!=NIL){
        pconcat(&temp, linearPrefix(left(P)));
        InsertVLast(&temp, info(P));
        pconcat(&temp, linearPrefix(right(P)));
    }
    return temp;
}

List1 MakeListLevel (bintree3 P, int N){
    //Kamus Lokal
    List1 temp;

    //Algoritma
    CreateList(&temp);
    if (!IsEmptyTree(P)){
        if (N == 1){
            InsertVLast(&temp, info(P));
        }
        else{
            temp = fconcat(MakeListLevel(left(P),N-1), MakeListLevel(right(P),N-1));

        }
    }
    return temp;
}

List1 linearBreadthFS (bintree3 P){
    //Kamus Lokal
    List1 temp;
    int i;

    //Algoritma
    CreateList(&temp);
    for (i = 1 ; i <= Tinggi(P) + 1 ; i++ ){
        temp = fconcat((temp), MakeListLevel(P,i));
    }
    return temp;
}

void printPathX(bintree3 P, infotype X) {
    //Kamus Lokal

    //Algoritma
    if (IsEmptyTree(P)) {
        printf("Tidak ketemu!\n");
        return;
    }

    printf("%c", info(P));

    if (info(P) == X) {
        printf("\n");
        return;
    }
    printf(" -> ");
    if (SearchXtree(left(P), X)) {
        printPathX(left(P), X);
    } 
    else if (SearchXtree(right(P), X)) {
        printPathX(right(P), X);
    }
}

void printPathDaunX(bintree3 P, infotype X) {
    //Kamus Lokal

    //Algoritma
    if (IsEmptyTree(P)) {
        printf("Tidak ketemu!\n");
        return;
    }

    printf("%c", info(P));

    if (SearchXtree(left(P), X)) {
        printf(" -> ");
        printPathDaunX(left(P), X);
    } 
    else if (SearchXtree(right(P), X)) {
        printf(" -> ");
        printPathDaunX(right(P), X);
    } 
    else if (info(P) == X) {
        if (IsDaun(P)) {
            printf("\n");
        } else {
            printf(" bukan daun!\n");
        }
    }
}

List1 DaunTree(bintree3 P){
    //Kamus Lokal
    List1 temp;

    //Algoritma
    CreateList(&temp);
    if(!IsEmptyTree(P)){
        if(IsDaun(P)){
            InsertVLast(&temp,info(P));
        }else{
            temp = fconcat(DaunTree(left(P)),DaunTree(right(P)));
        }
    }

    return temp;
}


void printAllPaths(bintree3 P){
    //Kamus Lokal
    List1 temp;
    address A;

    //Algoritma
    temp = DaunTree(P);
    A = First(temp);
    
    while(A!=NIL){

        printPathDaunX(P,info(A));
        printf("\n");
        A = next(A);
    }
}