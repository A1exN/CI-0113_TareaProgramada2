#ifndef ORGANIGRAMA_H
#define ORGANIGRAMA_H

#include "empleadoDeNomina.h"
#include <map>

using namespace std;

class Organigrama {

    EmpleadoDeNomina *director;

    map<int, Empleado *> indiceEmpleados;

    public:

    Organigrama(EmpleadoDeNomina* director);
    ~Organigrama();

    void InsertarEmpleado(Empleado* nuevoEmpleado);

    Empleado* ObtenerEmpleado(int id_empleado); 

    map<int, Empleado *> ObtenerIndiceEmpleados();   
};

#endif