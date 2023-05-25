
#if !defined(VERTEX_COVER_H)
#define VERTEX_COVER_H

#define TRUE 1
#define FALSE 0
#include "grafo.h"

int *soluçãoOtimaVertexCover(GRAFO *g, int limit);
int existe(int vet[], int value, int tam);
int ehVertexCover(GRAFO *g, int S[]);
int *converteVertexParaIndempendt(GRAFO *g, int *S, int K);
void solucionaA(GRAFO *g);

#endif // VERTEX_COVER_H