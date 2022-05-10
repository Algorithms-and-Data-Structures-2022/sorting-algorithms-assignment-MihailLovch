#include "assignment/quick_sort.hpp"

#include <cassert>  // assert

#include "assignment/partitioning.hpp"  // partition, median_of_three

namespace assignment {

  void QuickSort::Sort(std::vector<int>& arr) const {
    quick_sort(arr, 0, static_cast<int>(arr.size()) - 1);
  }

  void QuickSort::quick_sort(std::vector<int>& arr, int start, int stop) const {
    assert(start >= 0);

    if (start >= stop) {
      return;
    }

    // вычисляем индекс опорного элемента ... median_of_three ...
    /* напишите здесь свой код ... */
    int pivot_index = median_of_three(arr,start,stop);
    // производим разбиение относительно опорного элемента ...  partition ...
    int border = partition(arr,start,stop,pivot_index);
    // рекурсивно повторяем процедуру над левой и правой частью ...
    quick_sort(arr,start,border-1);
    quick_sort(arr,border + 1,stop);
  }

}  // namespace assignment
