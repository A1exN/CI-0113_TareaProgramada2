#ifndef PLANILLA_H
#define PLANILLA_H

#include "organigrama.h"
#include <istream>
#include <ostream>
#include <fstream>

using namespace std;

class Planilla
{
    istream *personas;
    istream *nomina;
    istream *horasTrabajadas;
    ostream *reporte;

    Organigrama *organigrama;

    float subtotal {0};
    float impuestos {0};

    void LlenarOrganigrama();
    void LlenarArchivoCSV();

    public:

    Planilla(istream *personas, istream *nomina, istream *horasTrabajadas, ostream *reporte);
    ~Planilla();

    void GenerarReporte();
};

#endif