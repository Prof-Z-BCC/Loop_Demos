#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream> //--- string stream - reprocessing an input
#include <cctype>  //--- allows check of isdigit

using namespace std;

int main() {

	ifstream fin("data2.txt"); //--- Intentional error on file name
	int err_count = 0;

	//--- Error check on file opening
	while (!fin && err_count < 3) {
		err_count++;
		cout << "Error - no such file." << endl;
		string filename;
		cout << "Enter the filename: ";
		cin >> filename;
		fin.clear();
		fin.open(filename);
	}
	if (err_count == 3) {
		cout << "Too many filename errors - exiting." << endl;
		return 1;
	}

	string line;
	unsigned int line_count = 0;
	int valid_count = 0;
	int sum = 0;

	//--- Read one line at a time as long as there's a line to read
	while (getline(fin, line)) {
		line_count++;

		//--- Pass the string to the string stream for processing
		istringstream ss(line);
		string token;

		//--- Process variable-length tokens in each line
		while (ss >> token) {
			bool valid = true;
			int value = 0;
			int i = 0;

			//--- Manual integer validation (handles optional + or -)
			if (token.empty()) valid = false;
			if (valid) {
				if (token[0] == '-' || token[0] == '+') i = 1;
				for (i; i < token.length(); i++) {
					if (!isdigit(token[i])) {
						valid = false;
						break;
					}
				}
			}

			if (valid) {
				stringstream convert(token);
				convert >> value;
				sum += value;
				valid_count++;
			}
			else {
				cout << "Bad Read: " << token << endl;

				bool fixed = false;

				//--- Loop until valid replacement or skip
				while (!fixed) {
					cout << "Enter replacement (or s to skip): ";
					string input;
					cin >> input;

					if (input == "s" || input == "S") {
						cout << "Skipping..." << endl;
						break;
					}

					bool replace_valid = true;
					int j = 0;

					if (input.empty()) replace_valid = false;

					if (replace_valid) {
						if (input[0] == '-' || input[0] == '+') j = 1;
						for (j; j < input.length(); j++) {
							if (!isdigit(input[j])) {
								replace_valid = false;
								break;
							}
						}
					}

					if (replace_valid) {
						stringstream convert(input);
						convert >> value;
						sum += value;
						valid_count++;
						cout << "Replaced " << token << " with " << value << endl;
						fixed = true;
					}
					else {
						cout << "Still invalid." << endl;
					}
				}
			}
		}
	}

	fin.close();

	cout << "---Summary---" << endl;
	cout << "Total Lines: " << line_count << endl;
	cout << "Number of values read: " << valid_count << endl;
	cout << "Total: " << sum << endl;

	if (valid_count > 0) {
		double average = static_cast<double>(sum) / valid_count;
		cout << "Average: " << setprecision(2) << fixed << average << endl;
	}
	else {
		cout << "No valid data processed." << endl;
	}

	return 0;
}