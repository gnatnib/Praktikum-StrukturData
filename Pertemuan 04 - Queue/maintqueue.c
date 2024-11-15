#include <stdio.h>
#include <stdlib.h>
#include "tqueue.h"
#include "tqueue.c"
#include "boolean.h"

/* Program   : maintqueue.c */
/* Deskripsi : Realisasi ADT Queue aplikasi kontigu dengan array,
               model I: head selalu di posisi 0 atau 1 */
/* NIM/Nama  : 24060120120014 - Bintang Syafrian Rizal*/
/* Tanggal   : 20 September 2023*/
/***********************************/

int main (){
    //kamus
    tqueue A;
    char E;
    tqueue B;

    //algoritma
    printf("Create Queue A\n");
    createQueue(&A);
    printQueue(A);

    printf("\nCreate Queue B\n");
    createQueue(&B);
    printQueue(B);

    printf("\nEnqueue Queue A\n");
    enqueue(&A, 'b');
    enqueue(&A, 'i');
    enqueue(&A, 'n');
    enqueue(&A, 't');
    enqueue(&A, 'a');
    enqueue(&A, 'n');
    enqueue(&A, 'g');
    enqueue(&A, 'a');
    enqueue(&A, 'b');
    enqueue(&A, 'c');
    viewQueue(A);
    printf("\n");

    printf("Enqueue1 Queue A\n");
    enqueue1(&A, 'P');
    viewQueue(A);
    
    printf("\nApakah Queue A Kosong: \n%s\n", (isEmptyQueue(A) ? "true" : "false\n"));

	printf("Apakah Queue A Penuh: \n%s\n", (isFullQueue(A) ? "true" : "false\n"));

    printf("\nEnqueue Queue B\n");
    enqueue(&B, 'b');
    enqueue(&B, 'o');
    enqueue(&B, 's');
    enqueue(&B, 's');
    viewQueue(B);

    printf("\nApakah Queue B Kosong: \n%s\n", (isEmptyQueue(B) ? "true" : "false\n"));

	printf("Apakah Queue B Penuh: \n%s\n", (isFullQueue(B) ? "true" : "false\n"));

    printf("Max length : %d\n", maxlength(A,B));
    
    printf("\nDequeue Queue A\n");
    dequeue(&A,&E);
    viewQueue(A);
    printf("\n");

    printf("\nDequeue Queue B\n");
    dequeue(&B,&E);
    viewQueue(B);
    printf("\nMax Length : %d\n", maxlength(A,B));
    
    printf("\nEnqueue2\n");
    enqueue2(&A,&B,'a');
    viewQueue(B);

    printf("\nDequeue2\n");
    dequeue2(&A,&B,&E);
    printf("Elemen yang dikeluarkan dari queue setelah Dequeue 2: \n");
    printf("%c\n", E);

    printf("Queue Terpanjang Setelah Dequeue 2: \n");
    viewQueue(B);

    return 0;

}

