
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void task6() {
    int A[20];

    for (int i = 0; i < 20; i++) {
        A[i] = 20 - i;
        printf("%d ", A[i]);
    }
    printf("\n");
}

void task67() {
    int n;
    long long sum = 0;

    printf("Vvedit kilkist elementiv: ");
    scanf("%d", &n);

    if (n <= 0) return;

    int *A = malloc(n * sizeof(int));

    if (A == NULL) return;

    printf("Vvedit elementi:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);

        if (A[i] % 2 == 3) {
            sum += A[i];
        }
    }

    printf("Suma = %lld\n", sum);

    free(A);
}

void task153() {
    int K, L;

    printf("Vvedit K i L: ");
    scanf("%d %d", &K, &L);

    if (K < 0 || L < 0) return;

    int M = K + L;

    double *A = calloc(K + 1, sizeof(double));
    double *B = calloc(L + 1, sizeof(double));
    double *C = calloc(M + 1, sizeof(double));

    if (!A || !B || !C) {
        free(A);
        free(B);
        free(C);
        return;
    }

    printf("Vvedit koeficienti A:\n");
    for (int i = 0; i <= K; i++) {
        scanf("%lf", &A[i]);
    }

    printf("Vvedit koeficienti B:\n");
    for (int i = 0; i <= L; i++) {
        scanf("%lf", &B[i]);
    }

    for (int i = 0; i <= K; i++) {
        for (int j = 0; j <= L; j++) {
            C[i + j] += A[i] * B[j];
        }
    }

    printf("Koeficienti C:\n");

    for (int i = 0; i <= M; i++) {
        printf("C[%d] = %.2lf\n", i, C[i]);
    }

    free(A);
    free(B);
    free(C);
}

void task158() {
    int n;

    printf("Vvedit kilkist elementiv: ");
    scanf("%d", &n);

    if (n < 3) return;

    int *A = malloc(n * sizeof(int));

    if (A == NULL) return;

    printf("Vvedit elementi:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int min1 = A[0], min2 = A[1], min3 = A[2];

    if (min1 > min2) {
        int t = min1;
        min1 = min2;
        min2 = t;
    }

    if (min2 > min3) {
        int t = min2;
        min2 = min3;
        min3 = t;
    }

    if (min1 > min2) {
        int t = min1;
        min1 = min2;
        min2 = t;
    }

    for (int i = 3; i < n; i++) {
        if (A[i] < min1) {
            min3 = min2;
            min2 = min1;
            min1 = A[i];
        } else if (A[i] < min2) {
            min3 = min2;
            min2 = A[i];
        } else if (A[i] < min3) {
            min3 = A[i];
        }
    }

    printf("Suma = %lld\n", (long long)min1 + min2 + min3);

    free(A);
}

void task160() {
    int M1, M2;

    printf("Vvedit rozmir M1: ");
    scanf("%d", &M1);

    if (M1 <= 0) return;

    int *A = malloc(M1 * sizeof(int));

    if (A == NULL) return;

    printf("Vvedit elementi M1:\n");

    for (int i = 0; i < M1; i++) {
        scanf("%d", &A[i]);
    }

    printf("Vvedit rozmir M2: ");
    scanf("%d", &M2);

    if (M2 <= 0 || M2 > M1) {
        free(A);
        return;
    }

    int *B = malloc(M2 * sizeof(int));

    if (B == NULL) {
        free(A);
        return;
    }

    printf("Vvedit elementi M2:\n");

    for (int i = 0; i < M2; i++) {
        scanf("%d", &B[i]);
    }

    int count = 0;

    for (int i = 0; i <= M1 - M2; i++) {
        int found = 1;

        for (int j = 0; j < M2; j++) {
            if (A[i + j] != B[j]) {
                found = 0;
                break;
            }
        }

        if (found) count++;
    }

    printf("M2 zustrichaetsya %d raziv\n", count);

    free(A);
    free(B);
}

void task179() {
    int n, R, H;

    printf("Vvedit kilkist elementiv masivu: ");
    scanf("%d", &n);

    printf("Vvedit R i H: ");
    scanf("%d %d", &R, &H);

    if (n <= 0 || R <= 0 || H < 0 || H >= R) return;

    double *A = malloc(n * sizeof(double));
    int *B = malloc(n * sizeof(int));

    if (A == NULL || B == NULL) {
        free(A);
        free(B);
        return;
    }

    printf("Vvedit elementi masivu:\n");

    for (int i = 0; i < n; i++) {
        scanf("%lf", &A[i]);
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (fabs(A[i] - R) <= H) {
            B[count] = i + 1;
            count++;
        }
    }

    printf("Nomery elementiv:\n");

    for (int i = 0; i < count; i++) {
        printf("%d ", B[i]);
    }

    printf("\n");

    free(A);
    free(B);
}

int main() {
    int choice;

    do {
        printf("\n1. Zavdannya 6\n");
        printf("2. Zavdannya 67\n");
        printf("3. Zavdannya 153\n");
        printf("4. Zavdannya 158\n");
        printf("5. Zavdannya 160\n");
        printf("6. Zavdannya 179\n");
        printf("0. Vyhid\n");

        printf("Vyberit zavdannya: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: task6(); break;
            case 2: task67(); break;
            case 3: task153(); break;
            case 4: task158(); break;
            case 5: task160(); break;
            case 6: task179(); break;
            case 0: printf("Programa zavershena.\n"); break;
            default: printf("Nevirniy vybir!\n");
        }

    } while (choice != 0);

    return 0;
}