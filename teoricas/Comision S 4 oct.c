#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define PALOS 4
#define MAX 15

// Lee hasta el \n pero deja en el vector hasta MAX caracteres (y el cero)
// Es responsabilidad del usuario haber reservado al menos max+1 bytes
int Getline(char v[], size_t max) {
    int c;
    int i=0;
    while ( (c=getchar()) != '\n' && c != EOF) {
        if ( i < max) {
            v[i++] = c;
        }
    }
    v[i]=0;
    return i;
}

// Version de getline que lee TODA la linea, sin el \n
char * getline() {

}

int main(void) {
    int dim;
    do {
        dim = getint("Jugadores iniciales");
    } while (dim < 1);

    char * *palos = malloc(dim * sizeof(char *));
    // Vector auxiliar donde leer los nombres
    char aux[MAX+1];

    /* Version inicial: 4 strings "de entrada")
    palos[0] = malloc(5);
    strcpy(palos[0], "Copa");
    // palos[0][0] = 'C';  que es lo mismo que *palos[0] = 'C';
    palos[1] = malloc(6);
    strcpy(palos[1], "Basto");
    palos[2] = malloc(4);
    strcpy(palos[2], "Oro");
    palos[3] = malloc(7);
    strcpy(palos[3], "Espada");

    // Los imprimimos en orden
    for(int i=0; i<PALOS; i++) {
        puts(palos[i]);
    }

    // Quiero que el último palo sea "Espadita"
    palos[3] = realloc(palos[3], strlen("Espadita")+1);
    strcpy(palos[3], "Espadita");
    puts("");
    for(int i=0; i<PALOS; i++) {
        puts(palos[i]);
    }
    */

    // Para cada palo:
    //    Leo hasta MAX chars en aux
    //    Reservo strlen(aux)+1
    //    Copio
    for(int i=0; i<dim; i++) {
        palos[i] = malloc(Getline(aux, MAX) + 1);
        strcpy(palos[i], aux);
    }
    for(int i=0; i<dim; i++) {
        puts(palos[i]);
    }

    palos[3] = realloc(palos[3], strlen(palos[3]) + 15);
    strcat(palos[3], " el mas grande");

    dim++;
    // Agregamos uno
    palos = realloc(palos, dim * sizeof(*palos));
    palos[dim-1] = malloc(10);
    strcpy(palos[dim-1], "Fin");

    for(int i=0; i<dim; i++) {
        puts(palos[i]);
    }
    // Ahora el usuario indica cual es cada palo
    for(int i=0; i<dim; i++) {
        free(palos[i]);
    }

    free(palos);

    return 0;
}
