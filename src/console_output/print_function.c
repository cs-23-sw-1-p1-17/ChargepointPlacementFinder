#include "print_function.h"

void print_solution_nodes(solution_node_t *solution_nodes, int length_of_solution_nodes, node_t *node_list) {
    printf(" Ranked\t| Node ID | Traffic attracted | Name\n");
    printf("---------------------------------------------\n");

    for (int i = 0; i < length_of_solution_nodes; i++) {
        printf("%6d. | %5d%2c | %11d | %s\n", i + 1, solution_nodes[i].node_id, ' ',
               solution_nodes[i].total_traffic_attracted, node_list[solution_nodes[i].node_id-1].name);
    }
}
