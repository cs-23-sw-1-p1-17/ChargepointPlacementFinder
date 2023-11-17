#ifndef SEM_PROJ_1_GRAPH_THEORY_H
#define SEM_PROJ_1_GRAPH_THEORY_H
#include <stdbool.h>


struct Node {
    int quality_of_stop;
    int charger_present;
};

struct Edge {
    bool is_present;
    int traffic;
    int distance;
    struct Node* connection1;
    struct Node* connection2;
};


int get_cell(int sizeOfMatrix, int x, int y);

struct Node* CreateTestNetworkNodes();

struct Edge* CreateTestNetworkEdgeMatrix();

#endif //SEM_PROJ_1_GRAPH_THEORY_H
