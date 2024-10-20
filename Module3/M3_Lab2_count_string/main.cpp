#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;

    while (true) {
        cout << "Enter a sentence to analyze. Type 'END' to exit: ";
        getline(cin, input);

        if (input == "END") {
            break;
        }

        int letter_count = 0;
        int digit_count = 0;
        int special_count = 0;

        for (char c : input) {
            // Check if the character is a letter
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
                letter_count++;
                // Check if the character is a digit
            } else if (c >= '0' && c <= '9') {
                digit_count++;
                // Check if the character is a special character
            } else {
                special_count++;
            }
        }

        cout << "Letters: " << letter_count << endl;
        cout << "Numbers: " << digit_count << endl;
        cout << "Special characters: " << special_count << endl;

        // Prompt again
        cout << "If you are done, enter 'END'." << endl;
    }

    return 0;
}
