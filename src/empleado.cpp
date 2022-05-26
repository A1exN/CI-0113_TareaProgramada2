#include "empleado.h"

void Empleado::AsignarSupervisor(Empleado *supervisor)
{
    this->supervisor = supervisor;
}

void Empleado::AsignarSubordinado(Empleado *empleado)
{
    this->subordinados.push_back(empleado);
}

int Empleado::ObtenerID()
{
    return this->id_empleado;
}

int Empleado::ObtenerIDSupervisor()
{
    return this->id_supervisor;
}

Empleado *Empleado::ObtenerSupervisor()
{
    return this->supervisor;
}

vector <Empleado *> Empleado::ObtenerSubordinados()
{
    return this->subordinados;
}

istream& operator >> (istream &i, Empleado *empleado)
{
    i >> empleado->id_empleado
      >> empleado->nombre 
      >> empleado->apellido 
      >> empleado->email 
      >> empleado->tipoEmpleado 
      >> empleado->id_supervisor;

    return i;
}

ostream& operator << (ostream &o, Empleado *empleado)
{
    if (empleado->id_empleado == 1)
    {
        o << empleado->id_empleado << ","
            << empleado->nombre + " " + empleado->apellido << ","
            << empleado->nombre + " " + empleado->apellido << ","
            << empleado->CalculoPago();
    } else {
    o << empleado->id_empleado << ","
      << empleado->nombre + " " + empleado->apellido << ","
      << empleado->supervisor->nombre + " " + empleado->supervisor->apellido << ","
      << empleado->CalculoPago();
    }
    return o;
}