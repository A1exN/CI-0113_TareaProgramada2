#include <gtest/gtest.h>
#include "../src/empleadoDeNomina.h"
#include "../src/empleadoPorHoras.h"

namespace
{
  TEST(empleado_nomina_tests, obterner_id)
  {
    /// AAA

    // Arrange - configurar el escenario
    string strEmpleado {"4 Alan Patel alan_patel@biz.com 1 1"};
    stringstream streamLinea(strEmpleado);
    EmpleadoDeNomina* empleado = new EmpleadoDeNomina();
    streamLinea >> empleado;

    // Act - ejecute la operación
    int id_actual = empleado->ObtenerID();
    int id_esperado = 4;

    // Assert - valide los resultados
    ASSERT_EQ(id_actual, id_esperado);

    delete empleado;
  }

  TEST(empleado_nomina_tests, obterner_id_superior)
  {
    /// AAA

    // Arrange - configurar el escenario
    string strSupervisor {"1 Denis Tyler denis_tyler@biz.com 1 1"};
    string strEmpleado {"4 Alan Patel alan_patel@biz.com 1 1"};
    stringstream streamSupervisor(strEmpleado);
    stringstream streamEmpleado(strEmpleado);
    EmpleadoDeNomina* supervisor = new EmpleadoDeNomina();
    EmpleadoDeNomina* empleado = new EmpleadoDeNomina();
    streamSupervisor >> supervisor;
    streamEmpleado >> empleado;

    // Act - ejecute la operación
    int id_actual = empleado->ObtenerIDSupervisor();
    int id_esperado = 1;

    // Assert - valide los resultados
    ASSERT_EQ(id_actual, id_esperado);

    delete supervisor;
    delete empleado;
  }

  TEST(empleado_nomina_tests, asignar_supervisor)
  {
    /// AAA

    // Arrange - configurar el escenario
    string strSupervisor {"1 Denis Tyler denis_tyler@biz.com 1 1"};
    string strEmpleado {"4 Alan Patel alan_patel@biz.com 1 1"};
    stringstream streamSupervisor(strEmpleado);
    stringstream streamEmpleado(strEmpleado);
    EmpleadoDeNomina* supervisor = new EmpleadoDeNomina();
    EmpleadoDeNomina* empleado = new EmpleadoDeNomina();
    streamSupervisor >> supervisor;
    streamEmpleado >> empleado;

    // Act - ejecute la operación
    empleado->AsignarSupervisor(supervisor);

    // Assert - valide los resultados
    ASSERT_EQ(empleado->ObtenerSupervisor(), supervisor);

    delete supervisor;
    delete empleado;
  }

  TEST(empleado_nomina_tests, asignar_subordinado)
  {
    /// AAA

    // Arrange - configurar el escenario
    string strSupervisor {"1 Denis Tyler denis_tyler@biz.com 1 1"};
    string strEmpleado {"4 Alan Patel alan_patel@biz.com 1 1"};
    stringstream streamSupervisor(strSupervisor);
    stringstream streamEmpleado(strEmpleado);
    EmpleadoDeNomina* supervisor = new EmpleadoDeNomina();
    EmpleadoDeNomina* empleado = new EmpleadoDeNomina();
    streamSupervisor >> supervisor;
    streamEmpleado >> empleado;

    // Act - ejecute la operación
    supervisor->AsignarSubordinado(empleado);

    // Assert - valide los resultados
    ASSERT_EQ(supervisor->ObtenerSubordinados().at(0), empleado);

    delete supervisor;
  }

  TEST(empleado_nomina_tests, calcular_salario)
  {
    /// AAA

    // Arrange - configurar el escenario
    string strEmpleado {"4 Alan Patel alan_patel@biz.com 1 1"};
    stringstream streamLinea(strEmpleado);
    EmpleadoDeNomina* empleado = new EmpleadoDeNomina();
    streamLinea >> empleado;
    empleado->AsignarInformacionDePago(4606.19);

    // Act - ejecute la operación
    float salario_actual = empleado->CalculoPago();
    float salario_esperado = 4283.7567;

    // Assert - valide los resultados
    ASSERT_FLOAT_EQ(salario_actual, salario_esperado);

    delete empleado;
  }

  TEST(empleado_por_hora_tests, calcular_pago)
  {
    /// AAA

    // Arrange - configurar el escenario
    string strEmpleado {"4 Alan Patel alan_patel@biz.com 1 1"};
    stringstream streamLinea(strEmpleado);
    EmpleadoPorHoras* empleado = new EmpleadoPorHoras();
    streamLinea >> empleado;
    empleado->AsignarInformacionDePago(32.52, 90);

    // Act - ejecute la operación
    float pago_actual = empleado->CalculoPago();
    float pago_esperado = 2926.8;

    // Assert - valide los resultados
    ASSERT_FLOAT_EQ(pago_actual, pago_esperado);

    delete empleado;
  }

}