#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

const int MAX_NOTES = 1000;
const int DENOMINATIONS[] = { 100, 500, 1000, 5000 };

void fillATM() {
    ofstream file("atm.txt");

    if (!file.is_open()) {
        cout << "Error opening a file for writing." << endl;
        return;
    }

    srand(time(0));

    for (int i = 0; i < MAX_NOTES; i++) {
        int randomNote = DENOMINATIONS[rand() % 4];
        file << randomNote << " ";
    }

    file.close();
    cout << "The ATM has been successfully filled." << endl;
}

void withdrawMoney(int amount) {
    ifstream file("atm.txt");
    if (!file.is_open()) {
        cout << "Error opening a file for reading." << endl;
        return;
    }

    int atm[MAX_NOTES];
    int count = 0;

    while (file >> atm[count]) {
        count++;
    }
    file.close();

    int total = 0;
    int notesUsed = 0;

    for (int i = 0; i < count && total < amount; i++) {
        if (atm[i] != 0 && total + atm[i] <= amount) {
            total += atm[i];
            atm[i] = 0;
            notesUsed++;
        }
    }

    if (total == amount) {
        cout << "You withdrew " << amount << " rubles." << endl;

        ofstream outFile("atm.txt");
        for (int i = 0; i < count; i++) {
            outFile << atm[i] << " ";
        }
        outFile.close();
    }
    else {
        cout << "Unable to disburse this amount." << endl;
    }
}

int main() {
    char operation;

    cout << "Enter the operation (+ for filling, - for withdrawal): ";
    cin >> operation;

    if (operation == '+') {
        fillATM();
    }
    else if (operation == '-') {
        int amount;
        cout << "Enter the amount to be withdrawn (multiple of 100): ";
        cin >> amount;

        withdrawMoney(amount);
    }
    else {
        cout << "Incorrect operation." << endl;
    }

    return 0;
}
