#include "print_function.h"

void print_solution_nodes(solution_node_t *solution_nodes, int length_of_solution_nodes, node_t *node_list) {
    int longest_name_length = 0;
    for (int i = 0; i < length_of_solution_nodes; ++i) {
        int name_length = strlen(node_list[solution_nodes[i].node_id-1].name);
        if (name_length > longest_name_length){
            longest_name_length = name_length;
        }
    }

    // padding on both sides of 'Name' is half of the longest item in that column. It keeps the title centered.
    printf(" Ranked\t| Node ID | %*c Name %*c | Traffic attracted\n", (longest_name_length/2) - 2, ' ', (longest_name_length/2) - 3, ' ');

    for (int i = 0; i < longest_name_length; ++i) {
        printf("-");
    }
    printf("-----------------------------------------\n");

    for (int i = 0; i < length_of_solution_nodes; i++) {
        printf("%6d. | %5d%2c | %*s | %11d\n", i + 1, solution_nodes[i].node_id, ' ',
               longest_name_length, node_list[solution_nodes[i].node_id-1].name, solution_nodes[i].total_traffic_attracted);
    }
}
