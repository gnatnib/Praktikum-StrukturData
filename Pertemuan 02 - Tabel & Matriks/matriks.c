
/* Program   : matriks.h */
/* Deskripsi : file HEADER modul matriks integer */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/
/* KONSTRUKTOR */		
/* procedure initMatriks(output M: Matriks)
	{I.S.: - }
	{F.S.: Matriks M terdefinisi}
	{Proses mengisi elemen cell dengan -999, nbaris 0, nkolom 0} */
#include <math.h>
#include <stdlib.h>
#include "matriks.h"
#include "boolean.h"

void initMatriks(Matriks *M) {
	//Kamus lokal
	int i,j;

	//Algoritma
	(*M).nbaris = 0;
	(*M).nkolom = 0;

	for (i=1; i<=10; i++) {
		for (j=1; j<=10; j++) {
			(*M).cell[i][j] = -999;
		}
	}
}

/* SELEKTOR */
/* function getNBaris(M: Matriks) -> integer
	{mengembalikan banyak baris matriks M yang terisi } */
int getNBaris(Matriks M) {
	return M.nbaris;
}

/* function getNKolom(M: Matriks) -> integer
	{mengembalikan banyak kolom matriks M yang terisi } */
int getNKolom(Matriks M) {
	return M.nkolom;
}

/* PREDIKAT */
/* function isEmptyMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M kosong } */
boolean isEmptyMatriks(Matriks M) {
	return (M.nbaris == 0 && M.nkolom == 0);
}

/* function isFullMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M penuh } */
boolean isFullMatriks(Matriks M) {
	return (M.nbaris == 10 && M.nkolom == 10);
}

/* OPERASI PENCARIAN*/
/* procedure searchX( input M:Matriks, input X: integer, output row: integer, output col: integer )
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: row berisi indeks baris dan col berisi indeks kolom ketemu X di M.cell, atau -999 jika tidak ketemu}
	{Proses: mencari elemen bernilai X dalam M.cell} */
void searchX(Matriks M, int X, int *row, int *col) {
	//Kamus Lokal
	int i, j;

	//Algoritma
	*row = -999;
	*col = -999;

	for (i=1; i<=10; i++) {
		for (j=1; j<=10; j++) {
			if (M.cell[i][j] == X) {
				*row = i;
				*col = j;
				return;
			}
		}
	}
}

/* function countX (M:Matriks, X: integer) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam M.cell} */
int countX (Matriks M, int X){
	//Kamus Lokal
	int i, j;
	int count = 0;

	//Algoritma
	for (i=1; i<=10; i++) {
		for (j=1; j<=10; j++) {
			if (M.cell [i][j] == X) {
				count++;
			}
		}
	}
	return count;
}

/* MUTATOR */
/* procedure addX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell bertambah 1 elemen pada baris ke-row dan kolom ke-col jika belum penuh}
	{Proses: mengisi elemen M.cell dengan nilai X} */
void addX (Matriks *M, int X, int row, int col) {
	if ((*M).cell[row][col] == -999) {
		(*M).cell[row][col] = X;
		(*M).nbaris++;
		(*M).nkolom++;
	} else {
		printf("Matriks sudah terisi\n");
	}
}

/* procedure editX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell pada baris ke-row dan kolom ke-col diubah dengan nilai X}
	{Proses: mengubah isi M.cell pada baris ke-row dan kolom ke-col dengan nilai X} */
void editX (Matriks *M, int X, int row, int col) {
	if ((*M).cell[row][col] != -999) {
		(*M).cell[row][col] = X;
	} else {
		printf("Matriks belum terisi\n");
	}
}

/* procedure delX (input/output M:Matriks, input X:integer )
	{I.S.: M terdefinisi, X terdefinisi}
	{F.S.: elemen M.cell berkurang 1}
	{Proses: menghapus 1 elemen bernilai X dari M.cell*/
void delX (Matriks *M, int X) {
	// /Kamus Lokal/
	int i, j;

	// /Algoritma/
	for (i=1; i<=10; i++) {
		for (j=1; j<=10; j++) {
			if ((*M).cell[i][j] == X) {
				(*M).cell[i][j] = -999;
				(*M).nbaris--;
				(*M).nkolom--;
				return;
			}
		}
	}
}

/* procedure isiMatriksRandom(input/output M: Matriks, input x: integer, input y: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan bilangan random sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
	{proses: mengisi matriks dengan bilangan integer random dengan jumlah baris x dan kolom y} */
void isiMatriksRandom(Matriks *M, int x, int y) {
	// /Kamus Lokal/
	int i, j;

	// /Algoritma/
	for (i=1; i<=x; i++) {
		for (j=1; j<=y; j++) {
			(*M).cell[i][j] = rand() % 100;
			(*M).nbaris++;
			(*M).nkolom++;
		}
	}
}

/* procedure isiMatriksIdentitas(input/output M: Matriks, input n: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan matriks identitas berukuran n x n, nbaris=nkolom=n}
	{proses: mengisi matriks dengan matriks identitas berukuran n x n} */
void isiMatriksIdentitas(Matriks *M, int n) {
	// /Kamus Lokal/
	int i;

	// /Algoritma/
	for (i=1; i<=n; i++) {
		(*M).cell[i][i] = 1;
		(*M).nbaris++;
		(*M).nkolom++;
	}
}

/* OPERASI BACA/TULIS */
/* procedure populateMatriks(input/output M: Matriks, input x: integer, input y: integer)
{I.S.: M terdefinisi}
{F.S.: M terisi dengan inputan dari keybord sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
{proses: mengisi matriks dengan meminta inputan dari keyboard dengan jumlah baris x dan kolom y} */
void populateMatriks(Matriks *M, int x, int y) {
	// /Kamus Lokal/
	int i, j;

	// /Algoritma/
	for (i=1; i<=x; i++) {
		for (j=1; j<=y; j++) {
			scanf("%d", &(*M).cell[i][j]);
			(*M).nbaris++;
			(*M).nkolom++;
		}
	}
}

/* procedure printMatriks(input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen M.cell ke layar} */
void printMatriks(Matriks M) {
	// /Kamus Lokal/
	int i, j;

	// /Algoritma/
	for (i=1; i<=10; i++) {
		for (j=1; j<=10; j++) {
			printf("%d ", M.cell[i][j]);
		}
		printf("\n");
	}
}

/* procedure viewMatriks (input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen M.cell yang terisi ke layar} */
void viewMatriks (Matriks M) {
	// /Kamus Lokal/
	int i, j;

	// /Algoritma/
	for (i=1; i<=10; i++) {
		for (j=1; j<=10; j++) {
			if (M.cell[i][j] != -999) {
				printf("%d ", M.cell[i][j]);
			}
		}
		printf("\n");
	}
}

/* OPERASI ARITMATIKA */
/* function addMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil penjumlahan matriks M1 dengan M2} */
Matriks addMatriks(Matriks M1, Matriks M2) {
	// /Kamus Lokal/
	Matriks M;
	int i, j;

	// /Algoritma/
	initMatriks(&M);

	for (i=1; i<=10; i++) {
		for (j=1; j<=10; j++) {
			M.cell[i][j] = M1.cell[i][j] + M2.cell[i][j];
			M.nbaris++;
			M.nkolom++;
		}
	}
	return M;
}

/* function subMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil pengurangan antara matriks M1 dengan M2} */
Matriks subMatriks(Matriks M1, Matriks M2) {
	// /Kamus Lokal/
	Matriks M;
	int i, j;

	// /Algoritma/
	initMatriks(&M);

	for (i=1; i<=10; i++) {
		for (j=1; j<=10; j++) {
			M.cell[i][j] = M1.cell[i][j] - M2.cell[i][j];
			M.nbaris++;
			M.nkolom++;
		}
	}
	return M;
}

/* function kaliMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil perkalian antara matriks M1 dengan M2} */
Matriks kaliMatriks(Matriks M1, Matriks M2) {
	// /Kamus Lokal/
	Matriks M;
	int i, j, k;

	// /Algoritma/
	initMatriks(&M);

	for (i=1; i<=10; i++) {
		for (j=1; j<=10; j++) {
			M.cell[i][j] = 0;
			for (k=1; k<=10; k++) {
				M.cell[i][j] += M1.cell[i][k] * M2.cell[k][j];
			}
			M.nbaris++;
			M.nkolom++;
		}
	}
	return M;
}

/* function kaliSkalarMatriks(M: Matriks, x: integer) -> Matriks
{mengembalikan perkalian antara matriks M dengan nilai skalar x} */
Matriks kaliSkalarMatriks(Matriks M1, int x) {
	// /Kamus Lokal/
	Matriks M;
	int i, j;

	// /Algoritma/
	initMatriks(&M);

	for (i=1; i<=10; i++) {
		for (j=1; j<=10; j++) {
			M.cell[i][j] = M1.cell[i][j] * x;
			M.nbaris++;
			M.nkolom++;
		}
	}
	return M;
}

/* OPERASI STATISTIK*/
/* function getSumMatriks (M:Matriks) -> integer 
	{mengembalikan jumlah semua elemen pengisi M.cell} */
int getSumMatriks (Matriks M) {
	// /Kamus Lokal/
	int i, j;
	int sum = 0;

	// /Algoritma/
	for (i=1; i<=10; i++) {
		for (j=1; j<=10; j++) {
			sum += M.cell[i][j];
		}
	}
	return sum;
}

/* function getAveragematriks (M:Matriks) -> real 
	{mengembalikan nilai rata-rata elemen pengisi M.cell} */
float getAverageMatriks (Matriks M) {
	// /Kamus Lokal/
	int i, j;
	float sum = 0;
	int count = 0;

	// /Algoritma/
	for (i=1; i<=10; i++) {
		for (j=1; j<=10; j++) {
			if (M.cell[i][j] != -999) {
				sum += M.cell[i][j];
				count++;
			}
		}
	}
	return sum/count;
}

/* function getMaxMatriks (M:Matriks) -> integer
	{mengembalikan nilai elemen terbesar pengisi M.cell } */
int getMaxMatriks (Matriks M) {
	// /Kamus Lokal/
	int i, j;
	int max = M.cell[1][1];

	// /Algoritma/
	for (i=1; i<=10; i++) {
		for (j=1; j<=10; j++) {
			if (M.cell[i][j] > max) {
				max = M.cell[i][j];
			}
		}
	}
	return max;
}

/* function getMinMatriks (M:Matriks) -> integer
	{mengembalikan nilai elemen terkecil pengisi M.cell} */
int getMinMatriks (Matriks M) {
	// /Kamus Lokal/
	int i, j;
	int min = M.cell[1][1];

	// /Algoritma/
	for (i=1; i<=10; i++) {
		for (j=1; j<=10; j++) {
			if (M.cell[i][j] < min) {
				min = M.cell[i][j];
			}
		}
	}
	return min;
}

/* OPERASI LAINNYA */
/* procedure transposeMatriks(input/output M: Matriks)
	{I.S.: M terdefinisi}
	{F.S.: Matriks M sudah ditukar susunan baris dan kolomnya (Transpose)}
	{proses: mengubah susunan cell matriks, M.cell[i,j] menjadi M.cell[j,i]} */
void transposeMatriks(Matriks *M) {
	// /Kamus Lokal/
	Matriks temp;
	int i, j;

	// /Algoritma/
	initMatriks(&temp);

	for (i=1; i<=10; i++) {
		for (j=1; j<=10; j++) {
			temp.cell[j][i] = (*M).cell[i][j];
		}
	}
	*M = temp;
}

/* function getTransposeMatriks(M: Matriks)
	{menghasilkan sebuah matriks yang merupakan hasil transpose dari matriks M} */
Matriks getTransposeMatriks(Matriks M) {
	// /Kamus Lokal/
	Matriks temp;
	int i, j;

	// /Algoritma/
	initMatriks(&temp);

	for (i=1; i<=10; i++) {
		for (j=1; j<=10; j++) {
			temp.cell[j][i] = M.cell[i][j];
		}
	}
	return temp;
}