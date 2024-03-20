#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define COLS 7
#define FILS 6
#define BLOQUE 5

typedef enum {DER=0, IZQ, ABA, ARR, I_AR, I_AB, D_AR, D_AB} Tdireccion;

struct posicion {
    char * palabra;
    size_t fila;
    size_t columna;
    Tdireccion direccion;
};

// NOTA: depende del orden en que realizan la busqueda, el testeo puede dar diferente
//       en esta prueba asumimos que se recorre el diccionario, y cada palabra se busca en la sopa de 
//       letras.
//.      Si en vez de hacerlo así recorren la matriz y por cada letra buscan si hay una palabra en el diccionario
//       que empiece con esa letra, tienen que cambiar el testeo para que coincida con el orden en que se encuentran.

Tdireccion traducirDirec(int dirX, int dirY){
    Tdireccion retDir = DER;
    if(dirX == -1){
        if(dirY == -1)
            retDir = I_AR;
        else if(dirY == 0)
            retDir = ARR;
        else if(dirY == 1)
            retDir = D_AR;
    }
    else if(dirX == 0){
        if(dirY == -1)
            retDir = IZQ;
        else if(dirY == 1)
            retDir = DER;
    }
    else if(dirX == 1){
        if(dirY == -1)
            retDir = I_AB;
        else if(dirY == 0)
            retDir = ABA;
        else if(dirY == 1)
            retDir = D_AB;
    }
    return retDir;
}

#define VALIDAR(i,j,x,y,w) ((i) + (w)*(x) < FILS && (i) + (w)*(x) >= 0 && (j) + (w)*(y) < COLS && (j) + (w)*(y) >= 0)

int buscarPalabra(int i, int j, char * palabra, char sopa[][COLS], Tdireccion * dir){
    int inc = 0, retValue = 0, valid;
    int x = -1, y = -1;
    // printf("Como encontré la letra %c, busco en todas las direcciones.\n\n",palabra[0]);
    for(x = -1; x < 2 && !retValue; x++){
        for(y = -1; y < 2 && !retValue; y++){
            inc = 0;
            
            if(!(x == 0 && y == 0)){
                while((!retValue) && (valid = VALIDAR(i,j,x,y,inc)) && sopa[i + inc*x][j + inc*y] == palabra[inc]){
                    
                    // printf("En la dirección (%d + %d) (%d + %d) está la letra %c\n\n",i,(x*inc),j,(y*inc),sopa[i+inc*x][j+inc*y]);
                    inc++;
                    // printf("Letra siguiente a buscar de la palabra %s: %c\n\n",palabra,palabra[inc]);
                    if(palabra[inc] == '\0')
                        retValue = 1;
                }
                if(palabra[inc] == 0)
                    retValue = 1;
            }
            
            if(palabra[inc] != '\0' || !valid){
                // printf("Uy, parece que no era por esa dirección. Entonces retValue = 0 porque no es por ahí.\n\n");
                retValue = 0;
            }
        }
    }
    // printf("Traduzco la dirección %d %d y retorno que %s\n\n",x-1,y-1,retValue?"la encontré, porque matchean todas las letras":"no la encontré, porque algo falló.");
    *dir = traducirDirec(x-1,y-1);
    return retValue;
}

void agregarPalabra(struct posicion **vec, int dim, char *palabra, Tdireccion dir, int posFil, int posCol) {
    // printf("Si necesito más espacio, lo reservo.\n\n");
    if (dim % BLOQUE == 0) {
        *vec = realloc(*vec, (dim + BLOQUE) * sizeof(struct posicion));
        // puts("Necesito más espacio, hago realloc\n");
    }
    // printf("Guardo columna: %d, fila: %d y direccion. La palabra encontrada es: %s\n\n",posCol,posFil,palabra);
    (*vec)[dim].columna = posCol;
    (*vec)[dim].fila = posFil;
    (*vec)[dim].direccion = dir;

    (*vec)[dim].palabra = malloc((strlen(palabra) + 1) * sizeof(char));

    strcpy((*vec)[dim].palabra, palabra);
}


struct posicion * resolverSopa(char * diccionario[], char sopa[][COLS]){
    Tdireccion direc = -1;
    struct posicion * retArr = NULL;
    int dim = 0;
    for(int p = 0; diccionario[p][0] != '\0'; p++){
        // printf("Comienzo a buscar la palabra: %s\n\n",diccionario[p]);
        direc = -1;
        for(int i = 0; i < FILS; i++){
            for(int j = 0; j < COLS; j++){
                if(sopa[i][j] == diccionario[p][0]){
                    // printf("Encontré la letra %c en la posición fila: %d columna: %d de la sopa\n\n",diccionario[p][0],i,j);
                    if(buscarPalabra(i,j,diccionario[p],sopa,&direc)){
                        // puts("Como la encontré, la agrego al vector de retorno\n");
                        agregarPalabra(&retArr,dim,diccionario[p],direc,i,j);
                        // printf("Como ya agregué la palabra %s, agrando la dimensión a %d\n\n",diccionario[p], dim+1);
                        dim++;
                    }
                }
            }
        }
    }
    // printf("Hago realloc después de iterar por las palabras del diccionario para no tener espacio de más\n\n");
    retArr = realloc(retArr,(dim+1)*sizeof(struct posicion));
    // printf("Pongo marca de fin al vector de retorno\n\n");
    retArr[dim].palabra = NULL; 

    return retArr;
}

void liberarMemoria(struct posicion *result) {
    int i = 0;
    for (i = 0; result[i].palabra != NULL; ++i) {
        free(result[i].palabra);
    }
    free(result);
}

int main(void) {
    char * diccionario[] = {"ARRE", "CANCION", "CAPA", "ERROR", "ORCO", "PERRO", "PERTINAZ", "REA", "RIO", ""};
    
    char sopa[FILS][COLS] =
        {{'X','X','X','O','X','X','X'},
        {'A','P','A','C','Y','Y','O'},
        {'Z','E','Z','R','Z','C','X'},
        {'E','R','R','O','R','X','X'},
        {'X','R','I','O','I','E','X'},
        {'X','O','X','X','O','X','X'}};
    
    struct posicion * res = resolverSopa(diccionario, sopa);
    // La cantidad de palabras encontradas debe ser 9
    int expected = 9;
    int count = 0;
    while ( res[count].palabra != NULL)
        printf("%s\n", res[count++].palabra);
    assert(count == expected);

    assert(strcmp(res[0].palabra,"ARRE")==0);
    assert(res[0].fila==1);
    assert(res[0].columna==2);
    assert(res[0].direccion==D_AB);

    assert(strcmp(res[3].palabra,"ORCO")==0);
    assert(res[3].fila==3);
    assert(res[3].columna==3);
    printf("%d\n", res[3].direccion);
    assert(res[3].direccion==ARR);
    
    assert(strcmp(res[4].palabra,"ORCO")==0);
    assert(res[4].fila==4);
    assert(res[4].columna==3);
    assert(res[4].direccion==D_AR);

    assert(strcmp(res[6].palabra,"REA")==0);
    assert(res[6].fila==3);
    assert(res[6].columna==2);
    assert(res[6].direccion==I_AR);

    liberarMemoria(res);

    puts("OK");
    return 0;
}


