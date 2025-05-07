/*
    Program File Name: Ch5Ex11.cpp
    Programmer: Gabriel Inocentes
    Date: May 7, 2025
    Requirements: Make a program that reads a txt file and displays the data in a sorted way
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Declares functions
void readPopulationData(vector<int>& populations);
void displayPopulationChart(const vector<int>& populations);

int main() {
    //Sets vector for population sizes
    vector<int> populations;
    //Var to repeat
    char repeat;

    do {
        // Read and display population data
        populations.clear();
        readPopulationData(populations);

        //Failsafe if file is not found properly
        if (populations.empty()) {
            cout << "Error: No valid population data found in People.txt." << endl;
            return 1;
        }

        displayPopulationChart(populations);

        // Repeat option
        cout << endl << "Would you like to view the chart again? (Y/N): ";
        cin >> repeat;
        repeat = toupper(repeat);

    } while (repeat == 'Y');

    return 0;
}

// Function to read population data from file and validate it
void readPopulationData(vector<int>& populations) {
    ifstream inputFile("People.txt");
    //Checks to see if file can even be found/accessed
    if (!inputFile) {
        cerr << "Error: Could not open People.txt" << endl;
        exit(1);
    }

    int population;
    //While files are being read
    while (inputFile >> population) {
        if (population >= 0) { // Ensuring valid population data
            populations.push_back(population);
        }
    }
    //Closes the file once done
    inputFile.close();
}

// Function to display the population bar chart
void displayPopulationChart(const vector<int>& populations) {
    cout << endl << "PRAIRIEVILLE POPULATION GROWTH" << endl;
    cout << "(each * represents 1,000 people)" << endl;

    int year = 1900;
    for (int population : populations) {
        cout << year << " ";
        for (int i = 0; i < population / 1000; ++i) {
            cout << "*";
        }
        cout << endl;
        year += 20;
    }
}
