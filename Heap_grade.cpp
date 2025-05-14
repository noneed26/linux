#include <iostream>
using namespace std;

class MaxHeap
{
private:
    double grades[100];
    string names[100];
    int size;

    void percolateDown(int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && grades[left] > grades[largest])
            largest = left;
        if (right < size && grades[right] > grades[largest])
            largest = right;

        if (largest != i)
        {
            swap(grades[i], grades[largest]);
            swap(names[i], names[largest]);
            percolateDown(largest);
        }
    }

public:
    MaxHeap()
    {
        size = 0;
    }

    void push(double grade, string name)
    {
        grades[size] = grade;
        names[size] = name;
        int i = size;
        size++;

        while (i > 0 && grades[(i - 1) / 2] < grades[i])
        {
            swap(grades[i], grades[(i - 1) / 2]);
            swap(names[i], names[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void pop()
    {
        if (size == 0)
            return;

        swap(grades[0], grades[size - 1]);
        swap(names[0], names[size - 1]);
        size--;
        percolateDown(0);
    }

    string topName() { return names[0]; }
    double topGrade() { return grades[0]; }
};

// Separate heapify function for sorting
void heapify(double grades[], string names[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && grades[left] > grades[largest])
        largest = left;
    if (right < n && grades[right] > grades[largest])
        largest = right;

    if (largest != i)
    {
        swap(grades[i], grades[largest]);
        swap(names[i], names[largest]);
        heapify(grades, names, n, largest);
    }
}

// Standard heap sort
void heapSort(double grades[], string names[], int n)
{
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(grades, names, n, i);

    // Extract elements from heap
    for (int i = n - 1; i > 0; i--)
    {
        swap(grades[0], grades[i]);
        swap(names[0], names[i]);
        heapify(grades, names, i, 0);
    }
}

void getInput(int &n, MaxHeap &heap, double grades[], string names[])
{
    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cout << "Enter student name: ";
        getline(cin, names[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Enter grade for " << names[i] << ": ";
        cin >> grades[i];
        heap.push(grades[i], names[i]);
    }
}

void displayTopper(MaxHeap &heap)
{
    cout << "\nTopper student for internship: " << heap.topName()
         << " with grade " << heap.topGrade() << "\n";
    heap.pop();
}

void displaySorted(double grades[], string names[], int n)
{
    heapSort(grades, names, n);
    cout << "\nStudents sorted by grades (ascending):\n";
    for (int i = 0; i < n; i++)
    {
        cout << names[i] << " " << grades[i] << "\n";
    }
}

int main()
{
    int n;
    MaxHeap heap;
    double grades[100];
    string names[100];

    getInput(n, heap, grades, names);
    displayTopper(heap);
    displaySorted(grades, names, n);

    return 0;
}
