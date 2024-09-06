/* File : pohon1.c */
/* Deskripsi : Body bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060122120031 - Bintang Syafrian Rizal*/
/* Tanggal : 25 - 11 - 2023*/                             

#include <stdio.h>
#include <stdlib.h>
#include "pohon1.h"

void Alokasi (bintree *P){
    //Kamus Lokal
    
    //Algoritma
    *(P) = (bintree)malloc(sizeof(node));
}

void Dealokasi (bintree *P){
    //Kamus Lokal

    //Algoritma
    free(*P);
}

bintree Tree (infotype akar, bintree left, bintree right){
    //Kamus Lokal
    bintree P;

    //Algoritma
    Alokasi(&P);
    if (P!=NIL){
        akar(P) = akar;
        left(P) = left;
        right(P) = right;
    }
    return P;
}

infotype GetAkar (bintree P){
    //Kamus Lokal

    //Algoritma
    return akar(P);
}

bintree GetLeft (bintree P){
    //Kamus Lokal

    //Algoritma
    return left(P);
}

bintree GetRight (bintree P){
    //Kamus Lokal

    //Algoritma
    return right(P);
}

boolean IsEmptyTree (bintree P){
    //Kamus Lokal

    //Algoritma
    return (P==NIL);
}

boolean IsDaun (bintree P){
    //Kamus Lokal

    //Algoritma
    return (right(P) == NIL && left(P)==NIL);
}

boolean IsBiner (bintree P){
    //Kamus Lokal

    //Algoritma
    return (right(P) != NIL && left(P) != NIL);
}

boolean IsUnerLeft (bintree P){
    //Kamus Lokal

    //Algoritma
    return (right(P) == NIL && left(P) != NIL);
}

boolean IsUnerRight (bintree P){
    //Kamus Lokal

    //Algoritma
    return (right(P) != NIL && left(P) == NIL);
}

void PrintPrefix (bintree P){
    //Kamus Lokal

    //Algoritma
    if (IsEmptyTree(P)){
        printf("()");
    }
    else{
        printf ("%c(", GetAkar(P));
        PrintPrefix(GetLeft(P));
        printf(",");
        PrintPrefix(GetRight(P));
        printf(")");
    }
}

int NbElm (bintree P){
    //Kamus Lokal

    //Algoritma
    if (IsEmptyTree(P)){
        return 0;
    }
    else{
        return 1 + NbElm(left(P)) + NbElm(right(P));
    }
}

int NbDaun (bintree P){
    //Kamus Lokal

    //Algoritma
    if (IsEmptyTree(P)){
        return 0;
    }
    if (IsDaun(P)){
        return 1;
    }
    else{
        return NbDaun(left(P)) + NbDaun(right(P));
    }
}

int max2 (int a, int b){
    //Kamus Lokal
    int max;
    //Algoritma
    max=0;
    if (a>b){
        max = a;
    }
    else{
        max = b;
    }
    return max;
}

int Tinggi (bintree P){
    //Kamus Lokal

    //Algoritma
    if(IsEmptyTree(P)){
        return -1;
    }
    else{
        return 1 + max2(Tinggi(left(P)), Tinggi(right(P)));
    }
}

boolean SearchX (bintree P, infotype X){
    //Kamus Lokal

    //Algoritma;
    if (IsEmptyTree(P)){
        return false;
    }
    else{
        if(info(P)==X){
            return true;
        }
        else{
            return SearchX(left(P),X) || SearchX(right(P),X);
        }
    }
}

void UpdateX (bintree *P, infotype X, infotype Y){
    //Kamus Lokal

    //Algoritma
    if (!IsEmptyTree(*P)){
        if(info(*P)==X){
            info(*P)=Y;
        }
        else{
            UpdateX(&left(*P),X,Y);
            UpdateX(&right(*P),X,Y);

        }
    }
}

int CountX (bintree P, infotype X){
    //Kamus Lokal

    //Algoritma
    if (IsEmptyTree(P)){
        return 0;
    }
    else{
        if (info(P)==X){
            return 1 + CountX(left(P), X) + CountX(right(P), X);
        }
        else{
            return CountX(left(P), X) + CountX(right(P), X);
        }
    }
}

boolean IsSkewLeft (bintree P){
    //Kamus Lokal

    //Algoritma
    return (IsUnerLeft(P) && IsSkewLeft(left(P))) || IsDaun(P);
}

boolean IsSkewRight (bintree P){
    //Kamus Lokal

    //Algoritma
    return (IsUnerRight(P) && IsSkewRight(right(P))) || IsDaun(P);
}

void PrintPref (bintree P){
    //Kamus Lokal

    //Algoritma
    if (IsEmptyTree(P)){
        printf("()");
    }
    else{
        printf("%c", info(P));
        if (!IsDaun(P)){
            printf("(");
            PrintPref(left(P));
            printf(",");
            PrintPref(right(P));
            printf(")");
        }
    }
}

int LevelX(bintree P, infotype X){
    //Kamus Lokal

    //Algoritma
    if(info(P)==X){
        return 1;
    }
    else{
        if (SearchX(left(P),X)){
            return 1 + LevelX(left(P),X);
        }
        else{
            return 1 + LevelX(right(P),X);
        }
    }
}

int CountLevelT (bintree P, int T){
    //Kamus Lokal

    //Algoritma
    if (IsEmptyTree(P)){
        return 0;
    }
    else{
        if (T==1){
            return 1;
        }
        else{
            return CountLevelT(left(P),T - 1) + CountLevelT(right(P), T - 1);
        }
    }
}

infotype GetDaunTerkiri (bintree P){
    //Kamus Lokal

    //Algoritma
    if (IsEmptyTree(P)){
        return '#'; //kosong
    }
    else{
        if (IsDaun(P)){
            return info(P);
        }
        else if (!IsEmptyTree(left(P))){
            return GetDaunTerkiri(left(P));
        }
        else{
            return GetDaunTerkiri(right(P));
        }
    }
}

float FrekuensiX (bintree P, infotype X){
    //Kamus Lokal

    //Algoritma
    return (float)CountX(P,X) / NbElm(P);
}

int CountVocal (bintree L){
    //Kamus Lokal

    //Algoritma
    if (IsEmptyTree(L)){
        return 0;
    }
    else{
        if (info(L) == 'A' || info(L) == 'I' || info(L) == 'U' || info(L) == 'E' || info(L) == 'O' ||
            info(L) == 'a' || info(L) == 'i' || info(L) == 'u' || info(L) == 'e' || info(L) == 'o') {
            return 1 + CountVocal(left(L)) + CountVocal(right(L));
        }
        else{
            return CountVocal(left(L)) + CountVocal(right(L));
        }
    }
}

char Modus (bintree P){
    //Kamus Lokal

    //Algoritma
    if (IsEmptyTree(P)){
        return '#';
    }
    else{
        if (CountX(P, info(P)) > CountX(P, Modus(left(P))) && CountX(P, info(P)) > CountX(P, Modus(right(P)))) {
            return info(P);
        } 
        else if (CountX(P, Modus(left(P))) > CountX(P, Modus(right(P)))) {
            return Modus(left(P));
        } 
        else {
            return Modus(right(P));
        }
    }
}