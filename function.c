//#include <iostream>
#include <string.h>
#include <stdio.h>
#include<math.h>

#include "function.h"

Patient FillPatient(Patient *patient) {
    printf("Nome: ");
    fgets(patient->name, 50, stdin);
    patient->name[strcspn(patient->name, "\n")] = 0;

    printf("Sexo(M/F): ");
    scanf("%c", &patient->sex);

    printf("Idade: ");
    scanf("%d", &patient->age);

    printf("Altura: ");
    scanf("%f", &patient->height);

    printf("Peso: ");
    scanf("%f", &patient->weight);

    patient->BMI = CalculateBMI(patient->weight, patient->height);

    FillMeasurement(&patient->measurement);

    return *patient;
}

float MeasurementAverage() {
    float m1, m2, m3, average;
    scanf("%f %f %f", &m1, &m2, &m3);
    average = (m1 + m2 + m3) / 3;
    return average;
}

void PrintPatient(Patient patient) {
    printf("\n\n");

    printf("Nome: %s\n", patient.name);
    printf("Sexo: %c\n", patient.sex);
    printf("Idade: %danos\n", patient.age);
    printf("Altura: %.2fm\n", patient.height);
    printf("Peso: %.2fkg\n", patient.weight);
    printf("IMC: %.0fkg/m²\n", patient.BMI);
    printf("Triceps: %.2fmm\n", patient.measurement.triceps);
    printf("Subescapular: %.2fmm\n", patient.measurement.subscapular);
    printf("Peitoral: %.2fmm\n", patient.measurement.chest);
    printf("Axiliar Media: %.2fmm\n", patient.measurement.axilla);
    printf("Abdominal: %.2fmm\n", patient.measurement.abdominal);
    printf("Suprailiaca: %.2fmm\n", patient.measurement.suprailiac);
    printf("Coxa : %.2fmm", patient.measurement.thight);
}

float CalculateBMI(float weight, float height) {
    float BMI;
    BMI = weight / (pow(height, 2));

    return BMI;
}

Measurement FillMeasurement(Measurement *measurement) {

    printf("Tricipital(** ** **): \n");
    measurement->triceps = MeasurementAverage();

    printf("Subescapular(** ** **): \n");
    measurement->subscapular = MeasurementAverage();

    printf("Peitoral(** ** **): \n");
    measurement->chest = MeasurementAverage();

    printf("Axilar Media(** ** **): \n");
    measurement->axilla = MeasurementAverage();

    printf("Abdominal(** ** **): \n");
    measurement->abdominal = MeasurementAverage();

    printf("Suprailiaca(** ** **): \n");
    measurement->suprailiac = MeasurementAverage();

    printf("Coxa(** ** **): \n");
    measurement->thight = MeasurementAverage();

    return *measurement;
}
