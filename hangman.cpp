#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>

#define MAX_TRIES 6
#define WORD_LENGTH 100
#define GUESSED_LETTERS_LENGTH 26

using namespace std;

void printHangman(int tries) {
    switch (tries) {
        case 0:
            cout << "\n╔═════╗\n║     ║\n║     \n║     \n║     \n║     \n╚═════╝\n";
            break;
        case 1:
            cout << "\n╔═════╗\n║     ║\n║     O\n║     \n║     \n║     \n╚═════╝\n";
            break;
        case 2:
            cout << "\n╔═════╗\n║     ║\n║     O\n║     │\n║     \n║     \n╚═════╝\n";
            break;
        case 3:
            cout << "\n╔═════╗\n║     ║\n║     O\n║    /│\n║     \n║     \n╚═════╝\n";
            break;
        case 4:
            cout << "\n╔═════╗\n║     ║\n║     O\n║    /│\\\n║     \n║     \n╚═════╝\n";
            break;
        case 5:
            cout << "\n╔═════╗\n║     ║\n║     O\n║    /│\\\n║    / \n║     \n╚═════╝\n";
            break;
        case 6:
            cout << "\n╔═════╗\n║     ║\n║     O\n║    /│\\\n║    / \\\n║     \n╚═════╝\n";
            break;
    }
}

void chooseWord(char word[]) {
    const char *wordList[] = {
        "computer", "science", "hangman", "programming", "mathematics", "engineer", "education", "algorithm"
    };
    int index = rand() % 8;
    strcpy(word, wordList[index]);
}

void printBoxedMessage(const char *message) {
    int len = strlen(message);
    cout << "╔";
    for (int i = 0; i < len + 2; i++) cout << "═";
    cout << "╗\n║ " << message << " ║\n╚";
    for (int i = 0; i < len + 2; i++) cout << "═";
    cout << "╝\n";
}

int main() {
    char word[WORD_LENGTH], guessedWord[WORD_LENGTH];
    char guessedLetters[GUESSED_LETTERS_LENGTH + 1] = {0}; // +1 for null terminator
    int tries = 0, wordLength, correctGuesses = 0;

    srand(static_cast<unsigned int>(time(0)));
    chooseWord(word);
    wordLength = strlen(word);

    for (int i = 0; i < wordLength; i++) {
        guessedWord[i] = '_';
    }
    guessedWord[wordLength] = '\0';

    printBoxedMessage("Welcome to Hangman!");

    while (tries < MAX_TRIES) {
        printHangman(tries);
        cout << "\nWord: " << guessedWord << endl;
        cout << "Guessed Letters: " << guessedLetters << endl;
        cout << "Guess a letter: ";
        
        char guess;
        cin >> guess;
        guess = tolower(guess);

        if (strchr(guessedLetters, guess)) {
            printBoxedMessage("You've already guessed that letter.");
            continue;
        }

        strncat(guessedLetters, &guess, 1);

        bool correct = false;
        for (int i = 0; i < wordLength; i++) {
            if (word[i] == guess) {
                guessedWord[i] = guess;
                correct = true;
                correctGuesses++;
            }
        }

        if (!correct) {
            tries++;
        }

        if (correctGuesses == wordLength) {
            printBoxedMessage("Congratulations! You guessed the word!");
            break;
        }
    }

    if (tries == MAX_TRIES) {
        printHangman(tries);
        printBoxedMessage("Game Over! The word was:");
        cout << " " << word << endl;
    }

    return 0;
}
