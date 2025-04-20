#include <iostream>
#include <fstream>
using namespace std;
void createAndWriteFile(const char filename[]) 
{
    ofstream file(filename);
    if (!file) 
    {
        cout << "Unable to create the file!" << endl;
        return;
    }
    file << "This is a sample file containing some words to count";
    file.close();
    cout << "File created and written successfully." << endl;
}
int countWordsInFile(const char filename[])
{
    ifstream file(filename);
    if (!file) 
    {
        cout << "Unable to open the file!" << endl;
        return -1;
    }
    char word[100];
    int count = 0;
    while (file >> word)
    {
        count++;
    }
    file.close();
    return count;
}
int main() 
{
    const char filename[] = "words.txt";
    createAndWriteFile(filename);
    int wordCount = countWordsInFile(filename);
    if (wordCount != -1)
    {
        cout << "Total words in file= " << wordCount << endl;
    }
    return 0;
}
