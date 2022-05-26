#include <gtest/gtest.h>
#include "../src/planilla.h"

namespace
{
  TEST(planilla_tests, generar_reporte_test)
  {
    /// AAA

    // Arrange - configurar el escenario
    string empleados = "1 Denis Tyler denis_tyler@biz.com 1 1\n";
    empleados += "2 Alan Patel alan_patel@biz.com 2 1";
    string nomina = "1 4600.98";
    string horasTrabajadas = "2 42.26 55";
    istringstream streamEmpleado(empleados);
    istringstream streamNomina(nomina);
    istringstream streamHorasTrabajadas(horasTrabajadas);
    ostringstream reporte;


    // Act - ejecute la operación
    Planilla* planilla = new Planilla(&streamEmpleado, &streamNomina, &streamHorasTrabajadas, &reporte);
    planilla->GenerarReporte();
    string reporte_actual = reporte.str();
    string reporte_esperado = "1,Denis Tyler,Denis Tyler,4278.91\n2,Alan Patel,Denis Tyler,2324.3\n\n";
           reporte_esperado += ",Subtotal,Total Impuestos,Total\n,6603.21,322.07,6925.28";

    // Assert - valide los resultados
    ASSERT_EQ(reporte_actual, reporte_esperado);

    delete planilla;
  }
}