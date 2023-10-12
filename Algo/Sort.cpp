#include "Sort.h"

bool Sort::isSorted(std::vector<int>& vec)
{
    int n = vec.size();
    if (n == 1) {
        return true;
    }
    for (int i = 1; i < n; i++) {
        if (vec[i] > vec[i - 1]) {
            return false;
        }
    }
    return true;
}

void Sort::bubbleSort(std::vector<int>& vec)
{
    int n = vec.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

void Sort::selectionSort(std::vector<int>& vec)
{
    int n = vec.size();
    int min_index = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vec[min_index] > vec[j]) {
                min_index = j;
            }
        }
        std::swap(vec[min_index], vec[i]);
    }
}
