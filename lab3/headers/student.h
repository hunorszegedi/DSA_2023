//
// Created by Lenovo on 27/02/2023.
//

#ifndef LAB3_STUDENT_H
#define LAB3_STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <constants.h>
#include "compareFunctions.h"

//declaration

enum Gender {
    MALE, FEMALE, OTHER
};

typedef struct Date_t {
    int year;
    int month;
    int day;
} Date_t;
typedef struct Student_t {
    int nr;
    char name[50];
    char neptunCode[8];
    char birthPlace[25];
    Date_t dateOfBirth;
    enum Gender gender;
    float examResult;
} Student_t;

void readStudentDetailsCON(Student_t *pStudent);

void printStudent(Student_t student);

void readStudentDetails(Student_t *pStudent);

void allocateMemoryForStudents(Student_t **dpStudents, int numberOfStudents);

void readAllStudentsDetails(Student_t **dpStudents, int *pNumberOfStudents, const char *input);

void printAllStudents(Student_t *pStudents, int numberOfStudents, const char *destination);

int getNumberOfStudentsByGender(Student_t *pStudents, int numberOfStudents, enum Gender gender);

void printStudentsFromSpecificCity(Student_t *pStudents, int numberOfStudents, const char *city);

void* findStudentByNeptunCode(Student_t *pStudents, int numberOfStudents, const char* neptunCode);

void sortStudentsByName(Student_t *pStudents, int numberOfStudents);

void sortStudentsByAgeAndExam(Student_t *pStudents, int numberOfStudents);

#endif //LAB3_STUDENT_H
