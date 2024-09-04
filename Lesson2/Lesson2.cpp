#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    ofstream file;
    string fileName = "List.txt";

    file.open(fileName, ios::app);

    if (!file.is_open()) {
        cerr << "Error when opening a file!" << endl;
    }

    string firstName, lastName, date;
    int amount;

    cout << "Enter a name: ";
    cin >> firstName;
    cout << "Enter last name: ";
    cin >> lastName;
    cout << "Enter the date (DD.MM.YYYY): ";
    cin >> date;
    cout << "Enter the payout amount: ";
    cin >> amount;

    file << firstName << " " << lastName << " " << date << " " << amount << endl;

    file.close();
    cout << "The record has been added to the statement." << endl;

    return 0;
}
