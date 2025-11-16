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
    using tollBoothLane = deque<Car>;
    array<tollBoothLane, 4> tollBoothPlaza;

    //initializing the dequeue using the default constructor from the Car.h file until it reaches the size of our INITIAL_SIZE constant
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < INITIAL_SIZE; j++) {
            tollBoothPlaza[i].push_back(Car());
        }
    }

    //for loop that outputs the contents of the initial queue
    cout << "Initial queue:\n";
    for (int i = 0; i < 4; i++) {
        cout << "Lane: " << i + 1 << endl;
        for (int j = 0; j < tollBoothPlaza[i].size(); j++) {
            cout << "   ";
            tollBoothPlaza[i][j].print();
        }
    }
    cout << endl;

    //while loop that continuously loops until the tollBooth dequeue is empty
    for (int time = 0; time < 20; time++) {    
        cout << "Time: " << time + 1 << endl;
        for (int i = 0; i < 4; i++) {
            //declaring and initializing the chance variable that will cause a car to either pay and leave the queue or someone will join from the back of the queue
            int chance = rand()%100 + 1;
            if(tollBoothPlaza[i].empty()) {
                //if the chance is found to be greater than 55, then a new car object will be added to the back of the tollBooth dequeue
                if (chance <= 50) {
                    tollBoothPlaza[i].push_back(Car());
                    cout << "Lane: " << i + 1 << "  Operation: Joined lane:  ";
                    tollBoothPlaza[i][tollBoothPlaza[i].size() - 1].print();
                }
            }
            else if(!tollBoothPlaza[i].empty()) {
            //if the chance is found to be less than or equal to 55, then a car will be removed from the front of the tollBooth dequeue
                if (chance <= 46) {
                    cout << "Lane: " << i + 1 << "  Operation: Car paid: ";
                    tollBoothPlaza[i][0].print();
                    tollBoothPlaza[i].pop_front();
                }
                //if the chance is found to be greater than 55, then a new car object will be added to the back of the tollBooth dequeue
                else if (chance > 46 && chance <= 85) {
                    tollBoothPlaza[i].push_back(Car());
                    cout << "Lane: " << i + 1 << "  Operation: Joined lane:  ";
                    tollBoothPlaza[i][tollBoothPlaza[i].size() - 1].print();
                }
                else if (chance > 85) {
                    cout << "Lane: " << i + 1 << "  Operation: Switched lanes:  ";
                    int sLane = i;
                    while(sLane == i) {
                        sLane = rand() % 4;
                        if (sLane != i) break;
                    }
                    
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
            if(tollBoothPlaza[i].empty()) {
            cout << "   Empty\n";
            }
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