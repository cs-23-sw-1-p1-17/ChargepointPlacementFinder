#include "test_csv_parser.h"

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
    parse_nodes(TEST_NODES_FILEPATH,test_nodes,4);

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
    parse_nodes(TEST_NODES_FILEPATH,test_nodes,4);
    parse_edges(TEST_EDGES_FILEPATH,test_edges, test_nodes, 5);

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
    node_t nodes[SAMPLE_DATA_NODE_COUNT];

    // ACT
    parse_nodes(SAMPLE_NODES_FILEPATH, nodes, SAMPLE_DATA_NODE_COUNT);

    // ASSERTIONS
    // Test of Name
    TEST_ASSERT_EQUAL_STRING_MESSAGE("Korskro", nodes[9].name,"Failed reading correct name");
    TEST_ASSERT_EQUAL_STRING_MESSAGE("Oelholm", nodes[15].name,"Failed reading correct name");
    TEST_ASSERT_EQUAL_STRING_MESSAGE("Smidstrup Praestemark", nodes[12].name,"Failed reading correct name");
    TEST_ASSERT_EQUAL_STRING_MESSAGE("Kolding N", nodes[7].name,"Failed reading correct name");
    TEST_ASSERT_EQUAL_STRING_MESSAGE("Billund", nodes[0].name,"Failed reading correct name");
    // Test of Node ID
    TEST_ASSERT_EQUAL_INT_MESSAGE(10, nodes[9].node_id,  "Failed reading correct node id");
    TEST_ASSERT_EQUAL_INT_MESSAGE(16, nodes[15].node_id, "Failed reading correct node id");
    TEST_ASSERT_EQUAL_INT_MESSAGE(13, nodes[12].node_id, "Failed reading correct node id");
    TEST_ASSERT_EQUAL_INT_MESSAGE(8, nodes[7].node_id,   "Failed reading correct node id");
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, nodes[0].node_id,   "Failed reading correct node id");
    // Test of Node Charger Present
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, nodes[9].charger_present,  "Failed reading correct node charger present");
    TEST_ASSERT_EQUAL_INT_MESSAGE(0, nodes[15].charger_present, "Failed reading correct node charger present");
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, nodes[12].charger_present, "Failed reading correct node charger present");
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, nodes[7].charger_present,  "Failed reading correct node charger present");
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, nodes[0].charger_present,  "Failed reading correct node charger present");
    // Test of Node Quality
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(3.89, nodes[9].quality_of_stop,  "Failed reading correct node quality");
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0.00, nodes[15].quality_of_stop, "Failed reading correct node quality");
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(3.89, nodes[12].quality_of_stop, "Failed reading correct node quality");
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(4.72, nodes[7].quality_of_stop,  "Failed reading correct node quality");
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(3.06, nodes[0].quality_of_stop,  "Failed reading correct node quality");
}
/// @breif testing if parse_edges in csv_parser works on edges_list.csv - if test_parsing_of_nodes_on_example_data fails, this fails
void test_parsing_of_edges_on_example_data(void) {
    // ARRANGE initialising working struct-arrays
    node_t nodes[SAMPLE_DATA_NODE_COUNT];
    edge_t edges[SAMPLE_DATA_EDGE_COUNT];

    // ARRANGE
    parse_nodes(SAMPLE_NODES_FILEPATH, nodes, SAMPLE_DATA_NODE_COUNT);
    parse_edges(SAMPLE_EDGES_FILEPATH, edges, nodes, SAMPLE_DATA_EDGE_COUNT);

    // ASSERTIONS
    // Test of Names
    TEST_ASSERT_EQUAL_STRING_MESSAGE("E45 oestjyske Motorvej paa Vejlefjordsbroen", edges[10].name, "Failed reading correct edge name");
    TEST_ASSERT_EQUAL_STRING_MESSAGE("11  24 Ved Ribe", edges[0].name, "Failed reading correct edge name");
    TEST_ASSERT_EQUAL_STRING_MESSAGE("30 mellem Billund og Give", edges[19].name, "Failed reading correct edge name");
    TEST_ASSERT_EQUAL_STRING_MESSAGE("E45 mellem Smidstrup Praestemark og Kolding N", edges[13].name, "Failed reading correct edge name");
    TEST_ASSERT_EQUAL_STRING_MESSAGE("30 Ved Grindsted", edges[4].name, "Failed reading correct edge name");
    // Test of Traffic
    TEST_ASSERT_EQUAL_INT_MESSAGE(89920, edges[10].traffic, "Failed reading correct edge traffic");
    TEST_ASSERT_EQUAL_INT_MESSAGE(12527, edges[0].traffic,  "Failed reading correct edge traffic");
    TEST_ASSERT_EQUAL_INT_MESSAGE(7500,  edges[19].traffic, "Failed reading correct edge traffic");
    TEST_ASSERT_EQUAL_INT_MESSAGE(30000, edges[13].traffic, "Failed reading correct edge traffic");
    TEST_ASSERT_EQUAL_INT_MESSAGE(5781,  edges[4].traffic,  "Failed reading correct edge traffic");
    // Test of Length
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(8.7, edges[10].distance, "Failed reading correct edge distance");
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(11.0, edges[0].distance,  "Failed reading correct edge distance");
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(24.7, edges[19].distance, "Failed reading correct edge distance");
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(20.3, edges[13].distance, "Failed reading correct edge distance");
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(34.8, edges[4].distance,  "Failed reading correct edge distance");
    // Test of node.id 1
    TEST_ASSERT_EQUAL_INT_MESSAGE(14,  edges[10].connection1->node_id, "Failed reading correct node.id 1 connection");
    TEST_ASSERT_EQUAL_INT_MESSAGE(11, edges[0].connection1->node_id,  "Failed reading correct node.id 1 connection");
    TEST_ASSERT_EQUAL_INT_MESSAGE(1,  edges[19].connection1->node_id, "Failed reading correct node.id 1 connection");
    TEST_ASSERT_EQUAL_INT_MESSAGE(8,  edges[13].connection1->node_id, "Failed reading correct node.id 1 connection");
    TEST_ASSERT_EQUAL_INT_MESSAGE(6,  edges[4].connection1->node_id,  "Failed reading correct node.id 1 connection");
    // Test of node.id 2
    TEST_ASSERT_EQUAL_INT_MESSAGE(15, edges[10].connection2->node_id, "Failed reading correct node.id 2 connection");
    TEST_ASSERT_EQUAL_INT_MESSAGE(12, edges[0].connection2->node_id,  "Failed reading correct node.id 2 connection");
    TEST_ASSERT_EQUAL_INT_MESSAGE(5,  edges[19].connection2->node_id, "Failed reading correct node.id 2 connection");
    TEST_ASSERT_EQUAL_INT_MESSAGE(13, edges[13].connection2->node_id, "Failed reading correct node.id 2 connection");
    TEST_ASSERT_EQUAL_INT_MESSAGE(10, edges[4].connection2->node_id,  "Failed reading correct node.id 2 connection");
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