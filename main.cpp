#include <iostream>
#include <list>
#include <random>
using namespace std;

int main() {
    list<int> myList;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 1000000);

    for (int i = 0; i < 100000; i++) {
        int randomNumber = dist(gen);
        myList.push_front(randomNumber);
    }

    cout << "Enter a number to search for (between 1 - 1,000,000): ";
    int searchNum; cin >> searchNum;

    int closestNumValue = 1000000;
    int closestNum;

    for (int num : myList) {
        int distance = abs(searchNum - num);
        if (distance < closestNumValue) {
            closestNumValue = distance;
            closestNum = num;
        }
    }

    if (closestNumValue == 0) {
        cout << "Found your number!" << endl;
    } else {
        cout << "Did not find your number. The closest number we found to " << searchNum << " was " << closestNum;
    }

    return 0;
}
