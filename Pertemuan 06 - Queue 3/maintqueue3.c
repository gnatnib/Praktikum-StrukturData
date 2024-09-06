#include <stdio.h>
#include <stdlib.h>
#include "tqueue3.h"
#include "tqueue3.c"
#include "boolean.h"

/* Program   : maintqueue3.c */
/* Deskripsi : Realisasi ADT Queue aplikasi kontigu dengan array,
               model III: melingkar */
/* NIM/Nama  : 24060122120031 - Bintang Syafrian Rizal*/
/* Tanggal   : 06 Oktober 2023*/
/***********************************/

int main (){
    //kamus
    tqueue3 A;
    tqueue3 B;
    char E;

    //algoritma
    printf("Create Queue A\n");
    createQueue3(&A);
    printQueue3(A);

    printf("\nCreate Queue B\n");
    createQueue3(&B);
    printQueue3(B);

    printf("\nEnqueue Queue A\n");
    enqueue3(&A, 'l');
    enqueue3(&A, 'a');
    enqueue3(&A, 'p');
    enqueue3(&A, 'a');
    enqueue3(&A, 'r');
    viewQueue3(A);
    
    printf("\nHead dari Queue A: %d\n", head3(A));
    printf("Tail dari Queue A: %d\n", tail3(A));
    printf("Info Head dari Queue A: %c\n", infoHead3(A));
    printf("Info Tail dari Queue A: %c\n", infoTail3(A));
    printf("Size dari Queue A: %d\n", sizeQueue3(A));

    printf("\nApakah Queue A Kosong: \n%s\n", (isEmptyQueue3(A) ? "true" : "false\n"));

	printf("Apakah Queue A Penuh: \n%s\n", (isFullQueue3(A) ? "true" : "false\n"));

    printf("\nEnqueue Queue B\n");
    enqueue3(&B, 'n');
    enqueue3(&B, 'a');
    enqueue3(&B, 'd');
    enqueue3(&B, 'i');
    viewQueue3(B);

    printf("\nHead dari Queue B: %d\n", head3(B));
    printf("Tail dari Queue B: %d\n", tail3(B));
    printf("Info Head dari Queue B: %c\n", infoHead3(B));
    printf("Info Tail dari Queue B: %c\n", infoTail3(B));
    printf("Size dari Queue B: %d\n", sizeQueue3(B));

    printf("\nApakah Queue B Kosong: \n%s\n", (isEmptyQueue3(B) ? "true" : "false\n"));

	printf("Apakah Queue B Penuh: \n%s\n", (isFullQueue3(B) ? "true" : "false\n"));
    
    printf("Dequeue Queue A\n");
    dequeue3(&A,&E);
    printQueue3(A);
    printf("\n");

    printf("Elemen yang di Dequeue: %c\n", E);
    printf("Head dari Queue A: %d\n", head3(A));
    printf("Tail dari Queue A: %d\n", tail3(A));
    printf("Info Head dari Queue A: %c\n", infoHead3(A));
    printf("Info Tail dari Queue A: %c\n", infoTail3(A));
    printf("Size dari Queue A: %d\n", sizeQueue3(A));

    printf("\nDequeue Queue B\n");
    dequeue3(&B,&E);
    printQueue3(B);
    printf("\n");

    printf("Elemen yang di Dequeue: %c\n", E);
    printf("Head dari Queue B: %d\n", head3(B));
    printf("Tail dari Queue B: %d\n", tail3(B));
    printf("Info Head dari Queue B: %c\n", infoHead3(B));
    printf("Info Tail dari Queue B: %c\n", infoTail3(B));
    printf("Size dari Queue B: %d\n", sizeQueue3(B));

    //Dequeue ke 2
    printf("\nDequeue Queue A\n");
    dequeue3(&A,&E);
    printQueue3(A);

    printf("\nDequeue Queue B\n");
    dequeue3(&B,&E);
    printQueue3(B);

    //Enqueue ke 2
    printf("\nEnqueue Queue A\n");
    enqueue3(&A, 'u');
    printQueue3(A);
    viewQueue3(A);

    printf("\nHead dari Queue A: %d\n", head3(A));
    printf("Tail dari Queue A: %d\n", tail3(A));
    printf("Info Head dari Queue A: %c\n", infoHead3(A));
    printf("Info Tail dari Queue A: %c\n", infoTail3(A));
    printf("Size dari Queue A: %d\n", sizeQueue3(A));

    printf("\nApakah Tail Queue A Melebihi Head Queue A: \n%s\n", isTailOverHead(A) ? "true" : "false\n");

    printf("\nEnqueue Queue B\n");
    enqueue3(&B, 'k');
    enqueue3(&B, 'i');
    printQueue3(B);
    viewQueue3(B);

    printf("\nHead dari Queue B: %d\n", head3(B));
    printf("Tail dari Queue B: %d\n", tail3(B));
    printf("Info Head dari Queue B: %c\n", infoHead3(B));
    printf("Info Tail dari Queue B: %c\n", infoTail3(B));
    printf("Size dari Queue B: %d\n", sizeQueue3(B));

    printf("\nApakah Tail Queue B Melebihi Head Queue B: \n%s\n", isTailOverHead(B) ? "true" : "false\n");
    
    printf("\nMenghitung banyaknya huruf 'a' pada Queue A: %d\n", countMember(A, 'a'));

    printf("\nMenghitung banyaknya huruf 'i' pada Queue B: %d\n", countMember(B, 'i'));

    printf("\nEnqueue3E Queue A\n");
    enqueue3E(&A, 'u');
    printQueue3(A);
    viewQueue3(A);
    //Tidak bisa enqueue3E Queue A karena sudah terdapat elemen u di Queue A.

    printf("\nEnqueue3E Queue B\n");
    enqueue3E(&B, 'a');
    printQueue3(B);
    viewQueue3(B);
    return 0;
}