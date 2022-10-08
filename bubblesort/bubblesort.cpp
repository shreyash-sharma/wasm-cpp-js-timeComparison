#include <iostream>
#include <array>
#include <chrono>
#include <iterator>
#include <numeric>
#include <vector>
#include <algorithm>

void bubbleSort(std::array<int, 100'000>& arr, int size) {
    int temp;
    int i, j;

    for (i = 1; i < size; i++) {
        for (j = 0; j < size - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
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
        bubbleSort(nums, 100'000);
        milliseconds later = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
        times.push_back(duration_cast<milliseconds>(later - now).count());
    }
    std::cout << std::accumulate(times.begin(), times.end(), 0.0) / times.size() << "\n";

    return 0;
}