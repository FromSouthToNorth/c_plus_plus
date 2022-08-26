//
// Created by bw on 2022/8/26.
//
#include <vector>
#include <iostream>

class Sorting {
    int partition(int nums[], int lo, int hi) {
        int i = lo, j = hi + 1;
        int t = nums[lo];
        while (true) {
            while (nums[++i] < t) {
                if (i == hi) {
                    break;
                }
            }
            while (t < nums[--j]) {
                if (j == lo) {
                    break;
                }
            }
            if (i >= j) {
                break;
            }
            int tem = nums[i];
            nums[i] = nums[j];
            nums[j] = tem;
        }
        int tem = nums[lo];
        nums[lo] = nums[j];
        nums[j] = tem;
        return j;
    }

    void sort(int nums[], int lo, int hi) {
        if (lo < hi) {
            int j = partition(nums, lo, hi);
            sort(nums, lo, j-1);
            sort(nums, j+1, hi);
        }
    }

public:
    void sort(int nums[], int n) {
        sort(nums, 0, n);
    }
};

int main() {
    int nums[] = {2,1, 4,3,4,3};
    Sorting sorting;
    sorting.sort(nums, 5);
    for (int num : nums) {
        std::cout << num << " ";
    }
    return 0;
}