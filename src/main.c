#include <stdio.h>
#include "AlgorithmFunctions.c"

//Here, we want a 2D array featuring the struct implementing how we want to represent the edges of the graph

#define AMOUNT_NODE 10
void simple_test();

int main() {
    printf("Hello Anders!\n");
    simple_test();
    printf("HALP");
    return 0;
}


void simple_test()
{
    //Create nodes
    node_t* nodes = create_test_network_nodes();
    //Create edges
    edge_t* edges = create_test_network_edge_matrix(nodes);
    //Create solution
    solution_node*  solutions = create_solution_array(nodes, 5, edges);
    //Sort solution
    sort_solution_node_array(solutions, 5);
    //Print solution
    for(int i = 0; i < 5; i++)
    {
        printf("%d: Total attracted traffic = %d\n", solutions[i].node_ID, solutions[i].total_traffic_attracted);
    }
}