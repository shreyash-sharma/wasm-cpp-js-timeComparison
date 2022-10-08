#include <iostream>
#include <array>
#include <chrono>
#include <iterator>
#include <numeric>
#include <vector>
#include <algorithm>


void insertionSort(std::array<int, 100'000>& arr, int size) {
    int i, j, temp;
    for (i = 1; i < size; i++) {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
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
        insertionSort(nums, 100'000);
        milliseconds later = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
        times.push_back(duration_cast<milliseconds>(later - now).count());
    }
    std::cout << std::accumulate(times.begin(), times.end(), 0.0) / times.size() << "\n";

    return 0;
}