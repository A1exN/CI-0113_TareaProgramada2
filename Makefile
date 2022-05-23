FLAGS = -g -c --std=c++17

all:
	mkdir -p bin
	g++ $(FLAGS) src/empleado.cpp -o bin/empleado.o
	g++ $(FLAGS) src/empleadoDeNomina.cpp -o bin/empleadoDeNomina.o
	g++ $(FLAGS) src/empleadoPorHoras.cpp -o bin/empleadoPorHoras.o
	g++ $(FLAGS) src/planilla.cpp -o bin/planilla.o
	g++ $(FLAGS) src/main.cpp -o bin/main.o
	g++ -g -o bin/planilla bin/empleado.o bin/empleadoDeNomina.o bin/empleadoPorHoras.o bin/planilla.o bin/main.o
	
test:
	mkdir -p bin
	g++ $(FLAGS) src/empleado.cpp -o bin/empleado.o
	g++ $(FLAGS) src/empleadoDeNomina.cpp -o bin/empleadoDeNomina.o
	g++ $(FLAGS) src/empleadoPorHoras.cpp -o bin/empleadoPorHoras.o
	g++ $(FLAGS) src/planilla.cpp -o bin/planilla.o
	g++ $(FLAGS) tests/empleado_tests.cpp -o bin/empleado_tests.o
	g++ $(FLAGS) tests/planilla_tests.cpp -o bin/planilla_tests.o
	g++ -g -o bin/tests bin/empleado.o bin/empleadoDeNomina.o bin/empleadoPorHoras.o bin/empleado_tests.o bin/planilla.o bin/planilla_tests.o -lgtest -lgtest_main -lpthread

clean:
	rm -Rf bin

