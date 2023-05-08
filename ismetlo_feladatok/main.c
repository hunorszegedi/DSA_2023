#include "patient.h"


int main() {

    //hardCoded details
//    Patient patientUno = {1, "Nagy Attila"
//                             "5000629230011",
//                          {2000, 6, 15}, ANEMIA};
//
//    FILE *foutHardCoded = fopen("outUNO.txt", "w");
//    if (!foutHardCoded) {
//        printf(FILE_OPENING_ERROR_MESSAGE);
//        exit(FILE_OPENING_ERROR_CODE);
//    }
//    printPatient(patientUno, foutHardCoded);
    Patient *patients = (Patient *) calloc(20, sizeof(Patient));
    if (!patients) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    FILE *fin = fopen("patients.txt", "r");
    if (!fin) {
        printf(FILE_OPENING_ERROR_MESSAGE);
        exit(FILE_OPENING_ERROR_CODE);
    }

    FILE *fout = fopen("out.txt", "w");
    if (!fout) {
        printf(FILE_OPENING_ERROR_MESSAGE);
        exit(FILE_OPENING_ERROR_CODE);
    }

    for (int i = 0; i < 20; ++i) {
        patients[i].patientNumber = i + 1;
        readPatient(&patients[i], fin);
    }

    for (int i = 0; i < 20; ++i) {
        printPatient(patients[i], fout);
    }


    fclose(fin);
    fclose(fout);


    return 0;
}
