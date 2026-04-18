#include <stdio.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = ch;
    }
}

// Pop function
char pop() {
    if (top == -1) {
        return '\0';
    } else {
        return stack[top--];
    }
}

int main() {
    char str[MAX];
    int i, len;
    int isPalindrome = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    // Push all characters into stack
    for (i = 0; i < len; i++) {
        push(str[i]);
    }

    // Compare characters
    for (i = 0; i < len; i++) {
        if (str[i] != pop()) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}