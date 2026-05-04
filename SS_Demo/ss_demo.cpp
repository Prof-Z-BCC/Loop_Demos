#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream> //--- string stream - reprocessing an input

using namespace std;

int main() {

	ifstream fin("data2.txt");

	//--- Error check on file opening
	while (!fin) {
		cout << "Error - no such file." << endl;
		string filename;
		cout << "Enter the filename: ";
		cin >> filename;
		fin.clear();
		fin.open(filename);
	}

	string line;
	unsigned int line_count = 0;
	int valid_count = 0;

	int sum = 0;

	//--- Read one line at a time as long as there's a line to read
	while (getline(fin, line)) {

		//--- Pass the string to the string stream for processing
		istringstream ss(line);
		int a, b;
		line_count++;

		//--- Reads essentially like cin >> or fin >>
		ss >> a >> b;

		if (ss) {
			cout << "Line: " << line_count << " is valid" << endl;
			sum += a + b;
			valid_count += 2;
		}
		else {
			cout << "Invalid data on line: " << line_count << ". Skipping input." << endl;
			continue;
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