#include <stdio.h>
#include "tqueue.h" 
#include "boolean.h"

void createQueue (tqueue *Q){
    /* Kamus Lokal */
    int i;

    /* Algoritma */
    for (i = 1 ; i<=5 ; i++){
        (*Q).wadah[i] = '$';
    }
    (*Q).head = 0;
    (*Q).tail = 0;
}

char infoHead (tqueue Q){
    /* Kamus Lokal */

    /* Algoritma */
    if (isEmptyQueue(Q)){
        return isEmptyQueue(Q);
    }
    else{
        return (Q).wadah[(Q).head];
    }
}

char infoTail (tqueue Q){
    /* Kamus Lokal */

    /* Algoritma */
    if (isEmptyQueue(Q)){
        return isEmptyQueue(Q);
    }
    else{
        return (Q).wadah[(Q).tail];
    }
}

int sizeQueue (tqueue Q){
    /* Kamus Lokal */

    /* Algoritma */
    return tail(Q);
}

void printQueue (tqueue Q){
    /* Kamus Lokal */
    int i;
    /* Algoritma */
    for (i = 1 ; i <= 5; i++){
        printf ("  %c", (Q).wadah[i]);
    }
    printf("\n");
}

void viewQueue (tqueue Q){
    /* Kamus Lokal */
    int i;
    /* Algoritma */
    for (i = 1; i <= (Q).tail ; i++){
        printf ("  %c", (Q).wadah[i]);
    }
    printf("\n");
}

boolean isEmptyQueue(tqueue Q){
    return tail(Q) == 0;
}

boolean isFullQueue(tqueue Q){
    return tail(Q)==5;
}

boolean isOneElement(tqueue Q){
    return tail(Q)==1;
}

void enqueue (tqueue *Q, char E){
    /* Kamus Lokal */

    /* Algoritma */
    if (!isFullQueue(*Q)){
        if (isEmptyQueue(*Q)){
            (*Q).wadah[(*Q).tail+1] = E;
            (*Q).tail += 1;
            (*Q).head += 1;
        }
        else{
            (*Q).wadah[(*Q).tail+1] = E;
            (*Q).tail += 1;
        }
    }
    else{
        printf("Queue Penuh ");
    }
}

void dequeue(tqueue *Q, char *E){
    /* Kamus Lokal */
    int i;

    /* Algoritma */
    if (!isEmptyQueue(*Q)){
        (*E) = infoHead(*Q);
        if (isOneElement(*Q)){
            createQueue(Q);
        }
        else{
            for (i=2 ; i<= (*Q).tail ; i++){
                (*Q).wadah[i-1]= (*Q).wadah[i];
            }
            (*Q).wadah[tail(*Q)] = '$';
            (*Q).tail -= 1;
        }
    }
    else{
        (*E) = ' ';
        printf ("Queue Kosong!");
    }
}

int maxlength(tqueue Q1, tqueue Q2){
    /* Kamus Lokal */

    /* Algoritma */
    if (tail(Q1) > tail(Q2)){
        return tail(Q1);
    }
    else if (tail(Q2) > tail(Q1)){
        return tail(Q2);
    }
    else{
        return 0;
    }
}

void enqueue2(tqueue *Q1, tqueue *Q2, char E){
    /* Kamus Lokal */

    /* Algoritma */
    if (sizeQueue(*Q1) > sizeQueue(*Q2)){
        enqueue(Q2, E);
    }
    else{
        enqueue(Q1, E);
    }
}

void dequeue2(tqueue *Q1, tqueue *Q2, char *E){
    /* Kamus Lokal */

    /* Algoritma */
    if (sizeQueue(*Q1) > sizeQueue(*Q2)){
        dequeue(Q1, E);
    }
    else{
        dequeue(Q2, E);
    }
}

