#include <stdio.h>
#include <stdlib.h>
#define RESET   "\x1b[0m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
struct Fraccion {
    int numerador, denominador;
};

struct CalculadoraFracciones {
    struct Fraccion fraccion1;
    struct Fraccion fraccion2;
};

struct Fraccion sumar(struct Fraccion fraccion1, struct Fraccion fraccion2);
struct Fraccion restar(struct Fraccion fraccion1, struct Fraccion fraccion2);
struct Fraccion multiplicar(struct Fraccion fraccion1, struct Fraccion fraccion2);
struct Fraccion dividir(struct Fraccion fraccion1, struct Fraccion fraccion2);
struct Fraccion simplificar(struct Fraccion fraccion);
void simplificarPorReferencia(struct Fraccion *fraccion);
float convertirPuntoFlotante(struct Fraccion fraccion);
struct Fraccion ingresarFraccion(char *mensaje);
char elegirOperacion();
struct Fraccion calcular(char operacion, struct CalculadoraFracciones calculadora);
void presentarFraccion(struct Fraccion fraccion);
void presentarResultado(char operacion, struct CalculadoraFracciones calculadora, struct Fraccion rta);

int main(){
    system("@cls||clear");
    char opcion = 'c';
    do
    {
        struct Fraccion fraccion1 = ingresarFraccion(RED"Ingrese fraccion 1"RESET );
        struct Fraccion fraccion2 = ingresarFraccion(RED"Ingrese fraccion 2"RESET );
        struct CalculadoraFracciones calculadora = {fraccion1, fraccion2};
        char opcion = elegirOperacion();
        struct Fraccion rta = calcular(opcion, calculadora);
        presentarResultado(opcion, calculadora, rta);
        printf("Presione 'c' para realizar otra multiplicacion o cualquier otra tecla para salir: ");
        scanf(" %c", &opcion);
        getchar();
    } while (opcion == 'c' || opcion == 'C');
    
    return 0;
}

void presentarResultado(char operacion, struct CalculadoraFracciones calculadora, struct Fraccion rta) {
    printf("\n");
    presentarFraccion(calculadora.fraccion1);
    printf( YELLOW" %c "RESET , operacion);
    presentarFraccion(calculadora.fraccion2);
    printf( YELLOW" = "RESET );
    presentarFraccion(rta);
    printf( YELLOW" ===> "RESET );
    printf("%.2f \n", convertirPuntoFlotante(rta));
}

struct Fraccion calcular(char operacion, struct CalculadoraFracciones calculadora) {
    struct Fraccion rta;
    switch (operacion) {
        case '+':
            rta = sumar(calculadora.fraccion1, calculadora.fraccion2);
            break;
        case '-':
            rta = restar(calculadora.fraccion1, calculadora.fraccion2);
            break;
        case '*':
            rta = multiplicar(calculadora.fraccion1, calculadora.fraccion2);
            break;
        case '/':
            rta = dividir(calculadora.fraccion1, calculadora.fraccion2);
            break;
        default:
            rta.numerador = 0;
            rta.denominador = 0;
            break;
    }
    return rta;
}

struct Fraccion ingresarFraccion(char *mensaje) {
    struct Fraccion fraccion;
    printf("%s:\n", mensaje);
    printf(BLUE "Numerador: "RESET );
    scanf("%d", &fraccion.numerador);
    getchar();
    printf(BLUE "Denominador: "RESET );
    scanf("%d", &fraccion.denominador);
    getchar();
    return fraccion;
}

struct Fraccion simplificar(struct Fraccion fraccion) {
    if (fraccion.denominador == 0) {
        fraccion.numerador = 0;
        return fraccion;
    }

    int menor = fraccion.numerador;
    if (menor > fraccion.denominador) {
        menor = fraccion.denominador;
    }

    for (int i = menor; i > 1; i--) {
        if (fraccion.numerador % i == 0 && fraccion.denominador % i == 0) {
            fraccion.numerador = fraccion.numerador / i;
            fraccion.denominador = fraccion.denominador / i;
            break;
        }
    }
    return fraccion;
}

void simplificarPorReferencia(struct Fraccion *fraccion) {
    struct Fraccion simplificada = simplificar(*fraccion);
    fraccion->numerador = simplificada.numerador;
    fraccion->denominador = simplificada.denominador;
}

float convertirPuntoFlotante(struct Fraccion fraccion) {
    return (float)fraccion.numerador / (float)fraccion.denominador;
}

void presentarFraccion(struct Fraccion fraccion) {
    printf("%d / %d", fraccion.numerador, fraccion.denominador);
}

struct Fraccion sumar(struct Fraccion fraccion1, struct Fraccion fraccion2) {
    struct Fraccion resultado;
    resultado.numerador = (fraccion1.numerador * fraccion2.denominador) + (fraccion2.numerador * fraccion1.denominador);
    resultado.denominador = fraccion1.denominador * fraccion2.denominador;
    simplificarPorReferencia(&resultado);
    return resultado;
}

struct Fraccion restar(struct Fraccion fraccion1, struct Fraccion fraccion2) {
    struct Fraccion resultado;
    resultado.numerador = (fraccion1.numerador * fraccion2.denominador) - (fraccion2.numerador * fraccion1.denominador);
    resultado.denominador = fraccion1.denominador * fraccion2.denominador;
    simplificarPorReferencia(&resultado);
    return resultado;
}

struct Fraccion multiplicar(struct Fraccion fraccion1, struct Fraccion fraccion2) {
    struct Fraccion resultado;
    resultado.numerador = fraccion1.numerador * fraccion2.numerador;
    resultado.denominador = fraccion1.denominador * fraccion2.denominador;
    simplificarPorReferencia(&resultado);
    return resultado;
}

struct Fraccion dividir(struct Fraccion fraccion1, struct Fraccion fraccion2) {
    struct Fraccion resultado;
    if (fraccion2.numerador != 0) {
        resultado.numerador = fraccion1.numerador * fraccion2.denominador;
        resultado.denominador = fraccion1.denominador * fraccion2.numerador;
        simplificarPorReferencia(&resultado);
    } else {
        printf(BLUE "Error: Division es 0\n"RESET );
        resultado.numerador = 0;
        resultado.denominador = 1;  
    }
    return resultado;
}
char elegirOperacion() {
    char opcion;
    printf(BLUE "Ingrese la operacion (+, -, *, /): "RESET );
    scanf(" %c", &opcion);  
    return opcion;
}
