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
  }
}