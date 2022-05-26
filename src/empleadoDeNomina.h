#ifndef EMPLEADODENOMINA_H
#define EMPLEADODENOMINA_H

#include "empleado.h"


using namespace std;

class EmpleadoDeNomina : public Empleado {

    float salarioMensualBruto;

    public:
    EmpleadoDeNomina();
    ~EmpleadoDeNomina();

    void AsignarInformacionDePago(float salarioMensualBruto);
    virtual float CalculoPago();

};

#endif