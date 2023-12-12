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
    // ARRANGE initialising working struct-array
    node_t test_nodes[4];

    // ACT
    parse_nodes("test/dataparser/test_nodes.csv",test_nodes,4);

    // ASSERTIONS
    // Test of Name
    TEST_ASSERT_EQUAL_STRING_MESSAGE("node 1", test_nodes[0].name,"Failed reading correct name");
    TEST_ASSERT_EQUAL_STRING_MESSAGE("node 2", test_nodes[1].name,"Failed reading correct name");
    TEST_ASSERT_EQUAL_STRING_MESSAGE("node 3", test_nodes[2].name,"Failed reading correct name");
    TEST_ASSERT_EQUAL_STRING_MESSAGE("node 4", test_nodes[3].name,"Failed reading correct name");
    // Test of Node ID
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, test_nodes[0].node_id, "Failed reading correct node id");
    TEST_ASSERT_EQUAL_INT_MESSAGE(2, test_nodes[1].node_id, "Failed reading correct node id");
    TEST_ASSERT_EQUAL_INT_MESSAGE(3, test_nodes[2].node_id, "Failed reading correct node id");
    TEST_ASSERT_EQUAL_INT_MESSAGE(4, test_nodes[3].node_id, "Failed reading correct node id");
    // Test of Node Charger Present
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, test_nodes[0].charger_present, "Failed reading correct node charger present");
    TEST_ASSERT_EQUAL_INT_MESSAGE(0, test_nodes[1].charger_present, "Failed reading correct node charger present");
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, test_nodes[2].charger_present, "Failed reading correct node charger present");
    TEST_ASSERT_EQUAL_INT_MESSAGE(0, test_nodes[3].charger_present, "Failed reading correct node charger present");
    // Test of Node Quality
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(3.33, test_nodes[0].quality_of_stop, "Failed reading correct node quality");
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(1.1,  test_nodes[1].quality_of_stop, "Failed reading correct node quality");
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(5,    test_nodes[2].quality_of_stop, "Failed reading correct node quality");
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0,    test_nodes[3].quality_of_stop, "Failed reading correct node quality");
}
/// @breif testing if parse_edges in csv_parser works on test_edges.csv.csv - if test_parsing_of_nodes_on_test_nodes fails, this fails
void test_parsing_of_edges_on_test_edges(void) {
    // ARRANGE initialising working struct-arrays
    node_t test_nodes[4];
    edge_t test_edges[5];

    // ACT
    parse_nodes("test/dataparser/test_nodes.csv",test_nodes,4);
    parse_edges("test/dataparser/test_edges.csv",test_edges, test_nodes, 5);

    // ASSERTIONS
    // Test of Names
    TEST_ASSERT_EQUAL_STRING_MESSAGE("edge 1", test_edges[0].name, "Failed reading correct edge name");
    TEST_ASSERT_EQUAL_STRING_MESSAGE("edge 2", test_edges[1].name, "Failed reading correct edge name");
    TEST_ASSERT_EQUAL_STRING_MESSAGE("edge 3", test_edges[2].name, "Failed reading correct edge name");
    TEST_ASSERT_EQUAL_STRING_MESSAGE("edge 4", test_edges[3].name, "Failed reading correct edge name");
    TEST_ASSERT_EQUAL_STRING_MESSAGE("edge 5", test_edges[4].name, "Failed reading correct edge name");
    // Test of Traffic
    TEST_ASSERT_EQUAL_INT_MESSAGE(12345, test_edges[0].traffic, "Failed reading correct edge traffic");
    TEST_ASSERT_EQUAL_INT_MESSAGE(54321, test_edges[1].traffic, "Failed reading correct edge traffic");
    TEST_ASSERT_EQUAL_INT_MESSAGE(1001,  test_edges[2].traffic, "Failed reading correct edge traffic");
    TEST_ASSERT_EQUAL_INT_MESSAGE(7888,  test_edges[3].traffic, "Failed reading correct edge traffic");
    TEST_ASSERT_EQUAL_INT_MESSAGE(70000, test_edges[4].traffic, "Failed reading correct edge traffic");
    // Test of Length
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(15,  test_edges[0].distance, "Failed reading correct edge distance");
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(123, test_edges[1].distance, "Failed reading correct edge distance");
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(50,  test_edges[2].distance, "Failed reading correct edge distance");
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(200, test_edges[3].distance, "Failed reading correct edge distance");
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(150, test_edges[4].distance, "Failed reading correct edge distance");
    // Test of node.id 1
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, test_edges[0].connection1->node_id, "Failed reading correct node.id 1 connection");
    TEST_ASSERT_EQUAL_INT_MESSAGE(2, test_edges[1].connection1->node_id, "Failed reading correct node.id 1 connection");
    TEST_ASSERT_EQUAL_INT_MESSAGE(3, test_edges[2].connection1->node_id, "Failed reading correct node.id 1 connection");
    TEST_ASSERT_EQUAL_INT_MESSAGE(4, test_edges[3].connection1->node_id, "Failed reading correct node.id 1 connection");
    TEST_ASSERT_EQUAL_INT_MESSAGE(2, test_edges[4].connection1->node_id, "Failed reading correct node.id 1 connection");
    // Test of node.id 2
    TEST_ASSERT_EQUAL_INT_MESSAGE(2, test_edges[0].connection2->node_id, "Failed reading correct node.id 2 connection");
    TEST_ASSERT_EQUAL_INT_MESSAGE(3, test_edges[1].connection2->node_id, "Failed reading correct node.id 2 connection");
    TEST_ASSERT_EQUAL_INT_MESSAGE(4, test_edges[2].connection2->node_id, "Failed reading correct node.id 2 connection");
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, test_edges[3].connection2->node_id, "Failed reading correct node.id 2 connection");
    TEST_ASSERT_EQUAL_INT_MESSAGE(4, test_edges[4].connection2->node_id, "Failed reading correct node.id 2 connection");
}

/// @breif testing if parse_nodes in csv_parser works on nodes_list.csv
void test_parsing_of_nodes_on_example_data(void) {
    // ARRANGE  initialising working struct-array
    node_t nodes[NUM_EXAMPLE_NODES];

    // ACT
    parse_nodes(NODE_LIST_FILEPATH, nodes, NUM_EXAMPLE_NODES);

    // ASSERTIONS
    TEST_MESSAGE("Test not written yet");
    TEST_ASSERT(1);
}
/// @breif testing if parse_edges in csv_parser works on edges_list.csv - if test_parsing_of_nodes_on_example_data fails, this fails
void test_parsing_of_edges_on_example_data(void) {
    // ARRANGE initialising working struct-arrays
    node_t nodes[NUM_EXAMPLE_NODES];
    edge_t edges[NUM_EXAMPLE_EDGES];

    // ARRANGE
    parse_nodes(NODE_LIST_FILEPATH, nodes, NUM_EXAMPLE_NODES);
    parse_edges(EDGE_LIST_FILEPATH, edges, nodes, NUM_EXAMPLE_EDGES);

    // ASSERTIONS
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