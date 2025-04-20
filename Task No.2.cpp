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
int sumArray(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++) 
    {
        sum += arr[i];
    }
    return sum;
}
int main() 
{
    int numbers[10];
    inputArray(numbers, 10);
    int total = sumArray(numbers, 10);
    cout << "Sum of array elements = " << total << endl;
    return 0;
}
