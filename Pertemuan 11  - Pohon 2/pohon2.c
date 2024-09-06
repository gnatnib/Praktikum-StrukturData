/* File : pohon2.c */
/* Deskripsi : Body bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060122120031 - Bintang Syafrian Rizal*/
/* Tanggal : 03 - 12 - 2023*/       
  
#include <stdio.h>
#include <stdlib.h>
#include "pohon2.h"

void PrintLevel (bintree P, int N){
    //Kamus Lokal

    //Algoritma
    if (!IsEmptyTree(P)){
        if (N == 1){
            printf("%c ", info(P));
        }
        else{
            PrintLevel(left(P), N-1);
            PrintLevel(right(P),N-1);
        }
    }
}

bintree BuildBalanceTree(int n){
    //Kamus Lokal
    bintree P;

    //Algoritma
    if (n == 0){
        return NIL;
    }
    else{
        Alokasi(&P);
        printf("Masukkan nilai node ke -%d: ", n);
        scanf(" %c", &info(P));
        left(P) = BuildBalanceTree(n/2);
        right(P) = BuildBalanceTree(n-n/2-1);
        return P;
    }
}

boolean IsBalanceTree(bintree P){
    //Kamus Lokal

    //Algoritma
    return abs(NbElm(left(P))- NbElm(right(P))) <=1;
}

void AddDaunTerkiri(bintree *P, infotype X){
    //Kamus Lokal

    //Algoritma
    if (IsDaun(*P)){
        left(*P) = Tree(X,NIL,NIL);
    }
    else{
        if(IsBiner(*P) || IsUnerLeft(*P)){
            AddDaunTerkiri(&left(*P), X);
        }
        else{
            AddDaunTerkiri(&right(*P), X);
        }
    }
}

void AddDaun(bintree *P, infotype X, infotype Y, boolean Kiri){
    //Kamus Lokal

    //Algoritma
    if(!IsEmptyTree(*P)){
        if(IsDaun(*P)){
            if (info(*P)==X){
                if (Kiri){
                    left(*P) = Tree(Y,NIL,NIL);
                }
                else{
                    right(*P) = Tree(Y,NIL,NIL);
                }
            }
        }
        else{
            AddDaun(&left(*P), X, Y, Kiri);
            AddDaun(&right(*P), X, Y, Kiri);
        }
    }
}

void InsertX(bintree *P, infotype X){
    //Kamus Lokal

    //Algoritma
    if(!SearchX(*P, X)){
        AddDaunTerkiri(P,X);
    }
}

void DelDaunTerkiri(bintree *P, infotype *X){
    //Kamus Lokal

    //Algoritma
    if (IsDaun(*P)) {
        *X = info(*P);
        *P = NIL;
        Dealokasi(P);
    }
    else{
        if (IsBiner(*P) || IsUnerLeft(*P)){
            DelDaunTerkiri(&left(*P), X);
        }
        else if (IsUnerRight(*P)){
            DelDaunTerkiri(&right(*P), X);
        }
    }
}

void DelDaun(bintree *P, infotype X){
    //Kamus Lokal

    //Algoritma
    if (!IsEmptyTree(*P)){
        if (IsDaun(*P)){
            if (info(*P)==X){
                *P = NIL;
                Dealokasi(P);
            }
        }
        else{
            DelDaun(&left(*P), X);
            DelDaun(&right(*P),X);
        }
    }
}

void DeleteX(bintree *P, infotype X){
    //Kamus Lokal
    //Algoritma
    if (!IsEmptyTree(*P)){
        if (info(*P)==X){
            if(IsDaun(*P)){
                *P = NIL;
                Dealokasi(P);
            }
            else if (IsUnerLeft(*P)){
                *P = left(*P);
            }
            else if (IsUnerRight(*P)){
                *P = right(*P);
            }
            else{
                DelDaunTerkiri(P, &info(*P));
            }
        }
        else{
            DeleteX(&left(*P),X);
            DeleteX(&right(*P),X);
        }
    }
}

void UpdateAllX(bintree *P, infotype X, infotype Y){
    //Kamus Lokal

    //Algoritma
    if (!IsEmptyTree(*P)){
        if (info(*P)==X){
            info(*P) = Y;
        }
        UpdateAllX(&left(*P), X, Y);
        UpdateAllX(&right(*P), X, Y);
    }
}

char maxTree(bintree P){
    //Kamus Lokal
    char i, max;

    //Algoritma
    i = 'A';
    max ='\0';

    while (i <= 'Z'){
        if (SearchX(P, i)){
            max = i;
        }
        i++;
    }
    return max;
}

char minTree(bintree P){
    //Kamus Lokal
    char i, min;

    //Algoritma
    i = 'Z';
    min = '\0';

    while (i >= 'A'){
        if (SearchX(P, i)){
            min = i;
        }
        i--;
    }
    return min;
}

boolean BSearch(bintree P, infotype X){
    //Kamus Lokal

    //Algoritma
    if (IsEmptyTree(P)){
        return false;
    }
    else{
        if (info(P)==X){
            return true;
        }
        else if (X < info(P)){
            return BSearch(left(P), X);
        }
        else{
            return BSearch(right(P), X);
        }
    }
}

bintree InsSearch(bintree P, infotype X){
    //Kamus Lokal
    bintree Q;
    //Algoritma
    Q = P;
    if (!BSearch(Q,X)){
        if (IsEmptyTree(Q)){
            Q = Tree(X,NIL,NIL);
        }
        else{
            if (X < info(Q)){
                left(Q) = InsSearch(left(Q), X);
            }
            else{
                right(Q) = InsSearch(right(Q), X);
            }
        }
    }
    return Q;
}

void DelBtree(bintree *P, infotype X){
    //Kamus Lokal

    //Algoritma
    if (!IsEmptyTree(*P)){
        if (info(*P)==X){
            if(IsDaun(*P)){
                *P = NIL;
                Dealokasi(P);
            }
            else if(IsUnerLeft(*P)){
                *P = left(*P);
            }
            else if (IsUnerRight(*P)){
                *P = right(*P);
            }
            else{
                DelDaunTerkiri(P, &info(*P));
            }
        }
        else{
            if (X < info(*P)){
                DelBtree(&left(*P), X);
            }
            else{
                DelBtree(&right(*P), X);
            }
        }
    }
}