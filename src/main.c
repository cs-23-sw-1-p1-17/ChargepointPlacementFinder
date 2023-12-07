#include <stdio.h>
#include "algorithm_functions.h"
#include "print_function.h"
#include "graph_functions.h"
#include "sample_network.h"

//Here, we want a 2D array featuring the struct implementing how we want to represent the edges of the graph

#define AMOUNT_NODE 10

int main() {

    node_t* nodes = create_sample_network_nodes();
    edge_t* edges = create_sample_network_edge_matrix();
    solution_node_t* solution_nodes = create_solution_array(nodes, TEST_NETWORK_NODE_AMOUNT, edges);

    print_solution_nodes(solution_nodes, TEST_NETWORK_NODE_AMOUNT);

    return 0;
}
