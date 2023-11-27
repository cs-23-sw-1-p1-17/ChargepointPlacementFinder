#include "AlgorithmFunctions.h"
#include "graph_functions.c"
solution_node* create_solution_array(node_t* node_list, int node_list_length, edge_t* edge_matrix) {
    //Create solution node array
    solution_node *solution_array = (solution_node *) malloc(sizeof(solution_node) * node_list_length);
    solution_node current_solution_node;

    for (int i = 0; i < node_list_length; i++) {

        //Code for the primary nodes
        int total_traffic_attracted = 0;
        for (int j = 0; j < node_list_length; j++) {
            if (edge_matrix[get_cell(node_list_length, i, j)].is_present) {
                total_traffic_attracted += edge_matrix[get_cell(node_list_length, i, j)].traffic;
            }
        }

        //TotalTrafficAttracted now contains all the primary edges


        int secondary_node_traffic = 0;
        node_t *current_secondary_node;

        //Running through connection matrix
        //Still on primary node
        //This loop finds the connected node from the edge
        for (int j = 0; j < node_list_length; j++) {
            secondary_node_traffic = 0;

            if (edge_matrix[get_cell(node_list_length, i, j)].is_present) {
                current_secondary_node = get_connected_node(&node_list[i],
                                                            edge_matrix[get_cell(node_list_length, i, j)]);
                for (int k = 0; k < node_list_length; k++) {
                    secondary_node_traffic += edge_matrix[get_cell(node_list_length, current_secondary_node->node_id,
                                                                   k)].traffic;
                }
                secondary_node_traffic -= edge_matrix[get_cell(node_list_length, i, j)].traffic;

                secondary_node_traffic *= get_secondary_factor(node_list[i].quality_of_stop,
                                                               current_secondary_node->quality_of_stop);
                total_traffic_attracted += secondary_node_traffic;
            }

        }
//Save current traffic attracted in some form of array
        current_solution_node.node_ID = i + 1;
        current_solution_node.total_traffic_attracted = total_traffic_attracted;

        solution_array[i] = current_solution_node;

    }
    return solution_array;
}

node_t* get_connected_node (node_t* current_node, edge_t current_edge)
{
    if(current_edge.connection1 == current_node) return current_edge.connection2;
    else return current_edge.connection1;
}

int compare_solution_node(const void* a, const void* b)
{
    solution_node a1 = *(solution_node*) a;
    solution_node b1 = *(solution_node*) b;
    return b1.total_traffic_attracted - a1.total_traffic_attracted;
}

void sort_solution_node_array(solution_node* solution_nodes, int length_of_solution_nodes)
{
    qsort(solution_nodes, length_of_solution_nodes, sizeof(solution_node), compare_solution_node);
}

double get_secondary_factor(int primary_node_quality, int secondary_node_quality)
{
    int relative_factor = primary_node_quality - secondary_node_quality;

    switch(relative_factor)
    {
        case 4:
            return 0.2;

        case 3:
            return 0.15;

        case 2:
            return 0.1;

        case 1:
            return 0.05;

        case 0:
            return 0;

        case -1:
            return -0.05;

        case -2:
            return -0.1;

        case -3:
            return -0.15;

        case -4:
            return -0.2;

        default:
            printf("Something went wrong in relative factor calculation...");
            return 0;


    }
}