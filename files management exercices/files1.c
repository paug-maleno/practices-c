#include <stdio.h>
#include <string.h>

void escribir_entrada(FILE *f, const char *texto){
    int i = 0;
    while(texto[i] != '\0') {
        fputc(texto[i], f);
        i++;
    }
    fputc('\n', f);
}

void leer_fichero(FILE *f) {
    int c;
    while ((c = fgetc(f)) != EOF) {// c keep getting chars until eof 
        putchar(c);
    }
}

int contar_lineas(FILE *f){
    int count = 0;
    int c;
    while ((c = fgetc(f)) != EOF){
        if (c=='\n'){
            count++;
        }
    }
    return count;
}

void copiar_fichero(FILE *origen, FILE *destino) {
    int c;
    while((c = fgetc(origen)) != EOF){
        fputc(c, destino);
    }
}

int contar_caracteres(FILE *f) {
    int c;
    int count =0;
    while((c = fgetc(f)) != EOF){
        count++;
    }
    return count;
}

int contar_palabras(FILE *f) {
    int c;
    int count = 0;
    int palabra = 0; 
    while((c = fgetc(f)) != EOF){
        if (c == ' ' || c == '\n') {
            palabra =0;
        } else {
            if (palabra == 0) count ++;
            palabra=1;
        }
    }
    return count;
}

int buscar_caracter (FILE *f, char car) {
    int c;
    int count = 0;
    while((c = fgetc(f)) != EOF){
        if (c == car) count ++;
    }
    return count;
}

void añadir_entrada(FILE *f, const char *texto) {
    int i = 0;
    while(texto[i] != '\0'){
        fputc(texto[i], f);
        i++;
    }
    fputc('\n', f);

}

int main() {
    FILE *f =fopen("diario.txt", "w");
    if(f == NULL) return 1;

    escribir_entrada(f, "hola que tal");
    escribir_entrada(f, "buenas tardes");
    fclose(f);

    FILE *f2 =fopen("diario.txt", "r");
    if(f2 == NULL) return 1;

    leer_fichero(f2);
    fclose(f2);

    FILE *f3 = fopen("diario.txt", "r");
    if (f3 == NULL) return 1;
    int lineas = contar_lineas(f3);
    printf("el numero de lineas es %d\n", lineas);
    fclose(f3);

    FILE *orig=fopen("diario.txt", "r");
    FILE *copia=fopen("copia.txt", "w");
    copiar_fichero(orig, copia);
    fclose(orig);
    fclose(copia);

    FILE *f4 = fopen("diario.txt", "r");
    if (f4 == NULL) return 1;
    int carac = contar_caracteres(f4);
    printf("el numero de caracteres es %d\n", carac);
    fclose(f4);

    FILE *f5 = fopen("diario.txt", "r");
    if (f5 == NULL) return 1;
    int palabras = contar_palabras(f5);
    printf("el numero de palabras es %d\n", palabras);
    fclose(f5);

    FILE *f6 = fopen("diario.txt", "r");
    if(f6 == NULL) return 1;
    int repes = buscar_caracter(f6, 'a');
    printf("el numero de caracteres repes es %d\n", repes);
    fclose(f6);
     
    
    FILE *f7 =fopen("diario.txt", "a");
    if(f7 == NULL) return 1;

    añadir_entrada(f7, "nueva linea");
    
    fclose(f7);


    return 0;
}