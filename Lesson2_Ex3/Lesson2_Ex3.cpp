#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main() {
    setlocale(LC_CTYPE, "rus");

    ifstream file1;
    string fileName1 = "river.txt";

    ofstream file2;
    string fileName2 = "basket.txt";

    file1.open(fileName1, ios::app);

    file2.open(fileName2, ios::app);

    string nameFish;


    cout << "Enter the name of the fish:  ";
    cin >> nameFish;
    cout << endl;

    if (!file1.is_open())
    {
        cout << "File opening error";
    }
    else
    {
        int count = 0;
        string temp;

        while (!file1.eof())
        {
            file1 >> temp;
            if (temp == nameFish)
            {
                file2 << temp << endl;
                count++;
            }
        }
        file2 << "Fish caught: " << count;
    }
    file2 << endl;
    file2 << endl;

    file1.close();
    file2.close();
}
