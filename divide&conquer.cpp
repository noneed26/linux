#include <iostream>
using namespace std;
class dnc // Divide and conquer
{
public:
    void findMinMax(int *arr, int &min, int &max, int left, int right)
    {
        if (left == right)
        {
            min = max = arr[left];
            return;
        }
        if (right - left == 1)
        {
            if (arr[left] < arr[right])
            {
                min = arr[left];
                max = arr[right];
            }
            else
            {
                min = arr[right];
                max = arr[left];
            }
            return;
        }
        int mid = (left + right) / 2;
        int min1, max1, min2, max2;
        findMinMax(arr, min1, max1, left, mid);
        findMinMax(arr, min2, max2, mid + 1, right);
        min = (min1 < min2) ? min1 : min2;
        max = (max1 > max2) ? max1 : max2;
    }
};
int main()
{
    int size;
    cout << "Enter number of elements in array: \n";
    cin >> size;
    int arr[size];
    cout << "Enter elements in array: \n";
    for (int i = 0; i < size; i++)
    {
        cout << "index " << i << " :";
        cin >> arr[i];
    }
    dnc ob;
    int min, max;
    ob.findMinMax(arr, min, max, 0, size - 1);
    cout << "Minimum element: " << min << endl;
    cout << "Maximum element: " << max << endl;
    return 0;
}