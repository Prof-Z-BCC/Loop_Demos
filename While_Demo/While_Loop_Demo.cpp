#include <iostream>
#include <fstream>
#include <random>
#include <string>

using namespace std;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution distr(1, 100);

    int answer = distr(gen);
    int user_guess = -1;
    int counter = 0;
    
    // Controlled by comparison
    while (user_guess != answer && counter < 10) {
        cout << "Enter a guess between 1 and 100: ";
        cin >> user_guess;
        counter++;

        cout << counter << ": " << user_guess << endl;
        
    }
    cout << "You got it." << endl;

    ifstream fin("demo.txt");

    while (!fin.eof()) {
        fin >> user_guess;
        if (fin.fail()) {
            fin.clear();
            fin.ignore(100, '\n');
            continue;
        }
        if (user_guess < 0) {
            cout << "Skipping the negatives." << endl;
            continue;
        }
        cout << user_guess;
        cout << " was the number read." << endl;
        if (user_guess % 3 == 0) {
            cout << "It is divisible by 3." << endl;
        }
    }

    cin.ignore(100, '\n');
    string word;
    getline(cin, word);
    unsigned int i = 0;
    while (i < word.size()) {
        cout << "HERE";
        cout << word[i] << endl;
        i++;
    }

    int input = 0;
    cout << "Enter some numbers, -1 to stop: ";
    while (input != -1) {
        cin >> input;
    }

    return 0;
}