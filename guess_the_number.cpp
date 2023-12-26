#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    // Initialize the user's guess
    int userGuess = 0;

    // Keep asking for guesses until the correct number is guessed
    while (userGuess != secretNumber) {
        // Get user input for the guess
        cout << "Guess the number (between 1 and 100): ";
        cin >> userGuess;

        // Provide feedback on the guess
        if (userGuess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (userGuess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number, which was " << secretNumber << "." << endl;
        }
    }

    return 0;
}
