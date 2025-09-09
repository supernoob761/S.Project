#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char *words[] = {"restart", "remove", "abandon", "inferno", "motivation", "suceed", "pause"};
    int totalWords = sizeof(words) / sizeof(words[0]);

    srand(time(NULL));
    char *word = words[rand() % totalWords];

    int length = strlen(word);
    char guess;
    int lives = 6;           
    int correct = 0;         
    char display[20];        
    
    
    for (int i = 0; i < length; i++) {
        display[i] = '_';
    }
    display[length] = '\0';

    printf("START!\n");

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
