/*
  Módulo de definición de 'TFecha'.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#ifndef _FECHA_H
#define _FECHA_H

#include <utils.h>

// Representación de 'TFecha'.
// Se debe definir en fecha.cpp.
// struct _rep_fecha;
// Declaración del tipo 'TFecha'
typedef struct _rep_fecha *TFecha;

/*
  Devuelve un TFecha con los el día, mes y año definidos en los parámetros.
 */
TFecha crearFecha(nat dia, nat mes, nat anio);

/*
  Libera la memoria asignada a 'f'.
*/
void liberarFecha(TFecha f);

/*
    Aumenta la fecha cantDias días. 
*/
void aumentarFecha(TFecha f, nat cantDias);

/*
    Incrementa en un día la fecha actual de la aplicación.
*/
void siguienteDia(TFecha f);

/*  
    Compara f1 con f2. Si f1 es anterior a f2 devuelva -1. Si f1 es igual a f2 devuelve 0. 
    Si f1 es mayor a f2 devuelve 1.
*/
int compararFechas(TFecha f1, TFecha f2);

/*
    Devuelve un char* que contiene la representación de la fecha en formato corto, es decir dd/mm/aaaa.
	Por ejemplo 01/01/2022.
*/
char* fechaActual(TFecha f);

/*
    Devuelve un char* que contiene la representación de la fecha en formato extendido.
	Por ejemplo para la fecha 01/01/2022 se debería imprimir '01 de enero de 2022'.
*/
char* fechaActualExtendida(TFecha f);

#endif
