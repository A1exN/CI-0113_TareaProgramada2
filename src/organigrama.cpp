#include "organigrama.h"
#include "empleadoDeNomina.h"
#include "empleadoPorHoras.h"

Organigrama::Organigrama(EmpleadoDeNomina *director)
{
    this->director = director;
    director->AsignarSupervisor(NULL);
    this->indiceEmpleados.insert( std::pair<int, Empleado*>(director->ObtenerID(), director) );
}

Organigrama::~Organigrama()
{
    delete this->director;
}

void Organigrama::InsertarEmpleado(Empleado *nuevoEmpleado)
{
    // Quién es el supervisor?
    Empleado *supervisor = this->indiceEmpleados.at(nuevoEmpleado->ObtenerIDSupervisor());

    supervisor->AsignarSubordinado(nuevoEmpleado);
    nuevoEmpleado->AsignarSupervisor(supervisor);

    this->indiceEmpleados.insert( std::pair<int, Empleado*>(nuevoEmpleado->ObtenerID(), nuevoEmpleado) );

}

Empleado* Organigrama::ObtenerEmpleado(int id_empleado)
{
    Empleado *empleadoConEl_ID = this->indiceEmpleados.at(id_empleado);
    return empleadoConEl_ID;
}

map <int, Empleado *> Organigrama::ObtenerIndiceEmpleados()
{
    return this->indiceEmpleados;
}