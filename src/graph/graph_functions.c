#include "graph_functions.h"

int get_cell(int matrix_size, int x, int y) {
    return (y-1) * matrix_size + x - 1;
}
