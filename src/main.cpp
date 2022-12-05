#include <iostream>
#include <sstream>
#include <fstream>
#include "orderedMap.h"

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

   int valueInput;

   AVLTree MPGTree;
   AVLTree HPTree;
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

