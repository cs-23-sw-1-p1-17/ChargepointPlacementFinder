#include "sample_network.h"

node_t *create_sample_network_nodes() {
    node_t *working = (node_t *) malloc((sizeof(node_t)) * TEST_NETWORK_NODE_AMOUNT);

    // Fill out the node list here
    node_t empty = {0, 0};

    for (int i = 0; i < TEST_NETWORK_NODE_AMOUNT; i++) {
        working[i] = empty;
    }

    // TODO: Fill in actual values here

    return working;
}

edge_t *create_sample_network_edge_matrix() {
    edge_t *working = (edge_t *) malloc(sizeof(edge_t) * TEST_NETWORK_NODE_AMOUNT * TEST_NETWORK_NODE_AMOUNT);

    // Fill out the edge matrix here
    edge_t empty = {false, 0, 0, NULL, NULL};

    for (int i = 0; i < TEST_NETWORK_NODE_AMOUNT * TEST_NETWORK_NODE_AMOUNT; i++) {
        working[i] = empty;
    }

    // TODO: Fill out the non-empty values

    return working;
}

int sample_network_node_amount() {
    return TEST_NETWORK_NODE_AMOUNT;
}
