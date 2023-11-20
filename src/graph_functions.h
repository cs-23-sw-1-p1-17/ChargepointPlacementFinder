#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "graph_functions.h"
#define TEST_NETWORK_NODE_AMOUNT 10


int TestNetworkNodeAmount();

int get_cell(int sizeOfMatrix, int x, int y);

struct Node* CreateTestNetworkNodes();

struct Edge* CreateTestNetworkEdgeMatrix();

struct Node {
    int quality_of_stop;
    int charger_present;
};

struct Edge {
    bool is_present;
    int traffic;
    int distance;
    struct Node* connection1;
    struct Node* connection2;
};
