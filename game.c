#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_TRIES 6
#define WORD_LENGTH 100

void printHangman(int tries) {
    switch (tries) {
        case 0:
            printf("\n\n");
            printf("  +---+\n");
            printf("  |   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 1:
            printf("\n\n");
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 2:
            printf("\n\n");
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf("  |   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 3:
            printf("\n\n");
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 4:
            printf("\n\n");
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 5:
            printf("\n\n");
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf(" /    |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 6:
            printf("\n\n");
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf(" / \\  |\n");
            printf("      |\n");
            printf("=========\n");
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

int main() {
    char word[WORD_LENGTH], guessedWord[WORD_LENGTH];
    char guessedLetters[26] = {0};
    int tries = 0, wordLength, correctGuesses = 0;

    srand(time(0));
    chooseWord(word);
    wordLength = strlen(word);

    for (int i = 0; i < wordLength; i++) {
        guessedWord[i] = '_';
    }
    guessedWord[wordLength] = '\0';

    printf("Welcome to Hangman!\n");

    while (tries < MAX_TRIES) {
        printHangman(tries);
        printf("Word: %s\n", guessedWord);
        printf("Guessed Letters: %s\n", guessedLetters);
        printf("Guess a letter: ");
        
        char guess;
        scanf(" %c", &guess);
        guess = tolower(guess);

        int alreadyGuessed = 0;
        for (int i = 0; i < strlen(guessedLetters); i++) {
            if (guessedLetters[i] == guess) {
                alreadyGuessed = 1;
                break;
            }
        }

        if (alreadyGuessed) {
            printf("You've already guessed that letter.\n");
            continue;
        }

        strncat(guessedLetters, &guess, 1);

        int correct = 0;
        for (int i = 0; i < wordLength; i++) {
            if (word[i] == guess) {
                guessedWord[i] = guess;
                correct = 1;
                correctGuesses++;
            }
        }

        if (!correct) {
            tries++;
        }

        if (correctGuesses == wordLength) {
            printf("Congratulations! You guessed the word: %s\n", word);
            break;
        }
    }

    if (tries == MAX_TRIES) {
        printHangman(tries);
        printf("Game Over! The word was: %s\n", word);
    }

    return 0;
}
