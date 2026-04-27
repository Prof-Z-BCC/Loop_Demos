#include <iostream>
#include <random>

using namespace std;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution distr(1,10);
    // Every for loop should have:
    // initialization; stop condition; update
    // Counting up by 1's
    for (int i = 0; i < 10; i++) {
        cout << i << endl;
    }
    cout << "----------------" << endl;
    // Counting up by 3's
    for (int i = 0; i < 10; i+=3) {
        cout << i << endl;
    }
    cout << "----------------" << endl;
    // Counting backwards by 1's
    for (int i = 10; i > 0; i--) {
        cout << i << endl;
    }
    cout << "----------------" << endl;
    //initialize i outside
    int i = 0;
    for (i; i < 10; i++) {
        cout << i << endl;
    }
    cout << "----------------" << endl;
    // print 10 random numbers between 1 and 10
    for (int i = 0; i < 10; i++) {
        cout << distr(gen) << endl;
    }
    cout << "----------------" << endl;
    return 0;
}