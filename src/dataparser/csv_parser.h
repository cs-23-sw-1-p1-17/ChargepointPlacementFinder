#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph_functions.h"

#define NUM_EXAMPLE_NODES 16
#define NUM_EXAMPLE_EDGES 20
#define NUM_EXAMPLE_NODE_PARSED_VALUES 4
#define NUM_EXAMPLE_EDGE_PARSED_VALUES 5
#define NODE_LIST_FILEPATH ("src/dataparser/node_list.csv")
#define EDGE_LIST_FILEPATH ("src/dataparser/edge_list.csv")

void parse_nodes(const char *filepath, node_t *nodes);
void parse_edges(const char *filepath, edge_t *edges, node_t *nodes);
void parsing_debug_print(edge_t *edges);
void parsing();
