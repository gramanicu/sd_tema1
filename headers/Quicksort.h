// Copyright Grama Nicolae 2019
#ifndef HEADERS_QUICKSORT_H_
#define HEADERS_QUICKSORT_H_

#include <stdint.h>
#include <iostream>

// Quicksort function - explained in Readme in more detail
template <typename T>
void Quicksort(T *array, bool (*compare)(const T &first, const T &second),
               int32_t size, int32_t start = 0, int32_t end = 0) {
  if (end == 0) {
    end = size - 1;
  }

  int32_t pivot = end;
  int32_t i = start;

  // Partitioning
  while (i <= pivot) {
    // If the i element is lower than the pivot
    if (compare(array[i], array[pivot])) {
      T aux = array[pivot];
      array[pivot] = array[pivot - 1];
      array[pivot - 1] = aux;

      if (i + 1 != pivot) {
        aux = array[i];
        array[i] = array[pivot];
        array[pivot] = aux;
      }
      pivot--;
    } else {
      i++;
    }
  }

  // Recursive calls
  if (pivot - 1 > 0) {
    Quicksort(array, compare, size, start, pivot - 1);
  }
  if (pivot + 1 < end) {
    Quicksort(array, compare, size, pivot + 1, end);
  }
}

#endif  // HEADERS_QUICKSORT_H_
