#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ifstream fileIn("wordlist.txt");
    vector<string> wordlist;

    if (fileIn.good())
    {
        string word;

        while (!fileIn.eof())
        {
            fileIn >> word;
            wordlist.push_back(word);
        }
        fileIn.close();
    }
    else
    {
        cerr << "File not found" << endl;
    }

    for (auto word : wordlist)
    {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}