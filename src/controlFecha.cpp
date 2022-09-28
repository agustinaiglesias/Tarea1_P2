/* 5463192 */
/*
  Módulo de definición de 'TControlFecha'.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#include "../include/controlFecha.h"
#include "../include/fecha.h"

// Representación de 'TControlFecha'.
// Se debe definir en controlFecha.cpp.
// struct _rep_controlFecha;
// Declaración del tipo 'TControlFecha'
struct _rep_controlFecha{
  TFecha fecha;
};

/*
  Devuelve un TControlFecha vacío (sin fecha definida).
 */
TControlFecha crearControlFecha(){
  TControlFecha controlFecha = new _rep_controlFecha;
  controlFecha -> fecha = NULL;
  return controlFecha; }

/*
  Libera la memoria asignada a 'f'.
*/
void liberarControlFecha(TControlFecha f){
  if(f!= NULL){
    liberarFecha(f->fecha);
    delete f;
    f = NULL;
  }
}

/*
    Define la fecha actual de la aplicación. Si ya hay una fecha definida, la vuelve a redefinir.
	Ayuda: Tener cuidado con la memoria de la fecha anterior en caso de que se esté redefiniendo.
*/
void definirFecha(TControlFecha f, nat dia, nat mes, nat anio){

    if (f -> fecha == NULL){
      f -> fecha = crearFecha(dia, mes, anio);
    }
    else{
      TControlFecha aux = new _rep_controlFecha;
      aux -> fecha = f-> fecha;
      f -> fecha = crearFecha(dia, mes, anio);
      liberarFecha(aux -> fecha);
      delete aux;
      aux = NULL;
    }
}


/*
    Incrementa en cantDias la fecha actual de la aplicación y luego imprime el texto "Se incrementó la fecha.\n".
    Si la fecha no está definida entonces imprime el mensaje "La fecha del sistema no se ha definido.\n".
*/
void aumentarFechaControl(TControlFecha f, nat cantDias){
  if (f != NULL && f -> fecha != NULL){
    aumentarFecha(f -> fecha, cantDias);
    printf("Se incrementó la fecha.\n");
  }
  else{
    printf("La fecha del sistema no se ha definido.\n");
  }
}

/*
    Incrementa en un día la fecha actual de la aplicación y luego imprime el texto "Se aumentó un día.\n".
    Si la fecha no está definida entonces imprime el mensaje "La fecha del sistema no se ha definido.\n".
*/
void siguienteDiaControl(TControlFecha f){
  if (f != NULL && f -> fecha != NULL){
    siguienteDia(f -> fecha);
    printf("Se aumentó un día.\n");
  }
  else{
    printf("La fecha del sistema no se ha definido.\n");
  }
}

/*
	Compara f1 con f2.
	Si f2 es posterior a f1 devuelve "Posterior a actual.\n".
	Si f2 es igual a f1 devuelve "Fechas iguales.\n".
    Si f2 es mayor a f1 devuelve "Anterior a actual.\n".
	Si la fecha no está definida entonces imprime el mensaje "La fecha del sistema no se ha definido.\n".
*/
void compararConActualControl(TControlFecha f1, TControlFecha f2){
  if (f1 == NULL || f2 == NULL){
    printf("La fecha del sistema no se ha definido.\n");
  }
  else if (f2 -> fecha != NULL && f1 -> fecha != NULL){
    int aux = compararFechas(f1 -> fecha, f2 -> fecha);
    if(aux == -1) {
      printf("Posterior a actual.\n");
    }
    else if( aux == 0){
      printf("Fechas iguales.\n");
    }
    else{
      printf("Anterior a actual.\n");
    }
  }
}

/*
    Imprime la fecha actual en formato corto (definido en el módulo fecha).
    Si la fecha no está definida entonces imprime el mensaje "La fecha del sistema no se ha definido.\n".
*/
void fechaActualControl(TControlFecha f){
  if (f -> fecha != NULL){
    //if (f != NULL){
    char * prueba = fechaActual(f -> fecha);
     printf("La fecha actual es %s.\n", prueba);
     delete[] prueba;
     prueba = NULL;
  }
  else{
    printf("La fecha del sistema no se ha definido.\n");
  }
}

/*
    Imprime la fecha actual en formato corto (definido en el módulo fecha).
    Si la fecha no está definida entonces imprime el mensaje "La fecha del sistema no se ha definido.\n".
*/
void fechaActualExtendidaControl(TControlFecha f){
  if (f -> fecha != NULL){
    char* f_ext = fechaActualExtendida(f -> fecha);
    printf("La fecha actual es %s.\n", f_ext);
    delete[] f_ext;
    f_ext = NULL;
  }
  else{
    printf("La fecha del sistema no se ha definido.\n");
  }
}
