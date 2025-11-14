#include <iostream>
#include <iomanip>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"

using namespace std;

const int INITIAL_SIZE = 2;

int main() {
    srand(time(0));
    
    deque<Car> tollBooth;

    for (int i = 0; i < INITIAL_SIZE; i++) {
        tollBooth.push_back(Car());
    }

    cout << "Initial queue:\n";
    for (int i = 0; i < INITIAL_SIZE; i++) {
        tollBooth[i].print();
    }

    cout << endl;
    int time_interval = 1;

    while (!tollBooth.empty()) {    
        int chance = rand()%100 + 1;
        if (chance <= 55) {
            cout << "Time: " << time_interval << "  Operation: Car paid: ";
            tollBooth[0].print();
            tollBooth.pop_front();
        }
        else if (chance > 55) {
            tollBooth.push_back(Car());
            cout << "Time: " << time_interval << "  Operation: Joined lane:  ";
            tollBooth[tollBooth.size() - 1].print();
        }

        cout << "Queue:\n";
        for (int i = 0; i < tollBooth.size(); i++) {
            tollBooth[i].print();
        }

        if(tollBooth.empty()) {
            cout << "Empty";
        }

        cout << endl;
        time_interval++;
    }
    
    return 0;
}