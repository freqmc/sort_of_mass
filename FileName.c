#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>

double* full_elems_random(double* ptr_array, int size) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		double x = rand() % 100;
		ptr_array[i] = -1 + rand() % 2 + x / 100;
	}
	return ptr_array;
}

double* full_elems(double* ptr_array, int size) {
	double y = 0;
	double z = 2.1 / size;
	for (int i = 0; i < size; i++) {
		y += z;
		ptr_array[i] = pow(y, 2) - pow(cos(y + 1), 2);
	}
	return ptr_array;
}

int put_elems(double* ptr_array, int size) {
	for (int i = 0; i < size; i++) {
		printf("a[%d] = %.2lf\n", i, ptr_array[i]);
	}
	printf("\n");
}

int delete_k(double* ptr_arr, int size, int k) {
	for (int i = k; i < size; i++) {
		ptr_arr[i] = ptr_arr[i + 1];
	}
	--size;
	return size;
}

double* insert(double* ptr_arr, int* size, int index, double num) {
	int size_n = (*size) + 1;
	if (ptr_arr == NULL) return NULL;
	double* ptr_arr_n = (double*)realloc(ptr_arr, size_n * sizeof(double));
	if (ptr_arr_n == NULL) return ptr_arr;
	ptr_arr = ptr_arr_n;
	for (int i = size_n - 1; i > index; i--) {
		ptr_arr[i] = ptr_arr[i - 1];
	}
	ptr_arr[index] = num;
	*size = size_n;
	return ptr_arr;
}

void sort_buble(double* ptrarr, int n) {
	double temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (ptrarr[j] > ptrarr[j + 1]) {
				temp = ptrarr[i];
				ptrarr[i] = ptrarr[j];
				ptrarr[j] = temp;
			}
		}
	}
}

void sort_select(double* ptrarr, int n) {
	for (int i = 0; i < n - 1; i++) {
		int imax = i;
		for (int j = i + 1; j < n; j++) {
			if (ptrarr[j] > ptrarr[imax]) {
				imax = j;
			}
		}
		double temp = ptrarr[imax];
		ptrarr[imax] = ptrarr[i];
		ptrarr[i] = temp;
	}
}

double* rand_double(double* ptrarr, double dmin, double dmax, int n){
	for (int i = 0; i < n; i++) {
		ptrarr[i] = dmin + 1.f * (dmax - dmin) * rand() / RAND_MAX;
	}
	return ptrarr;
}

void sort_insert(double* ptrarr, int n) {
	for (int i = 1; i < n; i++) {
		double temp = ptrarr[i];
		int j = i;

		while ((j >= 0) && (ptrarr[j] > temp)) {
			ptrarr[j] = ptrarr[j-1];
			j = j - 1;
		}

		ptrarr[j] = temp;
	}
}

double* calc_elements(double* ptr_array, int n)
{
	double temp = 0.0;
	for (int i = 0; i < n; i++) {
		temp = ptr_array[i];
		ptr_array[i] = pow(ptr_array[i], 2);
	}
	return ptr_array;
}

int main() {
	double* ptr_array;
	int size, k;

	setlocale(LC_CTYPE, "RUS");

	printf("¬ведите размер массива\n");
	scanf("%d", &size);
	getchar();
	ptr_array = (double*)malloc(size * sizeof(double));
	if (ptr_array == NULL) {
		puts("Error");
		return -1;
	}
	//full_elems(ptr_array, size);
	//rand_double(ptr_array, 12.23, 32.75, size);
	calc_elements(ptr_array, size);
	//put_elems(ptr_array, size);
	clock_t t = clock();
	sort_select(ptr_array, size);

	double time = (clock() - t) * 1. / CLOCKS_PER_SEC;
	printf("%lf\n", time);
	//put_elems(ptr_array, size);
	free(ptr_array);
}