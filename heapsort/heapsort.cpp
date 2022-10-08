#include <iostream>
#include <array>
#include <chrono>
#include <iterator>
#include <numeric>
#include <vector>
#include <algorithm>

void swap(std::array<int, 100'000>& arr, int *g, int *b) {
    int temp;
    temp = arr[*g];
    arr[*g] = arr[*b];
    arr[*b] = temp;
}

void maxHeapify(std::array<int, 100'000>& arr, int parent, int last) {
    int child;
    child = 2 * parent;
    while (child <= last) {
        if ((child + 1 <= last) && (arr[child + 1] > arr[child]))
            child++;
        if (arr[parent] < arr[child])
            swap(arr, &parent, &child);
        parent = child;
        child = 2 * parent;
    }
}

void buildHeap(std::array<int, 100'000>& arr, int last) {
    int i;
    for (i = last / 2; i > 0; i--) {
        maxHeapify(arr, i, last);
    }
}

void heapSort(std::array<int, 100'000>& arr, int last) {
    int l;
    l = 1;
    buildHeap(arr, last);
    while (last > 1) {
        swap(arr, &l, &last);
        last--;
        maxHeapify(arr, 1, last);
    }
}

using namespace std::chrono;
int main()
{
    std::vector<double> times;
    std::array<int, 100'000> nums;

    for (int i = 0; i < 1'000; i++)
    {
        std::generate(nums.begin(), nums.end(), &rand);
        milliseconds now = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
        heapSort(nums, 100'000);
        milliseconds later = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
        times.push_back(duration_cast<milliseconds>(later - now).count());
    }
    std::cout << std::accumulate(times.begin(), times.end(), 0.0) / times.size() << "\n";

    return 0;
}