#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &heap, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] > heap[largest]) largest = left;

    if (right < n && heap[right] > heap[largest]) largest = right;

    if (largest != i)
    {
        swap(heap[i], heap[largest]);
        heapify(heap, n, largest);
    }
}

void insert(vector<int> &heap, int value)
{
    heap.push_back(value);
    int i = heap.size() - 1;

    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (heap[i] > heap[parent])
        {
            swap(heap[i], heap[parent]);
            i = parent;
        }
        else
        {
            break;
        }
    }
}

void buildHeap(vector<int> &heap)
{
    int n = heap.size();

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(heap, n, i);
    }
}

void heapSort(vector<int> &heap)
{
    int n = heap.size();

    buildHeap(heap);

    for (int i = n - 1; i > 0; i--)
    {
        swap(heap[0], heap[i]);
        heapify(heap, i, 0);
    }
}

int main()
{
    vector<int> heap = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    for (int num : heap)
    {
        cout << num << " ";
    }
    cout << endl;

    heapSort(heap);

    cout << "Sorted array: ";
    for (int num : heap)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}



