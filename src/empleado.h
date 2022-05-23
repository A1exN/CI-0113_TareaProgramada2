#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include <vector>

using namespace std;

class Empleado {

    // Privado

    protected:
    int tipoEmpleado;
    int id_empleado;
    string nombre;
    string apellido;
    string email;
    Empleado *supervisor;
    vector <Empleado *> subordinados;

    public:

    void AsignarSupervisor(Empleado *supervisor);

    void AsignarSubordinado(Empleado *empleado);

    int ObtenerTipoEmpleado();

    int ObtenerID();

    string ObtenerNombre();

    string ObtenerApellido();

    string ObtenerEmail();

    Empleado *ObtenerSupervisor();

    vector <Empleado *> ObtenerSubordinados();

    virtual float CalculoPago() = 0;

};


#endif