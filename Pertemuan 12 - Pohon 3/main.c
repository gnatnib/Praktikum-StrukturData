/* File : main.c */
/* Deskripsi : Driver binary tree 3 dengan representasi fisik pointer */
/* NIM & Nama : 24060122120031 - Bintang Syafrian Rizal*/
/* Tanggal : 10 - 12 - 2023*/

#include "list1.h"
#include "list1.c"
#include "pohon3.h"
#include "pohon3.c"
#include <stdio.h>

void printVisitedStatus(bintree3 P) {
    if (!IsEmptyTree(P)) {
        printf("Node %c visited status: %s\n", info(P), visited(P) ? "true" : "false");
        printVisitedStatus(left(P));
        printVisitedStatus(right(P));
    }
}

int main() {
    /* Kamus Main */
    bintree3 A, B, C, D, E, F, G, H, I;
    List1 L, L1;

    /* Algoritma */
    printf("\nMembuat bintree A:\n");
    A = Tree3(NIL, 'A', false, NIL, NIL);
    B = Tree3(A, 'B', false, NIL, NIL);
    C = Tree3(A, 'C', false, NIL, NIL);
    left(A) = B; right(A) = C;
    D = Tree3(B, 'D', false, NIL, NIL);
    E = Tree3(B, 'E', false, NIL, NIL);
    left(B) = D; right(B) = E;
    F = Tree3(C, 'F', false, NIL, NIL);
    G = Tree3(C, 'G', false, NIL, NIL);
    left(C) = F; right(C) = G;
    H = Tree3(G, 'H', false, NIL, NIL);
    I = Tree3(G, 'I', false, NIL, NIL);
    left(G) = H; right(G) = I;
    
    printf("A = ");
    PrintPrefix(A);

    printf("\nTesting resetVisited:\n");
    
    visited(A) = true;
    visited(C) = true;
    visited(G) = true;
    visited(I) = true;
    
    printf("Before resetVisited:\n");
    printVisitedStatus(A);
    
    printf("\nAfter resetVisited:\n");
    resetVisited(A);
    printVisitedStatus(A);

    printf("\nCreateList(L):\n");
    CreateList(&L);
    InsertVLast(&L, 'A'); InsertVLast(&L, 'B'); InsertVLast(&L, 'C'); InsertVLast(&L, 'D'); InsertVLast(&L, 'E');
    printf("L = ");
    PrintList(L);

    printf("\nCreateList(L1):\n");
    CreateList(&L1);
    InsertVLast(&L1, 'F'); InsertVLast(&L1, 'G'); InsertVLast(&L1, 'H'); InsertVLast(&L1, 'I'); InsertVLast(&L1, 'J');
    printf("L1 = ");
    PrintList(L1);

    printf("\npconcat(L, L1):\n");
    pconcat(&L, L1);
    printf("L = ");
    PrintList(L);

    printf("\nlinearPrefix(A):\n");
    PrintList(linearPrefix(A));    
    printf("\nlinearPostfix(A):\n");
    PrintList(linearPosfix(A));
    printf("\nlinearInfix(A):\n");
    PrintList(linearInfix(A));

    printf("\nlinearBreadthFS(A):\n");
    PrintList(linearBreadthFS(A));
    printf("\nprintPathX(A, 'I'):\n");
    printPathX(A, 'I');
    printf("\nprintPathDaunX(A, 'B'):\n");
    printPathDaunX(A, 'B');
    printf("\nprintAllPaths(A):\n");
    printAllPaths(A);
    printf("\n");
    
    return 0;
}
