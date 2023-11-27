#include "AlgorithmFunctions.h"
#include "graph_functions.c"
solution_node* create_solution_array(node_t* node_list, int node_list_length, edge_t* edge_matrix)
{
    //Create solution node array
    solution_node* solution_array = (solution_node*) malloc(sizeof(solution_node)*node_list_length);

    for(int i = 0; i < node_list_length; i++)
    {

        //Code for the primary nodes
        int totalTrafficAttracted = 0;
        for(int j = 0; j < node_list_length; j++)
        {
            if(edge_matrix[get_cell(node_list_length, i, j)].is_present)
            {
                totalTrafficAttracted += edge_matrix[get_cell(node_list_length, i, j)].traffic;
            }
        }

        //TotalTrafficAttracted now contains all the primary edges


        int secondaryNodeTraffic;
        for(int j = 0; i < node_list_length; i++)
        {
            secondaryNodeTraffic = 0;
            //Fill edge with empty
            if(edge_matrix[node.number][j].isPresent)
            {
                //GetConnectedNode
                for()
                {
                    GetTotalTrafficOfEach
                }
                currentEdge
                        CalculateAttractedTrafficFromQualityStop,
                GetSecondaryFactor(currentNodeQuality - )
                Multiply with secondary factor
                Add to totalTrafficAttracted
            }
        }
//Save current traffic attracted in some form of array
    }

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
    return b1.totalTrafficAttracted - a1.totalTrafficAttracted;
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