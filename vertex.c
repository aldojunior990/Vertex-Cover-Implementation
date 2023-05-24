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
        g->adj[u][v] = 0;
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
    printf("\n   ");
    for (int i = 0; i < g->nVertices; i++)
        printf(" %d ", i);
    printf("\n");
    for (int i = 0; i < g->nVertices; i++)
    {
        printf(" %d ", i);
        for (int j = 0; j < g->nVertices; j++)
        {
            printf(" %d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

int *soluçãoOtimaVertexCover(GRAFO *g, int limit)
{
    GRAFO *aux = g;
    int *S = (int *)malloc(limit * sizeof(int));
    int maiorG = 0;
    int grauAtual;
    int K = 0;

    // Zera todas posições de S
    for (int i = 0; i < limit; i++)
        S[i] = 0;

    while (aux->nArestas > 0)
    {
        // encontra o vértice de maior grau
        for (int i = 0, max = 0; i < aux->nVertices; i++)
        {
            grauAtual = grauV(g, i);
            if (grauAtual > max)
            {
                maiorG = i;
                max = grauAtual;
            }
        }
        // adiciona o vértice de maior grau em S
        S[K++] = maiorG;
        // remove o maior vértice do grafo
        for (int i = 0; i < aux->nVertices; i++)
        {
            if (aux->adj[maiorG][i] == 1)
                removeAresta(aux, maiorG, i);
        }
    }

    printf("\nS de B' = ");
    for (int i = 0; i < limit; i++)
        printf(" %d ", S[i]);
    printf("\n\n");

    return S;
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
}