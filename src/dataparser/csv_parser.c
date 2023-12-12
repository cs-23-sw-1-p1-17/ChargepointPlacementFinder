#include "csv_parser.h"

void parse_nodes(const char *filepath, node_t *nodes, int n) {
    // open file with nodes
    FILE *input_fp = NULL;
    input_fp = fopen(filepath, "r");
    // if file not opened
    if(input_fp == NULL) {
        printf("Error Loading Nodes!");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; ++i) {
        // creating temp variables
        node_t node;

        // get values from string
        int rt = fscanf(input_fp, " %[^;];%d;%d;%lf*[^ \\t\\n]",
                        node.name, &node.node_id, &node.charger_present, &node.quality_of_stop);

        // assign to if successfully parsed
        if (rt == NUM_EXAMPLE_NODE_PARSED_VALUES){
            nodes[i] = node;
        }
    }
}

void parse_edges(const char *filepath, edge_t *edges, node_t *nodes, int n) {
    // open file with edges
    FILE *input_fp = NULL;
    input_fp = fopen(filepath, "r");
    // if file not opened
    if(input_fp == NULL) {
        printf("Error Loading Edges!");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; ++i) {
        // creating temp variables
        edge_t edge;
        int node_a;
        int node_b;

        // get values from string
        int rt = fscanf(input_fp, " %[^;];%d;%lf;%d;%d*[^ \\t\\n]",
                        edge.name, &edge.traffic, &edge.distance, &node_a, &node_b);

        // assign connecting nodes
        edge.connection1 = &nodes[node_a];
        edge.connection2 = &nodes[node_b];

        // assign if successfully parsed
        if (rt == NUM_EXAMPLE_EDGE_PARSED_VALUES) {
            edges[i] = edge;
        }
    }
}

void parsing_debug_print(edge_t *edges) {
    for (int i = 0; i < NUM_EXAMPLE_EDGES; ++i) {
        printf("::: %d :::\nE-name:       %s\nE-traffic:    %d\nE-distance:   %lf\n",
               i+1, edges[i].name, edges[i].traffic, edges[i].distance);
        printf("->n1-name:    %s\n->n1-id:      %d\n->n1-quality: %lf\n->n1-charger: %d\n",
               edges[i].connection1->name, edges[i].connection1->node_id,edges[i].connection1->quality_of_stop,edges[i].connection1->charger_present);
        printf("->n2-name:    %s\n->n2-id:      %d\n->n2-quality: %lf\n->n2-charger: %d\n",
               edges[i].connection2->name, edges[i].connection2->node_id,edges[i].connection2->quality_of_stop,edges[i].connection2->charger_present);
        printf("\n");
    }
}

void parsing_debug() {
    node_t nodes[NUM_EXAMPLE_NODES];
    parse_nodes(NODE_LIST_FILEPATH, nodes, NUM_EXAMPLE_NODES);

    edge_t edges[NUM_EXAMPLE_EDGES];
    parse_edges(EDGE_LIST_FILEPATH, edges, nodes, NUM_EXAMPLE_EDGES);

    parsing_debug_print(edges);
}
