//1
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to print prefixes
void printPrefixes(char *str) {
    int len = strlen(str);

    printf("\nPrefixes:\n");
    for (int i = 0; i < len; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%c", str[j]);
        }
        printf("\n");
    }
    printf("*********\n");
}

// Function to print suffixes
void printSuffixes(char *str) {
    int len = strlen(str);

    printf("\nSuffixes:\n");
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            printf("%c", str[j]);
        }
        printf("\n");
    }
    printf("*********\n");
}

// Function to print substrings
void printSubstrings(char *str) {
    int len = strlen(str);

    printf("\nSubstrings:\n");
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            for (int k = i; k <= j; k++) {
                printf("%c", str[k]);
            }
            printf("\n");
        }
    }
    printf("*********\n");
}

int main() {
    char str[MAX_LENGTH];
    char choice;

    do {
        printf("Enter a string: ");
        scanf("%s", str);

        printPrefixes(str);
        printSuffixes(str);
        printSubstrings(str);

        printf("Do you want to enter another string? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("Program Exiting!!!\n");

    return 0;
}
