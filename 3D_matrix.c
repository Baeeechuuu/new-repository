#include <stdio.h>

// Fungsi untuk menjumlahkan dua matriks 3D [2][2][2]
void addMatrices(int matrix1[2][2][2], int matrix2[2][2][2], int result[2][2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                result[i][j][k] = matrix1[i][j][k] + matrix2[i][j][k];
            }
        }
    }
}

// Fungsi untuk mencetak matriks 3D [2][2][2]
void printMatrix(int matrix[2][2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                printf("%d ", matrix[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main() {
    int matrix1[2][2][2], matrix2[2][2][2], result[2][2][2];

    printf("Masukkan elemen-elemen untuk matriks pertama [2][2][2]:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                printf("matrix1[%d][%d][%d]: ", i, j, k);
                scanf("%d", &matrix1[i][j][k]);
            }
        }
    }


    printf("Masukkan elemen-elemen untuk matriks kedua [2][2][2]:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                printf("matrix2[%d][%d][%d]: ", i, j, k);
                scanf("%d", &matrix2[i][j][k]);
            }
        }
    }

    
    addMatrices(matrix1, matrix2, result);

    printf("Hasil penjumlahan kedua matriks [2][2][2]:\n");
    printMatrix(result);

    return 0;
}
