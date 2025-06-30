#ifndef DISCORDIA_H
#define DISCORDIA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pixel {
    long int id;
    int red;
    int green;
    int blue;
    int desencript;
} pix_t;

// dis_reader.c
pix_t *leer_dis(const char *filename, int *cols, int *rows);

// sorter.c
void insertion_sort(pix_t *arr, int n);
void merge_sort(pix_t *arr, int l, int r);
void counting_sort(pix_t *arr, int n);

// ppm_writer.c
void guardar_ppm(const char *nombre_salida, pix_t *pixeles, int cols, int rows, float porcentaje);

#endif
