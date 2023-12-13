#include "algorithm_functions.h"
#include "print_function.h"
#include "graph_functions.h"
#include "csv_parser.h"

int main() {
    node_t node_list[SAMPLE_DATA_NODE_COUNT];
    parse_nodes(NODE_LIST_FILEPATH, node_list, SAMPLE_DATA_NODE_COUNT);
    edge_t edge_list[SAMPLE_DATA_EDGE_COUNT];
    parse_edges(EDGE_LIST_FILEPATH, edge_list, node_list, SAMPLE_DATA_EDGE_COUNT);
    edge_t *edge_matrix = convert_edge_list_to_matrix(edge_list, SAMPLE_DATA_EDGE_COUNT, SAMPLE_DATA_NODE_COUNT);

    solution_node_t *solution_nodes = create_solution_array(node_list, SAMPLE_DATA_NODE_COUNT, edge_matrix);
    sort_solution_node_array(solution_nodes, SAMPLE_DATA_NODE_COUNT);
    print_solution_nodes(solution_nodes, SAMPLE_DATA_NODE_COUNT, node_list);

    free(solution_nodes);
    free(edge_matrix);
    return 0;
}