//
// Created by Lenovo on 27/02/2023.
//

#include "student.h"

//definition

/**
 * if gender = 0 -> returns MALE
 * if gender = 1 -> returns FEMALE
 * if gender = 2 -> returns OTHER
 * @param gender is a number
 * @return
 */
char *genderType(enum Gender gender) {
    switch (gender) {
        case MALE:
            return "MALE";
        case FEMALE:
            return "FEMALE";
        default:
            return "OTHER";
    }
}

/**
 * Prints all details of a student
 * @param student
 */
void printStudent(Student_t student) {
    printf("\tInformation:\n");
    printf("Nr: %i\nName: %s\nNeptun Code: %s\nBirth Place: %s\nDate of Birth:\n\tYear: %i\n\tMonth: %i\n\tDay: %i\nGender: %s\nExam Result: %.2f\n\n",
           student.nr,
           student.name,
           student.neptunCode,
           student.birthPlace,
           student.dateOfBirth.year,
           student.dateOfBirth.month,
           student.dateOfBirth.day,
           genderType(student.gender),
           student.examResult);
}

/**
* Allocates memory for an array of Student_t types, array must be passed by reference
* @param dpStudents - double pointer to a Student_t type
* @param numberOfStudents
*/
void allocateMemoryForStudents(Student_t **dpStudents, int numberOfStudents) {

}

void readStudentDetailsFrom(Student_t *pStudent, const char *input) {
    if (!freopen(input, "r", stdin)) {
        printf("hiba");
        exit(-1);
    }
    scanf("%i\n", &pStudent->nr);
    fflush(stdin);
//    allocateMemory

    freopen("CON", "r", stdin);
}

void readStudentDetails(Student_t *pStudent) {
    scanf("%i\n", &pStudent->nr);
    scanf("%[\n]\n", pStudent->name);
    scanf("%[\n]\n", pStudent->neptunCode);
    scanf("%[\n]\n", pStudent->birthPlace);

    scanf("%i", &pStudent->dateOfBirth.year);
    scanf("%i", &pStudent->dateOfBirth.month);
    scanf("%i", &pStudent->dateOfBirth.day);

    scanf("%i", &pStudent->gender);
    scanf("%f", &pStudent->examResult);
}
