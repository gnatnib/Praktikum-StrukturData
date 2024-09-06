/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 24060122120031 - Bintang Syafrian Rizal*/
/* Tanggal   : 15 September 2023*/
/***********************************/

#include <stdio.h>
#include "tstack.h"
#include "boolean.h"

void createStack (Tstack *T){
    //Kamus lokal
    int i;

    //Algoritma
    (*T).top = 0;
    for (i = 1 ; i <= 10 ; i++){
        (*T).wadah[i] = '#';
    }
}

boolean isEmptyStack (Tstack T){
    //Kamus lokal

    //Algoritma
    return (T.top == 0);
}

boolean isFullStack (Tstack T){
    //Kamus lokal

    //Algoritma 
    return (T.top == 10);
}

void push (Tstack *T, char E){
    //Kamus lokal

    //Algoritma
    if (isFullStack(*T) == 0){
        (*T).top = (*T).top +1;
        (*T).wadah[(*T).top] = E;
    }
}

void pop (Tstack *T, char *X){
    //Kamus lokal

    //Algoritma
    (*X) = (*T).wadah[(*T).top];
    (*T).wadah[(*T).top] = '#';
    (*T).top -= 1;
}

void printStack (Tstack T){
    //Kamus lokal
    int i;

    //Algoritma
    for (i = 1 ; i<=10 ; i++){
        printf("%c; ", T.wadah[i]);
    }
}

void viewStack (Tstack T){
    //Kamus Lokal
    int i;

    //Algoritma
    for (i = 1 ; i <= T.top ; i++){
        printf("%c; ", T.wadah[i]);
    }
}


void pushN (Tstack *T, int N){
    //Kamus lokal
    int i;
    char E;

    //Algoritma
    if (!isFullStack(*T)){
        for (i = 1 ; i <= N ; i++){
            scanf(" %c", &E);
            push(T, E);
        }
    }
}

void pushBabel1 (Tstack *T, char E){
    //Kamus lokal

    //Algoritma
    if (isFullStack(*T)){
        createStack(T);
    }
    else{
        push(T,E); 
    }
}

void pushZuma (Tstack *T, char E){
    //Kamus lokal
    char popped;

    //Algoritma
    if (isEmptyStack(*T)){
        push (T,E);
    }
    else if (E == infotop(*T)){
        pop (T,&popped);
    }
    else {
        push (T,E);
    }
}