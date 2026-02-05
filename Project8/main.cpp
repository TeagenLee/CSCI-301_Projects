/*
This file requests a file from the user and allows them to make a list of people that they can add,remove, and modify.
    They can also see it in the order they added people or in alphebetic order.
Teagen Lee
Due: 12/3/2025
*/

#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include "PeopleDB.h"
#include "People.h"
#include "Date.h"

using namespace std;


extern ofstream fsOut;

int main() {
    cout << "Welcome to people database system. Please enter the file that contains initial people list: ";
    string inFile;
    getline(cin, inFile);
    if (inFile.empty()) {
        getline(cin, inFile); 
    }

    PeopleDB pdb(inFile);

    cout << "The initial database built from the input file is displayed by its original order:\n";
    pdb.displayPreorder();

    cout << endl;
    
    bool exitFlag = false;
    while (!exitFlag) {
        cout << "Please enter your option\n"
             << "1. add a new person\n"
             << "2. remove a person\n"
             << "3. modify the database\n"
             << "4. Search for a person in the database\n"
             << "5. Display the database\n"
             << "6. Display the database sorted by names\n"
             << "7. Quit and save the database to a file\n"
             << "--> ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            string dummy;
            getline(cin, dummy);
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: { // add
                char again = 'Y';
                while (again == 'Y' || again == 'y') {
                    cout << "To add, enter name and birthday (month day year):\n";
                    People p;
                    string line;
                    getline(cin, line);
                    if (line.empty()) { getline(cin, line); }
                    istringstream iss(line);
                    iss >> p;
                    if (!p.getName().empty()) {
                        if (pdb.addPerson(p))
                            cout << "Person added.\n";
                        else
                            cout << "Person with that name already exists. Not added.\n";
                    }
                    cout << "Add another one? ";
                    cin >> again;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << endl;
                break;
            }
            case 2: { // remove
                char again = 'Y';
                while (again == 'Y' || again == 'y') {
                    cout << "To remove, enter person's name and birthday (or just name):\n";
                    string line;
                    getline(cin, line);
                    if (line.empty()) getline(cin, line);
                    istringstream iss(line);
                    string name;
                    iss >> name;
                    int m,d,y;
                    if (iss >> m >> d >> y) {
                        People p(name, Date(m,d,y));
                        if (pdb.removePerson(p))
                            cout << "This person has been removed.\n";
                        else
                            cout << "Can not find this person.\n";
                    } else {
                        if (pdb.removePersonByName(name))
                            cout << "This person has been removed.\n";
                        else
                            cout << "Can not find this person.\n";
                    }
                    cout << "Remove another one? ";
                    cin >> again;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << endl;
                break;
            }
            case 3: { // modify
                char cont = 'Y';
                while (cont == 'Y' || cont == 'y') {
                    cout << "To modify, enter person's name and birthday:\n";
                    People oldP;
                    string line;
                    getline(cin, line);
                    if (line.empty()) getline(cin, line);
                    istringstream iss(line);
                    iss >> oldP;
                    People found;
                    if (!pdb.searchPerson(oldP, found)) {
                        cout << "Cannot find this person.\n";
                    } else {
                        cout << "Found this person in the database. This person's data has been removed.\n";
                        pdb.removePerson(oldP);
                        cout << "Enter this person's new information: name and birthday (month day year):\n";
                        People newP;
                        getline(cin, line);
                        if (line.empty()) getline(cin, line);
                        istringstream iss2(line);
                        iss2 >> newP;
                        pdb.addPerson(newP);
                        cout << "The database has been modified.\n";
                    }
                    cout << "Continue to modify? ";
                    cin >> cont;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << endl;
                break;
            }
            case 4: { // search
                char cont = 'Y';
                while (cont == 'Y' || cont == 'y') {
                    cout << "To search, enter person’s name and birthday:\n";
                    People p;
                    string line;
                    getline(cin, line);
                    if (line.empty()) getline(cin, line);
                    istringstream iss(line);
                    iss >> p;
                    People found;
                    if (pdb.searchPerson(p, found)) {
                        cout << "Found the person in the database:\n";
                        cout << found <<endl;
                    } else {
                        cout << "Can not find.\n";
                    }
                    cout << "Continue another search? ";
                    cin >> cont;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << endl;
                break;
            }
            case 5: {
                pdb.displayPreorder();
                cout << endl;
                break;
            }
            case 6: {
                pdb.displayInorder();
                cout << endl;
                break;
            }
            case 7: {
                string outF = "studentDB2.txt";
                pdb.saveToFile(outF);
                cout << "The updated database has been saved to \"" << outF << "\".\nBye!\n";
                exitFlag = true;
                cout << endl;
                break;
            }
            default:
                cout << "Invalid option.\n";
                cout << endl;
        }
    }

    return 0;
}
