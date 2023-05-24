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

int ehVertexCover(GRAFO *g, int S[])
{
    // Encontra a solução Vertex-Cover do Grafo
    int *vertex = soluçãoOtimaVertexCover(g, g->nVertices);

    // Percorre todo a solução ideal verificando se a solução passada está correta
    for (int i = 0; i < g->nVertices; i++)
    {
        if (vertex[i] != S[i])
        {
            printf("NÃO EH UMA SOLUÇAO VALIDA\n");
            return 0;
        }
    }
    printf("EH UMA SOLUÇAO VALIDA\n");
    return 1;
}
