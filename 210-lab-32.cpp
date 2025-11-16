//COMSC-210 | Lab 32 | Kristofer King
//IDE Used: VSC
#include <iostream>
#include <iomanip>
#include <deque>
#include <array>
#include <cstdlib>
#include <ctime>
#include "Car.h"

using namespace std;

//declaring and initializing the initial size of the dequeue containing the Car objects
const int INITIAL_SIZE = 2;

int main() {
    //necessary call function in order to ensure that only random numbers are generated each time the rand() function is called
    srand(time(0));
    
    //declaring the dequeue that will be storing our Car objects
    array<deque<Car>, 4> tollBoothPlaza;

    //initializing the dequeue using the default constructor from the Car.h file until it reaches the size of our INITIAL_SIZE constant
    for (int i = 0; i < INITIAL_SIZE; i++) {
        tollBoothPlaza[i].push_back(Car());
    }

    //for loop that outputs the contents of the initial queue
    cout << "Initial queue:\n";
    for (int i = 0; i < INITIAL_SIZE; i++) {
        cout << "   ";
        tollBoothPlaza[i].print();
    }

    cout << endl;

    //declares and initializes the time interval variable
    int time_interval = 1;

    //while loop that continuously loops until the tollBooth dequeue is empty
    while (!tollBoothPlaza.empty()) {    
        //declaring and initializing the chance variable that will cause a car to either pay and leave the queue or someone will join from the back of the queue
        int chance = rand()%100 + 1;
        //if the chance is found to be less than or equal to 55, then a car will be removed from the front of the tollBooth dequeue
        if (chance <= 55) {
            cout << "Time: " << time_interval << "  Operation: Car paid: ";
            tollBoothPlaza[0].print();
            tollBoothPlaza.pop_front();
        }
        //if the chance is found to be greater than 55, then a new car object will be added to the back of the tollBooth dequeue
        else if (chance > 55) {
            tollBoothPlaza.push_back(Car());
            cout << "Time: " << time_interval << "  Operation: Joined lane:  ";
            tollBoothPlaza[tollBoothPlaza.size() - 1].print();
        }

        //code block that will output all of the Car objects stored in the tollBooth dequeue
        cout << "Queue:\n";
        for (int i = 0; i < tollBoothPlaza.size(); i++) {
            cout << "   ";
            tollBoothPlaza[i].print();
        }
        
        //if the tollbooth is found to be empty, then the program will output the following message
        if(tollBoothPlaza.empty()) {
            cout << "   Empty";
        }

        cout << endl;

        //increments the time_interval value to keep track of how many time intervals pass until the queue is empty
        time_interval++;
    }
    
    return 0;
}