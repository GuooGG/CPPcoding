#include <vector>
class Sort
{
public:
    bool isSorted(std::vector<int> &vec);
    void bubbleSort(std::vector<int> &vec);
    void selectionSort(std::vector<int> &vec);
    void insertionSort(std::vector<int> &vec);
    void shellSort(std::vector<int> &vec);
    void mergeSort(std::vector<int> &vec);
    void quickSort(std::vector<int> &vec);
    void heapSort(std::vector<int> &vec);

private:
    void merge_sort(std::vector<int> &vec, std::vector<int> &tmp, int left, int right);
};
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

void Sort::insertionSort(std::vector<int>& vec)
{
    int n = vec.size();
    for (int i = 1; i < n; i++) {
        int temp = vec[i];
        int j;
        for (j = i - 1; j >= 0; j--) {
            if (vec[j] > temp) {
                vec[j + 1] = vec[j];
            }
            else {
                break;
            }
        }
        vec[j + 1] = temp;
    }

}

void Sort::shellSort(std::vector<int>& vec)
{
    int n = vec.size();
    int h = 1;
    while (h < n / 3) {
        h = 3 * h + 1;
    }
    while (h >= 1) {
        for (int i = h; i < n; i++) {
            int temp = vec[i];
            int j;
            for (j = i; j >= h && vec[j - h] > temp; j -= h) {
                vec[j] = vec[j - h];
            }
            vec[j] = temp;
        }
        h /= 3;
    }
}

void Sort::mergeSort(std::vector<int>& vec)
{
    int n = vec.size();
    std::vector<int> tmp(n);
    merge_sort(vec, tmp, 0, n);
}

void Sort::merge_sort(std::vector<int>& vec,std::vector<int>& tmp, int left, int right)
{
    if (left >= right) {
        return;
    }
    int mid = (right - left) >> 1 + left;
    merge_sort(vec, tmp, left, mid);
    merge_sort(vec, tmp, mid + 1, right);
    //¹é²¢
    int i = left;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right) {
        if (vec[i] <= vec[j]) {
            tmp[k++] = vec[i++];
        }
        else {
            tmp[k++] = vec[j++];
        }
    }
    while (i <= mid) {
        tmp[k++] = vec[i++];
    }
    while (j <= right)
    {
        tmp[k++] = vec[j++];
    }
    for (int p = 0; p < k; p++) {
        vec[left + p] = tmp[p];
    }
}

