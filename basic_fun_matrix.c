#include "basic_fun_matrix.h"

void PrintMat(FLOATING_POINT** a, INTEGER lin, INTEGER col) //O(n^2)
{
	INTEGER i, e;
	for (i = 0; i < lin; i++)
	{
		for (e = 0; e < col; e++)
			print("%f ", a[i][e]);
		print("\n");
	}
}

FLOATING_POINT **MatrixMult(FLOATING_POINT** mat1, INTEGER lin1, INTEGER col1, FLOATING_POINT** mat2, INTEGER lin2, INTEGER col2, short fail_output) //O(n^3)
{
    INTEGER i, e, k;
    if (col1 != lin2 || lin1 != col2)
    {
        if(fail_output != 0)
        {
            SET_COLOR_RED
            print("Invalid dimensions\n");
            SET_COLOR_WHITE
        }
        return NULL;
    }

	//lin3 = lin1
	//col3 = col2
	INTEGER lin3 = lin1, col3 = col2;

	FLOATING_POINT** rez = (FLOATING_POINT**)malloc(lin3 * sizeof(FLOATING_POINT*));
    
    if(rez == NULL)
    {
        if(fail_output != 0)
        {
            SET_COLOR_RED
            print("1st step allocation error\n");
            SET_COLOR_WHITE
        }
        return NULL;
    }

	for (i = 0; i < lin3; i++)
	{
		rez[i] = (FLOATING_POINT*)calloc(col3, sizeof(FLOATING_POINT));
        if(rez == NULL)
        {
            if(fail_output != 0)
            {
                SET_COLOR_RED
                print("step %d: allocation error\n", i);
                SET_COLOR_WHITE
            }
            return NULL;
        }

        for (e = 0; e < col3; e++)
		{
			rez[i][e] = 0;
			for (k = 0; k < col3; k++)
			{
				rez[i][e] += mat1[i][k] * mat2[k][e];
			}
		}
	}

    return rez;
}

FLOATING_POINT **MatrixAdd(FLOATING_POINT** mat1, INTEGER lin1, INTEGER col1, FLOATING_POINT** mat2, INTEGER lin2, INTEGER col2, short fail_output) //O(n^2)
{
    INTEGER i, e, k;
    if (lin1 != lin2 || col1 != col2)
    {
        if(fail_output != 0)
        {
            SET_COLOR_RED
            print("Invalid dimensions\n");
            SET_COLOR_WHITE
        }
        return NULL;
    }

    INTEGER lin3 = lin1, col3 = col1;

	FLOATING_POINT** rez = (FLOATING_POINT**)malloc(lin3 * sizeof(FLOATING_POINT*));
    
    if(rez == NULL)
    {
        if(fail_output != 0)
        {
            SET_COLOR_RED
            print("1st step allocation error\n");
            SET_COLOR_WHITE
        }
        return NULL;
    }

	for (i = 0; i < lin3; i++)
	{
		rez[i] = (FLOATING_POINT*)calloc(col3, sizeof(FLOATING_POINT));
        if(rez == NULL)
        {
            if(fail_output != 0)
            {
                SET_COLOR_RED
                print("step %d: allocation error\n", i);
                SET_COLOR_WHITE
            }
            return NULL;
        }

        for (e = 0; e < col3; e++)
			rez[i][e] = mat1[i][e] + mat2[i][e];
	}

    return rez;
}

void MatrixScale(FLOATING_POINT** mat, INTEGER lin, INTEGER col, FLOATING_POINT scalar) //O(n^2) n^2 = lin * col
{   
    INTEGER i, e;
    for(i=0; i<lin; i++)
        for(e=0; e<col; e++)
            mat[i][e] *= scalar;
}

FLOATING_POINT **MatrixGen(CHARACTER *input_string, INTEGER lin, INTEGER col, short fail_output) //O(n^2) n^2 = lin * col 
{
    CHARACTER *str = (CHARACTER*)malloc(strlen(input_string) * sizeof(CHARACTER));
    if(str == NULL)
    {
        if(fail_output != 0)
        {
            SET_COLOR_RED
            print("String copy allocation error\n");
            SET_COLOR_WHITE
        }
        return NULL;
    }
    strcpy(str, input_string);

    FLOATING_POINT **mat = (FLOATING_POINT**)malloc(lin * sizeof(FLOATING_POINT*));
    if(mat == NULL)
    {
        if(fail_output != 0)
        {
            SET_COLOR_RED
            print("Matrix allocation error\n");
            SET_COLOR_WHITE
        }
        return NULL;
    }
    INTEGER i, e;

    CHARACTER *num = strtok(str, SEP_STR);

    for(i=0; i<lin; i++)
    {
        mat[i] = (FLOATING_POINT*)calloc(col, sizeof(FLOATING_POINT));

        if(mat[i] == NULL)
        {
            if(fail_output != 0)
            {
                SET_COLOR_RED
                print("Matrix row %d allocation error\n", i);
                SET_COLOR_WHITE
            }
            return NULL;
        }

        for(e=0; e<col; e++)
        {
            mat[i][e] = (FLOATING_POINT)atof(num);
            num = strtok(NULL, SEP_STR);
        }
    }

    return mat;
}

FLOATING_POINT **MatrixI(INTEGER size, short fail_output) //O(n) n = size
{
    INTEGER i, e;
    FLOATING_POINT **mat = (FLOATING_POINT**)malloc(size * sizeof(FLOATING_POINT*));
    
    if(mat == NULL)
    {
        if(fail_output != 0)
        {
            SET_COLOR_RED
            print("Matrix allocation error\n");
            SET_COLOR_WHITE
        }
        return NULL;
    }

    for(i=0; i<size; i++)
    {
        mat[i] = (FLOATING_POINT*)calloc(size, sizeof(FLOATING_POINT));

        if(mat[i] == NULL)
        {
            if(fail_output != 0)
            {
                SET_COLOR_RED
                print("Matrix row %d allocation error\n", i);
                SET_COLOR_WHITE
            }
            return NULL;
        }

        mat[i][e] = 1;
    }

    return mat;
}

FLOATING_POINT **MatrixO(INTEGER lin, INTEGER col, short fail_output) //O(n) n = col
{
    FLOATING_POINT **mat = (FLOATING_POINT**)malloc(lin * sizeof(FLOATING_POINT*));

    if(mat == NULL)
    {
        if(fail_output != 0)
        {
            SET_COLOR_RED
            print("Matrix allocation error\n");
            SET_COLOR_WHITE
        }
        return NULL;
    }

    INTEGER i;

    for(i=0; i<col; i++)
    {
        mat[i] = (FLOATING_POINT*)calloc(col, sizeof(FLOATING_POINT));
        
        if(mat[i] == NULL)
        {
            if(fail_output != 0)
            {
                SET_COLOR_RED
                print("Matrix row %d allocation error\n", i);
                SET_COLOR_WHITE
            }
            return NULL;
        }
    }

    return mat;
}

int test_functions()
{
    int i,e;

    FLOATING_POINT **mat1 = MatrixGen("1 2 3, 4 5 6, 7 8 9", 3, 3, 1);
    FLOATING_POINT **mat2 = MatrixGen("1 0 0, 0 0 1, 0 1 0", 3, 3, 1);

    PrintMat(mat1, 3, 3);
    print("\n");
    PrintMat(mat2, 3, 3);

    print("\n");
    PrintMat(MatrixMult(mat2, 3, 3, mat1, 3, 3, 1), 3, 3);

    return 0;
}