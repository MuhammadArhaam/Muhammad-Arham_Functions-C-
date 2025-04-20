#include<iostream>
#include<string>
using namespace std;
void inputString(char str[], int size) 
{
    cout << "Enter a string= ";
    cin.getline(str, size);
}
void printCharacters(char str[]) {
    int i = 0;
    cout << "Characters in the string= " << endl;
    while (str[i] != '\0') {
        cout << str[i] << endl;
        i++;
    }
}
int main() 
{
    char input[100];
    inputString(input, 100);
    printCharacters(input);
    return 0;
}
