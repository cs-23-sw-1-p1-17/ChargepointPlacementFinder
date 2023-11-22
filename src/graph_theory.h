#ifndef SEM_PROJ_1_GRAPH_THEORY_H
#define SEM_PROJ_1_GRAPH_THEORY_H
#include <stdbool.h>


struct node {
    int quality_of_stop;
    int charger_present;
};

struct edge {
    bool is_present;
    int traffic;
    int distance;
    struct node* connection1;
    struct node* connection2;
};


#endif //SEM_PROJ_1_GRAPH_THEORY_H