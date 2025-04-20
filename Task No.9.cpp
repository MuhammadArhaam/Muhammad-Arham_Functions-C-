#include <iostream>
using namespace std;
void takeStringInput(char str[]) 
{
    cout << "Enter a string= ";
    cin.getline(str, 100);
}
bool isPalindrome(char str[]) 
{
    int end = 0;
    while (str[end] != '\0')
    {
        end++;
    }
    int start = 0;
    end = end - 1;
    while (start < end)
    {
        if (str[start] != str[end]) 
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
int main()
{
    char input[100];
    takeStringInput(input);
    if (isPalindrome(input)) 
    {
        cout << "The string is a palindrome" << endl;
    }
    else 
    {
        cout << "The string is not a palindrome" << endl;
    }
    return 0;
}
