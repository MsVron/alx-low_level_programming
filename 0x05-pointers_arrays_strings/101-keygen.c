#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LEN 8

int main(void)
{
    srand(time(NULL));  // Initialize the random number generator with the current time

    char password[PASSWORD_LEN + 1];  // Allocate space for the password (plus a null terminator)

    for (int i = 0; i < PASSWORD_LEN; i++) {
        int r = rand() % 62;  // Generate a random number from 0 to 61
        if (r < 26) {
            password[i] = 'A' + r;  // If the number is less than 26, use a capital letter
        } else if (r < 52) {
            password[i] = 'a' + r - 26;  // If the number is between 26 and 51, use a lowercase letter
        } else {
            password[i] = '0' + r - 52;  // If the number is between 52 and 61, use a digit
        }
    }

    password[PASSWORD_LEN] = '\0';  // Add a null terminator to the end of the password

    printf("%s\n", password);  // Print the password

    return 0;
}

