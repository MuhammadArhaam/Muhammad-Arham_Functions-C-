#include<iostream>
#include<fstream>
#include<string>
using namespace std;
string inputText() 
{
    string text;
    cout << "Enter text to save in file= ";
    getline(cin, text);
    cin.ignore();
    return text;
}
void saveToFile(string text)
{
    ofstream savefile;
    savefile.open("output.txt");
    if (!savefile.is_open())
    {
        cout << "Error in opening the file";
    }
    savefile << text;
    savefile.close();
    cout << "Text saved to 'output.txt' successfully!" << endl;
}
int main()
{
    string usertext = inputText();
    saveToFile(usertext);
    return 0;
}
