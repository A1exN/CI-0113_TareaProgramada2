#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Empleado {

    // Privado

    protected:
    int tipoEmpleado;
    int id_empleado;
    int id_supervisor;
    string nombre;
    string apellido;
    string email;
    Empleado *supervisor;
    vector <Empleado *> subordinados;

    public:

    void AsignarSupervisor(Empleado *supervisor);

    void AsignarSubordinado(Empleado *empleado);

    int ObtenerID();

    int ObtenerIDSupervisor();

    Empleado *ObtenerSupervisor();

    vector <Empleado *> ObtenerSubordinados();

    friend istream& operator >> (istream &i, Empleado *empleado);

    friend ostream& operator << (ostream &o, Empleado *empleado);

    virtual float CalculoPago() = 0;

};


#endif