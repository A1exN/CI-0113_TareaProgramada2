#include "empleadoDeNomina.h"

using namespace std;

EmpleadoDeNomina::EmpleadoDeNomina(int id_empleado, string nombre, string apellido, string email, int tipoEmpleado, float salarioMensualBruto)
{
    this->id_empleado = id_empleado;
    this->nombre = nombre;
    this->apellido = apellido;
    this->email = email;
    this->tipoEmpleado = tipoEmpleado;
    this->salarioMensualBruto = salarioMensualBruto;
}

EmpleadoDeNomina::~EmpleadoDeNomina()
{
    
}

float EmpleadoDeNomina::CalculoPago()
{
    return salarioMensualBruto * (1 - 0.07);
}