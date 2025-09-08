#include <stdio.h>
#include <string.h>

int main() {
    char word[] = "apple";   // Secret word
    int length = strlen(word);
    char guess;
    int lives = 6;           // Number of tries
    int correct = 0;         // Correct guesses
    char display[20];        // To show progress
    
    // Initialize display with underscores
    for (int i = 0; i < length; i++) {
        display[i] = '_';
    }
    display[length] = '\0';

    printf("Welcome to Hangman!\n");

    while (lives > 0 && correct < length) {
        printf("\nWord: %s\n", display);
        printf("Lives left: %d\n", lives);
        printf("Enter a letter: ");
        scanf(" %c", &guess);

        int found = 0;
        for (int i = 0; i < length; i++) {
            if (word[i] == guess && display[i] == '_') {
                display[i] = guess;
                correct++;
                found = 1;
            }
        }

        if (!found) {
            lives--;
            printf("Wrong guess!\n");
        }
    }

    if (correct == length) {
        printf("\nYou win! The word was %s\n", word);
    } else {
        printf("\nGame over! The word was %s\n", word);
    }

    return 0;
}
