#include <iostream>
using namespace std;
void takeStringInput(char str[])
{
    cout << "Enter a string= ";
    cin.getline(str, 100);
}
void reverseString(char str[]) 
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    cout << "Reversed String= ";
    for (int j = i - 1; j >= 0; j--) 
    {
        cout << str[j];
    }
    cout << endl;
}
int main() 
{
    char input[100];
    takeStringInput(input);
    reverseString(input);
    return 0;
}
