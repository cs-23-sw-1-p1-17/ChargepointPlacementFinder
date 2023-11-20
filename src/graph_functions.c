//
// Created by Petra on 15/11/2023.
//
#include "graph_functions.h"

int get_cell(int matrix_size, int x, int y)
{
    return (y-1) * matrix_size + x - 1;
}

node_t* create_test_network_nodes()
{
    node_t* working = (struct Node*) malloc((sizeof(struct Node)) * TEST_NETWORK_NODE_AMOUNT);

    //Fill out the node list here
    node_t empty = {0,0};

    for(int i = 0; i < TEST_NETWORK_NODE_AMOUNT; i++)
    {
        working[i] = empty;
    }

    //Fill in actual values here

    return working;
}

edge_t* create_test_network_edge_matrix() {
    edge_t* working = (struct Edge*) malloc(sizeof(struct Edge) * TEST_NETWORK_NODE_AMOUNT * TEST_NETWORK_NODE_AMOUNT);

    //Fill out the edge matrix here
    edge_t empty = {false, 0, 0, NULL, NULL};

    for(int i = 0; i < TEST_NETWORK_NODE_AMOUNT * TEST_NETWORK_NODE_AMOUNT; i++)
    {
        working[i] = empty;
    }


    //Fill out the non-empty values


    return working;
}

int test_network_node_amount()
{
    return TEST_NETWORK_NODE_AMOUNT;
}
