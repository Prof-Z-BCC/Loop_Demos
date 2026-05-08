#include <iostream>
#include <iomanip>
#include <sstream> //--- Required header for ostringstream
using namespace std;

int main() {
    double average;
    int input;
    int total = 0;
    int num_values = 0;
    bool cont = true;

    //--- Declare an output string stream object
    ostringstream oss_pos;
    ostringstream oss_neg;
    ostringstream oss_out;

    //--- Add initial text to the stream buffer
    oss_pos << "Positive values: ";
    oss_neg << "Negative values: ";

    //--- Apply formatting (precision, fixed) directly to the stream buffer
    oss_out << setprecision(2) << fixed;

    do {
        cout << "Enter the value to be used. Enter '0' to stop entry: ";
        cin >> input;

        if (!cin) {
            char c;
            cout << "Invalid number read...";
            cout << "Try again? (y or n): ";
            cin.clear();
            cin.ignore(100, '\n');
            cin.get(c);

            if (c == 'y' || c == 'Y') {
                cin.ignore(100, '\n');
                continue;
            }
            else {
                oss_pos << endl;
                oss_neg << endl;
                cont = false;
                continue;
            }
        }

        if (input == 0) {
            oss_out << oss_pos.str() << endl << oss_neg.str() << endl;
            cont = false;
        }
        else {
            //--- Store data in the stream instead of printing immediately
            if (input > 0) {
                oss_pos << input << " ";
            }
            else {
                oss_neg << input << " ";
            }
            total += input;
            num_values++;
        }
    } while (cont);

    if (num_values > 0) {
        average = static_cast<double>(total) / num_values;

        //--- Append final calculations to the stream
        oss_out << "Total: " << total << endl;
        oss_out << "Number of entries: " << num_values << endl;
        oss_out << "Average: " << average << endl;

        //--- .str() converts the stream buffer into a standard string for cout
        cout << oss_out.str();

        //--- To clear or reset the stream content, you would use:
        //--- oss.str(""); 
        //--- oss.clear(); // Resets error flags
    }
    else {
        cout << "No data entered." << endl;
    }

    return 0;
}
