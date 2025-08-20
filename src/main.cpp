#include <cstdio>
#include <iostream>
#include <filesystem>
#include <string>
#include <cctype>

using namespace std;
namespace fs = filesystem;

int main()
{
    string oldName, newName;

    cout << "Enter the current file/folder name (with path): ";
    getline(cin, oldName);

    cout << "Enter the new name (with path): ";
    getline(cin, newName);

    if (rename(oldName.c_str(), newName.c_str()) == 0)
    {
        cout << "Renamed successfully." << endl;
    }
    else
    {
        perror("Error renaming");
    }

    return 0;
}