#include <stdio.h>
#include <stdlib.h>
#include "tqueue2.h"
#include "tqueue2.c"
#include "boolean.h"

/* Program   : maintqueue2.c */
/* Deskripsi : Realisasi ADT Queue aplikasi kontigu dengan array,
               model II: bergeser */
/* NIM/Nama  : 24060122120031 - Bintang Syafrian Rizal*/
/* Tanggal   : 30 September 2023*/
/***********************************/

int main (){
    //kamus
    tqueue2 A;
    tqueue2 B;
    char E;
    

    //algoritma
    printf("Create Queue A\n");
    createQueue2(&A);
    printQueue2(A);

    printf("\nCreate Queue B\n");
    createQueue2(&B);
    printQueue2(B);

    printf("\nEnqueue Queue A\n");
    enqueue2(&A, 'm');
    enqueue2(&A, 'a');
    enqueue2(&A, 's');
    enqueue2(&A, 'a');
    enqueue2(&A, 'k');
    viewQueue2(A);
    
    printf("\nHead dari Queue A: %d\n", head2(A));
    printf("Tail dari Queue A: %d\n", tail2(A));
    printf("Info Head dari Queue A: %c\n", infoHead2(A));
    printf("Info Tail dari Queue A: %c\n", infoTail2(A));
    printf("Size dari Queue A: %d\n", sizeQueue2(A));

    printf("\nApakah Queue A Kosong: \n%s\n", (isEmptyQueue2(A) ? "true" : "false\n"));

	printf("Apakah Queue A Penuh: \n%s\n", (isFullQueue2(A) ? "true" : "false\n"));

    printf("\nEnqueue Queue B\n");
    enqueue2(&B, 'r');
    enqueue2(&B, 'a');
    enqueue2(&B, 's');
    enqueue2(&B, 'a');
    viewQueue2(B);

    printf("\nHead dari Queue B: %d\n", head2(B));
    printf("Tail dari Queue B: %d\n", tail2(B));
    printf("Info Head dari Queue B: %c\n", infoHead2(B));
    printf("Info Tail dari Queue B: %c\n", infoTail2(B));
    printf("Size dari Queue B: %d\n", sizeQueue2(B));

    printf("\nApakah Queue B Kosong: \n%s\n", (isEmptyQueue2(B) ? "true" : "false\n"));

	printf("Apakah Queue B Penuh: \n%s\n", (isFullQueue2(B) ? "true" : "false\n"));
    
    printf("Dequeue Queue A\n");
    dequeue2(&A,&E);
    printQueue2(A);
    printf("\n");

    printf("Head dari Queue A: %d\n", head2(A));
    printf("Tail dari Queue A: %d\n", tail2(A));
    printf("Info Head dari Queue A: %c\n", infoHead2(A));
    printf("Info Tail dari Queue A: %c\n", infoTail2(A));
    printf("Size dari Queue A: %d\n", sizeQueue2(A));

    printf("\nDequeue Queue B\n");
    dequeue2(&B,&E);
    printQueue2(B);
    printf("\n");

    printf("Head dari Queue B: %d\n", head2(B));
    printf("Tail dari Queue B: %d\n", tail2(B));
    printf("Info Head dari Queue B: %c\n", infoHead2(B));
    printf("Info Tail dari Queue B: %c\n", infoTail2(B));
    printf("Size dari Queue B: %d\n", sizeQueue2(B));

    printf("\nApakah Queue A dan B sama: \n%s\n", (isEqualQueue2(A,B) ? "true" : "false\n"));
    printf("Queue A\n");
    printQueue2(A);
    enqueue2N(&A, 1);
    printf("Queue A setelah Enqueue2N: \n");
    printQueue2(A);

    //Tes apabila Enqueue2N melebihi kapasitas
    enqueue2N(&A, 1);
    printf("\nQueue A setelah Enqueue2N: \n");
    printQueue2(A);
    printf("\nHead dari Queue A: %d\n", head2(A));
    printf("Tail dari Queue A: %d\n", tail2(A));
    printf("Info Head dari Queue A: %c\n", infoHead2(A));
    printf("Info Tail dari Queue A: %c\n", infoTail2(A));
    printf("Size dari Queue A: %d\n", sizeQueue2(A));

    printf("\n");
    printf("Queue B\n");
    printQueue2(B);
    enqueue2N(&B, 2);
    printf("\nQueue B setelah Enqueue2N: \n");
    printQueue2(B);
    printf("\nHead dari Queue B: %d\n", head2(B));
    printf("Tail dari Queue B: %d\n", tail2(B));
    printf("Info Head dari Queue B: %c\n", infoHead2(B));
    printf("Info Tail dari Queue B: %c\n", infoTail2(B));
    printf("Size dari Queue B: %d\n", sizeQueue2(B));

    printf("\nApakah Queue A dan B sama: \n%s\n", (isEqualQueue2(A,B) ? "true" : "false\n"));

    return 0;
}

