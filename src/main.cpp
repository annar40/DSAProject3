#include <iostream>
#include <sstream>
#include <fstream>
#include "orderedMap.h"
#include "unorderedMap.h"

using namespace std;

string MenuAndInput()
{
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

int main()
{

    /*
    AVLTree MPGTree;
    AVLTree HPTree;
    HashMap<int, string> *MPGHash = new HashMap<int, string>(20);
    HashMap<int, string> *HPHash = new HashMap<int, string>(20);

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
            MPGHash->insertNode(stoi(mpg), name);
            HPHash->insertNode(stoi(hp), name);



        }
    }
    */

    string input;

    int valueInput;

    AVLTree MPGTree;
    AVLTree HPTree;
    HashMap<int, string> *MPGHash = new HashMap<int, string>(20);
    // MPGHash->insertNode(1, "caleb");
    // MPGHash->insertNode(6, "eb");

    // MPGHash->insertNode(11, "abbey");
    // MPGHash->insertNode(17, "jake");
    // MPGHash->insertNode(19, "class");
    // MPGHash->insertNode(19, "math");
    // MPGHash->insertNode(20, "soccer");
    // MPGHash->insertNode(21, "mom");
    // MPGHash->insertNode(6, "dad");
    // MPGHash->insertNode(14, "hero");
    // MPGHash->insertNode(39, "blah");
    // MPGHash->insertNode(40, "green");
    // MPGHash->insertNode(67, "sea");
    // MPGHash->insertNode(98, "snake");


    // vector<string> answer = MPGHash->get(20);
    // for (int i=0; i<answer.size(); i++){
    //     if(i == 3)
    //     {
    //         cout << "Your Value: ";
    //     }
    //     cout<<answer[i] << " ";
    // }






    MPGTree.insertCar("M", "8");
    MPGTree.insertCar("L", "9");
    MPGTree.insertCar("T", "10");
    MPGTree.insertCar("G", "3");
    MPGTree.insertCar("Y", "2");
    MPGTree.insertCar("A", "1");

    input = MenuAndInput();

    if (input == "mpg")
    {
        cout << endl;
        cout << "What is the MPG of your car?" << endl;
        cin >> valueInput;
        MPGTree.printVehicleComparison(valueInput);
    }
    else if (input == "hp")
    {
        cout << endl;
        cout << "What is the HP of your car?" << endl;
        cin >> valueInput;
        // HPTree.printVehicleComparison(stoi(input));
    }

    else
    {
        cout << "Your input was not recognized." << endl;
    }

    return 0;
}
