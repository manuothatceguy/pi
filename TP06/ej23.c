#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LENFECHA 10
#define TRUE 1
#define FALSE 0

typedef unsigned int uInt ;


/* Recibe un string con el formato dd/mm/yyyy y retorna por parámetro el día, mes
** y año de la misma. En caso de que el formato sea inválido
** o la fecha incorrecta, retorna FALSE y no altera los parámetros
*/
int valorFecha( const char * fecha, uInt *dia, uInt *mes, uInt * anio);


int main(void) {
  unsigned int d=100, m=200, a=300;
  int res;
  res = valorFecha("", &d, &m, &a);
  assert(res==0);
  assert(d==100);
  assert(m==200);
  assert(a==300);

  res = valorFecha("29/02/1999", &d, &m, &a);
  assert(res==0);
  assert(d==100);
  assert(m==200);
  assert(a==300);

  res = valorFecha("30/14/2020", &d, &m, &a);
  assert(res==0);
  assert(d==100);
  assert(m==200);
  assert(a==300);

  res = valorFecha("12/12/", &d, &m, &a);
  assert(res==0);
  assert(d==100);
  assert(m==200);
  assert(a==300);

  res = valorFecha("1/1/2000", &d, &m, &a);
  assert(res==0);
  assert(d==100);
  assert(m==200);
  assert(a==300);

  res = valorFecha("12/01/2000", &d, &m, &a);
  assert(res==1);
  assert(d==12);
  assert(m==1);
  assert(a==2000);

  res = valorFecha("29/02/1900", &d, &m, &a);
  assert(res==0);
  assert(d==12);
  assert(m==1);
  assert(a==2000);

  res = valorFecha("29/02/2000", &d, &m, &a);
  assert(res==1);
  assert(d==29);
  assert(m==2);
  assert(a==2000);

  printf("OK\n");
  return 0;
}

int esBisiesto(int anio){
    return (((anio%4 == 0) && (anio % 100 != 0)) || anio%400 == 0)?1:0;
}

int validarFormato(const char * fecha){
    int ok = 1;
    if(strlen(fecha) == LENFECHA && fecha[2] == '/' && fecha[5] == '/'){
        for (char i = 0; i < LENFECHA && ok; i++)
        {
            if(i != 2 && i != 5){
                ok = isdigit(fecha[i]);
            }
        }
    }
    return ok;
}

void getDate(const char * fecha, uInt *dia, uInt *mes, uInt *anio){
    *dia = atoi(fecha);
    *mes = atoi(fecha + 3);
    *anio = atoi(fecha + 6);
}

int validarFecha(uInt dia, uInt mes, uInt anio){
    int daytab[2][13] = {
        {0,31,28,31,30,31,30,31,31,30,31,30,31},
        {0,31,29,31,30,31,30,31,31,30,31,30,31}
    };
    return ((mes > 0 && mes < 13)) && (dia <= daytab[esBisiesto(anio)][mes]) && (dia > 0) && (anio > 0);
}

int valorFecha( const char * fecha, uInt *dia, uInt *mes, uInt * anio){
    uInt d,m,a;
    int isValidF, isDate;
    if((isValidF = validarFormato(fecha))){
        getDate(fecha, &d, &m, &a);
    }
    if((isDate = isValidF?validarFecha(d,m,a):0)){
        * dia = d;
        * mes = m;
        * anio = a;
    }
    return isDate?1:0;
}