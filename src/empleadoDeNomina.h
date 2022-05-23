#ifndef EMPLEADODENOMINA_H
#define EMPLEADODENOMINA_H

#include "empleado.h"

using namespace std;

class EmpleadoDeNomina : public Empleado {

    float salarioMensualBruto;

    public:
    EmpleadoDeNomina(int id_empleado, string nombre, string apellido, string email, int tipoEmpleado);
    ~EmpleadoDeNomina();

    void AsignarSalarioMensualBruto(float salarioMensualBruto);
    virtual float CalculoPago();

};

#endif