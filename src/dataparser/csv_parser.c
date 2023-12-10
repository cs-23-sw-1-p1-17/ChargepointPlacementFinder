#include "csv_parser.h"

void parse_nodes(node_t *nodes) {
    // open file with nodes
    FILE *in_fp = NULL;
    in_fp = fopen(NODE_LIST_FILEPATH, "r");
    if(in_fp == NULL) {
        printf("Error!");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < NUM_EXAMPLE_NODES; ++i) {
        // creating temp variables
        node_t node;
        // get values from string
        int rt = fscanf(in_fp, " %[^;];%d;%d;%lf%*[^ \\t\\n]",
                        node.name, &node.node_id, &node.charger_present, &node.quality_of_stop);
        // assign if successfully parsed
        if (rt == NUM_EXAMPLE_NODE_PARSED_VALUES)
            nodes[i] = node;
    }
}

void parse_edges(edge_t *edges, node_t *nodes) {
    // open file with edges
    FILE *in_fp = NULL;
    in_fp = fopen("../src/dataparser/edge_list.csv", "r");
    if(in_fp == NULL) {
        printf("Error!");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < NUM_EXAMPLE_EDGES; ++i) {
        // creating temp variables
        edge_t edge;
        int n_a, n_b;
        // get values from string
        int rt = fscanf(in_fp, " %[^;]s;%d;%lf;%d;%d%*[^ \\t\\n]",
                        edge.name, &edge.traffic, &edge.distance, &node_a, &node_b);
        // assign connecting nodes
        edge.connection1 = &nodes[n_a];
        edge.connection2 = &nodes[n_b];
        // assign if successfully parsed
        if (rt == NUM_EXAMPLE_EDGE_PARSED_VALUES)
            edges[i] = edge;
    }
}

void example_parsing_print(edge_t *edges) {
    for (int i = 0; i < NUM_EXAMPLE_EDGES; ++i) {
        printf("E-name: %s\nE-pres: %d\nE-traf: %d\nE-dist: %lf\n",
               edges[i].name, edges[i].is_present, edges[i].traffic, edges[i].distance);
        printf("->n1-name: %s\n->n1-id:  %d\n->n1-qual: %lf\n->n1-char: %d\n",
               edges[i].connection1->name, edges[i].connection1->node_id,edges[i].connection1->quality_of_stop,edges[i].connection1->charger_present);
        printf("->n2-name: %s\n->n2-id:  %d\n->n2-qual: %lf\n->n2-char: %d\n",
               edges[i].connection2->name, edges[i].connection2->node_id,edges[i].connection2->quality_of_stop,edges[i].connection2->charger_present);
        printf("\n");
    }
}

edge_t* example_parsing() {
    node_t nodes[NUM_EXAMPLE_NODES];
    parse_nodes(nodes);

    edge_t edges[NUM_EXAMPLE_EDGES];
    parse_edges(edges, nodes);

    example_parsing_print(edges);
}

