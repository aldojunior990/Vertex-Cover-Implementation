
#if !defined(VERTEX_COVER_H)
#define VERTEX_COVER_H

#include "grafo.h"

int *soluçãoOtimaVertexCover(GRAFO *g, int limit);
int ehVertexCover(GRAFO *g, int S[]);

#endif // VERTEX_COVER_H