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
        case OTHER:
            return "OTHER";
        default:
            return "UNDEFINED";
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
 * reading student details from CON
 * @param pStudent
 */
void readStudentDetailsCON(Student_t *pStudent) {
    printf("Nr:");
    scanf("%i", &pStudent->nr);
    fflush(stdin);
    printf("Name:");
    scanf("%[^\n]", pStudent->name);
    fflush(stdin);
    printf("Neptun Code:");
    scanf("%[^\n]", pStudent->neptunCode);
    fflush(stdin);
    printf("Birth Place:");
    scanf("%[^\n]", pStudent->birthPlace);

    printf("Date of Birth:");
    printf("\n\tYear:");
    scanf("%i", &pStudent->dateOfBirth.year);
    printf("\n\tMonth:");
    scanf("%i", &pStudent->dateOfBirth.month);
    printf("\n \tDay:");
    scanf("%i", &pStudent->dateOfBirth.day);
    printf("Gender:");
    scanf("%i", &pStudent->gender);
    printf("Exam Result:");
    scanf("%f", &pStudent->examResult);
}

/**
* Reads all details of a student, student must be passed by reference
* @param pStudent - pointer to a student
*/
void readStudentDetails(Student_t *pStudent) {
    scanf("%i\n", &pStudent->nr);
    scanf("%[^\n]\n", pStudent->name);
    scanf("%s\n", pStudent->neptunCode);
    scanf("%[^\n]\n", pStudent->birthPlace);

    scanf("%i", &pStudent->dateOfBirth.year);
    scanf("%i", &pStudent->dateOfBirth.month);
    scanf("%i", &pStudent->dateOfBirth.day);

    scanf("%i", &pStudent->gender);
    scanf("%f", &pStudent->examResult);
}

/**
* Allocates memory for an array of Student_t types, array must be passed by reference
* @param dpStudents - double pointer to a Student_t type
* @param numberOfStudents
*/
void allocateMemoryForStudents(Student_t **dpStudents, int numberOfStudents) {
    *dpStudents = (Student_t *) calloc(numberOfStudents, sizeof(Student_t));
    if (!*dpStudents) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

/**
* Reads all students' data from an input
* This function should call first the @allocateMemoryForStudents function
* @param dpStudents - double pointer to a Student_t type
* @param numberOfStudents
* @param input CON or input file name
*/
void readAllStudentsDetails(Student_t **dpStudents, int *pNumberOfStudents, const char *input) {
    if (!freopen(input, "r", stdin)) {
        printf(FILE_OPENING_ERROR_MESSAGE);
        exit(FILE_OPENING_ERROR_CODE);
    }

    scanf("%i", pNumberOfStudents);
    allocateMemoryForStudents(dpStudents, *pNumberOfStudents);
    for (int i = 0; i < *pNumberOfStudents; ++i) {
        readStudentDetails((*dpStudents) + i);
    }

    freopen("CON", "r", stdin);
}

/**
* Prints all students to a given destination
* @param pStudents - pointer to a student, start of the array
* @param numberOfStudents
* @param destination CON or output file name
*/
void printAllStudents(Student_t *pStudents, int numberOfStudents, const char *destination) {
    freopen(destination, "w", stdout);
    for (int i = 0; i < numberOfStudents; ++i) {
        printStudent(pStudents[i]);
    }
    freopen("CON", "w", stdout);
}

/**
* Returns the number of students with a specific gender
* @param pStudents - pointer to a student, start of the array
* @param numberOfStudents
* @param gender - one of the Gender enum values
* @return - number of students with a specific gender
*/
int getNumberOfStudentsByGender(Student_t *pStudents, int numberOfStudents, enum Gender gender) {
    int counter = 0;
    for (int i = 0; i < numberOfStudents; ++i) {
        if (pStudents[i].gender == gender) {
            counter++;
        }
    }
    return counter;
}

/**
* Prints all students from a specific city
* @param pStudents - pointer to a student, start of the array
* @param numberOfStudents
* @param city
*/
void printStudentsFromSpecificCity(Student_t *pStudents, int numberOfStudents, const char *city) {
    for (int i = 0; i < numberOfStudents; ++i) {
        if (strcmp(pStudents[i].birthPlace, city) == 0) {
            printStudent(pStudents[i]);
        }
    }
}

/**
* Finds a student with a specific Neptun code
* @param pStudents - pointer to a student, start of the array
* @param numberOfStudents
* @param neptunCode the required neptunCode
* @return A Student_t with the provided Neptun code, otherwise NULL
*/
void *findStudentByNeptunCode(Student_t *pStudents, int numberOfStudents, const char *neptunCode) {
    for (int i = 0; i < numberOfStudents; ++i) {
        if (strcmp(pStudents[i].neptunCode, neptunCode) == 0) {
            return pStudents + i;
        }
    }
    return NULL;
}


/**
* Sorts the array of students by name in ABC order
* @param pStudents - pointer to a student, start of the array
* @param numberOfStudents
*/
void sortStudentsByName(Student_t *pStudents, int numberOfStudents) {
    qsort(pStudents, numberOfStudents, sizeof(Student_t), compareByName);
}

int compareByAgeAndExam(const void *a, const void *b) {
    int ageResult = compareByAge(a, b);
    if (ageResult == 0) {
        return compareByExam(a, b);
    }
    return ageResult;
}


/**
* Sorts the array of students by their date of birth (ASC) and exam results (ASC)
* @param pStudents - pointer to a student, start of the array
* @param numberOfStudents
*/
void sortStudentsByAgeAndExam(Student_t *pStudents, int numberOfStudents) {
    qsort(pStudents, numberOfStudents, sizeof(Student_t), compareByAgeAndExam);
}