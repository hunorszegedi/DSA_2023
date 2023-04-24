//
// Created by Lenovo on 20/03/2023.
//

#include "patient.h"


enum SICKNESS getDiseaseByString(char *type) {
    if (strcmp(type, "INFLUENZA") == 0) return INFLUENZA;
    if (strcmp(type, "DIABETES") == 0) return DIABETES;
    if (strcmp(type, "CANCER") == 0) return CANCER;
    if (strcmp(type, "HYPTERTENSION") == 0) return HYPERTENSION;
    if (strcmp(type, "ASTHMA") == 0) return ASTHMA;
    if (strcmp(type, "HEPATITIS") == 0) return HEPATITIS;
    if (strcmp(type, "DEPRESSION") == 0) return DEPRESSION;
    if (strcmp(type, "MIGRANES") == 0) return MIGRAINES;
    if (strcmp(type, "ANEMIA") == 0) return ANEMIA;
    if (strcmp(type, "OBESITY") == 0) return OBESITY;
    if (strcmp(type, "ALLERGIES") == 0) return ALLERGIES;
    return UNDIFINED;
}

char *getDiseaseCharByEnum(enum SICKNESS sickness) {
    switch (sickness) {
        case INFLUENZA:
            return "INFLUENZA";
        case DIABETES:
            return "DIABETES";
        case CANCER:
            return "CANCER";
        case HYPERTENSION:
            return "HYPERTENSION";
        case ASTHMA:
            return "ASTHMA";
        case HEPATITIS:
            return "HEPATITIS";
        case DEPRESSION:
            return "DEPRESSION";
        case MIGRAINES:
            return "MIGRAINES";
        case ANEMIA:
            return "ANEMIA";
        case OBESITY:
            return "OBESITY";
        case ALLERGIES:
            return "ALLERGIES";
        default:
            return "UNDIFINED";
    }
}

void readPatient(Patient *patient, FILE *fin) {
    char disease[20];
    fscanf(fin, "%[^\n]\n", patient->name);
    fscanf(fin, "%s\n", patient->CNP);

    fscanf(fin, "%s\n", disease);
    patient->sickness = getDiseaseByString(disease);

    fscanf(fin, "%d%d%d\n", &patient->date.day, &patient->date.month, &patient->date.year);
}

void printPatient(Patient patient, FILE *fout) {

    fprintf(fout, "\t%i. Patient\n", patient.patientNumber);
    fprintf(fout, "%s\n", patient.name);
    fprintf(fout, "%s\n", patient.CNP);
    fprintf(fout, "%s\n", getDiseaseCharByEnum(patient.sickness));
    fprintf(fout, "Day: %i Month: %i Year: %i\n", patient.date.day, patient.date.month, patient.date.year);
    fprintf(fout, "\n");

}


