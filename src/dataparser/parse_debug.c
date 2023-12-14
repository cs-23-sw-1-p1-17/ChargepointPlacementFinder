#include "parse_debug.h"

void parsing_debug_print(edge_t *edges) {
    for (int i = 0; i < SAMPLE_DATA_EDGE_COUNT; ++i) {
        printf("::: %d :::\nE-name:       %s\nE-traffic:    %d\nE-distance:   %lf\n",
               i + 1, edges[i].name, edges[i].traffic, edges[i].distance);
        printf("->n1-name:    %s\n->n1-id:      %d\n->n1-quality: %lf\n->n1-charger: %d\n",
               edges[i].connection1->name, edges[i].connection1->node_id, edges[i].connection1->quality_of_stop,
               edges[i].connection1->charger_present);
        printf("->n2-name:    %s\n->n2-id:      %d\n->n2-quality: %lf\n->n2-charger: %d\n",
               edges[i].connection2->name, edges[i].connection2->node_id, edges[i].connection2->quality_of_stop,
               edges[i].connection2->charger_present);
        printf("\n");
    }
}

void parsing_debug() {
    node_t nodes[SAMPLE_DATA_NODE_COUNT];
    parse_nodes(NODE_LIST_FILEPATH, nodes, SAMPLE_DATA_NODE_COUNT);

    edge_t edges[SAMPLE_DATA_EDGE_COUNT];
    parse_edges(EDGE_LIST_FILEPATH, edges, nodes, SAMPLE_DATA_EDGE_COUNT);

    parsing_debug_print(edges);
}
