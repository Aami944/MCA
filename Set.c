#include <stdio.h>

#define MAX 32

void readSet(int set[]) {
    int n, x;
    for (int i = 0; i < MAX; i++) set[i] = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x >= 0 && x < MAX) set[x] = 1;
    }
}

void displaySet(int set[]) {
    for (int i = 0; i < MAX; i++)
        if (set[i] == 1) printf("%d ", i);
    printf("\n");
}

void setUnion(int A[], int B[], int C[]) {
    for (int i = 0; i < MAX; i++)
        C[i] = A[i] | B[i];
}

void setIntersection(int A[], int B[], int C[]) {
    for (int i = 0; i < MAX; i++)
        C[i] = A[i] & B[i];
}

void setDifference(int A[], int B[], int C[]) {
    for (int i = 0; i < MAX; i++)
        C[i] = A[i] & (!B[i]);
}

int main() {
    int A[MAX], B[MAX], C[MAX];
    int choice;
    while (1) {
        printf("\n1.Read Set A\n2.Read Set B\n3.Union\n4.Intersection\n5.Difference A-B\n6.Display A\n7.Display B\n8.Display Result\n9.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                readSet(A);
                break;
            case 2:
                readSet(B);
                break;
            case 3:
                setUnion(A, B, C);
                break;
            case 4:
                setIntersection(A, B, C);
                break;
            case 5:
                setDifference(A, B, C);
                break;
            case 6:
                displaySet(A);
                break;
            case 7:
                displaySet(B);
                break;
            case 8:
                displaySet(C);
                break;
            case 9:
                return 0;
        }
    }
}