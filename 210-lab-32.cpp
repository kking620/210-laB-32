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
}