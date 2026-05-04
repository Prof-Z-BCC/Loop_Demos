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
        if (user_guess > answer)
            cout << "Lower" << endl;
        else if (user_guess < answer)
            cout << "Higher" << endl;
        else {
            cout << "You got it." << endl;
        }
    }

    cout << "\n----------------------\n\n";
    
    ifstream fin("demo.txt");

    // Reading from a file until there is nothing left to read
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

    cout << "\n----------------------\n\n";

    cin.ignore(100, '\n');
    string word;
    cout << "Enter a word or phrase: ";
    getline(cin, word);
    unsigned int i = 0;
    while (i < word.size()) {
        cout << word[i] << endl;
        i++;
    }

    cout << "\n----------------------\n\n";

    int input = 0;
    int total = 0;
    counter = 0;
    double average = 0;
    cout << "Enter some numbers, -1 to stop: ";
    while (input != -1) {
        cin >> input;
        if (input != -1) {
            total += input;
            counter++;
            average = (static_cast<double>(total) / counter);
            cout << "\nRunning Average: " << average << endl;
        }
    }
    cout << "\nFinal Average: " << average << endl;
    return 0;
}