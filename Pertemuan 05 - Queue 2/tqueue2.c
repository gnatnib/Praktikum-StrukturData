#include <stdio.h>
#include "tqueue2.h" 
#include "boolean.h"

/* Program   : tqueue2.c */
/* Deskripsi : file BODY modul queue kontigu jelajah */
/* NIM/Nama  : 24060122120031 - Bintang Syafrian Rizal*/
/* Tanggal   : 30 September 2023*/
/***********************************/

void createQueue2(tqueue2 *Q){
    //Kamus Lokal
    int i;

    //Algoritma
    for (i=1 ; i <= 5; i++){
        (*Q).wadah[i] = '#';
    }
    (*Q).head = 0;
    (*Q).tail = 0;
}

int head2(tqueue2 Q){
    //Kamus Lokal

    //Algoritma
    return Q.head;
}

int tail2(tqueue2 Q){
    //Kamus Lokal

    //Algoritma
    return Q.tail;
}

boolean isEmptyQueue2(tqueue2 Q){
    //Kamus Lokal

    //Algoritma
    return head2(Q) == 0;
}

boolean isFullQueue2(tqueue2 Q){
    //Kamus Lokal

    //Algoritma
    return head2(Q) == 1 && tail2(Q) == 5;
}

boolean isOneElement2(tqueue2 Q){
    //Kamus Lokal

    //Algoritma
    if (!isEmptyQueue2(Q)){
        return head2(Q) == tail2(Q);
    }
    else{
        return false;
    }
    
}

char infoHead2(tqueue2 Q){
    //Kamus Lokal

    //Algoritma
    return Q.wadah[head2(Q)];
}

char infoTail2(tqueue2 Q){
    //Kamus Lokal

    //Algoritma
    return Q.wadah[tail2(Q)];
}

int sizeQueue2(tqueue2 Q){
    //Kamus Lokal

    //Algoritma
    if (isEmptyQueue2(Q)){
        return 0;
    }
    else{
        return tail2(Q) - head2(Q) + 1;
    }
}

void printQueue2(tqueue2 Q){
    //Kamus Lokal
    int i;

    //Algoritma
    for (i = 1 ; i <= 5 ; i++){
        printf("%c ", Q.wadah[i]);
    }
    printf("\n");
}

void viewQueue2(tqueue2 Q){
    //Kamus Lokal
    int i;
    
    //Algoritma
    for (i = head2(Q) ; i <= tail2(Q) ; i++){
        printf("%c ", Q.wadah[i]);
    }
    printf("\n");
}

boolean isTailStop2(tqueue2 Q){
    //Kamus Lokal

    //Algoritma
    return head2(Q) > 1 && tail2(Q) == 5;
}

void resetHead2 (tqueue2 *Q){
    //Kamus Lokal
    int i;

    //Algoritma
    for (i = 1 ; i<=sizeQueue2(*Q) ; i++){
        (*Q).wadah[i] = (*Q).wadah[head2(*Q)+i-1];
        (*Q).wadah[head2(*Q)+i-1] = '#';
    }
    (*Q).tail = sizeQueue2(*Q);
    (*Q).head = 1;
}

void enqueue2(tqueue2 *Q, char E){
    if(!isFullQueue2(*Q)){
        if(isEmptyQueue2(*Q)){
            (*Q).head=1;
        }else if(isTailStop2(*Q)){
            resetHead2(Q);
        }

        (*Q).tail+=1;
        (*Q).wadah[tail2(*Q)]=E;
    }else{
        printf("Queue Penuh\n");
    }
}

void dequeue2(tqueue2 *Q, char *E){
    //Kamus Lokal

    //Algoritma
    if (!isEmptyQueue2(*Q)){
        *E = infoHead2(*Q);
        (*Q).wadah[head2(*Q)] = '#';

        if (isOneElement2(*Q)){
            (*Q).tail = 0;
            (*Q).head = 0;
        }
        (*Q).head += 1; 
    }
    else{
        *E = '#';
    }
}

void enqueue2N (tqueue2 *Q, int N){
    //Kamus Lokal
    char E;

    //Algoritma
    if (N > 5 - sizeQueue2(*Q)){
        printf("Jumlah elemen yang dimasukkan melebihi kapasitas queue!\n");
    }
    else{
        for (int i = 1 ; i <= N ; i++){
            printf("Masukkan elemen ke-%d: ", i);
            scanf(" %c", &E);
            enqueue2(&(*Q), E);
        }
    }
}

boolean isEqualQueue2(tqueue2 Q1, tqueue2 Q2){
    //Kamus Lokal
    int i;
    int j;

    //Algoritma
    if (isEmptyQueue2(Q1) && isEmptyQueue2(Q2)){
        return true;
    }
    else{
        if (sizeQueue2(Q1) != sizeQueue2(Q2)){
            return false;
        }
        else{
            i = head2(Q1);
            j = head2(Q2);
            while (i <= tail2(Q1) && j <= tail2(Q2)){
                if (Q1.wadah[i] != Q2.wadah[j]){
                    return false;
                }
                i++;
                j++;
            }
            return true;
        }
    }
}

