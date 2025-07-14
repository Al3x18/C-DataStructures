#include "btree.h"

//Costruire ricorsivamente un albero binario
Btree inputBtree(void);

int computeDepth(Btree t);

int numNodes(Btree t);

int numLeaves(Btree t);

int numNodesWithSingleChild(Btree t);

int numDXChilds(Btree t);

int sumNodes(Btree t);

int fratelli(Btree t);

int foglieK(Btree t, int k);

int strutturalmenteUguali(Btree t1, Btree t2);

int ugualeSommaDxSx(Btree t);

int numeroNipoti(Btree t, item i);

int almenoUnFiglioDX(Btree t);