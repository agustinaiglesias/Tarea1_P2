/*
  Módulo principal de la tarea 1.

Intérprete de comandos para probar los módulos implementados.

Cada comando tiene un nombre y una secuencia (posiblemente vacía) de parámetros.
Se asume que los comandos están bien formados. Esto implica que:
- el nombre es uno de los descritos más abajo;
- la cantidad y tipo de los parámetros cumplen con lo requerido.

El comando 'Fin' termina el programa

El comando '# comentario' imprime comentario.

El comando 'reiniciarEstructuras' libera la memoria asignada a todas las estructuras y las vuelve a crear.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
*/

#include "include/utils.h"
#include "include/fecha.h"
#include "include/controlFecha.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PALABRA 32
#define MAX_LINEA 256

#define MAX_CP 10
#define MAX_MAP 10
#define TAM_COL_CAD 10

// programa principal
int main() {

  TControlFecha cf = crearControlFecha();

  char restoLinea[MAX_LINEA + 1];
  char nom_comando[MAX_PALABRA];

  int cont_comandos = 0;
  bool salir = false;
  while (!salir) {
    // mostrar el prompt
    cont_comandos++;
    printf("%u>", cont_comandos);

    // leer el comando
    leerChars(nom_comando);

    // procesar el comando
    if (0 == strcmp(nom_comando, "Fin")) {
      salir = true;
      printf("Fin.\n");
      // comentario

    } else if (0 == strcmp(nom_comando, "#")) {
      leerRestoLinea(restoLinea);
      printf("# %s.\n", restoLinea);

    } else if (0 == strcmp(nom_comando, "definirFecha")) {
      nat* componentes = leerFecha();
      definirFecha(cf, componentes[0], componentes[1], componentes[2]);
	  delete[] componentes;
      printf("Fecha definida en forma exitosa.\n");

    } else if (0 == strcmp(nom_comando, "siguienteDia")) {
      siguienteDiaControl(cf);

    } else if (0 == strcmp(nom_comando, "aumentarDias")) {
      nat cantDias = leerNat();
      aumentarFechaControl(cf, cantDias);

    } else if (0 == strcmp(nom_comando, "fechaActual")) {
      fechaActualControl(cf);
      
    } else if (0 == strcmp(nom_comando, "fechaActualExtendida")) {
      fechaActualExtendidaControl(cf);

    } else if (0 == strcmp(nom_comando, "compararFecha")) {
	  nat* componentes = leerFecha();
	  TControlFecha cfComp = crearControlFecha();
      definirFecha(cfComp, componentes[0], componentes[1], componentes[2]);
	  delete[] componentes;
      compararConActualControl(cf, cfComp);
	  liberarControlFecha(cfComp);

    } else if (0 == strcmp(nom_comando, "reiniciarEstructuras")) {
      liberarControlFecha(cf);
      cf = crearControlFecha();
      printf("Estructuras reiniciadas.\n");

    } else {
      printf("Comando no reconocido.\n");
    } // if
    fgets(restoLinea, MAX_LINEA + 1, stdin);
  } // while

  liberarControlFecha(cf);
  return 0;
} // main
