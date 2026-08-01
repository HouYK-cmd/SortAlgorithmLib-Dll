#include <iostream>
#include <vector>
#include <windows.h>  // 包含 Windows API 头文件
#include "SortAlgorithmLib.h"  // 引用头文件
using namespace std;

int main() {
    // 设置控制台为 UTF-8 代码页
    //SetConsoleOutputCP(CP_UTF8);
    //SetConsoleOutputCP(936);  // 或者使用系统默认：GBK
    vector<int> arr = { 64, 34, 25, 12, 22, 11, 90 };

    cout << "排序前: ";
    for (int val : arr) cout << val << " ";
    cout << endl;

    //algorithmStatic::BubbleSort(arr);
    //algorithmStatic::SelectionSort(arr);
    //algorithmStatic::InsertionSort(arr);
    //algorithmStatic::ShellSort(arr);
    //algorithmStatic::MergeSort(arr);
    algorithmStatic::QuickSort(arr);
    //algorithmStatic::HeapSort(arr);

    cout << "排序后: ";
    for (int val : arr) cout << val << " ";
    cout << endl;

    return 0;
}