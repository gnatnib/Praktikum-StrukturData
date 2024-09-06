/* File : main.c */
/* Deskripsi : Aplikasi list berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060122120031 - Bintang Syafrian Rizal*/
/* Tanggal : 10 - 11 - 2023*/

#include <stdio.h>
#include <stdlib.h>
#include "list2.h"
#include "list2.c"

int main()
{ //kamus
  list2 Z;
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
  InsertVFirst(&Z,'S');
  InsertVLast(&Z,'O');
  InsertVLast(&Z,'P');
  PrintList(Z);

  printf("\nHapus elemen pertama dari linked list Z:\n");
  DeleteVFirst(&Z,&V);
  printf("\nHapus elemen terakhir dari linked list Z:\n");
  DeleteVLast(&Z,&V);
  printf("\nList Z setelah dilakukan delete: \n");
  PrintList(Z);
  printf("\nJumlah element dalam linked list Z: %d\n", NbElm(Z));

  printf("\nInsert huruf ke dalam linked list Z:\n");
  InsertVFirst(&Z,'R');
  InsertVLast (&Z, 'T');
  InsertVLast(&Z,'A');
  InsertVLast(&Z,'R');
  InsertVLast(&Z,'O');
  InsertVLast(&Z,'F');
  InsertVLast(&Z,'N');
  InsertVLast(&Z,'I');
  PrintList(Z);
  printf("\nJumlah element dalam linked list Z: %d\n", NbElm(Z));
  printf("\nMencari X dalam list:\n");
  SearchX(Z, 'A', &A);
  printf("Alamat X: %p\n", A);

  printf("\nMengupdate linked list Z dengan mengganti elemen R menjadi S, dan O menjadi I:\n");
  UpdateX(&Z, 'R', 'S');
  UpdateX(&Z, 'O', 'I');
  printf("List Z setelah di update:\n");
  PrintList(Z);

  printf("\nMemasukkan elemen baru setelah elemen X dengan InsertVAfter.\n");
  InsertVAfterX(&Z, 'A', 'M');
  PrintList(Z);
  printf("\nMemasukkan elemen baru sebelum elemen X dengan InsertVBefore.");
  InsertVBeforeX(&Z, 'I', 'C');
  printf("\nLinked list Z setelah dimasukkan elemen baru: \n");
  PrintList(Z);

  printf("\nMenginvers linked list Z agar posisi elemen menjadi terbalik:\n");
  Invers(&Z);
  printf("Linked list Z setelah di invers:\n");
  PrintList(Z);

  printf("\nMenghapus elemen setelah X:\n");
  DeleteVAfterX(&Z, 'C', &V);
  PrintList(Z);
  printf("\nMenghapus elemen sebelum X:\n");
  DeleteVBeforeX(&Z, 'R', &V);
  PrintList(Z);
  
  printf("\nBanyaknya elemen I pada linked list Z: %d \n", CountX(Z,'I'));

  printf("\nJumlah element dalam linked list Z: %d", NbElm(Z));
  printf("\nFrekuensi kemunculan I pada linked list Z: %f\n", FrekuensiX(Z,'I'));
  
  printf("\nHuruf yang paling banyak muncul dalam linked list Z: %c\n", Modus(Z));

  printf("\nMencari semua elemen X.\n");
  SearchAllX(Z,'I');
  return 0;
}
