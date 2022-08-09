#include <array>
#include <iostream>
#include <cassert>

namespace data_structures {

namespace array_list {

  struct list {
    std::array<uint64_t, 50> data{}; 
    uint64_t top = 0;
    bool isSorted = false;

    /**
     * @brief 二分查找
     * 
     * @param dataArr 
     * @param first 
     * @param last 
     * @param val 
     * @return uint16_t 
     */
    uint16_t BinarySearch(const std::array<uint64_t, 50> &dataArr, const uint64_t &first, const uint64_t &last, 
                          const uint64_t &val) {
      if (last < first) {
        return -1;
      }
      uint64_t mid = (first + last) / 2;
      uint64_t midVal = dataArr[mid];
      if (midVal == val) {
        return mid;
      }
      else if (val < midVal) {
        return BinarySearch(dataArr, first, mid - 1, val);
      }
      else if (val > midVal) {
        return BinarySearch(dataArr, mid + 1, last, val);
      }
      std::cerr << __func__ << ":" << __LINE__ << ": Undefined condition \n";
      return -1;
    }

    uint64_t LinearSearch(const std::array<uint64_t, 50> &dataArr, const uint64_t &val) const {
      for (uint64_t i = 0; i < top; i++) {
        if (dataArr[i] == val) {
          return i;
        }
      }

      return -1;
    }

    uint64_t search(const uint64_t &val) {
      uint64_t pos;
      if (isSorted) {
        pos = BinarySearch(data, 0, top - 1, val);
      }
      else {
        pos = LinearSearch(data, val);
      }
      if (pos != -1) {
        std::cout << "\n Element found at position: " << pos;
      }
      else {
        std::cout << "\n Element ont found";
      }

      return pos;
    }

    void sort() {
      for (uint64_t i = 0; i < top; i++) {
        uint64_t min = i;
        for (uint64_t j = 0; j < top; j++) {
          if (data[j] < data[min]) {
            min = j;
          }
        }
        std::swap(data[min], data[i]);
      }
      isSorted = true;
    }
  };
  
}
  
}
