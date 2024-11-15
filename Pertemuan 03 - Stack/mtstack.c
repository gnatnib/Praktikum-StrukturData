/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060122120031 - Bintang Syafrian Rizal*/
/* Tanggal   : 15 September 2023*/
/***********************************/

#include <stdio.h>
#include <string.h>
#include "tstack.h"
#include "tstack.c"
#include "boolean.h"

int main()
{	/* kamus main */
	Tstack A; // variabel A bertipe tStack
	char X;

    Tstack B;
    int i=1;
    int N;
    char P;
    char kata[]={'M','A','L','A','M'};

    //Algoritma
    printf("\n\nApakah Stack Palindrom ?\n");
	printf("Kata : ");
	N = strlen (kata);
	for(i=0; i<N; i++){
 		printf(" %c  ", kata[i]);
	}

	createStack(&B);
	for (i=0;i<N/2;i++){
		push(&B, kata[i]);
	}

	if (N % 2 == 1){
		i = i + 1;
	}

	printf ("\n");

	while (i<N){
		pop(&B,&P);
		if (P == kata[i] && i < N - 1){
			i++;
		}
		else if(P == kata[i] && i == N - 1){
			printf("Palindrome\n");
			break;
		}
		else{
			printf("Bukan Palindrome\n");
			break;
		}
	}
	
	/* algoritma */
	printf("\nCreate stack A\n");
	createStack(&A);

	printf("Top Stack A = %d\n", top(A));

    printf("Infotop Stack A = %c\n", infotop(A));

	printf("\nApakah Stack A isEmptyStack = %s\n", isEmptyStack(A) ? "Ya" : "Tidak");
	printf("Apakah Stack A isFullStack = %s\n", isFullStack(A) ? "Ya" : "Tidak");

    printf("\nPush ke Stack A\n");
    push(&A,'b');
    push(&A,'i');
    push(&A,'n');
    push(&A,'t');
    push(&A,'a');
    push(&A,'n');
    push(&A,'g');

    printf("Push = %c\n",A.wadah[1]);
    printf("Push = %c\n",A.wadah[2]);
    printf("Push = %c\n",A.wadah[3]);
    printf("Push = %c\n",A.wadah[4]);
    printf("Push = %c\n",A.wadah[5]);
    printf("Push = %c\n",A.wadah[6]);
    printf("Push = %c\n",A.wadah[7]);

	printf("\nStack A\n");
    printStack(A);
	printf("\n");

    printf("\nTop dari Stack A = %d\n", top(A));

    printf("Infotop dari Stack A = %c\n", infotop(A));

    printf("\nApakah Stack A isEmptyStack = %d\n", isEmptyStack(A));
    printf("Apakah Stack A isFullStack = %d\n", isFullStack(A));

    pop(&A,&X);
    printf("\nSetelah di pop maka stack A menjadi sebagai berikut.\n");
	printStack(A);
	printf("\n");

    printf("\nTop dari Stack A = %d\n", top(A));

    printf("Infotop dari Stack A = %c\n", infotop(A));

	printf("\n");
    viewStack(A);
    printf("\nApakah Stack A isEmptyStack = %d\n", isEmptyStack(A));
    printf("Apakah Stack A isFullStack = %d\n", isFullStack(A));
	printf("\n");

	printf("\nIsi elemen PushN stack A sebanyak 4 Kali: \n");
	pushN(&A, 4);
	printf("\nSetelah di pushN maka stack A menjadi sebagai berikut:\n");
	viewStack(A);

	printf("\n");
	printf("\nApakah Stack A isEmptyStack = %d\n", isEmptyStack(A));
    printf("Apakah Stack A isFullStack = %d\n", isFullStack(A));

	printf("\nIsi elemen PushBabel1 stack A: \n");
	pushBabel1(&A, 'a');
	printf("Setelah di pushBabel1 maka stack A menjadi sebagai berikut:\n");
	printStack(A);

	printf("\n");
	printf("\nIsi elemen PushBabel1 stack A: \n");
	pushBabel1(&A, 'm');
	printf("Setelah di pushBabel1 maka stack A menjadi sebagai berikut:\n");
	printStack(A);

	printf("\n");
	printf("\nIsi elemen push zuma: \n");
	pushZuma(&A, 'a');
	printf("Setelah di pushZuma maka stack menjadi sebagai berikut:\n");
	printStack(A);

	printf("\n");
	printf("\nIsi elemen push zuma apabila sama: \n");
	pushZuma(&A, 'a');
	printf("Setelah di pushZuma dengan char yang sama maka stack menjadi sebagai berikut:\n");
	printStack(A);
	printf("\n");

	printf("\n===================================================THANK YOU===================================================\n");

	return 0;
}
