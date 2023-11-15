#ifndef SEM_PROJ_1_GRAPH_THEORY_H
#define SEM_PROJ_1_GRAPH_THEORY_H

struct edge {
    int isPresent;
    int traffic;
    int distance;
};

struct node {
    struct edge connection1;
    struct edge connection2;
    int quality_of_stop;
    int chargerPresent;
};


#endif //SEM_PROJ_1_GRAPH_THEORY_H
