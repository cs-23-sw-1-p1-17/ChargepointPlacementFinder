#include "AlgorithmFunctions.h"

solution_node* create_solution_array(node_t* node_list, int node_list_length, edge_t* ege_matrix){}

node_t get_connected_node (node_t current_node, edge_t current_edge){}

int compare_solution_node(const void* a, const void* b)
{
    solution_node a1 = *(solution_node*) a;
    solution_node b1 = *(solution_node*) b;
    return b1.totalTrafficAttracted - a1.totalTrafficAttracted;
}

void sort_solution_node_array(solution_node* solution_nodes, int length_of_solution_nodes){}