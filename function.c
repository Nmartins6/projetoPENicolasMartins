//#include <iostream>
#include <string.h>
#include <stdio.h>
#include<math.h>

#include "function.h"

//SetPatient armazena alguns dados do paciente;
Patient SetPatient(Patient *patient) {
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

    SetMeasurement(&patient->measurement);

    patient->method = SelectMethod();

    patient->DC=CalculateBF(patient);

    return *patient;
}

//SetMeasurement foi criado para fins de praticar ponteiros e structs;
Measurement SetMeasurement(Measurement *measurement) {
    SetSkinfold(&measurement->skinfolds);
    SetCircunference(&measurement->circunference);
}

//SetSkinfold é armazena dados em uma struct dentro de paciente. (patietn-->measurement-->skinfold);
Skinfolds SetSkinfold(Skinfolds *skinfolds) {

    printf("Tricipital(** ** **): \n");
    skinfolds->triceps = MeasurementAverage();

    printf("Subescapular(** ** **): \n");
    skinfolds->subscapular = MeasurementAverage();

    printf("Peitoral(** ** **): \n");
    skinfolds->chest = MeasurementAverage();

    printf("Axilar Media(** ** **): \n");
    skinfolds->axilla = MeasurementAverage();

    printf("Abdominal(** ** **): \n");
    skinfolds->abdominal = MeasurementAverage();

    printf("Suprailiaca(** ** **): \n");
    skinfolds->suprailiac = MeasurementAverage();

    printf("Coxa(** ** **): \n");
    skinfolds->thigh = MeasurementAverage();

    printf("Panturrilha(** ** **): \n");
    skinfolds->calf = MeasurementAverage();

    printf("Antebraço(** ** **): \n");
    skinfolds->forearm = MeasurementAverage();

    printf("Biceps(** ** **): \n");
    skinfolds->biceps = MeasurementAverage();

    return *skinfolds;
}

//SetCircunference armazena dados em uma struct dentro de paciente. (patietn-->measurement-->circunference)
Circunference SetCircunference(Circunference *circunference) {
    printf("Circunferencia cintura: \n");
    scanf("%f", &circunference->circWaist);

    printf("Circunferencia biceps: \n");
    scanf("%f", &circunference->cirBiceps);

    printf("Circunferencia torax: \n");
    scanf("%f", &circunference->circChest);


    printf("Circunferencia pescoço: \n");
    scanf("%f", &circunference->circNeck);


    printf("Circunferencia abdomen: \n");
    scanf("%f", &circunference->cirAbdominal);


    printf("Circunferencia quadril: \n");
    scanf("%f", &circunference->circHip);


    printf("Circunferencia coxa: \n");
    scanf("%f", &circunference->circThigh);


    printf("Circunferencia antebraço: \n");
    scanf("%f", &circunference->circForearm);


    printf("Circunferencia panturrilha: \n");
    scanf("%f", &circunference->circCalf);

    return *circunference;
}

//Imprime todos os dados coletados do paciente, provavelmente não usarei a 'apresentação' final pro usuário assim, estou usando para testes;
void PrintPatient(Patient patient) {
    printf("\n\n");

    printf("Nome: %s\n", patient.name);
    printf("Sexo: %c\n", patient.sex);
    printf("Idade: %d anos\n", patient.age);
    printf("Altura: %.2fm\n", patient.height);
    printf("Peso: %.2fkg\n", patient.weight);
    printf("IMC: %.0fkg/m²", patient.BMI);
    ResponseBMI(patient.BMI);
    printf("\n");
    printf("Antebraço: %.2fmm\n", patient.measurement.skinfolds.forearm);
    printf("Biceps: %.2fmm\n", patient.measurement.skinfolds.biceps);
    printf("Panturrilha: %.2fmm\n", patient.measurement.skinfolds.calf);
    printf("Subescapular: %.2fmm\n", patient.measurement.skinfolds.subscapular);
    printf("Peitoral: %.2fmm\n", patient.measurement.skinfolds.chest);
    printf("Axiliar Media: %.2fmm\n", patient.measurement.skinfolds.axilla);
    printf("Abdominal: %.2fmm\n", patient.measurement.skinfolds.abdominal);
    printf("Suprailiaca: %.2fmm\n", patient.measurement.skinfolds.suprailiac);
    printf("Coxa: %.2fmm", patient.measurement.skinfolds.thigh);
    printf("Circunferencia cintura: %.2f\n", patient.measurement.circunference.circWaist);
    printf("Circunferencia biceps: %.2f\n", patient.measurement.circunference.cirBiceps);
    printf("Circunferencia torax: %.2f\n", patient.measurement.circunference.circChest);
    printf("Circunferencia pescoço: %.2f\n", patient.measurement.circunference.circNeck);
    printf("Circunferencia abdomen: %.2f\n", patient.measurement.circunference.cirAbdominal);
    printf("Circunferencia quadril: %.2f\n", patient.measurement.circunference.circHip);
    printf("Circunferencia coxa %.2f\n", patient.measurement.circunference.circThigh);
    printf("Circunferencia antebraço: %.2f\n", patient.measurement.circunference.circForearm);
    printf("Circunferencia panturrilha: %.2f\n", patient.measurement.circunference.circCalf);
    printf("Densidade Corporal: %.2lf\n", patient.DC);
}

//Calcula o IMC do paciente, tanto para impressão, seleção de alguns indicadores e futuros cálculos;
float CalculateBMI(float weight, float height) {
    float BMI;
    BMI = weight / (pow(height, 2));

    return BMI;
}

//Coleta o que seria a média de 3 medidas do adipômetro e retorna a média entre eles. Uma boa prática para melhor precisão da medida;
float MeasurementAverage() {
    float m1, m2, m3, average;
    scanf("%f %f %f", &m1, &m2, &m3);
    average = (m1 + m2 + m3) / 3;

    return average;
}

//Retorna pro usuário qual a indicação do seu IMC de acordo com uma tabela existente;
void ResponseBMI(float BMI) {

    if (BMI < 17) {
        printf(" (Magreza Leve)");
    } else if (BMI < 18.5) {
        printf(" (Magreza Leve)");
    } else if (BMI < 25) {
        printf(" (Saudável)");
    } else if (BMI < 30) {
        printf(" (Sobrepeso)");
    } else if (BMI < 35) {
        printf(" (Obesidade grau I");
    } else if (BMI < 40) {
        printf(" (Obesidade grau II)");
    } else {
        printf(" (Obesidade grauIII)");
    }
}

//*As próximas funções são protocolos para obter densidade corporal e percentual de gordura dos pacientes, nem todos
//os metodos serão usados nesse primeiro momento, ainda irei decidir sobre o fator de escolha de cada metodo;

//Inicialmente o usuário escolherá a função através da função seguinte;

int SelectMethod(){
    int method;

    printf("\nSelecione o protocolo para estimar o percentual de gordura do paciente:\n"
           "1 - Pollock 3 dobras;\n"
           "2 - Pollock 4 dobras;\n"
           "3 - Pollock 7 dobras;\n");
    scanf("%d", &method);

    return method;
}

double CalculateBF(Patient *patient) {
    if (patient->method == 1) {
        if (patient->sex == 'M') {
            patient->DC = MethodPollockMale3(patient->measurement.skinfolds.chest, patient->measurement.skinfolds.abdominal,
                               patient->measurement.skinfolds.thigh, patient->age);
        } else {
            patient->DC = MethodPollockFemale3(patient->measurement.skinfolds.triceps, patient->measurement.skinfolds.suprailiac,
                                 patient->measurement.skinfolds.thigh, patient->age);
        }

//    }else if(method == 2){
//        if(){
//
//        }else
//    }else{
//        if(){
//
//        }else{
//
//        }
//    }
    }
}

double MethodPollockMale3(float chest, float abdominal, float thigh, int age){
    double DC;
    double sumSkinfolds;

    sumSkinfolds = chest + abdominal + thigh;

    DC = 1.10938 - (0.0008267 * sumSkinfolds) + (0.0000016 * pow(sumSkinfolds,2)) - (0.0002574 * age);

    return DC;
}

double MethodPollockFemale3(float triceps, float suprailiac, float thigh, int age){
    double DC;
    double sumSkinfolds;

    sumSkinfolds = triceps + suprailiac + thigh;

    DC = 1.0994921 - (0.0009929 * sumSkinfolds) + (0.0000023 * pow(sumSkinfolds,2)) - (0.0001392 * age);

    return DC;
}