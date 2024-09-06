/* File : list2.c */
/* Deskripsi : Body list berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060122120031 - Bintang Syafrian Rizal*/
/* Tanggal : 10 - 11 - 2023*/

#include <stdio.h>
#include <stdlib.h>
#include "list2.h"

void CreateList (list2 *L){
    //Kamus Lokal

    //Algoritma
    First(*L) = NIL;
}

boolean IsEmptyList (list2 L){
    //Kamus Lokal

    //Algoritma
    return First(L) == NIL;
}

void PrintList (list2 L){
    //Kamus Lokal
    address P;

    //Algoritma
    if (IsEmptyList(L)){
        printf("List Kosong");
    }
    else{
        P=First(L);
        while (P!=NIL){
            printf("%c", info(P));
            P = next(P);
        }
    }
    printf("\n");
}

int NbElm(list2 L){
    //Kamus Lokal
    address P;
    int count;

    //Algoritma
    count = 0;
    P = First(L);
    while (P!=NIL){
        count++;
        P = next(P);
    }
    return count;
}

void Alokasi (address *P){
    //Kamus Lokal

    //Algoritma
    (*P) = (address)malloc(sizeof(ElmList2));
}

void Dealokasi (address *P){
    //Kamus Lokal

    //Algoritma
    free(*P);
}

void InsertVFirst (list2 *L, infotype V){
    //Kamus Lokal
    address P;

    //Algoritma
    Alokasi(&P);
    if (P!=NIL){
        info(P) = V;
        if(IsEmptyList(*L)){
            First(*L) = P;
            next(First(*L)) = NIL;
        }
        else{
            next(P) = First(*L);
            prev(First(*L)) = P;
        }
        First(*L) = P;
    }
}

void InsertVLast (list2 *L, infotype V){
    //Kamus Lokal
    address P, last;
    
    //Algoritma
    Alokasi(&P);
    if (P!=NIL){
        info(P) = V;
        next(P) = NIL;
        if (IsEmptyList(*L)){
            First(*L) = P;
        }
        else{
            last = First(*L);
            while (next(last)!= NIL){
                last = next(last);
            }
            prev(P) = last;
            next(last) = P;
        }
    }
}

void DeleteVFirst (list2 *L, infotype *V){
    //Kamus Lokal
    address P;

    //Algoritma
    P = First(*L);
    (*V)= info(P);
    if (next(P) != NIL){
        First(*L)=next(P);
        prev(next(P)) = NIL;
        prev(First(*L)) = NIL;
    }
    else{
        First(*L) = NIL;
    }
}

void DeleteVLast (list2 *L, infotype *V){
    //Kamus Lokal
    address last;

    //Algoritma
    if (!IsEmptyList(*L)){
        last = First(*L);
        (*V) = info(last);
        if (next(last) == NIL){
            CreateList(L);
        }
        else{
            while (next(last) != NIL){
                last = next(last);
            }
            next(prev(last)) = NIL;
        }
    }
}

void DeleteX (list2 *L, infotype X){
    //Kamus Lokal
    address P;

    //Algoritma
    P = First(*L);
    if (NbElm(*L) == 1){
        if (info(P) == X){
            CreateList(L);
        }
    }
    else{
        while (P != NIL && info(P) != X){
            P = next(P);
        }
        if (info(P) == X){
            if(prev(P)==NIL){
                First(*L)=next(P);
                prev(First(*L))=NIL;
            }
            else if (prev(P)!= NIL && next(P) !=NIL){
                next(prev(P))=next(P);
                prev(next(P))=prev(P);
            }
            else{
                next(prev(P)) = NIL;
            }
        }
    }
}

void SearchX (list2 L, infotype X, address *A){
    //Kamus Lokal
    address P;

    //Algoritma
    if (!IsEmptyList(L)){
        P= First(L);
        while (P!=NIL && info(P)!=X){
            P = next(P);
        }
        if (info(P)==X){
            printf("X ditemukan, ");
            (*A) = P;
        }
        else{
            printf("Elemen yang dicari tidak ditemukan!\n");
        }
    }
}

void UpdateX (list2 *L, infotype X, infotype Y){
    //Kamus Lokal
    address P;
    boolean found;

    //Algoritma
    P = First(*L);
    found = false;
    while (P!=NIL && !found){
        if(info(P)==X){
            info(P) = Y;
            found = true;
        }
        P = next(P);
    }
}

void Invers (list2 *L){
    //Kamus Lokal
    address P;
    list2 M;

    CreateList(&M);
    P = First(*L);
    while(P!=NIL){
        InsertVFirst(&M, info(P));
        P = next(P);
    }
    (*L) = M;
}

void InsertVAfterX (list2 *L, infotype X, infotype V){
    //Kamus Lokal
    address P, Q;

    //Algoritma
    if (!IsEmptyList(*L)){
        Alokasi(&P);
        if(P!=NIL){
            info(P) = V;
            Q = First(*L);
            while(Q!=NIL && info(Q)!=X){
                Q = next(Q);
            }
            if (info(Q)==X){
                prev(P) = Q;
                if (next(Q)!=NIL){
                    next(P)=next(Q);
                    prev(next(Q))= P;
                }
                next(Q)=P;
            }
        }
    }
}

void InsertVBeforeX (list2 *L, infotype X, infotype V){
    //Kamus Lokal
    address P,Q;

    //Algoritma
    if(!IsEmptyList(*L)){
        Alokasi(&P);
        if(P!=NIL){
            info(P)=V;
            Q=First(*L);
            while(Q!=NIL && info(Q)!=X){
                Q = next(Q);
            }
            if (info(Q)==X){
                next(P)=Q;
                if (prev(Q)!=NIL){
                    prev(P)=prev(Q);
                    next(prev(Q)) = P;
                }
                else{
                    First(*L) = P;
                }
                prev(Q) = P;
            }
        }
        prev(First(*L)) = NIL;
    }
}

void DeleteVAfterX(list2 *L, infotype X, infotype *V){
    //Kamus Lokal
    address P;

    //Algoritma
    if (!IsEmptyList(*L)&&NbElm(*L)>1){
        P = First(*L);
        while(P!=NIL && info(P)!=X){
            P=next(P);
        }
        if (info(P)==X && next(P)!=NIL){
            (*V) = info(next(P));
            if (next(next(P))==NIL){
                next(P) = NIL;
            }
            else{
                prev(next(P)) = prev(P);
                next(prev(P)) = next(P);
            }
        }
    }
}

void DeleteVBeforeX(list2 *L, infotype X, infotype *V){
    //Kamus Lokal
    address P;

    //Algoritma
    if (!IsEmptyList(*L)&&NbElm(*L)>1){
        P = First(*L);
        while(P!=NIL && info(P)!=X){
            P=next(P);
        }
        if (info(P)==X && next(P)!=NIL){
            (*V) = info(prev(P));
            if (prev(prev(P))==NIL){
                First(*L) = P;
                prev(P) = NIL;
            }
            else{
                prev(next(P)) = prev(P);
                next(prev(P)) = next(P);
            }
        }
        prev(First(*L))=NIL;
    }
}

int CountX (list2 L, infotype X){
    //Kamus Lokal
    address P;
    int count;

    //Algoritma
    count = 0;
    P = First(L);
    while (P!=NIL){
        if(info(P) == X){
            count++;
        }
        P = next(P);
    }
    return count;
}

float FrekuensiX(list2 L, infotype X){
    return (float)CountX(L, X)/(float)NbElm(L);
}

char Modus (list2 L){
    //Kamus Lokal
    address P;
    int max, temp;
    char store;
    
    //Algoritma
    max = 0;
    store = ' ';

    P = First(L);
    while (P!=NIL){
        temp = CountX(L, info(P));
        if (temp>max){
            store = info(P);
            max = CountX(L, info(P));
        }
        P = next(P);
    }
    return store;
}

void SearchAllX(list2 L, infotype X){
    //Kamus Lokal
    address P;
    int i;
    
    //Algoritma
    i = 1;
    P = First(L);
    if (P==NIL){
        printf("List Kosong!");
    }
    while (P != NIL){
        if (info(P) == X){
            printf("Posisi %c berada di indeks ke-: %d\n", X,i);
        }
        i++;
        P = next(P);
    }
    printf("\n");
}