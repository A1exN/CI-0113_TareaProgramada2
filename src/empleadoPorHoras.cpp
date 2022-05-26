#include "empleadoPorHoras.h"

using namespace std;

EmpleadoPorHoras::EmpleadoPorHoras()
{

}

EmpleadoPorHoras::~EmpleadoPorHoras()
{
    for (Empleado* empleado : this->subordinados)
    {
        delete empleado;
    }
}

void EmpleadoPorHoras::AsignarInformacionDePago(float montoPorHora, int horasLaboradas)
{
    this->costoPorHoras = montoPorHora;
    this->horasEnMes = horasLaboradas;
}

float EmpleadoPorHoras::CalculoPago()
{
    return this->costoPorHoras * this->horasEnMes;
}