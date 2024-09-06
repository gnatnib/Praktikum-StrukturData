#include <stdio.h>
#include "tqueue3.h" 
#include "boolean.h"

/* Program   : tqueue3.c*/
/* Deskripsi : ADT Queue representasi kontigu dengan array,
               model III: head melingkar */
/* NIM/Nama  : 24060122120031 - Bintang Syafrian Rizal*/
/* Tanggal   : 27 September 2023*/
/***********************************/

boolean isEmptyQueue3(tqueue3 Q){
    return (Q).head == 0 && (Q).tail == 0;
}

boolean isFullQueue3(tqueue3 Q){
    return sizeQueue3(Q) == 5;
}

boolean isOneElement3(tqueue3 Q){
    return head3(Q) == tail3(Q);
}

void createQueue3(tqueue3 *Q){
    //Kamus Lokal
    int i;

    //Algoritma
    for (i = 1 ; i<=5 ; i++){
        (*Q).wadah[i] = '#';
    }
    (*Q).head = 0;
    (*Q).tail = 0;
}

int head3(tqueue3 Q){
    //Kamus Lokal

    //Algoritma
    return Q.head;
}

int tail3(tqueue3 Q){
    //Kamus Lokal

    //Algoritma
    return Q.tail;
}

char infoHead3(tqueue3 Q){
    //Kamus Lokal

    //Algoritma
    return Q.wadah[head3(Q)];
}

char infoTail3(tqueue3 Q){
    //Kamus Lokal

    //Algoritma
    return Q.wadah[tail3(Q)];
}

int sizeQueue3(tqueue3 Q){
    //Kamus Lokal

    //Algoritma
    if (!isEmptyQueue3(Q)){
        if (tail3(Q) >= head3(Q)){
            return tail3(Q) - head3(Q) + 1;
        }
        if (tail3(Q) < head3(Q)){
            return 5 - (head3(Q) - tail3(Q)) + 1;
        }
    }
    return 0;
}

void printQueue3(tqueue3 Q){
    //Kamus Lokal

    //Algoritma
    int i;

    for (i = 1 ; i<=5 ; i++){
        printf("%c ", (Q).wadah[i]);
    }
    printf("\n");
}

void viewQueue3(tqueue3 Q){
    //Kamus Lokal

    //Algoritma
    int i;

    if (!isEmptyQueue3(Q)){
        i = head3(Q);
        while (i != tail3(Q)){
            printf("%c ", (Q).wadah[i]);
            if (i == 5){
                i = 0;
            }
            i++;
        }
        printf("%c ", (Q).wadah[i]);
    }
    else{
        printf("Queue Kosong!");
    }
    printf("\n");
}

void enqueue3 (tqueue3 *Q,char E){
    //Kamus Lokal

    //Algoritma
    if (!isFullQueue3(*Q)){
        if (isEmptyQueue3(*Q)){
            (*Q).head = 1;
        }
        if ((*Q).tail == 5){
            (*Q).tail = 0;
        }
        (*Q).tail++;
        (*Q).wadah[tail3(*Q)] = E;
    }
    else{
        printf("Queue Penuh!");
    }
}

void dequeue3 (tqueue3 *Q,char *E){
    //Kamus Lokal

    //Algoritma
    if (!isEmptyQueue3(*Q)){
        *E = infoHead3(*Q);
        if (isOneElement3(*Q)){
            createQueue3(Q);
        }
        (*Q).wadah[head3(*Q)] = '#';
        if ((*Q).head == 5){
            (*Q).head = 1;
        }
        else{
            (*Q).head += 1;
        }
    }
    else{
        *E = ' ';
    }
}

boolean isTailOverHead(tqueue3 Q){
    //Kamus Lokal

    //Algoritma
    if (tail3(Q) < head3(Q)){
        return true;
    }
    else{
        return false;
    }
}

int countMember(tqueue3 Q, char E){
    //Kamus Lokal
    int i;
    int count;

    //Algoritma
    count = 0;
    for (i = 1 ; i <= 5 ; i++){
        if ((Q).wadah[i] == E){
            count++;
        }
    }
    return count;
}

void enqueue3E(tqueue3 *Q,char E){
    //Kamus Lokal

    //Algoritma
    if (!isFullQueue3(*Q)){
        if (countMember(*Q, E) == 0){
            enqueue3(&(*Q), E);
        }
    }
}