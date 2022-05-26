#include "empleadoDeNomina.h"

using namespace std;

EmpleadoDeNomina::EmpleadoDeNomina()
{

}

EmpleadoDeNomina::~EmpleadoDeNomina()
{
    for (Empleado* empleado : this->subordinados)
    {
        delete empleado;
    }
}

void EmpleadoDeNomina::AsignarInformacionDePago(float salarioMensualBruto)
{
    this->salarioMensualBruto = salarioMensualBruto;
}

float EmpleadoDeNomina::CalculoPago()
{
    return salarioMensualBruto * (1 - 0.07);
}