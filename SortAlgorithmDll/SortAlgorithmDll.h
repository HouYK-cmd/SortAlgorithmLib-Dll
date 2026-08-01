#ifndef ALGORITHMDYNAMIC_H
#define ALGORITHMDYNAMIC_H

#include <vector>

// ⭐ 修改：宏名改为项目名的大写形式
#ifdef ALGORITHMDYNAMICDLL_EXPORTS
#define ALGORITHM_API __declspec(dllexport)  // 导出：给 DLL 自己用
#else
#define ALGORITHM_API __declspec(dllimport)  // 导入：给测试程序用
#endif

class ALGORITHM_API algorithmDynamic {
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
