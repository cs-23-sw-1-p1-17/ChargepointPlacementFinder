#include "csv_parser.h"
#include "graph_functions.h"
#include "unity.h"

void setUp(void) {
    // set stuff up here
}
void tearDown(void) {
    // clean stuff up here
}
/// @breif testing if parse_nodes in csv_parser works on test_nodes.csv
void test_parsing_of_nodes_on_test_nodes(void) {
    // initialising working struct-array
    node_t test_nodes[4];
    parse_nodes("test/dataparser/test_nodes.csv",test_nodes,4);

    // insert assertions
    TEST_MESSAGE("Test not written yet");
    TEST_ASSERT(1);
}
/// @breif testing if parse_edges in csv_parser works on test_edges.csv.csv - if test_parsing_of_nodes_on_test_nodes fails, this fails
void test_parsing_of_edges_on_test_edges(void) {
    // initialising working struct-arrays
    node_t test_nodes[4];
    edge_t test_edges[5];
    parse_nodes("test/dataparser/test_nodes.csv",test_nodes,4);
    parse_edges("test/dataparser/test_edges.csv",test_edges, test_nodes, 5);

    // insert assertions
    TEST_MESSAGE("Test not written yet");
    TEST_ASSERT(1);
}

/// @breif testing if parse_nodes in csv_parser works on test_nodes.csv
void test_parsing_of_nodes_on_example_data(void) {
    // initialising working struct-array
    node_t nodes[NUM_EXAMPLE_NODES];
    parse_nodes(NODE_LIST_FILEPATH, nodes, NUM_EXAMPLE_NODES);

    // insert assertions
    TEST_MESSAGE("Test not written yet");
    TEST_ASSERT(1);
}
/// @breif testing if parse_edges in csv_parser works on test_edges.csv.csv - if test_parsing_of_nodes_on_example_data fails, this fails
void test_parsing_of_edges_on_example_data(void) {
    // initialising working struct-arrays
    node_t nodes[NUM_EXAMPLE_NODES];
    edge_t edges[NUM_EXAMPLE_EDGES];
    parse_nodes(NODE_LIST_FILEPATH, nodes, NUM_EXAMPLE_NODES);
    parse_edges(EDGE_LIST_FILEPATH, edges, nodes, NUM_EXAMPLE_EDGES);

    // insert assertions
    TEST_MESSAGE("Test not written yet");
    TEST_ASSERT(1);
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_parsing_of_nodes_on_test_nodes);
    RUN_TEST(test_parsing_of_edges_on_test_edges);
    RUN_TEST(test_parsing_of_nodes_on_example_data);
    RUN_TEST(test_parsing_of_edges_on_example_data);
    return (UnityEnd());
}