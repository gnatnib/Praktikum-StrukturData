/* File : main.c */
/* Deskripsi : Aplikasi list berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060122120031 - Bintang Syafrian Rizal*/
/* Tanggal : 04 - 11 - 2023*/

#include <stdio.h>
#include <stdlib.h>
#include "list1.h"
#include "list1.c"

int main()
{ //kamus
  List1 Z;
  address A;
  infotype V;
  //algoritma
  // A = (address) malloc ( sizeof (ElmList) ); // Alokasi(P)
  // A->info = 'G';   A->next = NIL;
  // printf("info(A)=%c\t", A->info );
  // B = (address) malloc ( sizeof (ElmList) ); // Alokasi(P)
  // B->info = 'H';   B->next = A;
  // printf("info(B)=%c\n", B->info );
  // LL.First = B;
  // PrintList( LL );

  CreateList(&Z);
  printf("\nInsert huruf ke dalam linked list Z:\n");
  InsertVFirst(&Z,'B');
  InsertVLast(&Z,'I');
  PrintList(Z);

  printf("\nHapus elemen pertama dari linked list Z:\n");
  DeleteVFirst(&Z,&V);
  printf("\nHapus elemen terakhir dari linked list Z:\n");
  DeleteVLast(&Z,&V);

  PrintList(Z);
  printf("\nJumlah element dalam linked list Z: %d\n", NbElm(Z));

  printf("\nInsert huruf ke dalam linked list Z:\n");
  InsertVFirst(&Z,'M');
  InsertVLast (&Z, 'T');
  InsertVLast(&Z,'A');
  InsertVLast(&Z,'N');
  PrintList(Z);
  printf("\nJumlah element dalam linked list Z: %d\n", NbElm(Z));
  SearchX(Z, 'N', &A);
  printf("Alamat A: %p\n", A);

  printf("\nMengupdate linked list Z dengan mengganti elemen N menjadi M:\n");
  UpdateX(&Z, 'N', 'M');
  printf("List Z setelah di update:\n");
  PrintList(Z);

  printf("\nMenginvers linked list Z agar posisi elemen menjadi terbalik:\n");
  Invers(&Z);
  printf("Linked list Z setelah di invers:\n");
  PrintList(Z);

  printf("\nBanyaknya elemen M pada linked list Z: %d \n", CountX(Z,'M'));

  printf("\nJumlah element dalam linked list Z: %d", NbElm(Z));
  printf("\nFrekuensi kemunculan M pada linked list Z: %f\n", FrekuensiX(Z,'M'));
  
  printf("\nHuruf yang paling banyak muncul dalam linked list Z: %c\n", Modus(Z));
  
  printf("\nPosisi - posisi alamat kemunculan huruf M dalam linked list Z: \n");
  SearchAllX(Z, 'M');

  printf("\nMemasukkan elemen baru setelah elemen sebelumnya dengan InsertVAfter.\n");
  InsertVAfter(&Z, 'T', 'O');
  printf("\nLinked list Z setelah dimasukkan elemen baru: \n");
  PrintList(Z);

  return 0;
}
