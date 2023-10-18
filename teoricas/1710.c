unsigned long factorial(unsigned long n){
    if(n == 0)
        return 1;
    return n*factorial(n-1);
}

/*Potencia, contempla que no esté el caso 0 ^ 0. FUNCIÓN RECURSIVA NO VALIDA PARÁMETROS, NO SE AGREGAN CASOS DE OPTIMIZACIÓN!*/ 
int potencia(int base,unsigned int exp){
    /*
    Ahorra solo un caso. 
    if(base == 0)
        return 0;
    
    Ahorra solo con el caso de base == 1, pero penalizo a todo el resto.
    if(base == 1) //Ahorra 1²⁰ en una sola resp
        return 1;

    */
    if(exp == 0)
        return 1;

    return base*potencia(base,exp-1);
}

//Puedo usar una función wrapper para optimizar y validar
int potenciaWrapper(int base, int exp){
    if(base == 1 || exp == 0)
        return 1;
    else if(base == 0 && exp == 0)
        return -1;
    return potencia(base,exp);
}

//Dar un número en la sucesión de fibonacci, claro pero INEFICIENTE!!!
unsigned int
fibonacci(n){
    if(n <= 1)
        return n;
    return fibonacci(n-1)+fibonacci(n-1);
}

// EJERCICIOS

/*MCD con algoritmo de euclides*/
int mcd(int n1, int n2){
    if(n2 == 0)
        return n1;
    return mcd(n2,n1 % n2);
}