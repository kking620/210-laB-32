#include <iostream>
#include <iomanip>
#include <deque>
#include <cstdlib>
#include <cmath>
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

    int time_interval = 1;

    while (!tollBooth.empty()) {
        int changes = 0;
        
        int chance = rand()%100 + 1;
        if (chance <= 55) {
            Car fCar = tollBooth.front();
            tollBooth.pop_front();
            changes++;
        }
        else if (chance > 55) {
            tollBooth.push_back(Car());
            Car nCar = tollBooth.back();
            changes++;
        }

        cout << "Time: " << time_interval << "  Operation: "
    }
    
}