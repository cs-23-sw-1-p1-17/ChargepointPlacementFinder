#include "test_algorithm.h"

void setUp(void) {
    // set stuff up here
}

edge_t* test_network_matrix(node_t* node_list)
{
    edge_t* working = (edge_t*) malloc((sizeof(edge_t))*25);

    //Fill out the edge matrix here
    edge_t empty = {"",false, 0, 0, NULL, NULL};

    for(int i = 0; i < 5 * 5; i++)
    {
        working[i] = empty;
    }
    //Fill out the non-empty values

    working[get_cell(5,0,1)].traffic = 1000;
    working[get_cell(5,0,1)].is_present = true;
    working[get_cell(5,0,1)].connection1 = &(node_list[0]);
    working[get_cell(5,0,1)].connection2 = &(node_list[1]);
    working[get_cell(5,0,1)].distance = 5;
    working[get_cell(5,1,0)].traffic = 1000;
    working[get_cell(5,1,0)].is_present = true;
    working[get_cell(5,1,0)].connection1 = &(node_list[0]);
    working[get_cell(5,1,0)].connection2 = &(node_list[1]);
    working[get_cell(5,1,0)].distance = 5;

    working[get_cell(5,0,3)].traffic = 1000;
    working[get_cell(5,0,3)].is_present = true;
    working[get_cell(5,0,3)].connection1 = &(node_list[0]);
    working[get_cell(5,0,3)].connection2 = &(node_list[3]);
    working[get_cell(5,0,3)].distance = 5;
    working[get_cell(5,3,0)].traffic = 1000;
    working[get_cell(5,3,0)].is_present = true;
    working[get_cell(5,3,0)].connection1 = &(node_list[0]);
    working[get_cell(5,3,0)].connection2 = &(node_list[3]);
    working[get_cell(5,3,0)].distance = 5;

    working[get_cell(5,2,3)].traffic = 1000;
    working[get_cell(5,2,3)].is_present = true;
    working[get_cell(5,2,3)].connection1 = &(node_list[2]);
    working[get_cell(5,2,3)].connection2 = &(node_list[3]);
    working[get_cell(5,2,3)].distance = 5;
    working[get_cell(5,3,2)].traffic = 1000;
    working[get_cell(5,3,2)].is_present = true;
    working[get_cell(5,3,2)].connection1 = &(node_list[2]);
    working[get_cell(5,3,2)].connection2 = &(node_list[3]);
    working[get_cell(5,3,2)].distance = 5;

    working[get_cell(5,2,1)].traffic = 1000;
    working[get_cell(5,2,1)].is_present = true;
    working[get_cell(5,2,1)].connection1 = &(node_list[2]);
    working[get_cell(5,2,1)].connection2 = &(node_list[1]);
    working[get_cell(5,2,1)].distance = 5;
    working[get_cell(5,1,2)].traffic = 1000;
    working[get_cell(5,1,2)].is_present = true;
    working[get_cell(5,1,2)].connection1 = &(node_list[2]);
    working[get_cell(5,1,2)].connection2 = &(node_list[1]);
    working[get_cell(5,1,2)].distance = 5;


    working[get_cell(5,0,4)].traffic = 1000;
    working[get_cell(5,0,4)].is_present = true;
    working[get_cell(5,0,4)].connection1 = &(node_list[0]);
    working[get_cell(5,0,4)].connection2 = &(node_list[4]);
    working[get_cell(5,0,4)].distance = 5;
    working[get_cell(5,4,0)].traffic = 1000;
    working[get_cell(5,4,0)].is_present = true;
    working[get_cell(5,4,0)].connection1 = &(node_list[0]);
    working[get_cell(5,4,0)].connection2 = &(node_list[4]);
    working[get_cell(5,4,0)].distance = 5;

    working[get_cell(5,1,4)].traffic = 1000;
    working[get_cell(5,1,4)].is_present = true;
    working[get_cell(5,1,4)].connection1 = &(node_list[1]);
    working[get_cell(5,1,4)].connection2 = &(node_list[4]);
    working[get_cell(5,1,4)].distance = 5;
    working[get_cell(5,4,1)].traffic = 1000;
    working[get_cell(5,4,1)].is_present = true;
    working[get_cell(5,4,1)].connection1 = &(node_list[1]);
    working[get_cell(5,4,1)].connection2 = &(node_list[4]);
    working[get_cell(5,4,1)].distance = 5;

    working[get_cell(5,2,4)].traffic = 1000;
    working[get_cell(5,2,4)].is_present = true;
    working[get_cell(5,2,4)].connection1 = &(node_list[2]);
    working[get_cell(5,2,4)].connection2 = &(node_list[4]);
    working[get_cell(5,2,4)].distance = 5;
    working[get_cell(5,4,2)].traffic = 1000;
    working[get_cell(5,4,2)].is_present = true;
    working[get_cell(5,4,2)].connection1 = &(node_list[2]);
    working[get_cell(5,4,2)].connection2 = &(node_list[4]);
    working[get_cell(5,4,2)].distance = 5;

    working[get_cell(5,3,4)].traffic = 1000;
    working[get_cell(5,3,4)].is_present = true;
    working[get_cell(5,3,4)].connection1 = &(node_list[3]);
    working[get_cell(5,3,4)].connection2 = &(node_list[4]);
    working[get_cell(5,3,4)].distance = 5;
    working[get_cell(5,4,3)].traffic = 1000;
    working[get_cell(5,4,3)].is_present = true;
    working[get_cell(5,4,3)].connection1 = &(node_list[3]);
    working[get_cell(5,4,3)].connection2 = &(node_list[4]);
    working[get_cell(5,4,3)].distance = 5;

    return working;
}

node_t* test_network_node_list()
{
    node_t* working = malloc(sizeof(node_t)*5);

    //Fill out the node list here
    node_t empty = {"", 0, 0, 0};

    for(int i = 0; i < 5; i++)
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

    return working;
}

void tearDown(void) {
    // clean stuff up here
}

/// @breif Testing algorithm functionality on simple 5 node network
void test_algorithm_on_test(void) {

    node_t* nodes = test_network_node_list();
    edge_t* matrix = test_network_matrix(nodes);

    solution_node_t* solution = create_solution_array(nodes, 5, matrix);

    // do the NODE ID's transfer
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, solution[0].node_id, "Node ID transition failure");
    TEST_ASSERT_EQUAL_INT_MESSAGE(2, solution[1].node_id, "Node ID transition failure");
    TEST_ASSERT_EQUAL_INT_MESSAGE(3, solution[2].node_id, "Node ID transition failure");
    TEST_ASSERT_EQUAL_INT_MESSAGE(4, solution[3].node_id, "Node ID transition failure");
    TEST_ASSERT_EQUAL_INT_MESSAGE(5, solution[4].node_id, "Node ID transition failure");


    // test the expected result
    TEST_ASSERT_EQUAL_INT_MESSAGE(2520, solution[0].total_traffic_attracted, "Node total_traffic_error");
    TEST_ASSERT_EQUAL_INT_MESSAGE(2520, solution[1].total_traffic_attracted, "Node total_traffic_error");
    TEST_ASSERT_EQUAL_INT_MESSAGE(2520, solution[2].total_traffic_attracted, "Node total_traffic_error");
    TEST_ASSERT_EQUAL_INT_MESSAGE(2520, solution[3].total_traffic_attracted, "Node total_traffic_error");
    TEST_ASSERT_EQUAL_INT_MESSAGE(5280, solution[4].total_traffic_attracted, "Node total_traffic_error");
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_algorithm_on_test);
    return (UnityEnd());
}