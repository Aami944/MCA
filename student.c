#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int roll;
    char name[50];
    int mark1, mark2;
    int total;
};

struct Student s[MAX];
int count = 0;

void insert() {
    struct Student st;
    printf("Roll No: ");
    scanf("%d", &st.roll);
    printf("Name: ");
    scanf("%s", st.name);
    printf("Mark1: ");
    scanf("%d", &st.mark1);
    printf("Mark2: ");
    scanf("%d", &st.mark2);
    st.total = st.mark1 + st.mark2;
    s[count++] = st;
}

void deleteRecord() {
    int r, i, j;
    printf("Enter roll no to delete: ");
    scanf("%d", &r);
    for(i = 0; i < count; i++) {
        if(s[i].roll == r) {
            for(j = i; j < count - 1; j++)
                s[j] = s[j + 1];
            count--;
            printf("Record deleted\n");
            return;
        }
    }
    printf("Record not found\n");
}

void display() {
    int i;
    for(i = 0; i < count; i++) {
        printf("%d %s %d %d %d\n", s[i].roll, s[i].name, s[i].mark1, s[i].mark2, s[i].total);
    }
}

void save() {
    FILE *fp = fopen("students.dat", "wb");
    fwrite(&count, sizeof(int), 1, fp);
    fwrite(s, sizeof(struct Student), count, fp);
    fclose(fp);
    printf("Saved\n");
}

void restore() {
    FILE *fp = fopen("students.dat", "rb");
    if(fp == NULL) {
        printf("No file found\n");
        return;
    }
    fread(&count, sizeof(int), 1, fp);
    fread(s, sizeof(struct Student), count, fp);
    fclose(fp);
    printf("Restored\n");
}

int main() {
    int ch;
    while(1) {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Save\n5.Restore\n6.Exit\n");
        scanf("%d", &ch);
        switch(ch) {
            case 1: insert(); break;
            case 2: deleteRecord(); break;
            case 3: display(); break;
            case 4: save(); break;
            case 5: restore(); break;
            case 6: return 0;
            default: printf("Invalid\n");
        }
    }
}
