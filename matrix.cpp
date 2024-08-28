#include<stdio.h>
#include<assert.h>
#include<math.h>
#include<stdlib.h>

void skipLine(void);

int* getMatrix(int*, int*);
int multiplicationMatrix(int*, int*, int, int, int, int);

const int winEOF = 26;


int main(void)
{
    int* matrix_one = NULL; // TODO: null_ptr
    int* matrix_two = NULL;
    int size_x_one = 0;
    int size_y_one = 0;
    int size_x_two = 0;
    int size_y_two = 0;

    matrix_one = getMatrix(&size_x_one, &size_y_one);
    matrix_two = getMatrix(&size_x_two, &size_y_two);

    assert(matrix_one != NULL);
    assert(matrix_two != NULL);
    assert(matrix_one != matrix_two);

    multiplicationMatrix(matrix_one, matrix_two, size_x_one, size_y_one, size_x_two, size_y_two);

    return 0;
}


void skipLine(void)
{
        int ch = 0;
        while (((ch = getchar()) != '\n') && (ch != winEOF) && (ch != EOF));
}

int* getMatrix(int* size_x_return, int* size_y_return)
{
    int size_x = NAN, size_y = NAN, check_error = 0;

    do
    {
        printf("Enter the number of rows and columns of the matrix: ");
        check_error = scanf("%d %d", &size_y, &size_x);
        skipLine();
    } while (check_error != 2);

    assert(isfinite(size_x));
    assert(isfinite(size_y));

    *size_x_return = size_x;
    *size_y_return = size_y;

    int* adr = (int*) calloc(size_x * size_y, sizeof(int));
    if (adr == NULL)
    {
        fprintf(stderr, "ERROR: Not enough memory\n");
        return 0;
    }

    for(int i = 0; i < size_y; i++)
    {
        printf("Enter the row of the matrix #%d\n", i + 1); // TODO: в функцию
        for(int j = 0; j < size_x; j++)
        {
            do
            {
            printf("Enter a line item #%d\n", j + 1);
            check_error = scanf("%d", (adr + i * size_x + j));
            skipLine();
            } while (check_error != 1);
        }
    }

    for(int i = 0; i < size_y; i++) // TODO: в функцию
    {
        for(int j = 0; j < size_x; j++)
        {
            printf("%5.d ", *(adr + size_x * i + j));
        }
        printf("\n");
    }
    return (adr);
}

int multiplicationMatrix(int* mtrx_one, int* mtrx_two, int size_x_one, int size_y_one, int size_x_two, int size_y_two)
{

    if (size_x_one != size_y_two)
    {
        printf("Unsuitable matrix size");
        return 0;
    }

    int* adr = (int*) calloc(size_x_two * size_y_one, sizeof(int)); // TODO:  дерьмозвание

    for(int i = 0; i < size_y_one; i++)
    {
        for(int j = 0; j < size_x_two; j++)
        {
            int qwerty = 0; // TODO: название
            for(int r = 0; r < size_y_two; r++)
            {
                qwerty = qwerty + ((*(mtrx_one + r + (i * size_x_one))) * (*(mtrx_two + (r * size_x_two) + j)));
            }

            *(adr + i * size_y_one + j) = qwerty;
        }
    }

    printf ("y_one == %d\nx_two == %d\n", size_y_one, size_x_two);
    for(int i = 0; i < size_y_one; i++)
    {
        for(int j = 0; j < size_x_two; j++)
        {
            printf("%5.d ", *(adr + size_x_two * i + j));
        }
        printf("\n");
    }
    return 0;
}
