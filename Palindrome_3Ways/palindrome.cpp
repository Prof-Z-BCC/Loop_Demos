#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    // Check the string exactly as entered (case and spaces matter).
    // For example, "Racecar" is NOT considered a palindrome here because 'R' != 'r'.

    // --- Using a for loop
    bool isPal_for = true;
    for (size_t i = 0; i < s.size() / 2; ++i) { // Remember, size_t is just an unsigned int
        // s[i] is the character from the left,
        // s[s.size() - 1 - i] is the matching character from the right.
        // If they differ, it's not a palindrome.
        if (s[i] != s[s.size() - 1 - i]) {
            isPal_for = false;
            break; // stop the loop early because we already know it's not a palindrome
        }
    }

    // --- Using a while loop
    bool isPal_while = true;
    size_t left = 0;                            // start index from the left
    size_t right = (s.empty() ? 0 : s.size() - 1); // start index from the right
    while (left < right) {
        // Compare characters at left and right positions.
        if (s[left] != s[right]) {
            isPal_while = false;
            break; // stop early on mismatch
        }
        ++left;  // move left index one step to the right
        --right; // move right index one step to the left
    }
    
    // --- Using a do-while loop
    bool isPal_do = true;
    // A do-while loop always runs its body at least once, so we handle small strings first.
    if (s.size() < 2) {
        isPal_do = true; // strings with 0 or 1 character are palindromes by definition
    }
    else {
        size_t l = 0;
        size_t r = s.size() - 1;
        do {
            if (s[l] != s[r]) {
                isPal_do = false;
                break; // stop early on mismatch
            }
            ++l; // move inward from the left
            --r; // move inward from the right
            // The condition below is checked after the loop body runs.
        } while (l < r);
    }

    // Output results
    cout << "\nResults:\n";
    cout << "For loop:     " << (isPal_for ? "Palindrome" : "Not a palindrome") << '\n';
    cout << "While loop:   " << (isPal_while ? "Palindrome" : "Not a palindrome") << '\n';
    cout << "Do-while:     " << (isPal_do ? "Palindrome" : "Not a palindrome") << '\n';

    return 0;
}
