#include <stdio.h>
#include "course.h"
#include "courseResult.h"
#include "gpa.h"
#include "student.h"

void showMainMenu()
{
    printf("1. Student Management\n2. Academic Records\n3. Exit\nEnter Choice: ");
}

void viewStudents(Student students[], int n_students)
{
    for (int i = 0; i < n_students; i++) viewStudent(students[i]);
}

void addStudent(Student students[], int *n_students)
{
    char id[20], name[80];
    printf("Student ID: "); scanf("%19s", id);
    printf("Student Name: "); scanf("%79s", name);
    students[*n_students] = createStudent(id, name);
    (*n_students)++;
}

void studentManagement(Student students[], int *n_students)
{
    int choice = 0;
    while (choice != 5)
    {
        printf("1. Add Student\n2. Edit Student\n3. Delete Student\n4. View Students\n5. Back\nEnter Choice: ");
        scanf("%d", &choice);
        if (choice == 1) addStudent(students, n_students);
        else if (choice == 4) viewStudents(students, *n_students);
    }
}

void addCourse(Course courses[], int *n_courses)
{
    char code[16], name[100];
    double credit;
    int semester;
    printf("Course Code: "); scanf("%15s", code);
    printf("Course Name: "); scanf("%99s", name);
    printf("Credit: "); scanf("%lf", &credit);
    printf("Semester: "); scanf("%d", &semester);
    courses[*n_courses] = createCourse(code, name, credit, semester);
    (*n_courses)++;
}

void addCourseResult(Student *student, Course courses[], int n_courses)
{
    int course_no, completed;
    double marks;
    printf("Course Number: "); scanf("%d", &course_no);
    if (course_no < 1 || course_no > n_courses) return;
    printf("%s: %s Completed?\n1. YES.\n2. NO.\nEnter Choice: ",
           courses[course_no - 1].code, courses[course_no - 1].name);
    scanf("%d", &completed);
    if (completed == 1)
    {
        printf("Marks: "); scanf("%lf", &marks);
        addCourseResultToStudent(student,
            createCompletedCourseResult(&courses[course_no - 1], marks));
    }
    else
    {
        addCourseResultToStudent(student,
            createIncompleteCourseResult(&courses[course_no - 1]));
    }
}

void viewMarksheet(Student *student)
{
    for (int i = 0; i < student->n_results; i++)
        viewCourseResult(student->courseResults[i]);
    printf("CGPA: %.2f\n", student->cgpa);
}

void academicRecords(Student *student, Course courses[], int *n_courses)
{
    int choice = 0;
    while (choice != 11)
    {
        printf("1. Add Course\n2. Edit Course\n3. Delete Course\n4. View Courses\n");
        printf("5. Add Course Result\n6. Edit Course Result\n7. Delete Course Result\n");
        printf("8. View Marksheet\n9. Calculate Required GPA\n10. Calculate Expected CGPA\n11. Back\nEnter Choice: ");
        scanf("%d", &choice);
        if (choice == 1) addCourse(courses, n_courses);
        else if (choice == 4)
            for (int i = 0; i < *n_courses; i++) viewCourse(courses[i]);
        else if (choice == 5) addCourseResult(student, courses, *n_courses);
        else if (choice == 8) viewMarksheet(student);
        else if (choice == 9)
        {
            double target, remaining;
            printf("Target CGPA: "); scanf("%lf", &target);
            printf("Remaining credits: "); scanf("%lf", &remaining);
            printf("Required GPA: %.2f\n",
                   calculateRequiredGPA(student->cgpa, 0.0, target, remaining));
        }
        else if (choice == 10)
        {
            double expected, credits;
            printf("Expected future GPA: "); scanf("%lf", &expected);
            printf("Future credits: "); scanf("%lf", &credits);
            printf("Expected CGPA: %.2f\n",
                   calculateExpectedCGPA(student->cgpa, 0.0, expected, credits));
        }
    }
}

int main()
{
    Student students[100];
    Course courses[1000];
    int n_students = 0, n_courses = 0, choice = 0, student_no;

    while (choice != 3)
    {
        showMainMenu();
        scanf("%d", &choice);
        if (choice == 1) studentManagement(students, &n_students);
        else if (choice == 2)
        {
            printf("Enter Student ID Number: "); scanf("%d", &student_no);
            if (student_no >= 1 && student_no <= n_students)
                academicRecords(&students[student_no - 1], courses, &n_courses);
        }
    }
    return 0;
}
