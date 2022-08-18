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

    void insert(const uint64_t &val) {
      if (top == 49) {
        std::cout << "\nOverflow";
        return;
      }
      if (!isSorted) {
        data[top] = val;
        top++;
      } 
      else {
        uint64_t pos = 0;
        for (uint64_t i = 0; i < top - 1; i++) {
          if (data[i] <= val && val <= data[i + 1]) {
            pos = i + 1;
            break;
          }
        }
        if (pos == 0) {
          pos = top - 1;
        }
        for (uint64_t i = top; i > pos; i--) {
          data[i] = data[i - 1];
        }
        top++;
        data[pos] = val;
      }
    }
    void remove(const uint64_t &val) {
      uint64_t pos = search(val);
      if (pos == -1) {
        std::cout << "\n Element does not present in the list";
        return;
      }
      std::cout << "\n" << data[pos] << " deleted";
      for (uint64_t i = pos; i < top; i++) {
        data[i] = data[i + 1];
      }
      top--;
    }
    void show() {
      std::cout << "\n";
      for (uint64_t i = 0; i < top; i++) {
        std::cout << data[i] << " ";
      }
    }
  };
}
  
}

static void test() {
  data_structures::array_list::list L;
  L.insert(1);
  L.insert(2);
  L.insert(3);
  L.insert(4);
  L.insert(3);
  L.insert(3);
  L.insert(5);
  L.show();
  
  L.remove(3);
  L.show();
  L.sort();
  L.show();
}

int main() {
  test();
  return 0;
}
