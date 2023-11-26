#ifndef MATRIX_OPERATIONS_H_INCLUDED
#define MATRIX_OPERATIONS_H_INCLUDED

void* allocate_matrix(int rows, int cols, int element_size);
void deallocate_matrix(void* matrix, int rows);
void input_int_matrix(void* matrix, int rows, int cols);
void input_double_matrix(void* matrix, int rows, int cols);
void print_int_matrix(void* matrix, int rows, int cols);
void print_double_matrix(void* matrix, int rows, int cols, int precision);

#endif // MATRIX_OPERATIONS_H_INCLUDED
