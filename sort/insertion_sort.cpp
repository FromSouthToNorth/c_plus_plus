#include <algorithm>
#include <cassert>
#include <vector>
#include <iostream>

namespace sort {
  template <typename T>
  void insertionSort(T *arr, int n) {
    for (int i = 0; i < n; i++) {
      int j = i;
      while (j >= 1 && arr[j] < arr[j - 1]) {
        T temp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = temp;
        j--;
      }
    }
  }

  template <typename T>
  void insertionSort(std::vector<T> *arr) {
    size_t n = arr->size();

    for (size_t i = 0; i < n; i++) {
      int32_t j = i;
      while (j >= 1 && arr[0][j] < arr[0][j - 1]) {
        T temp = arr[0][j];
        arr[0][j] = arr[0][j - 1];
        arr[0][j - 1] = temp;
        j--;
      }
    }
  }
}

/**
*@brief 创建随机数组 objecthelper 函数创建随机数组
*
*@tparam T 类型的数组
*@param arr 要填充的数组（必须预先分配）
*@param N 个数组元素
*/
template <typename T>
static void create_random_array(T *arr, int N) {
  while (N--) {
    double r = (std::rand() % 10000 - 5000) / 100.f;
    arr[N] = static_cast<T>(r);
  }
}

void tests() {
  int arr1[10] = { 89, 78, 39, 40, 45, 12, 789, 11, -2, 9 };
  std::cout << "Test 1... ";
  sort::insertionSort(arr1, 10);
  assert(std::is_sorted(arr1, arr1 + 10));
  std::cout << "passed" << std::endl;

  int arr2[5] = { 7, 5, 2, 10, 8 };
  std::cout << "Test 2... ";
  sort::insertionSort(arr2, 5);
  assert(std::is_sorted(arr2, arr2 + 5));
  std::cout << "passed" << std::endl;
  
  float arr3[5] = { 9.1, 0.08, 10.2, -9, 1.2 };
  std::cout << "Test 3... ";
  sort::insertionSort(arr3, 5);
  assert(std::is_sorted(arr3, arr3 + 5));
  std::cout << "passed" << std::endl;

  std::vector<float> arr4({5.6, -3.1, -3.0, -2.1, 1.8});
  std::cout << "Test 4... ";
  sort::insertionSort(&arr4);
  assert(std::is_sorted(std::begin(arr4), std::end(arr4)));
  std::cout << "passed" << std::endl;


  int arr5[50];
  std::cout << "Test 5... ";
  create_random_array(arr5, 50);
  sort::insertionSort(arr5, 50);
  assert(std::is_sorted(arr5, arr5 + 50));
  std::cout << "passed" << std::endl;

  float arr6[50];
  std::cout << "Test 6... ";
  create_random_array(arr6, 50);
  sort::insertionSort(arr6, 50);
  assert(std::is_sorted(arr6, arr6 + 50));
  std::cout << "passed" << std::endl;
}

/** Main Function */
int main() {

  // 运行预定义的测试来测试算法
  tests();
  
  size_t n;
  std::cout << "输入数组的长度(输入 0 exit):";
  std::cin >> n;
  if (n == 0) {
    return 0;
  }

  int *arr = new int[n];
  std::cout << "开始输入 " << n << "无序数组的数字: "; 

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  sort::insertionSort(arr, n);

  std::cout << "\nSorted Array : ";
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

  std::cout << std::endl;
  delete[] arr;
  return 0;
}
