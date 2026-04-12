#ifndef ALGORITHMSTATIC_H
#define ALGORITHMSTATIC_H

#include <vector>

class algorithmStatic {
public:
    static void BubbleSort(std::vector<int>& arr);
    static void SelectionSort(std::vector<int>& arr);
    static void InsertionSort(std::vector<int>& arr);
    static void ShellSort(std::vector<int>& arr);
    static void MergeSort(std::vector<int>& arr);
    static void HeapSort(std::vector<int>& arr);
    static void QuickSort(std::vector<int>& arr);
};

#endif