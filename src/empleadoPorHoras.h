#ifndef EMPLEADOPORHORAS_H
#define EMPLEADOPORHORAS_H

#include "empleado.h"

using namespace std;

class EmpleadoPorHoras : public Empleado {

    float costoPorHoras;
    int horasEnMes;

    public:
    EmpleadoPorHoras(int id_empleado, string nombre, string apellido, string email, int tipoEmpleado, float costoPorHoras, int horasPorMes);
    ~EmpleadoPorHoras();

    virtual float CalculoPago();
};

#endif