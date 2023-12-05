 #include "algorithm_functions.h"

#include <math.h>

solution_node_t* create_solution_array(node_t* node_list, int node_list_length, edge_t* edge_matrix) {
    // Create solution node array
    solution_node_t *solution_array = (solution_node_t *) malloc(sizeof(solution_node_t) * node_list_length);
    solution_node_t current_solution_node;

    for (int i = 0; i < node_list_length; i++) {
        // Code for the primary nodes
        int total_traffic_attracted = 0;
        for (int j = 0; j < node_list_length; j++) {
            edge_t edge = edge_matrix[get_cell(node_list_length, i+1, j+1)];

            if (edge.is_present) {
                total_traffic_attracted += edge.traffic;
            }
        }

        // TotalTrafficAttracted now contains all the primary edges


        int secondary_node_traffic = 0;
        node_t *current_secondary_node = NULL;

        // Running through connection matrix
        // Still on primary node
        // This loop finds the connected node from the edge
        for (int j = 0; j < node_list_length; j++) {
            secondary_node_traffic = 0;
            edge_t current_edge = edge_matrix[get_cell(node_list_length, i + 1, j + 1)];

            if (current_edge.is_present) {
                current_secondary_node = get_connected_node(&node_list[i], current_edge);
                for (int k = 0; k < node_list_length; k++) {
                    secondary_node_traffic += edge_matrix[get_cell(node_list_length, current_secondary_node->node_id,k + 1)].traffic;
                }

                secondary_node_traffic -= current_edge.traffic;
                secondary_node_traffic = floor(secondary_node_traffic * get_secondary_factor(node_list[i].quality_of_stop,
                                                               current_secondary_node->quality_of_stop));
                total_traffic_attracted += secondary_node_traffic;
            }
        }

        // Save current traffic attracted in some form of array
        current_solution_node.node_ID = i + 1;
        current_solution_node.total_traffic_attracted = total_traffic_attracted;

        solution_array[i] = current_solution_node;
    }

    return solution_array;
}

node_t* get_connected_node (node_t* current_node, edge_t current_edge) {
    return current_edge.connection1 == current_node ? current_edge.connection2 : current_edge.connection1;
}

int compare_solution_node(const void* solution_node_a, const void* solution_node_b) {
    solution_node_t a1 = *(solution_node_t*) solution_node_a;
    solution_node_t b1 = *(solution_node_t*) solution_node_b;
    return b1.total_traffic_attracted - a1.total_traffic_attracted;
}

void sort_solution_node_array(solution_node_t* solution_nodes, int length_of_solution_nodes) {
    qsort(solution_nodes, length_of_solution_nodes, sizeof(solution_node_t), compare_solution_node);
}

double get_secondary_factor(int primary_node_quality, int secondary_node_quality) {
    return (primary_node_quality - secondary_node_quality) * 0.04;
}
