#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;
// Function to perform Bubble Sort
void bubbleSort(vector<int>& arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int main()
{
    vector<int> data(100000);
    for (int i = 0; i < 100000; ++i)
    {
        data[i] = 100000 - i;
    }
    auto startBubbleSort = high_resolution_clock::now();
    bubbleSort(data);
    auto stopBubbleSort = high_resolution_clock::now();
    auto durationBubbleSort = duration_cast<milliseconds>(stopBubbleSort - startBubbleSort);
    cout << "Bubble Sort Execution Time: " << durationBubbleSort.count() << " milliseconds" << endl;
    cout << "First 10 elements: ";
    for (int i = 0; i < 10; ++i)
    {
        cout << data[i] << " ";
    }
    cout << endl;
    cout << "Last 10 elements: ";
    for (int i = data.size() - 10; i < data.size(); ++i)
    {
        cout << data[i] << " ";
    }
    cout << endl;
    // Reset vector for STL sort
    for (int i = 0; i < 100000; ++i) {
        data[i] = 100000 - i;
    }
    auto startSTLSort = high_resolution_clock::now();
    sort(data.begin(), data.end());
    auto stopSTLSort = high_resolution_clock::now();
    auto durationSTLSort = duration_cast<milliseconds>(stopSTLSort - startSTLSort);
    cout << "STL Sort Execution Time: " << durationSTLSort.count() << " milliseconds" << endl;
    cout << "First 10 elements: ";
    for (int i = 0; i < 10; ++i)
    {
        cout << data[i] << " ";
    }
    cout << endl;
    cout << "Last 10 elements: ";
    for (int i = data.size() - 10; i < data.size(); ++i)
    {
        cout << data[i] << " ";
    }
    cout << endl;
    return 0;
}