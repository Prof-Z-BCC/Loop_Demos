#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {

	int num_inputs = -1;
	int input;
	int total = 0;
	double average = 0;
	int counter = 0;
	bool valid = false;

	// --- Ensure the user provides a valid number of scores before proceeding
	do {
		cout << "How many scores? ";
		cin >> num_inputs;
		if (cin.fail() || num_inputs < 1) {
			cout << "Bad input detected - must be an integer greater than 1." << endl;
			if (cin.fail()) {
				cin.clear();
				// --- Clear the input buffer to remove invalid characters
				cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			}
		}
		else {
			valid = true;
			// --- Check for and handle trailing characters following a valid integer
			if (cin.peek() != '\n') {
				cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
				cout << "Did you mean to enter " << num_inputs << "? (y to continue): ";
				if (!(cin.get() == 'y' || cin.get() == 'Y')) {
					valid = false;
				}
			}
		}
	} while (!valid);

	// --- Loop until the specified number of valid scores has been collected
	do {

		cout << "\nEnter score " << (counter + 1) << ": ";
		cin >> input;
		// --- Verify user intent if non-integer data follows the numerical input
		if (cin.peek() != '\n') {
			cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			cout << "Did you mean to enter " << input << "? (y to continue): ";
			if (!(cin.get() == 'y' || cin.get() == 'Y')) {
				valid = false;
				continue;
			}
		}
		if (cin.fail() || input < 0) {
			cout << "Bad input detected - must be a non-negative integer." << endl;
			if (cin.fail()) {
				cin.clear(); // --- Reset the error flags to allow further input
				cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			}
			valid = false;
		}
		else {
			counter++;
			total += input;
			cout << "Score: " << input << endl;
			cout << "Running Total: " << total << endl;
			valid = true; // --- Reset validity to true after a successful score entry
		}
	} while (!valid || counter < num_inputs); // --- Continue loop if input was invalid or more scores are needed

	average = static_cast<double>(total) / num_inputs;

	cout << setprecision(2) << fixed << "\nAverage: " << average << "%" << endl;

	return 0;
}
