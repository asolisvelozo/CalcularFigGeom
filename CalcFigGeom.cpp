#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Constantes a utilizar
const float PI = 3.1415926536;
const int MAX_FIGS = 3;
const int MAX_PREG = 20;


struct Resultados {
    int cantPreg;
    int cantRespCor;
    int cantRespInc;
};


const string nomFigGeom[MAX_FIGS] = { "Triángulo", "Rectángulo", "Círculo" };


void CantRespFig(Resultados res[], int cantFig) {
    for (int i = 0; i < cantFig; i++) {
        res[i].cantPreg = 0;
        res[i].cantRespCor = 0;
        res[i].cantRespInc = 0;
    }
}


float FigsDosArg(float base, float altura, int tipoFigura) {
    if (tipoFigura == 0) {
        return (base * altura) / 2;
    } else if (tipoFigura == 1) {
        return base * altura;
    }
    return 0;
}

float SuperficieCirculo(float radio) {
    return PI * pow(radio, 2);
}


void ProCvarLFM(Resultados res[], int cantFig) {
    float base, altura, radio, respuestaAlumno, supCorrecta;
    int tipoFigura;

    for (int i = 0; i < cantFig; i++) {

        tipoFigura = i;


        if (tipoFigura == 0) {
            cout << "Ingrese base y altura del triángulo: ";
            cin >> base >> altura;
            supCorrecta = FigsDosArg(base, altura, tipoFigura);
        } else if (tipoFigura == 1) {
            cout << "Ingrese base y altura del rectángulo: ";
            cin >> base >> altura;
            supCorrecta = FigsDosArg(base, altura, tipoFigura);
        } else if (tipoFigura == 2) {
            cout << "Ingrese el radio del círculo: ";
            cin >> radio;
            supCorrecta = SuperficieCirculo(radio);
        }


        res[tipoFigura].cantPreg++;


        cout << "¿Cuál es la superficie del " << nomFigGeom[tipoFigura] << "?: ";
        cin >> respuestaAlumno;


        if (fabs(respuestaAlumno - supCorrecta) < 0.01) {
            cout << "¡Correcto!\n";
            res[tipoFigura].cantRespCor++;
        } else {
            cout << "Incorrecto. La superficie correcta es: " << supCorrecta << endl;
            res[tipoFigura].cantRespInc++;
        }
    }
}

void EmitirResultados2(Resultados res[], int cantFig) {
    cout << "\nResultados Totales\n";
    cout << left << setw(15) << "Figura" << setw(10) << "Preg." << setw(10) << "Correctas" << setw(10) << "Incorrectas" << endl;
    for (int i = 0; i < cantFig; i++) {
        cout << left << setw(15) << nomFigGeom[i]
             << setw(10) << res[i].cantPreg
             << setw(10) << res[i].cantRespCor
             << setw(10) << res[i].cantRespInc << endl;
    }
}

int main() {
    Resultados res[MAX_FIGS];
    CantRespFig(res, MAX_FIGS);

    ProCvarLFM(res, MAX_FIGS);

    EmitirResultados2(res, MAX_FIGS);

    return 0;
}
