#include<iostream>
using namespace std;
void inputString(char str[], int size)
{
    cout << "Enter a string= ";
    cin.getline(str, size);
}
int countVowels(char str[])
{
    int count = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        char ch = str[i];

        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' ||ch == 'U' || ch == 'a' 
            || ch == 'e' || ch == 'i' ||ch == 'o' || ch == 'u') 
        {
            count++;
        }
        i++;
    }
    return count;
}
int main()
{
    char input[100];
    inputString(input, 100);
    int vowels = countVowels(input);
    cout << "Number of vowels= " << vowels << endl;
    return 0;
}
