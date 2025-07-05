#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>

using namespace std;

void printRules(){
    cout << "Welcome to the Number Guessing Game!" << "\n";
    cout << "You have to guess a number between 1 and 100 to figure out the correct answer " << "\n"; 
    cout << "Choose difficulty level: " << "\n";
    cout << "1. Easy (1-50, 10 attempts)" << "\n";
    cout << "2. Medium (1-100, 7 attempts)" << "\n";
    cout << "3. Hard (1-200, 5 attempts)" << "\n";
    cout << "Enter your choice (1-3): " << "\n";
}

bool askPlayAgain(){
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

void playGame(){
    int maximumRange = 100;
    int maximumAttempt = 7;
    int difficultyLevel;

    printRules();
    cin >> difficultyLevel;

    //Input Validation
    if (cin.fail() || difficultyLevel < 1 || difficultyLevel > 3){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice. Switching to Medium." << "\n";
        difficultyLevel = 2;
    }

    //Setting range and attempts based on difficulty
    if (difficultyLevel == 1){
        maximumRange = 50;
        maximumAttempt = 10;
    } else if (difficultyLevel == 2){
        maximumRange = 100;
        maximumAttempt = 7;
    } else {
        maximumRange = 200;
        maximumAttempt = 5;
    }

    srand(time(0));
    int randomizedNum = rand() % maximumRange + 1;

    int guess = 0;
    int attempts = 0;
    int lastDifference = -1;

    cout << "I have selected a number between 1 and " << maximumRange << ". Try to guess it." << "\n";

    while (guess != randomizedNum && attempts < maximumAttempt){
        cout << "Enter your guessed number: " << "\n";
        cin >> guess;

        //Validating input
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 100." << "\n";
            continue;
        }

        //Checking if number is out of range
        if (guess < 1 || guess > 100){
            cout << "Please enter a correct range between 1 and 100" << "\n";
            continue;
        }

        //Cheat for revealing the number
        if (guess == -1){
            cout << "The number is: " << randomizedNum << "\n";
            continue;
        }

        attempts++;

        int currentDifference = abs(guess - randomizedNum);

        if (lastDifference != -1){
            if (currentDifference < lastDifference){
                cout << "You're getting closer" << "\n";
            } else if (currentDifference > lastDifference){
                cout << "You're getting further away." << "\n";
            } else{
                cout << "Same distance as your last guess." << "\n";
            }
        }
        lastDifference = currentDifference;

        if (guess < randomizedNum){
            cout << "Too low!" << "\n";
        } else if (guess > randomizedNum){
            cout << "Too high!" << "\n";
        } else{
            cout << "Correct! You guessed the correct number in " << attempts << " attempts." << "\n";
            break;
        }

        cout << "Attempts left: " << (maximumAttempt - attempts) << "\n";
    }

    if (guess != randomizedNum){
        cout << "Game over! The number was: " << randomizedNum << "\n";
    }
}

int main(){
    do{
        playGame();
    } while (askPlayAgain());

    cout << "Thanks for playing!" << "\n";
    return 0;
}