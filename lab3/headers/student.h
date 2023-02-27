//
// Created by Lenovo on 27/02/2023.
//

#ifndef LAB3_STUDENT_H
#define LAB3_STUDENT_H

#include <stdio.h>
#include <stdlib.h>
//declaration

enum Gender {MALE, FEMALE, OTHER};

typedef struct {
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

void readStudentDetails(Student_t *pStudent);

void readStudentDetailsFrom(Student_t *pStudent, const char *input);

void printStudent(Student_t student);

void allocateMemoryForStudents(Student_t **dpStudents, int numberOfStudents);


#endif //LAB3_STUDENT_H
