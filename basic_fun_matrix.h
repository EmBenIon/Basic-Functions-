#include "global.h"

void PrintMat(FLOATING_POINT** a, INTEGER lin, INTEGER col); //O(n^2)

FLOATING_POINT **MatrixMult(FLOATING_POINT** mat1, INTEGER lin1, INTEGER col1, FLOATING_POINT** mat2, INTEGER lin2, INTEGER col2, short fail_output); //O(n^3)

FLOATING_POINT **MatrixAdd(FLOATING_POINT** mat1, INTEGER lin1, INTEGER col1, FLOATING_POINT** mat2, INTEGER lin2, INTEGER col2, short fail_output); //O(n^2)

void MatrixScale(FLOATING_POINT** mat, INTEGER lin, INTEGER col, FLOATING_POINT scalar); //O(n^2) n^2 = lin * col

FLOATING_POINT **MatrixGen(CHARACTER *input_string, INTEGER lin, INTEGER col, short fail_output); //O(n^2) n^2 = lin * col 

FLOATING_POINT **MatrixO(INTEGER lin, INTEGER col, short fail_output); //O(n) n = col

FLOATING_POINT **MatrixI(INTEGER size, short fail_output); //O(n) n = size

int test_functions();
