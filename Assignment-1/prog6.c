#include <stdio.h>
#include <string.h>

#define MAX_NAMES 100
#define MAX_LEN 100

typedef struct {
    int roll;
    char name[MAX_LEN];
} Student;

void store_students(const char *filename, Student students[], int count) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s\n", students[i].roll, students[i].name);
    }

    fclose(file);
}

void find_smallest_largest_names(Student students[], int count, Student *smallest, Student *largest) {
    *smallest = students[0];
    *largest = students[0];

    for (int i = 1; i < count; i++) {
        if (strlen(students[i].name) < strlen(smallest->name)) {
            *smallest = students[i];
        }
        if (strlen(students[i].name) > strlen(largest->name)) {
            *largest = students[i];
        }
    }
}

void sort_students_by_name(Student students[], int count) {
    Student temp;

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void store_sorted_names(const char *filename, Student students[], int count) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n", students[i].name);
    }

    fclose(file);
}

int main() {
    Student students[MAX_NAMES];
    int count;
    Student smallest, largest;

    printf("Enter number of students: ");
    scanf("%d", &count);

    printf("Enter the roll number and name of each student:\n");
    for (int i = 0; i < count; i++) {
        printf("Enter details for student-%d:\n", i+1);
        printf("Roll number: ");
        scanf("%d", &students[i].roll);
        printf("Name: ");
        scanf("%s", students[i].name);
    }

    store_students("students.txt", students, count);

    find_smallest_largest_names(students, count, &smallest, &largest);

    printf("Smallest name: %s (Length: %lu)\n", smallest.name, strlen(smallest.name));
    printf("Largest name: %s (Length: %lu)\n", largest.name, strlen(largest.name));

    sort_students_by_name(students, count);

    store_sorted_names("sorted_names.txt", students, count);
    return 0;
}
