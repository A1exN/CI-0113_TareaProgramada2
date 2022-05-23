#include "planilla.h"
#include "empleadoDeNomina.h"
#include "empleadoPorHoras.h"

Planilla::Planilla(int id_empleado, string nombre, string apellido, string email, int tipoEmpleado, float salarioMensualBruto)
{
    // Agregar nodo raíz
    this->director = new EmpleadoDeNomina(id_empleado, nombre, apellido, email, tipoEmpleado, salarioMensualBruto);
    this->indiceEmpleados.insert( std::pair<int, Empleado*>(id_empleado, this->director) );
}

Planilla::~Planilla()
{
    delete this->director;
}

void Planilla::InsertarEmpleado(int id_empleado, string nombre, string apellido, string email, int tipoEmpleado, int id_supervisor, float salarioMensualBruto)
{
    EmpleadoDeNomina *nuevoEmpleado = new EmpleadoDeNomina(id_empleado, nombre, apellido, email, tipoEmpleado, salarioMensualBruto);

    // Quién es el supervisor?
    Empleado *supervisor = this->indiceEmpleados.at(id_supervisor);

    supervisor->AsignarSubordinado(nuevoEmpleado);
    nuevoEmpleado->AsignarSupervisor(supervisor);

    // Agregar nuevo nodo al índice
    this->indiceEmpleados.insert( std::pair<int, Empleado*>(id_empleado, nuevoEmpleado) );
}

void Planilla::InsertarEmpleado(int id_empleado, string nombre, string apellido, string email, int tipoEmpleado, int id_supervisor, float costoPorHoras, int horasPorMes)
{
    EmpleadoPorHoras *nuevoEmpleado = new EmpleadoPorHoras(id_empleado, nombre, apellido, email, tipoEmpleado, costoPorHoras, horasPorMes);

    // Quién es el supervisor?
    Empleado *supervisor = this->indiceEmpleados.at(id_supervisor);

    supervisor->AsignarSubordinado(nuevoEmpleado);
    nuevoEmpleado->AsignarSupervisor(supervisor);

    // Agregar nuevo nodo al índice
    this->indiceEmpleados.insert( std::pair<int, Empleado*>(id_empleado, nuevoEmpleado) );
}

Empleado* Planilla::ObtenerEmpleado(int id_empleado)
{
    Empleado *empleadoConEl_ID = this->indiceEmpleados.at(id_empleado);
    return empleadoConEl_ID;
}