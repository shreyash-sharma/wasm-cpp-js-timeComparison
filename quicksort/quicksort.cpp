#include <iostream>
#include <array>
#include <chrono>
#include <iterator>
#include <numeric>
#include <vector>
#include <algorithm>

void quickSort(std::array<int, 100'000>& arr, int left, int right)
{
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    /* partition */
    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
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
        quickSort(nums, 0, 100'000-1);
        milliseconds later = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
        times.push_back(duration_cast<milliseconds>(later - now).count());
    }
    std::cout << std::accumulate(times.begin(), times.end(), 0.0) / times.size() << "\n";

    return 0;
}