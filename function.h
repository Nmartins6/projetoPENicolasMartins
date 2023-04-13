typedef struct {
    float triceps;
    float subscapular;
    float chest;
    float axilla;
    float abdominal;
    float suprailiac;
    float thight;
} Measurement;

typedef struct {
    char name[50];
    char sex;
    int age;
    float height;
    float weight;
    float BMI;
    Measurement measurement;

} Patient;

Patient FillPatient(Patient *patient);

Measurement FillMeasurement(Measurement *measurement);

void PrintPatient(Patient patient);

float CalculateBMI(float weight, float height);

float MeasurementAverage();