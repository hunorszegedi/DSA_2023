//
// Created by Lenovo on 20/03/2023.
//

#ifndef ISMETLO_FELADATOK_PATIENT_H
#define ISMETLO_FELADATOK_PATIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <constants.h>
#include <string.h>

enum SICKNESS {
    INFLUENZA, DIABETES, CANCER,
    HYPERTENSION, ASTHMA, HEPATITIS, DEPRESSION, MIGRAINES,
    ANEMIA, OBESITY, ALLERGIES, UNDIFINED
};

typedef struct dateStruct {
    int year;
    int month;
    int day;
} dateStruct;

typedef struct Patient {
    int patientNumber;
    char name[40];
    char CNP[13];
    dateStruct date;
    enum SICKNESS sickness;

} Patient;

void readPatient(Patient *patient, FILE *fin);

void printPatient(Patient patient, FILE *fout);

enum SICKNESS getDiseaseByString(char *type);

#endif //ISMETLO_FELADATOK_PATIENT_H
