#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "../graph_functions.h"

#define NUM_EXAMPLE_NODES 16
#define NUM_EXAMPLE_EDGES 20
#define NUM_EXAMPLE_NODE_PARSED_VALUES 4
#define NUM_EXAMPLE_EDGE_PARSED_VALUES 5

void parse_nodes(node_t *nodes);
void parse_edges(edge_t *edges, node_t *nodes);
edge_t* example_parsing();
void example_parsing_print(edge_t *edges);
