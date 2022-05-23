#include "empleado.h"

void Empleado::AsignarSupervisor(Empleado *supervisor)
{
    this->supervisor = supervisor;
}

void Empleado::AsignarSubordinado(Empleado *empleado)
{
    this->subordinados.push_back(empleado);
}

int Empleado::ObtenerTipoEmpleado()
{
    return this->tipoEmpleado;
}

int Empleado::ObtenerID()
{
    return this->id_empleado;
}

string Empleado::ObtenerNombre()
{
    return this->nombre;
}

string Empleado::ObtenerApellido()
{
    return this->apellido;
}

string Empleado::ObtenerEmail()
{
    return this->email;
}

Empleado *Empleado::ObtenerSupervisor()
{
    return this->supervisor;
}

vector <Empleado *> Empleado::ObtenerSubordinados()
{
    return this->subordinados;
}