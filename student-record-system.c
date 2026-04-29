#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[50];
    float marks;
};

void addStudent() {
    FILE *fp = fopen("students.dat", "a");
    struct student s;

    printf("Enter ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("Student added successfully!\n");
}

void displayStudents() {
    FILE *fp = fopen("students.dat", "rb");
    struct student s;

    if(fp==NULL){
        printf("No records found!\n");
        return;
    }

    while(fread(&s, sizeof(s), 1, fp)) {
        printf("\nID: %d\nName: %s\nMarks: %.2f\n", s.id, s.name, s.marks);
    }

    fclose(fp);
}

void searchStudent() {
    FILE *fp = fopen("students.dat", "r");
    struct student s;
    int id, found = 0;

    printf("Enter ID to search: ");
    scanf("%d", &id);

    while(fread(&s, sizeof(s), 1, fp)) {
        if(s.id == id) {
            printf("\nFound!\nID: %d\nName: %s\nMarks: %.2f\n", s.id, s.name, s.marks);
            found = 1;
            break;
        }
    }

    if(!found) printf("Student not found!\n");

    fclose(fp);
}

int main() {
    int choice;

    while(1) {
        printf("\n--- Student Record System ---\n");
        printf("1. Add Student\n2. Display Students\n3. Search Student\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}
