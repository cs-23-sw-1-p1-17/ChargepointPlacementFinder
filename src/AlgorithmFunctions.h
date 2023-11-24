#include "graph_functions.h"

typedef struct {
    int node_ID;
    int totalTrafficAttracted;
} solution_node;

solution_node* create_solution_array(node_t* node_list, int node_list_length, edge_t* ege_matrix);

node_t get_connected_node (node_t current_node, edge_t current_edge);

int compare_solution_node(const void* a, const void* b);

void sort_solution_node_array(solution_node* solution_nodes, int length_of_solution_nodes);
