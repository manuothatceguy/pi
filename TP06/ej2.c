/* Ejercicio 10
 	Escribir un programa que ofrezca un menú con las siguientes opciones:
Simplificar una fracción
Sumar dos fracciones
Terminar la ejecución

	   Si se elige la primera opción se le solicitará numerador y denominador de la fracción y se imprimirá la fracción simplificada (algunos de ellos podrían ser negativos). Si se opta por la segunda, se le solicitará dos fracciones y se imprimirá la suma de las mismas, también simplificada. Obviamente con la tercera opción finaliza la ejecución del mismo. Escribir una función para cada item del menú. (No más de 20 líneas para main y no más de 10 líneas para las funciones del menú).
	Pista: Escribir y usar la función DivisorComunMaximo.
*/
#include <assert.h>
#include <stdio.h>
#include <math.h>

// Si bien es mejor usar punteros, por ahora usaremos un vector v donde v[0] sea el numerador y v[1] el denominador
typedef int Fraccion[2];
#define NUM(f) f[0]
#define DEN(f) f[1]

/* Simplificaciรณn de la fraccion  */
void simplFrac(Fraccion frac);

/* Calcula la suma de dos fracciones representadas por frac1, frac2 
 * Deja el resultado en frac3 
 */
void sumarFrac(const Fraccion frac1, const Fraccion frac2, Fraccion frac3);


int main(void) {
    
    Fraccion f1, f2, fSum;

    printf("SIMPLIFICAR\n");
    NUM(f1) = 10; DEN(f1) = 15;
    simplFrac(f1);
    assert(NUM(f1)==2 && DEN(f1)==3);
    simplFrac(f1);
    assert(NUM(f1)==2 && DEN(f1)==3);

    NUM(f1) = 150; DEN(f1) = 15;
    simplFrac(f1);
    assert(NUM(f1)==10 && DEN(f1)==1);
    simplFrac(f1);
    assert(NUM(f1)==10 && DEN(f1)==1);
    
    NUM(f1) = 1; DEN(f1) = 10;
    simplFrac(f1);
    assert(NUM(f1)==1 && DEN(f1)==10);
    
    NUM(f1) = 12*5; DEN(f1) = 36*7;
    simplFrac(f1);
    assert(NUM(f1)==5 && DEN(f1)==21);
    NUM(f1) = 0; DEN(f1) = 36;
    simplFrac(f1);
    assert(NUM(f1)==0 && DEN(f1)==1);

    printf("SUMAR\n");
  
    NUM(f1) = 150; DEN(f1) = 15;
    NUM(f2) = 15;  DEN(f2) = 5;
    sumarFrac(f1, f2, fSum);
    assert(NUM(fSum)==13 && DEN(fSum)==1);
    assert(NUM(f1)==150 && DEN(f1)==15);

    NUM(f2) = 7;  DEN(f2) = 4;
    sumarFrac(f1, f2, fSum);
    assert(NUM(fSum)==47 && DEN(fSum)==4);

    return 0;
}


int dcm(int x, int y){
    int divcm = 1;
    for (int i = 2; i <= (x>y?y:x); i++){
        if((x%i == 0)&&(y%i == 0))
            divcm *= i;}
    return divcm;   
}
void simpFrac(int frac[]){
    int divcm = dcm(frac[0],frac[1]);
    frac[0] /= divcm;
    frac[1] /= divcm;
}

void sumaFracciones(int frac[]){
    int newDen = (frac[1])*(frac[3]);
    int newNum = (frac[0]*frac[3]) + (frac[2]*frac[1]);
    frac [2] = 0; frac[3] = 0;
    frac[0] = newNum;
    frac[1] = newDen;
    simpFrac(frac);
}
void printFrac(int num, int den){
    printf("%d/%d",num,den);
}
int menu(){
    int opt = 0;
    puts("Menu");
    printf("\n(1) - Simplificar una fracción");
    printf("\n(2) - Sumar fracciones");
    printf("\n(3) - Terminar con el programa\n");
    while ((opt < 1) || (opt > 3)){
        opt = getint("Elija una opción: ");
    }
    return opt;
}
