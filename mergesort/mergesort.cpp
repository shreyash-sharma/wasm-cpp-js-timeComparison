#include <iostream>
#include <array>
#include <chrono>
#include <iterator>
#include <numeric>
#include <vector>
#include <algorithm>

void merge(std::array<int, 100'000>& arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(std::array<int, 100'000>& InputArr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; 
        mergeSort(InputArr, l, m);
        mergeSort(InputArr, m + 1, r);
        merge(InputArr, l, m, r);
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
        mergeSort(nums, 0, 100'000-1);
        milliseconds later = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
        times.push_back(duration_cast<milliseconds>(later - now).count());
    }
    std::cout << std::accumulate(times.begin(), times.end(), 0.0) / times.size() << "\n";

    return 0;
}