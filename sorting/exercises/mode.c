#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int main() {
    int length;
    printf("Size of set: ");
    scanf("%d", &length);
    int *set = malloc(sizeof(int) * length);
    
    for (int i=0; i<length; i++) {
        printf("Input number: ");
        scanf("%d", &set[i]);
    }

    sort(set, length);

    int currentMode;
    int modeOccurrence = 0;
    for (int i=0; i<length;) {
        int occurence = 0;
        int j;

        for (j=i+1; j<length; j++) {
            if (set[i] == set[j]) {
                occurence++;
            } else {
                break;
            }
        }

        if (occurence > modeOccurrence) {
            currentMode = set[i];
            modeOccurrence = occurence;
        }

        i = j;
    }

    printf("Mode is %d\n", currentMode);
}