#include "ej10.h"


int main()
{
    randomize();
    char * palabras[] = {"VIDRIO", "CASA", "ARBOL","PESCADO","BIBLIOTECA","ODONTOLOGO","CUADERNO","VESTIMENTA",
                        "BICICLETA", "FONOAUDIOLOGIA","INSTITUTO","PROGRAMACION",
                        "PERDIDA","PLASTICO","ABECEDARIO","ESTOFADO","LENTEJAS","ANTEOJOS","AZUL",
                        "FUTBOL","BESTIALIDAD","SECRETARIA"};
    char alfabeto[ABC] = {0};

    int dimSecreta;
    char * palabraSecreta = elegirPalabra(palabras, &dimSecreta);
    char * palabraParcial = setParcial(dimSecreta);

    int resultado = jugar(palabraSecreta, dimSecreta, palabraParcial, alfabeto);

    if(resultado){
        puts("Ganaste!");
    }
    else{
        printf("Perdiste, la palabra era: %s\n",palabraSecreta);
    }
    
    free(palabraParcial);
    free(palabraSecreta);
    return 0;
}

char * setParcial(int dim){
    char * resp = malloc(dim);
    for(int i = 0; i < dim; i++){
        resp[i] = '_';
    }
    resp[dim - 1] = 0;
    return resp;
}

char * elegirPalabra(char * opcionesPalabras[], int * dim){
    int idxPalabra = randInt(0,CANT_PALABRAS-1);
    *dim = 0;
    char * palabra = NULL;
    int i = 0;
    
    while(opcionesPalabras[idxPalabra][i]){
        if((*dim) % BLOQUE == 0){
            palabra = realloc(palabra, (*dim + BLOQUE + 1)*sizeof(char));
        }
        palabra[(*dim)++] = opcionesPalabras[idxPalabra][i++];
    }
    palabra[(*dim)++] = '\0';
    palabra = realloc(palabra,*dim);

    return palabra;
}

int ingresarLetra(char * letrasIngresadas){
    int letra;
    do
    {
        printf("Letras ya ingresadas: ");
        for(int i = 0; i < ABC; i++){
            if(letrasIngresadas[i] != 0){
                printf("%c ",letrasIngresadas[i]);
            }
        }

        printf("\n\nIngrese una letra que no haya ingresado: ");
        letra = toupper(getchar());
        BORRA_BUFFER;
        puts("");
    } while (!isalpha(letra) || letrasIngresadas[letra - 'A'] != 0);    
    return letra;
}

int actualizarPalabra(char * palabraParcial, int len, int letra, char * letrasIngresadas, char * palabraSec){
    int letraEncontrada = 0;
    for(int i = 0; i < len; i++){
        if(palabraSec[i] == letra && palabraParcial[i] != letra){
            palabraParcial[i] = letra;
            letraEncontrada = 1;
            letrasIngresadas[letra - 'A'] = letra;
        }
    }
    if(!letraEncontrada){
        printf("\nLa letra %c no está en la palabra.\n",letra);
        letrasIngresadas[letra - 'A'] = letra;
    }
    return letraEncontrada;
}

int jugar(char * palabraSecreta, int dim, char * palabraParcial, char letrasReps[]){
    
    INTRO_JUEGO;

    int win = 0;
    int intentosRestantes = INTENTOS;
    int update = 1;
    
    while(!win && intentosRestantes){
        
        int letr = ingresarLetra(letrasReps);
        update = actualizarPalabra(palabraParcial,dim,letr,letrasReps,palabraSecreta); //Si agregué una letra correcta, entonces no disminuyen los intentos restantes.
        INTENTOS_RESTANTES_REPORTE(update);
        win = (strcmp(palabraParcial,palabraSecreta) == 0); //Reviso si la palabra parcial es igual a la secreta.

    }

    return win;
}