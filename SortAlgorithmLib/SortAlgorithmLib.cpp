// BubbleSortLib1.cpp : 定义静态库的函数。
#include "pch.h"
#include "framework.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include "SortAlgorithmLib.h"
using namespace std;

// ==================== 1. 冒泡排序 ====================
// 时间复杂度：O(n²)  空间复杂度：O(1)  稳定
void algorithmStatic::BubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// ==================== 2. 选择排序 ====================
// 时间复杂度：O(n²)  空间复杂度：O(1)  不稳定
void algorithmStatic::SelectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            std::swap(arr[i], arr[minIdx]);
        }
    }
}

// ==================== 3. 插入排序 ====================
// 时间复杂度：O(n²)  空间复杂度：O(1)  稳定
void algorithmStatic::InsertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// ==================== 4. 希尔排序 ====================
// 时间复杂度：O(n log n) ~ O(n²)  空间复杂度：O(1)  不稳定
void algorithmStatic::ShellSort(vector<int>& arr) {
    int n = arr.size();
    // 使用 Hibbard 增量序列：1, 3, 7, 15, ...
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

// ==================== 5. 归并排序 ====================
// 时间复杂度：O(n log n)  空间复杂度：O(n)  稳定
void Merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeAlgorithm(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeAlgorithm(arr, left, mid);
    mergeAlgorithm(arr, mid + 1, right);
    Merge(arr, left, mid, right);
}

void algorithmStatic::MergeSort(vector<int>& arr) {
    mergeAlgorithm(arr, 0, arr.size() - 1);
}

// ==================== 6. 快速排序 ====================
// 时间复杂度：平均 O(n log n)，最坏 O(n²)  空间复杂度：O(log n)  不稳定
int Partition(vector<int>& arr, int low, int high) {
    // 三数取中法优化，避免最坏情况
    int mid = low + (high - low) / 2;
    if (arr[mid] < arr[low]) swap(arr[low], arr[mid]);
    if (arr[high] < arr[low]) swap(arr[low], arr[high]);
    if (arr[high] < arr[mid]) swap(arr[mid], arr[high]);
    swap(arr[mid], arr[high]);  // 将中位数作为基准放到末尾

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void QuickAlgorithm(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = Partition(arr, low, high);
        QuickAlgorithm(arr, low, pi - 1);
        QuickAlgorithm(arr, pi + 1, high);
    }
}

void algorithmStatic::QuickSort(vector<int>& arr) {
    QuickAlgorithm(arr, 0, arr.size() - 1);
}

// ==================== 7. 堆排序 ====================
// 时间复杂度：O(n log n)  空间复杂度：O(1)  不稳定
void Heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}

void algorithmStatic::HeapSort(vector<int>& arr) {
    int n = arr.size();

    // 建堆
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);

    // 依次取出堆顶元素
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        Heapify(arr, i, 0);
    }
}