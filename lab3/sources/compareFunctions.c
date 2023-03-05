//
// Created by Lenovo on 05/03/2023.
//

#include "compareFunctions.h"



int compareByName(const void *a, const void *b) {
    Student_t *aStudent = (Student_t *) a;
    Student_t *bStudent = (Student_t *) b;
    return strcmp(aStudent->name, bStudent->name);
}
int compareByAge(const void *a, const void *b) {
    Student_t *aStudent = (Student_t *) a;
    Student_t *bStudent = (Student_t *) b;
    if (aStudent->dateOfBirth.year == bStudent->dateOfBirth.year) {
        if (aStudent->dateOfBirth.month == bStudent->dateOfBirth.month) {
            return aStudent->dateOfBirth.day - bStudent->dateOfBirth.day;
        }
        return aStudent->dateOfBirth.month - bStudent->dateOfBirth.month;
    }
    return aStudent->dateOfBirth.year - bStudent->dateOfBirth.year;
}
int compareByExam(const void *a, const void *b) {
    Student_t *aStudent = (Student_t *) a;
    Student_t *bStudent = (Student_t *) b;
    if (aStudent->examResult > bStudent->examResult) {
        return -1;
    } else if (aStudent->examResult < bStudent->examResult) {
        return 1;
    } else return 0;
}

