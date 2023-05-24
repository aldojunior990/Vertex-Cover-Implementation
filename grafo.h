#if !defined(GRAFO_H)
#define GRAFO_H

typedef struct grafo
{
    int nVertices;
    int nArestas;
    int **adj; 
} GRAFO;

void criarAresta(GRAFO *g, int v, int u);
void removeAresta(GRAFO *g, int v, int u);
GRAFO *iniciar(int n);
int grauV(GRAFO *g, int vertice);
void imprimeGrafo(GRAFO *g);
void imprimirMatriz(GRAFO *g);

#endif