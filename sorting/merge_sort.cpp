#include <iostream>

void merge(int *arr, int *aux, int l, int mid, int r) {
  for (int k = l; k <= r; k++) {
    aux[k] = arr[k];
  }

  int i = l, j = mid + 1;

  for (int k = l; k <= r; k++) {
    if (i > mid) {
      arr[k] = aux[j++];
    }
    else if (j > r) {
      arr[k] = aux[i++];
    }
    else if (aux[i] > aux[j]) {
      arr[k] = aux[j++];
    }
    else {
      arr[k] = aux[i++];
    }
  }
}

void sort(int *arr, int n) {
  int *aux = new int[n];
  for (int len = 1; len < n; len *= 2) {
    for (int lo = 0; lo < n - len; lo += len + len) {
      int mid = lo + len - 1;
      int r = lo + len + len - 1 > n - 1 ? n - 1 : lo + len + len - 1;
      merge(arr, aux, lo, mid, r);
    }
  }
}

void show(int *arr, int size) {
    for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
    std::cout << "\n";
}

int main () {
  int size;
  std::cout << "Enter the number of elements : ";
  std::cin >> size;
  int *arr = new int[size];
  std::cout << "Enter the unsorted elements : ";
  for (int i = 0; i < size; ++i) {
      std::cin >> arr[i];
  }
  sort(arr, size);
  std::cout << "Sorted array : ";
  show(arr, size);
  delete[] arr;
  return 0;
}
