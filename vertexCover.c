#include <stdio.h>
#include <stdlib.h>
#include "vertexCover.h"

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

int existe(int vet[], int value, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        if (vet[i] == value)
        {
            return 1;
        }
    }

    return 0;
}

int ehVertexCover(GRAFO *g, int S[])
{

    // Percorre todo a solução ideal verificando se a solução passada está correta
    for (int i = 0; i < g->nVertices; i++)
    {
        for (int j = 0; j < g->nVertices; j++)
        {
            if (g->adj[i][j] == 1)
            {
                if (existe(S, i, g->nVertices) == 0 && existe(S, j, g->nVertices) == 0)
                {
                    printf("NÃO EH UMA SOLUÇAO VALIDA\n");
                    return 0;
                }
            }
        }
    }
    printf("EH UMA SOLUÇAO VALIDA\n");
    return 1;
}
