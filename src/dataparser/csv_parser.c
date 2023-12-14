#include "csv_parser.h"

void parse_nodes(const char *filepath, node_t *nodes, int n) {
    // open file with nodes
    FILE *input_fp = NULL;
    input_fp = fopen(filepath, "r");
    // if file not opened
    if (input_fp == NULL) {
        printf("Error Loading Nodes!");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; ++i) {
        // creating temp variables
        node_t node;

        // get values from string
        int assigned_fields_count = fscanf(input_fp, " %[^;];%d;%d;%lf*[^ \\t\\n]",
                                           node.name, &node.node_id, &node.charger_present, &node.quality_of_stop);

        // assign to if successfully parsed
        if (assigned_fields_count == EXPECTED_PARSED_VALUES_PR_NODE) {
            nodes[i] = node;
        }
    }
}

void parse_edges(const char *filepath, edge_t *edges, node_t *nodes, int n) {
    // open file with edges
    FILE *input_fp = NULL;
    input_fp = fopen(filepath, "r");
    // if file not opened
    if (input_fp == NULL) {
        printf("Error Loading Edges!");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; ++i) {
        // creating temp variables
        edge_t edge;
        int node_a = 0;
        int node_b = 0;

        // get values from string
        int assigned_fields_count = fscanf(input_fp, " %[^;];%d;%lf;%d;%d*[^ \\t\\n]",
                                           edge.name, &edge.traffic, &edge.distance, &node_a, &node_b);

        // assign connecting nodes
        edge.connection1 = &nodes[node_a - 1]; // TODO: minus one as list is 1-index but array is 0-indexed
        edge.connection2 = &nodes[node_b - 1];

        // assign if successfully parsed
        if (assigned_fields_count == EXPECTED_PARSED_VALUES_PR_EDGE) {
            edges[i] = edge;
        }
    }
}
