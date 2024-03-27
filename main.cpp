#include <iostream>
#include <list>
#include <random>
using namespace std;
int main() {
    list <int> myList;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 1000000);
    for(int i = 0; i < 100000; i++) {
        int randomNumber = dist(gen);
        myList.push_front(randomNumber);
    }
    int maxValue = myList.front();
    int minValue = myList.front();
    for(int num : myList) {
        if(num > maxValue) {
            maxValue = num;
        }
        else if(num < minValue) {
            minValue = num;
        }
        if (num < 10) {cout << num <<endl;} else if (num > 999980) {cout << num <<endl;}
    }
    cout << "Max value: " << maxValue << " Min value: " << minValue;
}