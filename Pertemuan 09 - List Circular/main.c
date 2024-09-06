/* File : main.c */
/* Deskripsi : Aplikasi list berkait circular dengan representasi fisik pointer */
/* NIM & Nama : 24060122120031 - Bintang Syafrian Rizal*/
/* Tanggal : 18 - 11 - 2023*/

#include <stdio.h>
#include <stdlib.h>
#include "list3.h"
#include "list3.c"

int main()
{ //kamus
  List3 Z;
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
  InsertVFirst(&Z,'H');
  InsertVLast(&Z,'A');
  InsertVLast(&Z,'I');
  PrintList(Z);

  printf("\nHapus elemen pertama dari linked list Z:\n");
  DeleteVFirst(&Z,&V);
  printf("Hapus elemen terakhir dari linked list Z:\n");
  DeleteVLast(&Z,&V);
  printf("\nList Z setelah dilakukan delete: \n");
  PrintList(Z);
  printf("\nJumlah element dalam linked list Z: %d\n", NbElm(Z));

  printf("\nInsert huruf ke dalam linked list Z:\n");
  InsertVFirst(&Z,'R');
  InsertVLast(&Z, 'J');
  InsertVLast(&Z, 'A');
  InsertVLast(&Z, 'K');
  InsertVLast(&Z, 'U');
  PrintList(Z);
  printf("\nJumlah element dalam linked list Z: %d\n", NbElm(Z));
  printf("\nMencari X dalam list:\n");
  SearchX(Z, 'R', &A);
  printf("Alamat X: %p\n", A);

  printf("\nMengupdate linked list Z dengan mengganti elemen R menjadi S, dan O menjadi I:\n");
  UpdateX(&Z, 'R', 'B');
  UpdateX(&Z, 'K', 'M');
  printf("List Z setelah di update:\n");
  PrintList(Z);

  printf("\nMemasukkan elemen baru setelah elemen X dengan InsertVAfter.\n");
  InsertVAfterX(&Z, 'U', 'L');
  PrintList(Z);
  printf("\nMemasukkan elemen baru sebelum elemen X dengan InsertVBefore.");
  InsertVBeforeX(&Z, 'L', 'N');
  printf("\nLinked list Z setelah dimasukkan elemen baru: \n");
  PrintList(Z);

  printf("\nMenginvers linked list Z agar posisi elemen menjadi terbalik:\n");
  Invers(&Z);
  printf("Linked list Z setelah di invers:\n");
  PrintList(Z);

  printf("\nMenghapus elemen setelah X:\n");
  DeleteVAfterX(&Z, 'L', &V);
  PrintList(Z);
  printf("\nMenghapus elemen sebelum X:\n");
  DeleteVBeforeX(&Z, 'L', &V);
  PrintList(Z);
  
  printf("\nBanyaknya elemen A pada linked list Z: %d \n", CountX(Z,'A'));
  printf("\nMenghitung vocal pada linked list Z: %d \n", CountVocal(Z));

  printf("\nMemasukkan elemen NG untuk menguji CountNG:\n");
  InsertVLast(&Z, 'N');
  InsertVLast(&Z, 'G');
  PrintList(Z);
  printf("\nMenghitung NG pada linked list Z: %d \n", CountNG(Z));

  printf("\nJumlah element dalam linked list Z: %d\n", NbElm(Z));
  printf("\nFrekuensi kemunculan A pada linked list Z: %f\n", FrekuensiX(Z,'A'));
  
  printf("\nHuruf yang paling banyak muncul dalam linked list Z: %c\n", Modus(Z));

  printf("\nMencari semua elemen X.\n");
  SearchAllX(Z,'A');
  return 0;
}
