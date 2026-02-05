// Spell checks a file that is provided by the user
// Teagen Lee
// 10/3/2025

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "DoublyLinkedBag.h"

using namespace std;

// Convert string to lowercase
string toLowercase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Trim leading/trailing whitespace
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

int main() {
    DoublyLinkedBag<string> dictionary;
    string dictFile = "dictionary.txt"; //  dictionary file
    ifstream dictInput(dictFile);
    
    // Checks to see if dictionary.txt file could be opened
    if (!dictInput) {
        cerr << "Error: Could not open dictionary file " << dictFile << endl;
        return 1;
    }

    // puts all the words from the dictionary.txt file into a DoublyLinkedBag 
    string word;
    while (getline(dictInput, word)) {
        word = trim(word);
        if (!word.empty())
            dictionary.add(toLowercase(word));
    }
    dictInput.close();

    // Ask user for file to spell-check
    string userFile;
    cout << "Enter the filename of the file to spell-check: " << endl;;
    getline(cin, userFile);

    // Checks to see if userFile could be opened
    ifstream userInput(userFile);
    if (!userInput) {
        cerr << "Error: Could not open file " << userFile << endl;
        return 1;
    }

    // Displays the wrongly spelt words and words not in the dictionary.txt file
    cout << endl;
    cout << "The following words in the file " <<  userFile << " are not spelled correctly:" << endl;
    while (getline(userInput, word)) {
        word = trim(word);
        if (word.empty()) continue;

        string lowerWord = toLowercase(word);
        if (!dictionary.contains(lowerWord)) {
            cout << word << endl;
        }
    }
    userInput.close();

    cout << endl;
    cout << "Thanks for using the spell checker system." << endl;
    return 0;
}
