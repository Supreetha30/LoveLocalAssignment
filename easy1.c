#include <stdio.h>
#include <string.h>

int length_of_last_word(char *s) {
    int length = strlen(s);
    int count = 0;
    
    for (int i = length - 1; i >= 0; i--) {
        if (s[i] != ' ') {
            int j = i;
            while (j >= 0 && s[j] != ' ') {
                count++;
                j--;
            }
            break;
        }
    }
    return count;
}

int main() {
    char input[100]; 
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; 
    
    int result = length_of_last_word(input);
    printf("Length of the last word: %d\n", result);

    return 0;
}

