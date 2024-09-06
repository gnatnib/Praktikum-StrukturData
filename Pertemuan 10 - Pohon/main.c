/* File : main.c */
/* Deskripsi : Driver binary tree dengan representasi fisik pointer */
/* NIM & Nama : 24060122120031 - Bintang Syafrian Rizal*/
/* Tanggal : 25 - 11 - 2023*/
#include "pohon1.h"
#include "pohon1.c"
#include <stdio.h>

int main() {
    /* Kamus Main */
    bintree P;

    /* Algoritma */
    printf("\nMembuat Tree P:\n");
    P = Tree('A', Tree('B', Tree('D',Tree('H',NIL,NIL),Tree('I',NIL,NIL)), Tree('E',Tree('J',NIL,NIL),NIL)), Tree('C', Tree('F',NIL,NIL),Tree('G',NIL,NIL)));
    printf("P = ");
    PrintPrefix(P);
    printf("\n");

    printf("\nIsEmptyTree(P):\n%s\n", IsEmptyTree(P) ? "true" : "false");
    printf("\nGetAkar(P):\n'%c'\n", GetAkar(P));
    printf("\nGetAkar(GetLeft(P)):\n'%c'\n", GetAkar(GetLeft(P)));
    printf("\nGetAkar(GetRight(P)):\n'%c'\n", GetAkar(GetRight(P)));
    printf("\nIsDaun(P):\n%s\n", IsDaun(P) ? "true" : "false");
    printf("\nIsBiner(P):\n%s\n", IsBiner(P) ? "true" : "false");
    printf("\nIsUnerLeft(P):\n%s\n", IsUnerLeft(P) ? "true" : "false");
    printf("\nIsUnerRight(P):\n%s\n", IsUnerRight(P) ? "true" : "false");
    printf("\nNbElm(P):\n%d\n", NbElm(P));
    printf("\nNbDaun(P):\n%d\n", NbDaun(P));
    printf("\nTinggi(P):\n%d\n", Tinggi(P));
    printf("\nMencari C dalam tree: ");
    printf("\nSearchX(P, 'C'):\n%s\n", SearchX(P, 'C') ? "true" : "false");
    printf("\nMencari Q dalam tree: ");
    printf("\nSearchX(P, 'Q'):\n%s\n", SearchX(P, 'Q') ? "true" : "false");
    printf("\nUpdateX(P, 'B', 'S'):\n");
    UpdateX(&P, 'B', 'S');
    printf("\nPrint Pref: \n");
    printf("P = ");
    PrintPref(P);
    printf("\n");
    printf("\nCountX(P, 'A'):\n%d\n", CountX(P, 'A'));
    printf("\nIsSkewLeft(P):\n%s\n", IsSkewLeft(P) ? "true" : "false");
    printf("\nIsSkewRight(P):\n%s\n", IsSkewRight(P) ? "true" : "false");
    printf("\nLevelX(P, 'C'):\n%d\n", LevelX(P, 'C'));
    printf("\nCountLevelT(P, 3):\n%d\n", CountLevelT(P, 2));
    printf("\nGetDaunTerkiri(P):\n'%c'\n", GetDaunTerkiri(P));
    printf("\nFrekuensiX(P, 'A'):\n%f\n", FrekuensiX(P, 'A'));
    printf("\nCountVocal(P):\n%d\n", CountVocal(P));
    printf("\nModus(P):\n'%c'\n", Modus(P));
    
    return 0;
}