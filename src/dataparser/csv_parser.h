#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph_functions.h"

#define EXPECTED_PARSED_VALUES_PR_NODE 4
#define EXPECTED_PARSED_VALUES_PR_EDGE 5
#define NODE_LIST_FILEPATH ("dataparser/node_list.csv")
#define EDGE_LIST_FILEPATH ("dataparser/edge_list.csv")
#define SAMPLE_DATA_NODE_COUNT 16
#define SAMPLE_DATA_EDGE_COUNT 20

/// @breif Parsing of nodes from .csv file (semicolon)
/// @param filepath - filepath from working dir
/// @param nodes - struct-array of node_t type
/// @param n - number of nodes
void parse_nodes(const char *filepath, node_t *nodes, int n);

/// @breif Parsing of edges from .csv file (semicolon)
/// @param filepath - filepath from working dir
/// @param edges - struct-array of edge_t type
/// @param nodes - struct-array of node_t type
/// @param n - number of nodes
void parse_edges(const char *filepath, edge_t *edges, node_t *nodes, int n);
