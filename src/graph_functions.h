#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int node_id;
    double quality_of_stop;
    int charger_present;
} node_t;

typedef struct {
    bool is_present;
    int traffic;
    int distance;
    node_t* connection1;
    node_t* connection2;
} edge_t;


int get_cell(int matrix_size, int x, int y);

