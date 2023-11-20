#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "graph_functions.h"
#define TEST_NETWORK_NODE_AMOUNT 10


int test_network_node_amount();

int get_cell(int matrix_size, int x, int y);

struct Node* create_test_network_nodes();

struct Edge* create_test_network_edge_matrix();

struct Node {
    int quality_of_stop;
    int charger_present;
};

struct Edge {
    bool is_present;
    int traffic;
    int distance;
    struct Node* connection1;
    struct Node* connection2;
};
