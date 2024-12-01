#include <stdio.h>
#include <math.h>

// Función para calcular la media (promedio) de un arreglo de enteros
double calcular_media(int numeros[], int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += numeros[i];
    }
    return (double)suma / n;
}

// Función para calcular la desviación estándar de un arreglo de enteros
double calcular_desviacion_estandar(unsigned char arreglo[], int n) {
    int numeros[n * 2]; // Doble de espacio para almacenar cada número en el arreglo
    
    // Extraer los números del arreglo de caracteres
    for (int i = 0; i < n; i++) {
        numeros[i * 2] = (arreglo[i] >> 4) & 0x0F; // Obtener el número de los 4 bits superiores
        numeros[i * 2 + 1] = arreglo[i] & 0x0F; // Obtener el número de los 4 bits inferiores
    }
    
    // Calcular la media (promedio)
    double media = calcular_media(numeros, n * 2);
    
    // Calcular la suma de los cuadrados de las diferencias respecto a la media
    double suma_cuadrados = 0;
    for (int i = 0; i < n * 2; i++) {
        suma_cuadrados += pow(numeros[i] - media, 2);
    }
    
    // Calcular la varianza y la desviación estándar
    double varianza = suma_cuadrados / (n * 2);
    double desviacion_estandar = sqrt(varianza);
    
    return desviacion_estandar;
}

int main() {
    unsigned char arreglo[] = { 0x37, 0xF2, 0x03, 0x4A, 0xFF };
    int n = sizeof(arreglo) / sizeof(arreglo[0]);
    
    double desviacion = calcular_desviacion_estandar(arreglo, n);
    
    printf("La desviación estándar es: %.2lf\n", desviacion);
    
    return 0;
}