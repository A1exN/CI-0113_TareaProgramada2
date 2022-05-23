#ifndef PLANILLA_H
#define PLANILLA_H

#include "empleadoDeNomina.h"
#include <map>

using namespace std;

class Planilla {

    EmpleadoDeNomina *director;

    map<int, Empleado *> indiceEmpleados;

    public:

    Planilla(int id_empleado, string nombre, string apellido, string email, int tipoEmpleado, float salarioMensualBruto);
    ~Planilla();

    void InsertarEmpleado(int id_empleado, string nombre, string apellido, string email, int tipoEmpleado, int id_supervisor, float salarioMensualBruto);

    void InsertarEmpleado(int id_empleado, string nombre, string apellido, string email, int tipoEmpleado, int id_supervisor, float costoPorHoras, int horasPorMes);

    Empleado* ObtenerEmpleado(int id_empleado);    
};

#endif