#include <stdio.h>
#include <math.h>

float calcularDistancia(float* p1, float* p2);
float calcularAreaTriangulo(float lado1, float lado2, float lado3);
float calcularVolumenPiramide(float baseArea, float altura);
float calcularAreaSuperficial(float* lados, float altura);

int main() {
    float puntos[4][3] = {{0, 0, 3}, {3, 0, 0}, {0, 0, 0}, {1, 7, 1}};

    // Calcular distancias
    float l1 = calcularDistancia(puntos[0], puntos[1]);
    float l2 = calcularDistancia(puntos[0], puntos[2]);
    float l3 = calcularDistancia(puntos[0], puntos[3]);
    float l4 = calcularDistancia(puntos[1], puntos[2]);
    float l5 = calcularDistancia(puntos[1], puntos[3]);
    float l6 = calcularDistancia(puntos[2], puntos[3]);

    float perimetro = l1 + l2 + l4;
    float areaBase = calcularAreaTriangulo(l1, l2, l4);

    float altura = puntos[0][2] - puntos[3][2];
    float volumen = calcularVolumenPiramide(areaBase, altura);


    float lados[6] = {l1, l2, l3, l4, l5, l6};
    float areaSuperficial = calcularAreaSuperficial(lados, altura);

    printf("Perímetro del triángulo de la base: %.2f\n", perimetro);
    printf("Área de la base del triángulo: %.2f\n", areaBase);
    printf("Altura de la pirámide: %.2f\n", altura);
    printf("Volumen de la pirámide: %.2f\n", volumen);
    printf("Área superficial de la pirámide: %.2f\n", areaSuperficial);

    return 0;
}

float calcularDistancia(float* p1, float* p2) {
    float dist = sqrt(pow(p2[0] - p1[0], 2) + pow(p2[1] - p1[1], 2) + pow(p2[2] - p1[2], 2));
    return dist;
}

float calcularAreaTriangulo(float lado1, float lado2, float lado3) {
    float s = (lado1 + lado2 + lado3) / 2;
    float area = sqrt(s * (s - lado1) * (s - lado2) * (s - lado3));
    return area;
}

float calcularVolumenPiramide(float baseArea, float altura) {
    float volumen = (baseArea * altura) / 3;
    return volumen;
}

float calcularAreaSuperficial(float* lados, float altura) {
    float areaBase = calcularAreaTriangulo(lados[0], lados[1], lados[3]);
    float areaLateral = (lados[0] * altura + lados[1] * altura + lados[3] * altura) / 2;
    float areaSuperficial = areaBase + areaLateral;
    return areaSuperficial;
}
