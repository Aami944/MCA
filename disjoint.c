#include <stdio.h>

#define MAX 50

int parent[MAX], rank[MAX], n;

void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSet(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx == ry) return;
    if (rank[rx] < rank[ry]) parent[rx] = ry;
    else if (rank[rx] > rank[ry]) parent[ry] = rx;
    else {
        parent[ry] = rx;
        rank[rx]++;
    }
}

int main() {
    int choice, x, y;
    scanf("%d", &n);
    makeSet(n);
    while (1) {
        printf("\n1.Find\n2.Union\n3.Display Sets\n4.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                scanf("%d", &x);
                printf("Root: %d\n", find(x));
                break;
            case 2:
                scanf("%d %d", &x, &y);
                unionSet(x, y);
                break;
            case 3:
                for (int i = 0; i < n; i++)
                    printf("%d -> %d\n", i, find(i));
                break;
            case 4:
                return 0;
        }
    }
}