# Tarea Programada 2

Este programa lee tres archivos de datos, los procesa y luego genere un archivo con la información del monto a pagar por persona y qué supervisor debe realizar el pago (excepto el director, el cual se paga a sí mismo).

## Primer archivo - Personas.txt

El primer archivo contiene la información de cada persona, incluyendo si son empleados de nómina o si son profesionales independientes contratados por horas. Cada empleado tiene asignado un supervisor, excepto por el director de la empresa.

El formato de cada línea del archivo será el siguiente (separado por espacios):

| ID_Empleado | Nombre |Apellido |Email | Tipo_Empleado | ID_Supervisor |
|---|---|---|---|---|---|


Tipo_Empleado será 1 para empleado de nómina y 2 para profesional por horas.

## Segundo archivo - Nomina.txt

El segundo archivo contiene la información de pago para los empleados por nómina. Incluye el monto bruto a pagar, que debe de sufrir una retención del 7% por concepto de impuestos.

Monto neto (que es lo que se paga) = Monto bruto - retención del 7%

El formato de este archivo será el siguiente (separado por espacios):

|ID_Empleado|Pago mensual bruto (sin cálculo de retención)|
|---|---|

## Tercer archivo - HorasTrabajadas.txt

El tercer archivo contiene la información del monto que cobra el profesional por hora así como el acumulado de horas trabajadas en el mes a pagar. No se debe retener monto por impuestos porque cada profesional gestiona su pago de impuestos por separado.

El formato de este archivo será el siguiente (separado por espacios):

|ID_Empleado|Monto por hora|Horas laboradas en el mes|
|---|---|---|

## Archivo de salida - Reporte.csv

El archivo de salida es un archivo separado por comas (csv).
En cada línea, se incluye por empleado y profesional por horas:

|ID_Empleado,Nombre completo,Nombre completo del supervisor,Monto a pagar (monto neto)|
|---|

Al final del archivo, se incluye a manera de resumen:

Subtotal (suma de montos a pagar), total de impuestos a retener, total (subtotal más total de impuestos).