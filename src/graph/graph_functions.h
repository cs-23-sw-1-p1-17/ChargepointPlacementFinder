#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[48]; // TODO: Remove Magic-value.
    int node_id;
    double quality_of_stop;
    int charger_present;
} node_t;

typedef struct {
    char name[48];
    bool is_present;
    int traffic;
    double distance;
    node_t* connection1;
    node_t* connection2;
} edge_t;


int get_cell(int matrix_size, int x, int y);
edge_t* convert_edge_list_to_matrix(edge_t *edge_list, int edge_list_length, int node_list_length);
