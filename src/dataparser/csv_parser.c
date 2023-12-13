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
        int assigned_fields_count = fscanf(input_fp, " %[^;];%d;%d;%lf*[^ \\t\\n]",
                                           node.name, &node.node_id, &node.charger_present, &node.quality_of_stop);

        // assign to if successfully parsed
        if (assigned_fields_count == EXPECTED_PARSED_VALUES_PR_NODE){
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
        int node_a = 0;
        int node_b = 0;

        // get values from string
        int assigned_fields_count = fscanf(input_fp, " %[^;];%d;%lf;%d;%d*[^ \\t\\n]",
                                           edge.name, &edge.traffic, &edge.distance, &node_a, &node_b);

        // assign connecting nodes
        edge.connection1 = &nodes[node_a-1]; // TODO: minus one as list is 1-index but array is 0-indexed
        edge.connection2 = &nodes[node_b-1];

        // assign if successfully parsed
        if (assigned_fields_count == EXPECTED_PARSED_VALUES_PR_EDGE) {
            edges[i] = edge;
        }
    }
}

void parsing_debug_print(edge_t *edges) {
    for (int i = 0; i < LEN_EDGE_LIST; ++i) {
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
    node_t nodes[LEN_NODE_LIST];
    parse_nodes(NODE_LIST_FILEPATH, nodes, LEN_NODE_LIST);

    edge_t edges[LEN_EDGE_LIST];
    parse_edges(EDGE_LIST_FILEPATH, edges, nodes, LEN_EDGE_LIST);

    parsing_debug_print(edges);
}
