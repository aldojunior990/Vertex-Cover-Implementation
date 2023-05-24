#include <stdlib.h>
#include <stdio.h>

typedef struct grafo
{
    int nVertices;
    int nArestas;
    int **adj;
} GRAFO;

void criarAresta(GRAFO *g, int v, int u);
void removeAresta(GRAFO *g, int v, int u);
GRAFO *iniciar(int n);
void imprimeGrafo(GRAFO *g);