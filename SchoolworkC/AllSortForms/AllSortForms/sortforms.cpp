#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

// 直接插入排序
void insertionSort(vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// 简单选择排序
void selectionSort(vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// 冒泡排序
void bubbleSort(vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 快速排序
void quickSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int pivot = arr[left];
    int i = left, j = right;
    while (i < j) {
        while (i < j && arr[j] >= pivot) --j;
        arr[i] = arr[j];
        while (i < j && arr[i] <= pivot) ++i;
        arr[j] = arr[i];
    }
    arr[i] = pivot;
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}

// 堆排序
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// 希尔排序
void shellSort(vector<int>& arr) {
    for (int gap = arr.size() / 2; gap > 0; gap /= 2) {
        for (size_t i = gap; i < arr.size(); ++i) {
            int temp = arr[i];
            size_t j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

// 计时并调用排序函数
template <typename Func>
void testSort(const string& name, Func sortFunc, vector<int> arr, vector<int>& result) {
    auto start = high_resolution_clock::now();
    sortFunc(arr);
    auto end = high_resolution_clock::now();
    cout << name << " 耗时: "
        << duration_cast<microseconds>(end - start).count()
        << " 微秒" << endl;

    // 保存排序结果
    result = arr;
}

// 打印数组
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// 主函数
int main() {
    // 随机生成30个整数
    srand(time(0));
    vector<int> arr(30);
    for (int& num : arr) {
        num = rand() % 100; // 生成范围在0-99的随机数
    }

    cout << "原始数组: ";
    printArray(arr);

    vector<int> result;

    // 测试不同排序算法并记录排序结果
    testSort("直接插入排序", insertionSort, arr, result);
    testSort("简单选择排序", selectionSort, arr, result);
    testSort("冒泡排序", bubbleSort, arr, result);
    testSort("快速排序", [&](vector<int>& a) { quickSort(a, 0, a.size() - 1); }, arr, result);
    testSort("堆排序", heapSort, arr, result);
    testSort("希尔排序", shellSort, arr, result);

    // 输出排序后的数组
    cout << "\n排序后的数组: ";
    printArray(result);

    return 0;
}
