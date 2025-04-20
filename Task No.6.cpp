#include<iostream>
using namespace std;
void inputArray(int arr[], int size) 
{
    cout << "Enter " << size << " elements= ";
    for (int i = 0; i < size; i++) 
    {
        cin >> arr[i];
    }
}
int findMaximum(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++) 
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
int main() 
{
    int arr[10];
    inputArray(arr, 10);
    cout << "The maximum element in the array is= " << findMaximum(arr, 10) << endl;
    return 0;
}
