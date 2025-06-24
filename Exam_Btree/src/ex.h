#include "btree.h"

//Costruire ricorsivamente un albero binario
Btree inputBtree(void);

int computeDepth(Btree t);

int numNodes(Btree t);

int numLeaves(Btree t);

// int numNodesWithSingleChild(Btree t);

int numNodesWithSingleChildV2(Btree t);

int numDXChilds(Btree t);

int sumNodes(Btree t);