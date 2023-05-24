#include <stdio.h>
#include <stdlib.h>

typedef struct grafo
{
    int nVertices;
    int nArestas;
    int **adj;
} GRAFO;

void criarAresta(GRAFO *g, int v, int u)
{
    if (g->adj[v][u] == 0)
    {
        g->adj[v][u] = 1;
        g->adj[u][v] = 1;
        g->nArestas = g->nArestas + 1;
    }
}

void removeAresta(GRAFO *g, int v, int u)
{
    if (g->adj[v][u] == 1)
    {
        g->adj[v][u] = 0;
        g->nArestas = g->nArestas - 1;
    }
}

GRAFO *iniciar(int n)
{

    GRAFO *g = (GRAFO *)malloc(sizeof(GRAFO));
    g->nArestas = 0;
    g->nVertices = n;
    g->adj = (int **)malloc(n * sizeof(int *));

    // Inicica todos os indices da MATRIZ com zero
    for (int i = 0; i < n; i++)
    {
        g->adj[i] = (int *)malloc(n * sizeof(int *));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            g->adj[i][j] = 0;
        }
    }

    return g;
}

int grauV(GRAFO *g, int vertice)
{
    int grau = 0;
    for (int j = 0; j < g->nVertices; j++)
    {
        grau = grau + g->adj[vertice][j];
    }
    return grau;
}

void imprimeGrafo(GRAFO *g)
{
    for (int i = 0; i < g->nVertices; i++)
    {
        int grau = grauV(g, i);
        printf("%2d: grau(%d)", i, grau);
        for (int j = 0; j < g->nVertices; ++j)
        {
            if (g->adj[i][j] == 1)
            {

                printf("%2d ", j);
            }
        }

        printf("\n");
    }
}

void imprimirMatriz(GRAFO *g)
{
    for (int i = 0; i < g->nVertices; i++)
    {
        for (int j = 0; j < g->nVertices; j++)
        {
            printf(" %d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

int *soluçãoOtimaVertexCover(GRAFO *g, int limit)
{
    int *S;
    int i = 0;
    while (i < g->nVertices)
    {

        while ()
        {
            /* code */
        }
    }

    // +++++++++++++++++++++++++++++++++Willyan+++++++++++++++++++++++++++++++++

    // +++++++++++++++++++++++++++++++++Willyan+++++++++++++++++++++++++++++++++
}

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

    // soluçãoOtimaVertexCover(gr, 2);
}