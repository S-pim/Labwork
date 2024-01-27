#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int ravenstvo(int start, int end);
int sum(int n);
int start, end;

bool isInteger(const char *input) {
    char *endptr;
    strtol(input, &endptr, 10); 

    if (*endptr != '\0' && *endptr != '\n') {
        return false; 
    }
    
    long value = strtol(input, &endptr, 10);
    
    return (value >= INT_MIN && value <= INT_MAX); 
}

int getInput(const char *prompt, int *value) {
    int spaces = 5;
    while (1) {
        char input[100];
        printf("%*s %s\n", spaces, "", prompt);
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input.\n");
            return 1;
        }

        if (!isInteger(input)) {
            printf("%*s Invalid format or out of range. Enter an integer:\n", spaces, " ");
            continue;
        }

        *value = strtol(input, NULL, 10); 
        return 0; 
    }
}

int main() {
    

    if (getInput("Enter the beginning of the range:", &start) != 0) {
        return 1;
    }

    if (getInput("Enter the end of the range:", &end) != 0) {
        return 1;
    }

    if (start > end) {
        printf("%*s The start of the range is greater than the end. Swapping the values...\n", 5, "");
        int temp = start;
        start = end;
        end = temp;
    }
   
    printf("Numbers satisfying the condition: \n");
    ravenstvo(start, end);
    return 0;
}

int sum(int n) {
    int c = 0;
    n = abs(n);
    while (n) {
        c += n % 10;
        n /= 10;
    }
    return c;
}

int ravenstvo(int start, int end) {
    int count = 0;
    bool found = false;
    while (start <= end) {
        int square, cube, s;
        s = sum(start);
        square = start * start;
        cube = s * s * s;
        if (cube == square) {
            printf("%d\n", start);
            found = true;
            count++;
        }
        start++;
    }
    if (!found) {
        printf("No number in the specified range satisfies the condition.\n");
    }
    return count;
}