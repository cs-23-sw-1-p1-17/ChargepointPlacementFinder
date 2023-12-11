#include "print_function.h"
#include "algorithm_functions.h"

void print_solution_nodes(solution_node_t* solution_nodes, int length_of_solution_nodes){

    printf(" Ranked\t| Node ID | Traffic attracted\n");
    printf("--------------------------------------\n");

    for (int i = 0; i < length_of_solution_nodes; i++)
    {
        printf("%6d. | %5d%2c | %11d\n", i+1, solution_nodes[i].node_ID, ' ', solution_nodes[i].total_traffic_attracted);
    }

}
