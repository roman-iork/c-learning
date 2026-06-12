#include <stdio.h>

int main() {
    
    int capacity = 10;
    int len = 0;
    printf("Enter a string of text to count its length: \n");
    char ch;
    while (scanf("%c", &ch) == 1 && ch != '\n') {
        len++;
        printf("%d %c\n", len, ch);
    }
    printf("\nLength of a string is: %d character(s).", len);
    return 0;
}