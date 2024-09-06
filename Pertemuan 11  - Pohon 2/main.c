/* File : main.c */
/* Deskripsi : Driver binary tree dengan representasi fisik pointer */
/* NIM & Nama : 24060122120031 - Bintang Syafrian Rizal*/
/* Tanggal : 03 - 12 - 2023*/

#include "pohon1.h"
#include "pohon2.h"
#include "pohon1.c"
#include "pohon2.c"

int main(){
    /*Kamus Lokal*/
    bintree P;
    bintree Bst;
    infotype X;

    printf("\nBuildBalanceTree\n");
    P = BuildBalanceTree(6);
    printf("Tree setelah BuildBalanceTree selesai: \n");
    PrintPref(P);
    printf("\n");
    printf("\nIsBalanceTree");
    printf("\nIsBalanceTree(P):\n%s\n", IsBalanceTree(P) ? "Tree Balance." : "Tree Tidak Balance.");
    printf("\n");

    printf("\nMembuat Tree ke 2");
    P = Tree('A', Tree('B', Tree('D',Tree('H',NIL,NIL),Tree('I',NIL,NIL)), Tree('E',Tree('J',NIL,NIL),NIL)), Tree('C', Tree('F',NIL,NIL),Tree('G',NIL,NIL)));
    printf("\nTree: \n");
    PrintPref(P);

    printf("\n");
    printf("\nAddDaun\n");
    AddDaun(&P,'J','K',true);
    printf("Tree setelah AddDaun: ");
    PrintPref(P);

    printf("\n");
    printf("\nAddDaunTerkiri");
    printf("\nTree setelah AddDaunTerkiri: \n");
    AddDaunTerkiri(&P,'Z');
    PrintPref(P);
    
    printf("\n");
    printf("\nPrintLevel\n");
    printf("Elemen yang ada pada level 2: \n");
    PrintLevel(P,2);

    printf("\n");
    printf("\nInsertX");
    printf("\nTree setelah InsertX: ");
    InsertX(&P,'Q');
    printf("\n");
    PrintPref(P);

    printf("\n");
    printf("\nDelDaunTerkiri");
    printf("\nTree setelah DelDaunTerkiri: \n");
    DelDaunTerkiri(&P,&X);
    PrintPref(P);

    printf("\n");
    printf("\nDelDaun");
    printf("\nTree setelah DelDaun: ");
    DelDaun(&P,'Z');
    printf("\n");
    PrintPref(P);

    printf("\n");
    printf("\nUpdateAllX");
    printf("\nTree setelah UpdateAllX: \n");
    UpdateAllX(&P,'B','M');
    PrintPref(P);

    printf("\n");
    printf("\nMaxTree");
    printf("\nChar maks dalam tree : \n%c", maxTree(P));

    printf("\n");
    printf("\nMinTree");
    printf("\nChar min dalam tree : \n%c", minTree(P));

    printf("\n");
    printf("\n==================Binary Search Tree==================");
    printf("\n");
    printf("\nTree yang memenuhi aturan BST\n");
    Bst = Tree('C', Tree('A', NIL, Tree('B', NIL, NIL)), Tree('F', Tree('D', NIL, Tree('E', NIL, NIL)), Tree('G', NIL, NIL)));
    PrintPref(Bst);

    printf("\n");
    printf("\nMencari 'G' dalam menggunakan BSearch\n");
    printf("Bsearch(Bst,'G'):\n%s\n", BSearch(Bst,'G') ? "G ditemukan." : "G tidak ditemukan.");
    printf("\nMencari 'Q' dalam menggunakan BSearch\n");
    printf("Bsearch(Bst,'Q'):\n%s\n", BSearch(Bst,'Q') ? "Q ditemukan." : "Q tidak ditemukan.");

    printf("\n");
    printf("Memasukkan elemen 'Z' dalam Bst apabila belum ada, menggunakan InsSearch\n");
    Bst = InsSearch(Bst,'Z');
    printf("BST setelah InsSearch: \n");
    PrintPref(Bst);

    printf("\n");
    printf("\nDeleteX elemen 'B' dalam Bst\n");
    DeleteX(&Bst,'B');
    printf("BST setelah DeleteX: \n");
    PrintPref(Bst);

    printf("\n");
    printf("\nDelBTree elemen 'E' dalam Bst\n");
    DelBtree(&Bst, 'E');
    printf("BST setelah DelBTree: \n");
    PrintPref(Bst);


    



    





    return 0;
}