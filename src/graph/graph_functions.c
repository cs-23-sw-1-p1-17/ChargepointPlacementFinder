#include "graph_functions.h"

int get_cell(int matrix_size, int x, int y) {
    return (y) * matrix_size + x;
}

edge_t* convert_edge_list_to_matrix(edge_t *edge_list, int edge_list_length, int node_list_length) {
    // declare ant init matrix
    edge_t *edge_matrix = malloc(sizeof(edge_t) * node_list_length * node_list_length);

    // empty edge matrix
    edge_t empty = {"0",0,0,0, NULL, NULL};
    for(int i = 0; i < node_list_length * node_list_length; ++i) {
        edge_matrix[i] = empty;
    }

    for (int i = 0; i < edge_list_length; ++i) {
        edge_matrix[get_cell(node_list_length, edge_list[i].connection1->node_id,edge_list[i].connection2->node_id)] = edge_list[i];
        edge_matrix[get_cell(node_list_length, edge_list[i].connection2->node_id,edge_list[i].connection1->node_id)] = edge_list[i];
    }
    return edge_matrix;
}
