#include <stdio.h>
#include "algorithm_functions.h"
#include "print_function.h"
#include "graph_functions.h"
#include "csv_parser.h"
#include "sample_network.h"

int main() {
    node_t node_list[LEN_NODE_LIST];
    parse_nodes(NODE_LIST_FILEPATH, node_list, LEN_NODE_LIST);
    edge_t edge_list[LEN_EDGE_LIST];
    parse_edges(EDGE_LIST_FILEPATH, edge_list, node_list, LEN_EDGE_LIST);
    edge_t *edge_matrix = convert_edge_list_to_matrix(edge_list,LEN_EDGE_LIST,LEN_NODE_LIST);

    solution_node_t* solution_nodes = create_solution_array(node_list, LEN_NODE_LIST, edge_matrix);
    sort_solution_node_array(solution_nodes,LEN_NODE_LIST);
    print_solution_nodes(solution_nodes, LEN_NODE_LIST);

    free(solution_nodes);
    free(edge_matrix);
    return 0;
}


//node_t nodes[LEN_NODE_LIST];
//parse_nodes(NODE_LIST_FILEPATH, nodes, LEN_NODE_LIST);
//edge_t edges[LEN_EDGE_LIST];
//parse_edges(EDGE_LIST_FILEPATH, edges, nodes, LEN_EDGE_LIST);
//printf("hello\n");
//solution_node_t* solution_nodes = create_solution_array(nodes, LEN_NODE_LIST, edges);
//printf("hello\n");
//print_solution_nodes(solution_nodes, LEN_NODE_LIST);
//
//free(solution_nodes);