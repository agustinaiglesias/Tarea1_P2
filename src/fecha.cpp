/* 5463192 */
/*
  Módulo de definición de 'TFecha'.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#include "../include/utils.h"
#include "../include/fecha.h"
#include "stdio.h"
#include "string.h"

// Representación de 'TFecha'.
// Se debe definir en fecha.cpp.
// struct _rep_fecha;
// Declaración del tipo 'TFecha'
struct _rep_fecha{
    nat dia;
    nat mes;
    nat anio;
};

/*
  Devuelve un TFecha con los el día, mes y año definidos en los parámetros.
 */
TFecha crearFecha(nat dia, nat mes, nat anio){
    TFecha fecha =  new _rep_fecha;
    (*fecha).dia = dia;
    (*fecha).mes = mes;
    (*fecha).anio = anio;

    return fecha;
    }

/*
  Libera la memoria asignada a 'f'.
*/
void liberarFecha(TFecha f){
    if(f != NULL)
    {delete f;
    f = NULL;}
}

/*
    Aumenta la fecha cantDias días.
*/
void aumentarFecha(TFecha f, nat cantDias){
    //veo si el año es bisiesto o no.
    bool bis;
    int i;

    while(cantDias > 0){

        if (((*f).anio % 4 == 0 && (*f).anio % 100 != 0) || (*f).anio % 400 == 0){
        bis = true;
    } else {
        bis = false;
    }

        if (f->mes == 1 && cantDias > 0){
            for (i = f->dia+1; i<32; i++){
                if(cantDias > 0){
                    cantDias = cantDias - 1;
                    f->dia = i;
                }
            }
        if (cantDias > 0) {
            f->mes = 2;
            f->dia = 0; }
        }

        if (f->mes == 2 && bis == true && cantDias > 0){
            for (i = f->dia+1; i<30; i++){
                if(cantDias > 0){
                    cantDias = cantDias - 1;
                    f->dia = i;
                }
            }
        if (cantDias > 0) {
            f->mes = 3;
            f->dia = 0; }

        }

        if (f->mes == 2 && bis == false && cantDias > 0){
            for (i = f->dia+1; i<29; i++){
                if(cantDias > 0){
                    cantDias = cantDias - 1;
                    f->dia = i;
                }
            }
        if (cantDias > 0) {
            f->mes = 3;
            f->dia = 0; }

        }

        if (f->mes == 3 && cantDias > 0){ //marzo
            for (i = f->dia+1; i<32; i++){
                if(cantDias > 0){
                    cantDias = cantDias - 1;
                    f->dia = i;
                }
            }
        if (cantDias > 0) {
            f->mes = 4;
            f->dia = 0; }
        }

        if (f->mes == 4 && cantDias > 0){ //abril
            for (i = f->dia+1; i<31; i++){
                if(cantDias > 0){
                    cantDias = cantDias - 1;
                    f->dia = i;
                }
            }

        if (cantDias > 0) {
            f->mes = 5;
            f->dia = 0; }
        }

        if (f->mes == 5 && cantDias > 0){ //mayo
            for (i = f->dia+1; i<32; i++){
                if(cantDias > 0){
                    cantDias = cantDias - 1;
                    f->dia = i;
                }
            }

        if (cantDias > 0) {
            f->mes = 6;
            f->dia = 0; }
        }

        if (f->mes == 6 && cantDias > 0){ //junio
            for (i = f->dia+1; i<31; i++){
                if(cantDias > 0){
                    cantDias = cantDias - 1;
                    f->dia = i;
                }
            }

        if (cantDias > 0) {
            f->mes = 7;
            f->dia = 0; }
        }

        if (f->mes == 7 && cantDias > 0){ //julio
            for (i = f->dia+1; i<32; i++){
                if(cantDias > 0){
                    cantDias = cantDias - 1;
                    f->dia = i;
                }
            }

        if (cantDias > 0) {
            f->mes = 8;
            f->dia = 0; }
        }

        if (f->mes == 8 && cantDias > 0){ //agosto
            for (i = f->dia+1; i<32; i++){
                if(cantDias > 0){
                    cantDias = cantDias - 1;
                    f->dia = i;
                }
            }

        if (cantDias > 0) {
            f->mes = 9;
            f->dia = 0; }
        }

        if (f->mes == 9 && cantDias > 0){ //septiembre
            for (i = f->dia+1; i<31; i++){ //pongo un dia mas de los que tiene el mes
                if(cantDias > 0){
                    cantDias = cantDias - 1;
                    f->dia = i;
                }
            }

        if (cantDias > 0) {
            f->mes = 10;
            f->dia = 0; }
        }

        if (f->mes == 10 && cantDias > 0){ //octubre
            for (i = f->dia+1; i<32 ; i++){
                if(cantDias > 0){
                    cantDias = cantDias - 1;
                    f->dia = i;
                }
            }

        if (cantDias > 0) {
            f->mes = 11;
            f->dia = 0; }
        }

        if (f->mes == 11 && cantDias > 0){ //noviembre
            for (i = f->dia+1; i<31; i++){
                if(cantDias > 0){
                    cantDias = cantDias - 1;
                    f->dia = i;
                }
            }

        if (cantDias > 0) {
            f->mes = 12;
            f->dia = 0; }
        }

            if (f->mes == 12 && cantDias > 0){ //diciembre
            for (i = f->dia+1; i<32; i++){
                if(cantDias > 0){
                    cantDias = cantDias - 1;
                    f->dia = i;
                }
            }

        if (cantDias > 0) {
            f->mes = 1;
            f->dia = 0;
            f->anio++; }
        }
    }
}

/*
    Incrementa en un día la fecha actual de la aplicación.
*/
void siguienteDia(TFecha f){

    bool bis =(((*f).anio % 4 == 0 && (*f).anio % 100 != 0) || (*f).anio % 400 == 0);

    if (f->dia <= 27 || (f->dia <= 29 && f->mes != 2)){
        f->dia = f->dia + 1;
    }

    if(f->mes == 2){
        if (bis && f->dia == 28){ // si el año es bisiesto sumo un dia
            f->dia =  f->dia + 1;
        } else //if ((!bis && f->dia == 28) || (bis && f->dia == 29)){ // si el año no es bisiesto voy al 1 de marzo
        {    f->dia = 1;
            f->mes = 3;
        }
    }

    if(f->dia == 30 && (f->mes == 4 || f->mes == 6 || f->mes == 9 || f->mes == 11)){ //meses con 30 días
            f->dia = 1;
            f->mes = f->mes + 1;
    }

    if(f->dia == 31 && (f->mes == 1 || f->mes == 3 || f->mes == 5 || f->mes == 7 || f->mes == 8 || f->mes == 10)){ //meses con 31 días
            f->dia = 1;
            f->mes = f->mes + 1;
    }

    if(f->mes == 12 && f->dia == 31){
        f->dia = 1;
        f->mes = 1;
        f->anio = f->anio + 1;
    }
}

/*
    Compara f1 con f2. Si f1 es anterior a f2 devuelva -1. Si f1 es igual a f2 devuelve 0.
    Si f1 es mayor a f2 devuelve 1.
*/
int compararFechas(TFecha f1, TFecha f2){

    int aux;

    if(f1->anio < f2->anio){
        aux = -1;
    }
    else if(f1->anio > f2->anio){
        aux = 1;
    }
    else { //si los años son iguales
        if(f1->mes < f2->mes){
            aux = -1;
        }
        else if (f1->mes > f2->mes){
            aux = 1;
        }
        else{ // meses iguales
            if(f1->dia < f2->dia){
            aux = -1;
            }
            else if (f1->dia > f2->dia){
            aux = 1;
            }
            else{ //mismo dia, misma fecha
                aux = 0;
            }
        }
    }

    return aux;
}

/*
    Devuelve un char* que contiene la representación de la fecha en formato corto, es decir dd/mm/aaaa.
	Por ejemplo 01/01/2022.
*/

char* fechaActual(TFecha f){
    if (f != NULL){
      char* fecha = new char[15];
      sprintf(fecha, "%d/%d/%d", f->dia, f -> mes , f -> anio);

      return fecha;
    }
    else
      return NULL;
 }



/*
    Devuelve un char* que contiene la representación de la fecha en formato extendido.
	Por ejemplo para la fecha 01/01/2022 se debería imprimir '01 de enero de 2022'.
*/
char* fechaActualExtendida(TFecha f){
  if (f != NULL){
      char* f_ext = new char[100];
      switch (f->mes){
          case 1:
              sprintf(f_ext,"%d de Enero de %d" ,f->dia, f->anio);
              break;
          case 2:
              sprintf(f_ext,"%d de Febrero de %d", f->dia, f->anio);
              break;
          case 3:
              sprintf(f_ext,"%d de Marzo de %d", f->dia, f->anio);
              break;
          case 4:
              sprintf(f_ext,"%d de Abril de %d", f->dia, f->anio);
              break;
          case 5:
              sprintf(f_ext,"%d de Mayo de %d", f->dia, f->anio);
              break;
          case 6:
              sprintf(f_ext,"%d de Junio de %d", f->dia , f->anio);
              break;
          case 7:
              sprintf(f_ext,"%d de Julio de %d", f->dia, f->anio);
              break;
          case 8:
              sprintf(f_ext,"%d de Agosto de %d", f->dia, f->anio);
              break;
          case 9:
              sprintf(f_ext,"%d de Setiembre de %d", f->dia, f->anio);
              break;
          case 10:
              sprintf(f_ext,"%d de Octubre de %d", f->dia, f->anio);
              break;
          case 11:
              sprintf(f_ext,"%d de Noviembre de %d", f->dia, f->anio);
              break;
          case 12:
              sprintf(f_ext,"%d de Diciembre de %d", f->dia, f->anio);
              break;
      }
      return f_ext;
  }
  else
        return NULL;
  }
