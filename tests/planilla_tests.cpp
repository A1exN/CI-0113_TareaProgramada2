#include <gtest/gtest.h>
#include "../src/planilla.h"

namespace
{
  TEST(planilla_tests, agregar_director)
  {
    /// AAA

    // Arrange - configurar el escenario

    // Act - ejecute la operación
    Planilla* planilla = new Planilla(1, "Denis", "Tayler", "denis_tyler@biz.com", 1, 4600.98);

    string nombre_actual = planilla->ObtenerEmpleado(1)->ObtenerNombre();
    string nombre_esperado = "Denis";

    // Assert - valide los resultados
    ASSERT_EQ(nombre_actual, nombre_esperado);

    delete planilla;
  }

  TEST(planilla_tests, agregar_empleado_nomina)
  {
    /// AAA

    // Arrange - configurar el escenario
    Planilla* planilla = new Planilla(1, "Denis", "Tayler", "denis_tyler@biz.com", 1, 4600.98);

    // Act - ejecute la operación
    planilla->InsertarEmpleado(2, "Clarissa", "Parker", "clarissa_parker@biz.com", 1, 1, 3097.5);
    //string nombre_actual = planilla->ObtenerEmpleado(1)->ObtenerSubordinados().at(0)->ObtenerNombre();
    string nombre_actual = planilla->ObtenerEmpleado(2)->ObtenerNombre();
    string nombre_esperado = "Clarissa";

    // Assert - valide los resultados
    ASSERT_EQ(nombre_actual, nombre_esperado);

    delete planilla;
  }

  TEST(planilla_tests, agregar_empleado_por_horas)
  {
    /// AAA

    // Arrange - configurar el escenario
    Planilla* planilla = new Planilla(1, "Denis", "Tayler", "denis_tyler@biz.com", 1, 4600.98);

    // Act - ejecute la operación
    planilla->InsertarEmpleado(2, "Ryan", "Webster", "Ryan_Webster6612@hourpy.biz", 2, 1, 42.26, 55);
    //string nombre_actual = planilla->ObtenerEmpleado(1)->ObtenerSubordinados().at(0)->ObtenerNombre();
    string nombre_actual = planilla->ObtenerEmpleado(2)->ObtenerNombre();
    string nombre_esperado = "Ryan";

    // Assert - valide los resultados
    ASSERT_EQ(nombre_actual, nombre_esperado);

    delete planilla;
  }
}