#include <gtest/gtest.h>
#include "../src/empleadoDeNomina.h"
#include "../src/empleadoPorHoras.h"
#include "../src/organigrama.h"

namespace
{
  TEST(organigrama_tests, agregar_director)
  {
    /// AAA

    // Arrange - configurar el escenario
    string strDirector {"1 Alan Patel alan_patel@biz.com 1 1"};
    stringstream streamLinea(strDirector);
    EmpleadoDeNomina* director = new EmpleadoDeNomina();
    streamLinea >> director;

    // Act - ejecute la operación
    Organigrama *organigrama = new Organigrama(director);

    // Assert - valide los resultados
    ASSERT_EQ(director, organigrama->ObtenerEmpleado(1));

    delete organigrama;
  }

  TEST(organigrama_tests, insertar_empleado_no_director)
  {
    /// AAA

    // Arrange - configurar el escenario
    string strDirector {"1 Alan Patel alan_patel@biz.com 1 1"};
    string strEmpleado {"4 Denis Tyler denis_tyler@biz.com 1 1"};
    stringstream streamDirector(strDirector);
    stringstream streamEmpleado(strEmpleado);
    EmpleadoDeNomina* director = new EmpleadoDeNomina();
    EmpleadoDeNomina* empleado = new EmpleadoDeNomina();
    streamDirector >> director;
    streamEmpleado >> empleado;
    Organigrama *organigrama = new Organigrama(director);

    // Act - ejecute la operación
    organigrama->InsertarEmpleado(empleado);

    // Assert - valide los resultados
    ASSERT_EQ(empleado, organigrama->ObtenerEmpleado(4));

    delete organigrama;
  }

  TEST(organigrama_tests, obtener_indice_empleados)
  {
    /// AAA

    // Arrange - configurar el escenario
    string strDirector {"1 Denis Tyler denis_tyler@biz.com 1 1"};
    stringstream streamEmpleado(strDirector);
    EmpleadoDeNomina* director = new EmpleadoDeNomina();
    streamEmpleado >> director;
    Organigrama *organigrama = new Organigrama(director);
    // Act - ejecute la operación

    // Assert - valide los resultados
    ASSERT_EQ(director, organigrama->ObtenerIndiceEmpleados()[1]);

    delete organigrama;
  }
}
