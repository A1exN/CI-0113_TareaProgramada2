#include "planilla.h"
#include "empleadoDeNomina.h"
#include "empleadoPorHoras.h"
#include <sstream>
#include <iomanip>

using namespace std;

Planilla::Planilla(istream *personas, istream *nomina, istream *horasTrabajadas, ostream *reporte){
    this->personas = personas;
    this->nomina = nomina;
    this->horasTrabajadas = horasTrabajadas;
    this->reporte = reporte;
}

Planilla::~Planilla()
{
    delete this->organigrama;
}

void Planilla::LlenarOrganigrama()
{
    string lineaInformacionGeneral;
    string lineaInformacionSalario;
    float salario;
    getline(*(this->personas), lineaInformacionGeneral);
    getline(*(this->nomina), lineaInformacionSalario);
    istringstream streamPersonas(lineaInformacionGeneral);
    istringstream streamNomina(lineaInformacionSalario);
    streamNomina >> salario >> salario;
    // Nodo Raíz
    EmpleadoDeNomina* director = new EmpleadoDeNomina();
    streamPersonas >> director;
    director->AsignarInformacionDePago(salario);

    this->subtotal += director->CalculoPago();
    this->impuestos += salario * 0.07;
    
    this->organigrama = new Organigrama(director);

    while (getline(*(this->nomina), lineaInformacionSalario))
    {
        getline(*(this->personas), lineaInformacionGeneral);
        istringstream streamPersonas(lineaInformacionGeneral);
        istringstream streamNomina(lineaInformacionSalario);
        streamNomina >> salario >> salario;

        EmpleadoDeNomina *nuevoEmpleado = new EmpleadoDeNomina();
        streamPersonas >> nuevoEmpleado;
        nuevoEmpleado->AsignarInformacionDePago(salario);

        this->subtotal += nuevoEmpleado->CalculoPago();
        this->impuestos += salario * 0.07;

        this->organigrama->InsertarEmpleado(nuevoEmpleado);
    }

    float montoPorHoras;
    int horasLaboradas;

    while (getline(*(this->horasTrabajadas), lineaInformacionSalario))
    {
        getline(*(this->personas), lineaInformacionGeneral);
        istringstream streamPersonas(lineaInformacionGeneral);
        istringstream streamHorasTrabajadas(lineaInformacionSalario);
        streamHorasTrabajadas >> montoPorHoras >> montoPorHoras >> horasLaboradas;

        EmpleadoPorHoras *nuevoEmpleado = new EmpleadoPorHoras();
        streamPersonas >> nuevoEmpleado;
        nuevoEmpleado->AsignarInformacionDePago(montoPorHoras, horasLaboradas);

        this->subtotal += nuevoEmpleado->CalculoPago();

        this->organigrama->InsertarEmpleado(nuevoEmpleado);
    }
}

void Planilla::LlenarArchivoCSV()
{
    for (int i=1; i <= this->organigrama->ObtenerIndiceEmpleados().size(); i++)
    {
        *(this->reporte) << this->organigrama->ObtenerIndiceEmpleados()[i] << endl;
    }
    
    *(this->reporte) << endl;
    *(this->reporte) << "," << "Subtotal" << "," << "Total Impuestos" << "," << "Total" << endl;
    *(this->reporte) << setprecision(2) << fixed << "," << this->subtotal << "," 
                     << this->impuestos << "," << this->subtotal + this->impuestos;

}

void Planilla::GenerarReporte()
{
    LlenarOrganigrama();
    LlenarArchivoCSV();
}