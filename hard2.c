#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_palindrome(char *string, int length) {
    for (int i = 0; i < length / 2; i++) {
        if (string[i] != string[length - i - 1]) {
            return 0; 
        }
    }
    return 1; 
}

void reverse_string(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

char* shortest_palindrome(char *s) {
    if (s[0] == '\0') {
        char *empty = "";
        return empty;
    }

    int length = strlen(s);
    char *result = (char *)malloc(sizeof(char) * (2 * length + 1));
    if (result == NULL) {
        printf("Memory allocation failed.");
        return NULL;
    }

    int i;
    for (i = length; i > 0; i--) {
        if (is_palindrome(s, i)) {
            strcpy(result, s + i);
            reverse_string(result);
            strcat(result, s);
            break;
        }
    }

    return result;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    char *result = shortest_palindrome(input);
    
    if (result != NULL) {
        printf("Shortest palindrome: %s\n", result);
        free(result);
    }

    return 0;
}


