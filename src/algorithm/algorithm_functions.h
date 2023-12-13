#pragma once

#include "graph_functions.h"
#include <math.h>

#define NODE_ATTRACTION_FACTOR 0.04

typedef struct {
    int node_ID;
    int total_traffic_attracted;
} solution_node_t;

solution_node_t *create_solution_array(node_t *node_list, int node_list_length, edge_t *edge_matrix);

node_t *get_connected_node(node_t *current_node, edge_t current_edge);

int compare_solution_node(const void *solution_node_a, const void *solution_node_b);

void sort_solution_node_array(solution_node_t *solution_nodes, int length_of_solution_nodes);

double get_secondary_factor(double primary_node_quality, double secondary_node_quality);