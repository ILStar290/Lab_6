
#include <stdio.h>
#include <stdlib.h>

void task921() {
    int n, m;

    printf("Vvedit kilkist ryadkiv i stovptsiv: ");
    scanf("%d %d", &n, &m);

    if (n <= 0 || m <= 0 || n > 1000 || m > 1000) {
        printf("Pomylka!\n");
        return;
    }

    int *A = malloc(n * m * sizeof(int));

    if (A == NULL) {
        printf("Pomylka pamyati!\n");
        return;
    }

    printf("Vvedit elementi:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i * m + j]);
        }
    }

    int max = A[0];
    int row = 0, col = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i * m + j] > max) {
                max = A[i * m + j];
                row = i;
                col = j;
            }
        }
    }

    printf("Maximalniy element = %d\n", max);
    printf("Ryadok = %d\n", row + 1);
    printf("Stovpets = %d\n", col + 1);

    free(A);
}

void task935() {
    int n, m, X;

    printf("Vvedit kilkist ryadkiv i stovptsiv: ");
    scanf("%d %d", &n, &m);

    if (n <= 0 || m <= 0 || n > 1000 || m > 1000) {
        printf("Pomylka!\n");
        return;
    }

    int *A = malloc(n * m * sizeof(int));

    if (A == NULL) return;

    printf("Vvedit elementi masivu:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i * m + j]);
        }
    }

    printf("Vvedit X: ");
    scanf("%d", &X);

    int i = 0;
    int j = m - 1;
    int found = 0;

    while (i < n && j >= 0) {
        if (A[i * m + j] == X) {
            found = 1;
            break;
        } else if (A[i * m + j] > X) {
            j--;
        } else {
            i++;
        }
    }

    if (found) {
        printf("Element znaydeno!\n");
        printf("Indeksi: (%d, %d)\n", i + 1, j + 1);
    } else {
        printf("NI\n");
    }

    free(A);
}

void task956() {
    int n, m, c, r;

    printf("Vvedit kilkist ryadkiv i stovptsiv: ");
    scanf("%d %d", &n, &m);

    if (n < 3 || m < 2 || n > 1000 || m > 1000) {
        printf("Pomylka!\n");
        return;
    }

    int *A = malloc(n * m * sizeof(int));

    if (A == NULL) return;

    printf("Vvedit elementi masivu:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i * m + j]);
        }
    }

    printf("Vvedit c: ");
    scanf("%d", &c);

    printf("Vvedit r: ");
    scanf("%d", &r);

    if (c < 1 || c > n || r < 1 || r > n) {
        printf("Pomylka!\n");
        free(A);
        return;
    }

    long long sum1 = 0;
    long long sum2 = 0;
    long long sum3 = 0;
    long long sum4 = 0;

    for (int j = 0; j < m; j++) {
        sum1 += A[2 * m + j];
        sum2 += A[(c - 1) * m + j];
        sum4 += A[(r - 1) * m + j];
    }

    for (int i = 0; i < n; i++) {
        sum3 += A[i * m + 1];
    }

    printf("Suma 3-go ryadka = %lld\n", sum1);
    printf("Suma c-go ryadka = %lld\n", sum2);
    printf("Suma 2-go stovptsya = %lld\n", sum3);
    printf("Suma r-go ryadka = %lld\n", sum4);

    free(A);
}

void task961() {
    int A[18][36];

    printf("Vvedit 0 abo 1 dlya kozhnogo mistsya:\n");

    for (int i = 0; i < 18; i++) {
        printf("Vagon %d:\n", i + 1);

        for (int j = 0; j < 36; j++) {
            scanf("%d", &A[i][j]);

            if (A[i][j] != 0 && A[i][j] != 1) {
                printf("Pomylka! Vvedit 0 abo 1.\n");
                return;
            }
        }
    }

    for (int i = 0; i < 18; i++) {
        int freeSeats = 0;

        for (int j = 0; j < 36; j++) {
            if (A[i][j] == 0) {
                freeSeats++;
            }
        }

        printf("Vagon %d: vilnih mists %d\n", i + 1, freeSeats);
    }
}

void task1005() {
    int n, m;

    printf("Vvedit kilkist ryadkiv i stovptsiv: ");
    scanf("%d %d", &n, &m);

    if (n <= 0 || m <= 0 || n > 1000 || m > 1000) {
        printf("Pomylka!\n");
        return;
    }

    int *A = malloc(n * m * sizeof(int));

    if (A == NULL) return;

    printf("Vvedit elementi matritsi:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i * m + j]);
        }
    }

    long long maxSum = 0;
    long long minSum = 0;
    int maxRow = 0;
    int minRow = 0;

    for (int j = 0; j < m; j++) {
        maxSum += A[j];
        minSum += A[j];
    }

    for (int i = 1; i < n; i++) {
        long long sum = 0;

        for (int j = 0; j < m; j++) {
            sum += A[i * m + j];
        }

        if (sum > maxSum) {
            maxSum = sum;
            maxRow = i;
        }

        if (sum < minSum) {
            minSum = sum;
            minRow = i;
        }
    }

    printf("Ryadok z naybilshoyu sumoyu:\n");

    for (int j = 0; j < m; j++) {
        printf("%d ", A[maxRow * m + j]);
    }

    printf("\nSuma = %lld\n", maxSum);

    printf("Ryadok z naymenshoyu sumoyu:\n");

    for (int j = 0; j < m; j++) {
        printf("%d ", A[minRow * m + j]);
    }

    printf("\nSuma = %lld\n", minSum);

    free(A);
}

int main() {
    int choice;

    do {
        printf("\n========== MENU ==========\n");
        printf("1. Zavdannya 921\n");
        printf("2. Zavdannya 935\n");
        printf("3. Zavdannya 956\n");
        printf("4. Zavdannya 961\n");
        printf("5. Zavdannya 1005\n");
        printf("0. Vyhid\n");
        printf("==========================\n");

        printf("Vyberit zavdannya: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: task921(); break;
            case 2: task935(); break;
            case 3: task956(); break;
            case 4: task961(); break;
            case 5: task1005(); break;
            case 0: printf("Programa zavershena.\n"); break;
            default: printf("Nevirniy vybir!\n");
        }

    } while (choice != 0);

    return 0;
}