#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main() {
    setlocale(LC_CTYPE, "rus");

    ofstream file;
    string fileName = "pic.txt";

    file.open(fileName, ios::app);

    int height, width;

    cout << "Enter the height of the painting: ";
    cin >> height;
    cout << endl;

    cout << "Enter the width of the painting: ";
    cin >> width;
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int i = 0; i < width; i++)
        {
            file << rand() % (1 - 0 + 1);
        }
        file << endl;
    }

    file.close();

}
