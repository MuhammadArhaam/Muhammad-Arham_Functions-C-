#include <iostream>
using namespace std;
int takeArraySize() 
{
    int size;
    cout << "Enter size of the array= ";
    cin >> size;
    return size;
}
void takeArrayInput(int arr[], int size) 
{
    cout << "Enter " << size << " elements= ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}
void copyArray(int source[], int destination[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        destination[i] = source[i];
    }
}
void printArray(int arr[], int size) 
{
    cout << "Copied array= ";
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() 
{
    int source[100], destination[100];
    int size = takeArraySize();               
    takeArrayInput(source, size);             
    copyArray(source, destination, size);     
    printArray(destination, size);            
    return 0;
}
