#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_game() {
    char input[50];
    int guesses = 0;


    int random_number = (rand() % 100) + 1;
    while (1) {
        printf("Enter your guess: ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            return;
        }

        char *endptr;
        long guess = strtol(input, &endptr, 10);

        if (endptr == input || *endptr != '\n' && *endptr != '\0') {
            printf("Please enter a number\n");
            continue;
        }

        if (guess > 100) {
            printf("Please enter a valid number!\n");
            guesses++;
        } else if (guess < 1) {
            printf("Please enter a valid number!\n");
            guesses++;
        } else if (guess > random_number) {
            printf("Too high!\n");
            guesses++;
        } else if (guess < random_number) {
            printf("Too low!\n");
            guesses++;
        } else {
            guesses++;
            printf("Correct! It took you %d attempts!\n", guesses);
            break;
        }
    }
    return;
}

int main(void) {
    srand(time(NULL));
    play_game();
    return 0;
}