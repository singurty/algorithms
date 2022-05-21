#include "sort.h"
#include <stdio.h>

void sort(int s[], int length) {
	merge_sort(s, 0, length - 1);
}