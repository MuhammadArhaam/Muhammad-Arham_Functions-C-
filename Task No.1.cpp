#include<iostream>
using namespace std;
void inputArray(int arr[], int size)
{
    cout << "Enter " << size << " integers= ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}
void printArray(int arr[], int size)
{
    cout << "Array = { ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "}" << endl;
}
int main()
{
    int numbers[5];
    inputArray(numbers, 5);
    printArray(numbers, 5);
    return 0;
}
