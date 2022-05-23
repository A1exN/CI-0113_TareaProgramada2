#include "empleadoPorHoras.h"

using namespace std;

EmpleadoPorHoras::EmpleadoPorHoras(int id_empleado, string nombre, string apellido, string email, int tipoEmpleado, float costoPorHoras, int horasEnMes)
{
    this->id_empleado = id_empleado;
    this->nombre = nombre;
    this->apellido = apellido;
    this->email = email;
    this->tipoEmpleado = tipoEmpleado;
    this->costoPorHoras = costoPorHoras;
    this->horasEnMes = horasEnMes;
}

EmpleadoPorHoras::~EmpleadoPorHoras()
{
    
}

float EmpleadoPorHoras::CalculoPago()
{
    return this->costoPorHoras * this->horasEnMes;
}