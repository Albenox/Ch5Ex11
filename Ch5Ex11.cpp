/*
    Program File Name: Chapter5Ex11.cpp
    Programmer: Gabriel Inocentes
    Date: April 17, 2025
    Requirements:
    Create a program that predicts the size of a population based on user input
*/

#include <iostream>
using namespace std;

void inputChecker(double& populationCount, double& populationIncrease, double& time, char& type);
void timeLoop(double& populationCount, double& populationIncrease, double& populationEstimate, double& time);

int main()
{
    double populationCount;
    double populationIncrease;
    double time;
    double populationEstimate;
    
    //Variable to check what type of limitation to look for from the user
    char type;

    cout << "What is the current population count of the organisms?" << endl;
    type = 1;
    inputChecker(populationCount, populationIncrease, time, type);
    cout << "What is the  average daily percentage increase to the population count?" << endl;
    type = 2;
    inputChecker(populationCount, populationIncrease, time, type);
    cout << "How long should this prediction account growth for?" << endl;
    type = 3;
    inputChecker(populationCount, populationIncrease, time, type);
    cout << endl;

    populationIncrease = populationIncrease / 100;

    timeLoop(populationCount, populationIncrease, populationEstimate, time);

}

void timeLoop(double& populationCount, double& populationIncrease, double& populationEstimate, double& time) {
    for (; time > 0; time--) {
        int x = time;
        populationEstimate = populationCount * (1 + populationIncrease);
        populationCount = populationEstimate;
        cout << x << "   " << populationEstimate << endl;
    }
}

void inputChecker(double& populationCount,double& populationIncrease, double& time, char& type) {
    //Refuses if user input invalid
    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Input is invalid, please enter a valid number: " << endl;
    }
    else {
        //If statement once the user input has been validated
        if (type == 1) {
            cin >> populationCount;
            while (populationCount < 2) {
                cin.clear();
                cin.ignore();
                cout << "Input is invalid, please enter a starting population size of 2 or greater: " << endl;
                cin >> populationCount;
            }
        }
        else if (type == 2){
            cin >> populationIncrease;
            while (populationIncrease < 0) {
                cin.clear();
                cin.ignore();
                cout << "Input is invalid, please enter a positive daily population increase: " << endl;
                cin >> populationIncrease;
            }
        }
        else if (type == 3){
            cin >> time;
            while (time < 1) {
                cin.clear();
                cin.ignore();
                cout << "Input is invalid, please enter a time greater than 1: " << endl;
                cin >> time;
            }
        }
    }
}