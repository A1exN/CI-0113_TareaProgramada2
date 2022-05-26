#include "empleado.h"
#include "planilla.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {

    ifstream Personas("personas.txt", std::ifstream::in); // Por default abriendo como texto

    if (!Personas.is_open())
    {
        std::cerr << "Error leyendo archivo ejemplo.txt" << std::endl;
        return -1;
    }
    
    ifstream Nomina("nomina.txt", std::ifstream::in);

    if (!Nomina.is_open())
    {
        std::cerr << "Error leyendo archivo ejemplo.txt" << std::endl;
        return -1;
    }

    ifstream HorasTrabajadas("horastrabajadas.txt", std::ifstream::in);

    if (!HorasTrabajadas.is_open())
    {
        std::cerr << "Error leyendo archivo ejemplo.txt" << std::endl;
        return -1;
    }

    ofstream Reporte("reporte.csv", std::ofstream::out);

    if (!Reporte.is_open())
    {
        std::cerr << "Error abriendo archivo reporte.csv" << std::endl;
        return -1;
    }

    Planilla *planilla = new Planilla(&Personas, &Nomina, &HorasTrabajadas, &Reporte);
    planilla->GenerarReporte();
    delete planilla;

    Personas.close();
    Nomina.close();
    HorasTrabajadas.close();
    Reporte.close();

}