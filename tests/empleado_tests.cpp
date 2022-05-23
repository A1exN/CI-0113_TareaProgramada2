#include <gtest/gtest.h>
#include "../src/empleadoDeNomina.h"

namespace
{
  TEST(empleado_nomina_tests, obterner_id)
  {
    /// AAA

    // Arrange - configurar el escenario
    EmpleadoDeNomina* empleado = new EmpleadoDeNomina(4, "Alan", "Patel", "alan_patel@biz.com", 1);

    // Act - ejecute la operación
    int id_actual = empleado->ObtenerID();
    int id_esperado = 4;

    // Assert - valide los resultados
    ASSERT_EQ(id_actual, id_esperado);

    delete empleado;
  }

  TEST(empleado_nomina_tests, obterner_nombre)
  {
    /// AAA

    // Arrange - configurar el escenario
    EmpleadoDeNomina* empleado = new EmpleadoDeNomina(4, "Alan", "Patel", "alan_patel@biz.com", 1);

    // Act - ejecute la operación
    string nombre_actual = empleado->ObtenerNombre();
    string nombre_esperado = "Alan";

    // Assert - valide los resultados
    ASSERT_EQ(nombre_actual, nombre_esperado);

    delete empleado;
  }

  TEST(empleado_nomina_tests, obterner_apellido)
  {
    /// AAA

    // Arrange - configurar el escenario
    EmpleadoDeNomina* empleado = new EmpleadoDeNomina(4, "Alan", "Patel", "alan_patel@biz.com", 1);

    // Act - ejecute la operación
    string apellido_actual = empleado->ObtenerApellido();
    string apellido_esperado = "Patel";

    // Assert - valide los resultados
    ASSERT_EQ(apellido_actual, apellido_esperado);

    delete empleado;
  }

  TEST(empleado_nomina_tests, obterner_email)
  {
    /// AAA

    // Arrange - configurar el escenario
    EmpleadoDeNomina* empleado = new EmpleadoDeNomina(4, "Alan", "Patel", "alan_patel@biz.com", 1);

    // Act - ejecute la operación
    string email_actual = empleado->ObtenerEmail();
    string email_esperado = "alan_patel@biz.com";

    // Assert - valide los resultados
    ASSERT_EQ(email_actual, email_esperado);

    delete empleado;
  }

  TEST(empleado_nomina_tests, obterner_tipoDeEmpleado)
  {
    /// AAA

    // Arrange - configurar el escenario
    EmpleadoDeNomina* empleado = new EmpleadoDeNomina(4, "Alan", "Patel", "alan_patel@biz.com", 1);

    // Act - ejecute la operación
    int tipoDeEmpleado_actual = empleado->ObtenerTipoEmpleado();
    int tipoDeEmpleado_esperado = 1;

    // Assert - valide los resultados
    ASSERT_EQ(tipoDeEmpleado_actual, tipoDeEmpleado_esperado);

    delete empleado;
  }

  TEST(empleado_nomina_tests, obterner_idDelSupervisor)
  {
    /// AAA

    // Arrange - configurar el escenario
    EmpleadoDeNomina* supervisor = new EmpleadoDeNomina(1, "Denis", "Tyler", "denis_tyler@biz.com", 1);
    EmpleadoDeNomina* empleado = new EmpleadoDeNomina(4, "Alan", "Patel", "alan_patel@biz.com", 1);
    empleado->AsignarSupervisor(supervisor);

    // Act - ejecute la operación
    int idDeSupervisor_actual = empleado->ObtenerSupervisor()->ObtenerID();
    int idDeSupervisor_esperado = 1;

    // Assert - valide los resultados
    ASSERT_EQ(idDeSupervisor_actual, idDeSupervisor_esperado);

    delete supervisor;
    delete empleado;
  }

  TEST(empleado_nomina_tests, calcular_salario)
  {
    /// AAA

    // Arrange - configurar el escenario
    EmpleadoDeNomina* empleado = new EmpleadoDeNomina(4, "Alan", "Patel", "alan_patel@biz.com", 1);
    empleado->AsignarSalarioMensualBruto(4606.19);

    // Act - ejecute la operación
    float salario_actual = empleado->CalculoPago();
    float salario_esperado = 4283.7567;

    // Assert - valide los resultados
    ASSERT_FLOAT_EQ(salario_actual, salario_esperado);

    delete empleado;
  }
}