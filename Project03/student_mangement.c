
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 1000

#define DATA_FILE "students.txt"

struct all_students {
	int student_id;
	char name[50];
	char highest_qualification[50];
	float marks[5];
	float percentage;
	char phone[32];
	char address[200];
};

int student_count = 0;
static struct all_students students[MAX_STUDENTS];

void load_students() {
    FILE *f = fopen(DATA_FILE, "r");
    if (!f) {
        printf("No existing data file found.\n");
        return;
    }
    int loaded_new = 0;
    while (student_count < MAX_STUDENTS) {
        struct all_students tmp;
        int result = fscanf(f, "%d,%49[^,],%49[^,],%f,%f,%f,%f,%f,%f,%31[^,],%199[^\n]\n",
            &tmp.student_id,
            tmp.name,
            tmp.highest_qualification,
            &tmp.marks[0], &tmp.marks[1], &tmp.marks[2], &tmp.marks[3], &tmp.marks[4],
            &tmp.percentage,
            tmp.phone,
            tmp.address
        );
        if (result != 11) break;

        int found = 0;
        for (int k = 0; k < student_count; ++k) {
            if (students[k].student_id == tmp.student_id) { found = 1; break; }
        }
        if (!found) {
            students[student_count] = tmp;
            student_count++;
            loaded_new++;
        }

    }
    fclose(f);
    printf("Loaded %d new student(s) from file. Total in memory: %d\n", loaded_new, student_count);
}

void show_students() {
    if (student_count == 0) {
        printf("No students available.\n");
        return;
    }
    for (int i = 0; i < student_count; ++i) {
        struct all_students *s = &students[i];
        printf("Student %d:\n", i + 1);
        printf("  ID: %d\n", s->student_id);
        printf("  Name: %s\n", s->name);
        printf("  Qualification: %s\n", s->highest_qualification);
        printf("  Marks: %.1f, %.1f, %.1f, %.1f, %.1f\n", s->marks[0], s->marks[1], s->marks[2], s->marks[3], s->marks[4]);
        printf("  Percentage: %.2f\n", s->percentage);
        printf("  Phone: %s\n", s->phone);
        printf("  Address: %s\n", s->address);
    }
}

float calculate_percentage(float marks[5]) {
    float sum = 0.0f;
    for (int i = 0; i < 5; ++i) {
        sum += marks[i];
    }
    return sum / 5.0f;
}
void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("Storage full (max %d).\n", MAX_STUDENTS);
        return;
    }
    struct all_students *s = &students[student_count];

    printf("Enter student ID: ");
    scanf("%d", &s->student_id);


    for (int i = 0; i < student_count; ++i) {
        if (students[i].student_id == s->student_id) {
            printf("Student ID %d already exists — not adding duplicate.\n", s->student_id);
            return;
        }
    }


    printf("Enter name: ");
    scanf("%s", s->name);
    printf("Enter highest qualification: ");
    scanf("%s", s->highest_qualification);
    
    
    printf("Enter marks for 5 subjects:\n");
    for (int i = 0; i < 5; ++i) {
        printf(" Subject %d: ", i + 1);
        scanf("%f", &s->marks[i]);
    }
    s->percentage = calculate_percentage(s->marks);
    printf("Enter address: ");
    scanf(" %s", s->address);
    printf("Enter phone number: ");
    scanf("%s", s->phone);
    printf("Student added successfully.\n");
    student_count++;
}

int remove_student_by_id() {
    int id;
    printf("Enter student ID to remove: ");
    scanf("%d", &id);
    for (int i = 0; i < student_count; ++i) {
        if (students[i].student_id == id) {
            for (int j = i; j + 1 < student_count; ++j) {
                students[j] = students[j + 1];
            }
            student_count--;
            printf("Student with ID %d removed.\n", id);
            return 1;
        }
    }
    printf("Student with ID %d not found.\n", id);
    return 0;
}

int save_students() {
    FILE *f = fopen(DATA_FILE, "w");
    if (!f) {
        printf("Failed to open file '%s' for writing.\n", DATA_FILE);
        return 0;
    }
    for (int i = 0; i < student_count; ++i) {
        struct all_students *s = &students[i];
        fprintf(f, "%d,%s,%s,%.1f,%.1f,%.1f,%.1f,%.1f,%.2f,%s,%s\n",
            s->student_id,
            s->name,
            s->highest_qualification,
            s->marks[0], s->marks[1], s->marks[2], s->marks[3], s->marks[4],
            s->percentage,
            s->phone,
            s->address
        );
    }
    fclose(f);
    return 1;
}
int main(void){
    printf("Student Management System\n");
    
    load_students();

	while (1) {
		printf("\nMenu:\n");
		printf("  1) List students\n");
		printf("  2) Add single student\n");
		printf("  3) Remove student by ID\n");
		printf("  4) Save and exit\n");
		printf("  5) Exit without saving\n");
		printf("Choose option: ");
		int menu_choice;
        scanf("%d",&menu_choice);
        switch (menu_choice) 
        {
        case 1:
            show_students();
            break;
        case 2:
             add_student();
            break;
        case 3:
            remove_student_by_id();
            break;
        case 4:
            save_students();
            printf("Data saved. Exiting.\n");
            exit(0);
            break;
        case 5:
            printf("Exiting without saving.\n");
            exit(0);
            break;

        default:
            printf("Invalid option. Please try again.\n");
            break;
        }
    }
	
}
