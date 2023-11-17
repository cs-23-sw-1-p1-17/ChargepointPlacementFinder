//
// Created by Peter on 15/11/2023.
//
#include <stdio.h>
#include "graph_theory.h"
#include <stdlib.h>
#define TEST_NETWORK_NODE_AMOUNT 10

//Assumes input is 1-indexed
int get_cell(int sizeOfMatrix, int x, int y)
{
    return y * sizeOfMatrix + x - 1;
}

struct Node* CreateTestNetworkNodes()
{
    struct Node* working = (struct Node*) malloc((sizeof(struct Node)) * TEST_NETWORK_NODE_AMOUNT);

    //Fill out the node list here
    struct Node empty = {0,0};

    for(int i = 0; i < TEST_NETWORK_NODE_AMOUNT; i++)
    {
        working[i] = empty;
    }

    //Fill in actual values here

    return working;
}

struct Edge* CreateTestNetworkEdgeMatrix()
{
    struct Edge* working = (struct Edge*) malloc(sizeof(struct Edge) * TEST_NETWORK_NODE_AMOUNT * TEST_NETWORK_NODE_AMOUNT);

    //Fill out the edge matrix here
    struct Edge empty = {false, 0, 0, NULL, NULL};

    for(int i = 0; i < TEST_NETWORK_NODE_AMOUNT * TEST_NETWORK_NODE_AMOUNT; i++)
    {
        working[i] = empty;
    }


    //Fill out the non-empty values


    return working;
}