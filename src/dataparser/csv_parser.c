#include "csv_parser.h"

void parse_nodes(node_t *nodes) {
    // open file with nodes
    FILE *in_fp;
    in_fp = fopen("example_node_list.csv", "r");
    if(in_fp == NULL) {
        printf("Error!");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < NUM_EXAMPLE_NODES; ++i) {
        // creating temp variables
        node_t node;
        // get values from string
        int rt = fscanf(in_fp, " %[^,],%d,%d,%lf,%*[^ \\t\\n]",
                        node.name, &node.node_id, &node.charger_present, &node.quality_of_stop);
        // assign if successfully parsed
        if (rt == NUM_EXAMPLE_NODE_PARSED_VALUES)
            nodes[i] = node;
    }
}

void parse_edges(edge_t *edges, node_t *nodes) {
    // open file with edges
    FILE *in_fp;
    in_fp = fopen("example_edge_list.csv", "r");
    if(in_fp == NULL) {
        printf("Error!");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < NUM_EXAMPLE_EDGES; ++i) {
        // creating temp variables
        edge_t edge;
        int n_a, n_b;
        // get values from string
        int rt = fscanf(in_fp, " %[^,],%*[^,],%d,%lf,%d,%d%*[^ \\t\\n]",
                        edge.name, &edge.traffic,&edge.distance,&n_a,&n_b);
        // assign connecting nodes
        edge.connection1 = &nodes[n_a];
        edge.connection2 = &nodes[n_b];
        // assign if successfully parsed
        if (rt == NUM_EXAMPLE_EDGE_PARSED_VALUES)
            edges[i] = edge;
    }
}

void example_parsing() {
    node_t nodes[NUM_EXAMPLE_NODES];
    parse_nodes(nodes);

    edge_t edges[NUM_EXAMPLE_EDGES];
    parse_edges(edges, nodes);

}

