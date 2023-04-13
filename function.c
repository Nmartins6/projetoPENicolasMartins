//#include <iostream>
#include <string.h>
#include <stdio.h>
#include<math.h>

#include "function.h"

Patient FillPatient(Patient patient){
    printf("Nome: ");
    fgets(patient.name, 50, stdin);
    patient.name[strcspn(patient.name, "\n")] = 0;

    printf("Sexo(M/F): ");
    scanf("%c", &patient.sex);

    printf("Idade: ");
    scanf("%d", &patient.age);

    printf("Altura: ");
    scanf("%f", &patient.height);

    printf("Peso: ");
    scanf("%f", &patient.weight);

    patient.BMI = CalculateBMI(patient.weight, patient.height);

    FillMeasurement(&patient.measurement);

    return patient;
}

float MeasurementAverage() {
    float m1, m2, m3, average;
    scanf("%f %f %f", &m1, &m2, &m3);
    average = (m1+m2+m3)/3;
    return average;
}

void PrintPatient(Patient patient){
    printf("\n\n");

    printf("Nome: %s\n", patient.name);
    printf("Sexo: %c\n", patient.sex);
    printf("Idade: %d\n", patient.age);
    printf("Altura: %.2f\n", patient.height);
    printf("Peso: %.2f\n", patient.weight);
    printf("IMC: %.0f\n", patient.BMI);
    printf("Triceps: %.2f\n", patient.measurement.triceps);
    printf("Subescapular: %.2f\n", patient.measurement.subscapular);
    printf("Peitoral: %.2f\n", patient.measurement.chest);
    printf("Axiliar Media: %.2f\n", patient.measurement.axilla);
    printf("Abdominal: %.2f\n", patient.measurement.abdominal);
    printf("Suprailiaca: %.2f\n", patient.measurement.suprailiac);
    printf("Coxa : %.2f", patient.measurement.thight);
}

float CalculateBMI(float weight, float height){
    float BMI;
    BMI =  weight / (pow(height,2));

    return BMI;
}

Measurement FillMeasurement(Measurement *measurement){

    printf("Tricipital(mm): \n");
    measurement->triceps = MeasurementAverage();

    printf("Subescapular(mm): \n");
    measurement->subscapular = MeasurementAverage();

    printf("Peitoral(mm): \n");
    measurement->chest = MeasurementAverage();

    printf("Axilar Media(mm): \n");
    measurement->axilla = MeasurementAverage();

    printf("Abdominal(mm): \n");
    measurement->abdominal = MeasurementAverage();

    printf("Suprailiaca(mm): \n");
    measurement->suprailiac = MeasurementAverage();

    printf("Coxa(mm): \n");
    measurement->thight = MeasurementAverage();

    return *measurement;
}
