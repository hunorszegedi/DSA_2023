#include "student.h"

int main() {

    //creating a new Student_t type variable
    //hard coded details
    Student_t student_1 = {1,
                           "Szegedi Hunor",
                           "0000000",
                           "Neumarkt",
                           {2000, 7, 17},
                           MALE,
                           9.99};

    //choosing an exercise
    int option;
    feladat:
    printf("\nChoose an exercise (press 0 to exit):");
    scanf("%i", &option);

    //creating a new Student_t type variable
    Student_t student_2;

    //creating a Student_t array;
    Student_t *pStudents;
    int numberOfStudents;
    readAllStudentsDetails(&pStudents, &numberOfStudents, "students.txt");

    //result for 7
    Student_t *result = findStudentByNeptunCode(pStudents, numberOfStudents, "0000000");


    switch (option) {
        case 0:
            break;
        case 1:
            printStudent(student_1);
            goto feladat;
        case 2:
            printf("\tGive me the student's details!\n");
            readStudentDetailsCON(&student_2);
            printStudent(student_2);
            goto feladat;
        case 3:
            if (!freopen("be.txt", "r", stdin)) {
                printf(FILE_OPENING_ERROR_MESSAGE);
                exit(FILE_OPENING_ERROR_CODE);
            }
            readStudentDetails(&student_2);
            freopen("CON", "r", stdin);
            printStudent(student_2);
            goto feladat;
        case 4:
            printAllStudents(pStudents, numberOfStudents, "out.txt");
            goto feladat;
        case 5:
            printf("The number of male student: %i.\n", getNumberOfStudentsByGender(pStudents, numberOfStudents, MALE));
            goto feladat;
        case 6:
            printf("Students born in Marosvasarhely:\n");
            printStudentsFromSpecificCity(pStudents, numberOfStudents, "Neumarkt");
            goto feladat;

        case 7:
            if (!result) {
                printf(NULL_POINTER_EXCEPTION_ERROR_MESSAGE);
            } else {
                printf("Student with XX Neptun Code:");
                printStudent(*result);
            }
            goto feladat;
        case 8:
            sortStudentsByName(pStudents, numberOfStudents);
            printf("All students after sorting:\n");
            printAllStudents(pStudents, numberOfStudents, "abc_order.txt");
            goto feladat;
        case 9:
            sortStudentsByAgeAndExam(pStudents, numberOfStudents);
            printf("All student after sorting:\n");
            printAllStudents(pStudents, numberOfStudents, "age_exam_order.txt");
            goto feladat;
        default:
            break;
    }

    return 0;
}
