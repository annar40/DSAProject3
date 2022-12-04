#include <iostream>
#include <sstream>
#include <fstream>
#include "orderedMap.cpp"

using namespace std;

string MenuAndInput() {
    string _input;

    cout << "_________________________________________________________________________________" << endl;
    cout << "|                      Welcome to <insert project name here>                    |" << endl;
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

int main() {

    /*
    AVLTree MPGTree;
    AVLTree HPTree;

    string name;
    string mpg;
    string hp;


    ifstream carFile("******FILE NAME HERE******");

    if (carFile.is_open()) {

        string carInfo;
        getline(carFile, carInfo);

        while (getline(carFile, carInfo)) {
            istringstream carStream(carInfo);

            getline(carStream, name, ',');
            getline(carStream, mpg, ',');
            getline(carStream, hp, ',');

            MPGTree.insert(name, mpg);
            HPTree.insert(name, hp);
        }
    }
    */



    string input;

    input = MenuAndInput();

    if(input == "mpg") {
        cout << "calling mpg" << endl;
        MPGTree.printVehicleComparison(input);
    }

    else if(input == "hp") {
        cout << "calling hp" << endl;
        HPTree.printVehicleComparison(input);
    }

    else {
        cout << "Your input was not recognized." << endl;
    }

    return 0;
}