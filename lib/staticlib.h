#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

// Очистка потока ввода
void clearInputBuffer();

// Ввод последовательности int
int inputIntArray(int *array, int size);

// Ввод последовательности double
int inputDoubleArray(double *array, int size);

// Вывод int массива в виде непрерывной последовательности
void printIntArray(int *array, int size);

// Вывод int массива в виде таблицы
void printIntArrayTable(int *array, int size, int elementsPerRow);

// Вывод double массива в виде непрерывной последовательности
void printDoubleArray(double *array, int size);

// Вывод double массива в виде таблицы
void printDoubleArrayTable(double *array, int size, int elementsPerRow);

#endif // HEAD_H_INCLUDED
