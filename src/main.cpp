#include <iostream>
#include <sstream>
#include <fstream>
#include "orderedMap.h"
#include "unorderedMap.h"
#include <ctime>
#include <iomanip>
using namespace std;

string MenuAndInput()
{
    string _input;

    cout << "_________________________________________________________________________________" << endl;
    cout << "|                      Welcome to Kapoor's Blue Book                            |" << endl;
    cout << "|                                                                               |" << endl;
    cout << "| Please choose the characteristic of your car you would like to compare today! |" << endl;
    cout << "|                                                                               |" << endl;
    cout << "|          If you would like to compare <Miles Per Gallon>, type \"mpg\"          |" << endl;
    cout << "|                                                                               |" << endl;
    cout << "|              If you would like to compare <Horsepower>, type \"hp\"             |" << endl;
    cout << "_________________________________________________________________________________" << endl;
    cout << endl;
    cin >> _input;

    return _input;
}

int main()
{
    clock_t start, end;
    AVLTree MPGTree;
    AVLTree HPTree;
    HashMap<int, string> *MPGHash = new HashMap<int, string>(20);
    HashMap<int, string> *HPHash = new HashMap<int, string>(20);

    string name;
    string mpg;
    string hp;
    bool stop = false;
    
    ifstream carFile("C:/Users/arude/OneDrive/Desktop/cars.csv");
    if (carFile.is_open())
    {
        string carInfo;
        getline(carFile, carInfo);
        while (getline(carFile, carInfo))
        {
            istringstream carStream(carInfo);
            getline(carStream, name, ',');
            getline(carStream, mpg, ',');
            getline(carStream, hp, ',');
            MPGTree.insertCar(name, mpg);
            HPTree.insertCar(name, hp);
            MPGHash->insertNode(stoi(mpg), name);
            HPHash->insertNode(stoi(hp), name);
        }
    }
    else
    {
        cout << "File failed to open.";
    }

    string input;

    int valueInput;
    int dataStructure;
    while (!stop)
    {
        input = MenuAndInput();

        if (input == "mpg")
        {
            cout << endl;
            cout << "What is the MPG of your car?" << endl;
            cin >> valueInput;
            cout << "Select a data structure: " << endl
                 << "1. Ordered Map" << endl
                 << "2. Unordered Map" << endl;
            cin >> dataStructure;
            if (dataStructure == 1)
            {

                start = clock();
                MPGTree.printVehicleComparison(valueInput);
                end = clock();
                cout << "Execution time: " << fixed << double(end - start) / 1000000 << setprecision(5) << " seconds." << endl;
            }
            else
            {
                start = clock();
                MPGHash->print(valueInput);
                end = clock();
                cout << "Execution time: " << fixed << double(end - start) / 1000000 << setprecision(5) << " seconds." << endl;
            }
        }
        else if (input == "hp")
        {
            cout << endl;
            cout << "What is the HP of your car?" << endl;
            cin >> valueInput;
            cout << "Select a data structure: " << endl
                 << "1. Ordered Map" << endl
                 << "2. Unordered Map" << endl;
            cin >> dataStructure;
            if (dataStructure == 1)
            {
                start = clock();
                HPTree.printVehicleComparison(valueInput);
                end = clock();
                cout << "Execution time: " << fixed << double(end - start) / 1000000 << setprecision(5)<< " seconds." << endl;
            }
            else
            {
                start = clock();
                HPHash->print(valueInput);
                end = clock();
                cout << "Execution time: " << fixed << double(end - start) / 1000000 << setprecision(5) << " seconds." << endl;
            }
        }
        else
        {
            cout << "Your input was not recognized." << endl;
        }
        cout << "\nThanks for comparing with us!" << endl
             << "Enter 1 to compare again. \nEnter any other key to exit." << endl;
        int exitStatus;
        cin >> exitStatus;
        if (exitStatus != 1)
        {
            stop = true;
        }
    }

    return 0;
}
