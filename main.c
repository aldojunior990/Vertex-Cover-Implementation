#include <stdio.h>
#include <stdlib.h>
#include "vertexCover.h"

int main()
{

    GRAFO *gr = iniciar(7);
    criarAresta(gr, 1, 2);
    criarAresta(gr, 1, 3);
    criarAresta(gr, 2, 3);
    criarAresta(gr, 2, 4);
    criarAresta(gr, 2, 5);
    criarAresta(gr, 2, 6);
    imprimeGrafo(gr);
    imprimirMatriz(gr);
    soluçãoOtimaVertexCover(gr, 7);

    GRAFO *gr2 = iniciar(8);
    criarAresta(gr2, 1, 5);
    criarAresta(gr2, 2, 5);
    criarAresta(gr2, 2, 6);
    criarAresta(gr2, 3, 5);
    criarAresta(gr2, 4, 5);
    criarAresta(gr2, 4, 6);
    criarAresta(gr2, 6, 7);
    imprimeGrafo(gr2);
    imprimirMatriz(gr2);
    soluçãoOtimaVertexCover(gr2, 8);

    GRAFO *gr3 = iniciar(9);
    criarAresta(gr3, 1, 2);
    criarAresta(gr3, 1, 3);
    criarAresta(gr3, 1, 4);
    criarAresta(gr3, 1, 5);
    criarAresta(gr3, 2, 4);
    criarAresta(gr3, 3, 4);
    criarAresta(gr3, 3, 6);
    criarAresta(gr3, 3, 7);
    criarAresta(gr3, 4, 7);
    criarAresta(gr3, 5, 6);
    criarAresta(gr3, 5, 8);
    criarAresta(gr3, 6, 7);
    criarAresta(gr3, 6, 8);
    criarAresta(gr3, 7, 8);
    imprimeGrafo(gr3);
    imprimirMatriz(gr3);

    soluçãoOtimaVertexCover(gr3, 8);

    GRAFO *gr4 = iniciar(5);
    criarAresta(gr4, 1, 2);
    criarAresta(gr4, 1, 4);
    criarAresta(gr4, 2, 4);
    criarAresta(gr4, 2, 3);
    imprimeGrafo(gr4);
    imprimirMatriz(gr4);
    soluçãoOtimaVertexCover(gr4, 5);

    GRAFO *gr5 = iniciar(5);
    criarAresta(gr5, 1, 2);
    criarAresta(gr5, 1, 4);
    criarAresta(gr5, 2, 4);
    criarAresta(gr5, 2, 3);
    imprimeGrafo(gr5);
    imprimirMatriz(gr5);
    int *solução5 = (int *)malloc(2 * sizeof(int));
    solução5[0] = 2;
    solução5[1] = 1;

    ehVertexCover(gr5, solução5);
}