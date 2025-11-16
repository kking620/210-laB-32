//COMSC-210 | Lab 33 | Kristofer King
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
const int PROB_LEAVE = 46;
const int PROB_JOIN = 39;
const int PROB_SWITCH = 15;
const int PROB_E_SWITCH = 50;

int main() {
    //necessary call function in order to ensure that only random numbers are generated each time the rand() function is called
    srand(time(0));
    
    //declaring the dequeue that will be storing our Car objects as well as the array that will be storing the dequeues themselves
    using tollBoothLane = deque<Car>;
    array<tollBoothLane, 4> tollBoothPlaza;

    //initializing the dequeue using the default constructor from the Car.h file until it reaches the size of our INITIAL_SIZE constant
    for (int i = 0; i < 4; i++) {
        //for the current lane, insert a Car object to the dequeue
        for (int j = 0; j < INITIAL_SIZE; j++) {
            tollBoothPlaza[i].push_back(Car());
        }
    }

    //for loop that outputs the contents of the initial array of dequeues
    cout << "Initial queue:\n";
    for (int i = 0; i < 4; i++) {
        cout << "Lane: " << i + 1 << endl;
        //for the current lane, print the specific Car object at the given position within the dequeue
        for (int j = 0; j < tollBoothPlaza[i].size(); j++) {
            cout << "   ";
            tollBoothPlaza[i][j].print();
        }
    }
    cout << endl;

    //while loop that continuously loops until 20 time intervals go by
    for (int time = 0; time < 20; time++) {    
        cout << "Time: " << time + 1 << endl;
        for (int i = 0; i < 4; i++) {
            //declaring and initializing the chance variable that will cause a car to either pay and leave the queue or someone will join from the back of the queue
            int chance = rand()%100 + 1;
            //if the toolBoothPlaza is empty, then there is a 50 percent chance that a car will join the line
            if(tollBoothPlaza[i].empty()) {
                //if the chance is found to be greater than 55, then a new car object will be added to the back of the tollBooth dequeue
                if (chance <= PROB_E_SWITCH) {
                    tollBoothPlaza[i].push_back(Car());
                    cout << "Lane: " << i + 1 << "  Operation: Joined lane:  ";
                    tollBoothPlaza[i][tollBoothPlaza[i].size() - 1].print();
                }
            }
            //if the toolBoothPlaza is not empty, then these conditions will be checked
            else if(!tollBoothPlaza[i].empty()) {
            //if the chance is found to be less than or equal to 46, then a car will be removed from the front of the tollBooth dequeue
                if (chance <= PROB_LEAVE) {
                    cout << "Lane: " << i + 1 << "  Operation: Car paid: ";
                    tollBoothPlaza[i][0].print();
                    tollBoothPlaza[i].pop_front();
                }
                //if the chance is found to be greater than 46 and less than or equal to 85, then a new car object will be added to the back of the tollBooth dequeue
                else if (chance <= (PROB_LEAVE + PROB_JOIN)) {
                    tollBoothPlaza[i].push_back(Car());
                    cout << "Lane: " << i + 1 << "  Operation: Joined lane:  ";
                    tollBoothPlaza[i][tollBoothPlaza[i].size() - 1].print();
                }
                //if the chance is found to be greater than 85, then a new car object will be added to the back of the tollBooth dequeue
                else {
                    cout << "Lane: " << i + 1 << "  Operation: Switched lanes:  ";
                    int sLane = i;
                    //while loop that continuously tries to change the lane of the current car object
                    while(sLane == i) {
                        sLane = rand() % 4;
                        if (sLane != i) break;
                    }
                    
                    //this code block sets our temporary value as the last value in the current lane, removes that car from the current list, and then adds the car object to another lane
                    Car temp = tollBoothPlaza[i].back();
                    tollBoothPlaza[i].pop_back();
                    tollBoothPlaza[sLane].push_back(temp);
                    tollBoothPlaza[sLane][tollBoothPlaza[sLane].size() - 1].print();
                }
            }
        }
        //code block that will output all of the Car objects stored in the tollBooth dequeue
        for (int i = 0; i < 4; i++) {
            cout << "Lane " << i + 1 << " Queue: \n";
            //if the current lane is empty, then the empty message will be outputted
            if(tollBoothPlaza[i].empty()) {
            cout << "   Empty\n";
            }
            //if the current lane is not empty, then we will traverse the arrays and the dequeues until all elements were printed
            else {
                for (int j = 0; j < tollBoothPlaza[i].size(); j++) {
                    cout << "   ";
                    tollBoothPlaza[i][j].print();
                }
            }
        }

        cout << endl;
    }
    
    return 0;
}