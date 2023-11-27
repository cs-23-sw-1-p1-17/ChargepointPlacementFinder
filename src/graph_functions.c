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
    node_t* working = (node_t*) malloc((sizeof(node_t)) * TEST_NETWORK_NODE_AMOUNT);

    //Fill out the node list here
    node_t empty = {0,0};

    for(int i = 0; i < TEST_NETWORK_NODE_AMOUNT; i++)
    {
        working[i] = empty;
    }
    working[0].node_id = 1;
    working[0].quality_of_stop = 1;
    working[1].node_id = 2;
    working[1].quality_of_stop = 1;
    working[2].node_id = 3;
    working[2].quality_of_stop = 1;
    working[3].node_id = 4;
    working[3].quality_of_stop = 1;
    working[4].node_id = 5;
    working[4].quality_of_stop = 5;
    //Fill in actual values here

    return working;
}

edge_t* create_test_network_edge_matrix(node_t* node_list) {
    edge_t* working = (edge_t*) malloc(sizeof(edge_t) * TEST_NETWORK_NODE_AMOUNT * TEST_NETWORK_NODE_AMOUNT);

    //Fill out the edge matrix here
    edge_t empty = {false, 0, 0, NULL, NULL};

    for(int i = 0; i < TEST_NETWORK_NODE_AMOUNT * TEST_NETWORK_NODE_AMOUNT; i++)
    {
        working[i] = empty;
    }
    //Fill out the non-empty values

    working[get_cell(5,1,2)].traffic = 500;
    working[get_cell(5,1,2)].is_present = true;
    working[get_cell(5,1,2)].connection1 = &(node_list[0]);
    working[get_cell(5,1,2)].connection2 = &(node_list[1]);
    working[get_cell(5,1,2)].distance = 5;
    working[get_cell(5,2,1)].traffic = 500;
    working[get_cell(5,2,1)].is_present = true;
    working[get_cell(5,2,1)].connection1 = &(node_list[0]);
    working[get_cell(5,2,1)].connection2 = &(node_list[1]);
    working[get_cell(5,2,1)].distance = 5;

    working[get_cell(5,1,4)].traffic = 500;
    working[get_cell(5,1,4)].is_present = true;
    working[get_cell(5,1,4)].connection1 = &(node_list[0]);
    working[get_cell(5,1,4)].connection2 = &(node_list[3]);
    working[get_cell(5,1,4)].distance = 5;
    working[get_cell(5,4,1)].traffic = 500;
    working[get_cell(5,4,1)].is_present = true;
    working[get_cell(5,4,1)].connection1 = &(node_list[0]);
    working[get_cell(5,4,1)].connection2 = &(node_list[3]);
    working[get_cell(5,4,1)].distance = 5;

    working[get_cell(5,3,4)].traffic = 500;
    working[get_cell(5,3,4)].is_present = true;
    working[get_cell(5,3,4)].connection1 = &(node_list[2]);
    working[get_cell(5,3,4)].connection2 = &(node_list[3]);
    working[get_cell(5,3,4)].distance = 5;
    working[get_cell(5,4,3)].traffic = 500;
    working[get_cell(5,4,3)].is_present = true;
    working[get_cell(5,4,3)].connection1 = &(node_list[2]);
    working[get_cell(5,4,3)].connection2 = &(node_list[3]);
    working[get_cell(5,4,3)].distance = 5;

    working[get_cell(5,3,2)].traffic = 500;
    working[get_cell(5,3,2)].is_present = true;
    working[get_cell(5,3,2)].connection1 = &(node_list[2]);
    working[get_cell(5,3,2)].connection2 = &(node_list[1]);
    working[get_cell(5,3,2)].distance = 5;
    working[get_cell(5,2,3)].traffic = 500;
    working[get_cell(5,2,3)].is_present = true;
    working[get_cell(5,2,3)].connection1 = &(node_list[2]);
    working[get_cell(5,2,3)].connection2 = &(node_list[1]);
    working[get_cell(5,2,3)].distance = 5;


    working[get_cell(5,1,5)].traffic = 1000;
    working[get_cell(5,1,5)].is_present = true;
    working[get_cell(5,1,5)].connection1 = &(node_list[0]);
    working[get_cell(5,1,5)].connection2 = &(node_list[4]);
    working[get_cell(5,1,5)].distance = 5;
    working[get_cell(5,5,1)].traffic = 1000;
    working[get_cell(5,5,1)].is_present = true;
    working[get_cell(5,5,1)].connection1 = &(node_list[0]);
    working[get_cell(5,5,1)].connection2 = &(node_list[4]);
    working[get_cell(5,5,1)].distance = 5;

    working[get_cell(5,2,5)].traffic = 1000;
    working[get_cell(5,2,5)].is_present = true;
    working[get_cell(5,2,5)].connection1 = &(node_list[1]);
    working[get_cell(5,2,5)].connection2 = &(node_list[4]);
    working[get_cell(5,2,5)].distance = 5;
    working[get_cell(5,5,2)].traffic = 1000;
    working[get_cell(5,5,2)].is_present = true;
    working[get_cell(5,5,2)].connection1 = &(node_list[1]);
    working[get_cell(5,5,2)].connection2 = &(node_list[4]);
    working[get_cell(5,5,2)].distance = 5;

    working[get_cell(5,3,5)].traffic = 1000;
    working[get_cell(5,3,5)].is_present = true;
    working[get_cell(5,3,5)].connection1 = &(node_list[2]);
    working[get_cell(5,3,5)].connection2 = &(node_list[4]);
    working[get_cell(5,3,5)].distance = 5;
    working[get_cell(5,5,3)].traffic = 1000;
    working[get_cell(5,5,3)].is_present = true;
    working[get_cell(5,5,3)].connection1 = &(node_list[2]);
    working[get_cell(5,5,3)].connection2 = &(node_list[4]);
    working[get_cell(5,5,3)].distance = 5;

    working[get_cell(5,4,5)].traffic = 1000;
    working[get_cell(5,4,5)].is_present = true;
    working[get_cell(5,4,5)].connection1 = &(node_list[3]);
    working[get_cell(5,4,5)].connection2 = &(node_list[4]);
    working[get_cell(5,4,5)].distance = 5;
    working[get_cell(5,5,4)].traffic = 1000;
    working[get_cell(5,5,4)].is_present = true;
    working[get_cell(5,5,4)].connection1 = &(node_list[3]);
    working[get_cell(5,5,4)].connection2 = &(node_list[4]);
    working[get_cell(5,5,4)].distance = 5;




    return working;
}

int test_network_node_amount()
{
    return TEST_NETWORK_NODE_AMOUNT;
}