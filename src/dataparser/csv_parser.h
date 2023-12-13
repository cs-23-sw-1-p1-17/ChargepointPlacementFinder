#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph_functions.h"

#define EXPECTED_PARSED_VALUES_PR_NODE 4
#define EXPECTED_PARSED_VALUES_PR_EDGE 5
#define NODE_LIST_FILEPATH ("src/dataparser/node_list.csv")
#define EDGE_LIST_FILEPATH ("src/dataparser/edge_list.csv")
#define LEN_NODE_LIST 16
#define LEN_EDGE_LIST 20

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
/// @breif Used for debug printing when parsing lists of nodes and edges
/// @param edges - struct-array of edge_t type
void parsing_debug_print(edge_t *edges);
/// @breif Used for debugging the parsing of lists of nodes and edges
void parsing_debug();
