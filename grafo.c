#include "grafo.h"

void criarAresta(GRAFO *g, int v, int u)
{
    if (g->adj[v][u] == 0)
    {
        g->adj[v][u] = 1;
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
        g->adj[i] = (int *)malloc(n * sizeof(int));
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

void imprimeGrafo(GRAFO *g)
{
    for (int i = 0; i < g->nVertices; i++)
    {
        printf("%2d:", i);
        for (int j = 0; j < g->nVertices; ++j)
        {
            if (g->adj[i][j] == 1)
            {
                printf(" %2d", j);
            }
        }

        printf("\n");
    }
}
