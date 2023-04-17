typedef struct {
    float circWaist;    //Circunferência da cintura;
    float cirBiceps;    //Circunferência do bíceps
    float circChest;    //Circunferência do tórax;
    float circNeck;     //Circunferência do pescoço;
    float cirAbdominal; //Circunferência do abdômen;
    float circHip;      //Circunferência do quadril;
    float circThigh;    //Circunferência da coxa;
    float circForearm;  //Circunferência do antebraço;
    float circCalf;     //Circunferência da panturrilha;
} Circunference;

typedef struct {
    float triceps;     //Dobra Tríceps;
    float subscapular; //Dobra Subescapular;
    float chest;       //Dobra Peito;
    float axilla;      //Dobra Axila média;
    float abdominal;   //Dobra Abdominal;
    float suprailiac;  //Dobra Suprailíaca;
    float thigh;       //Dobra Coxa;
    float forearm;     //Dobra Antebraço;
    float calf;        //Dobra Panturrilha;
    float biceps;      //Dobra Bíceps;
} Skinfolds;

typedef struct {
    Skinfolds skinfolds;//Dobras cutâneas;
    Circunference circunference;
} Measurement;

typedef struct {
    char name[50];           //Nome;
    char sex;                //Sexo;
    int age;                 //Idade;
    float height;            //Altura;
    float weight;            //Peso;
    double BMI;               //IMC;
    char evaluator;          //Avaliador;
    Measurement measurement; //Medidas;
    int method;              //Metodo usado para calcular percentual de gordura, armazenado para numa proxima consulta usar o mesmo;
    double BD;
    double BF;
} Patient;

Patient SetPatient(Patient *patient);

Measurement SetMeasurement(Measurement *measurement);

Skinfolds SetSkinfold(Skinfolds *skinfolds);

Circunference SetCircunference(Circunference *circunference);

void PrintPatient(Patient patient);

double CalculateBMI(float weight, float height);

float MeasurementAverage();

void ResponseBMI(double BMI);

double MethodPollockMale3(float chest, float abdominal, float thigh, int age);

double MethodPollockFemale3(float triceps, float suprailiac, float thigh, int age);

int SelectMethod();

double CalculateBD(Patient *patient);

double MethodPollockMale4(float suprailliac, float abdominal, float triceps, float thigh, int age);

double MethodPollockFemale4(float suprailliac, float abdominal, float triceps, float thigh, int age);

double MethodPollockMale7(float chest, float axilla, float triceps, float subescapular, float abdominal, float suprailliac, float thigh, int age);

double MethodPollockFemale7(float chest, float axilla, float triceps, float subescapular, float abdominal, float suprailliac, float thigh, int age);

double CalculateBF(double BD);