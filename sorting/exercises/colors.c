#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int length;
    printf("How many numbers and colors?: ");
    scanf("%d", &length);
    int* redNumbers = malloc(sizeof(int) * length);
    int* blueNumbers = malloc(sizeof(int) * length);
    int* yellowNumbers = malloc(sizeof(int) * length);
    int redCount = 0;
    int blueCount = 0;
    int yellowCount = 0;

    char* color = malloc(sizeof("yellow")); // "yellow" is the longest word
    for (int i = 0; i < length; i++) {
        int number;
        printf("Enter number: ");
        scanf("%d", &number);
        printf("Enter color: ");
        scanf("%s", color);
        if (!strcmp(color, "red")) {
            redNumbers[redCount] = number;
            redCount++;
        } else if (!strcmp(color, "blue")) {
            blueNumbers[blueCount] = number;
            blueCount++;
        } else if (!strcmp(color, "yellow")) {
            yellowNumbers[yellowCount] = number;
            yellowCount++;
        } else {
            printf("TERMINATING INVALID COLOR: %s\n", color);
            return 1;
        }
    }

    for (int i = 0; i < redCount; i++) {
        printf("(%d, red)\n", redNumbers[i]);
    }
    for (int i = 0; i < blueCount; i++) {
        printf("(%d, blue)\n", blueNumbers[i]);
    }
    for (int i = 0; i < yellowCount; i++) {
        printf("(%d, yellow)\n", yellowNumbers[i]);
    }
}