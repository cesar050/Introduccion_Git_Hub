/**
 * @file multiplicacion_en_sumas.c
 * @author Grupo N°3 
 * @brief  Multiplicar mediante sumas y hacer del uso de subprogramas 
 * @version 0.1
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>
void ingresar_valores_de_la_multiplicacion(int *multiplicando,int *multiplicador);
int multiplicacion_por_sumas(int multipliacodor,int multiplicando);
void mostrar_resultado(int multiplicando,int multiplicador, int resultado,char opcion);
int main(){
    char opcion  = 'c';
    do{
    system("@cls||clear");
    int multiplicando, multiplicador,resultado;
    ingresar_valores_de_la_multiplicacion(&multiplicando,&multiplicador);
    resultado = multiplicacion_por_sumas(multiplicando,multiplicador); 
    printf("El resultado de la multiplicacion de %d por %d es: %d\n",multiplicando,multiplicador,resultado);
    printf("Presione 'c' para realizar otra multiplicacion o cualquier otra tecla para salir: ");
    scanf(" %c", &opcion);
    getchar();
    }while (opcion == 'c' || opcion == 'C');
    return 0;
}
void ingresar_valores_de_la_multiplicacion(int *multiplicando,int *multiplicador){
    printf("------Bienvenido a su calculadora de multiplicaciones-------\n");
    printf("Ingrese el multiplicando de la multiplicacion a realizar:\n");
    scanf("%d",multiplicando);
    getchar();
    printf("Ingrese el multiplicador de la multipliacion a realizar:\n");
    scanf("%d",multiplicador);
    getchar();
}
int multiplicacion_por_sumas(int multiplicador,int multiplicando){
    int factor = 0;
    int signo_multiplicador = 1;
    if (multiplicador < 0){
        signo_multiplicador = -1;
        multiplicador = -multiplicador;
    }
    for (int i = 0; i < multiplicador; i++){
        factor += multiplicando * signo_multiplicador;
    }
    return factor;
}
