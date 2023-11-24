#include "AlgorithmFunctions.h"

solution_node* create_solution_array(node_t* node_list, int node_list_length, edge_t* ege_matrix){}

node_t* get_connected_node (node_t* current_node, edge_t current_edge)
{
    if(current_edge.connection1 == current_node) return current_edge.connection2;
    else return current_edge.connection1;
}

int compare_solution_node(const void* a, const void* b)
{
    solution_node a1 = *(solution_node*) a;
    solution_node b1 = *(solution_node*) b;
    return b1.totalTrafficAttracted - a1.totalTrafficAttracted;
}

void sort_solution_node_array(solution_node* solution_nodes, int length_of_solution_nodes)
{
    qsort(solution_nodes, length_of_solution_nodes, sizeof(solution_node), compare_solution_node);
}