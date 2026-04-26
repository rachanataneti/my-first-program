/*
include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int priority(char x) {
    if(x == '(') return 0;
    if(x == '+' || x == '-') return 1;
    if(x == '*' || x == '/') return 2;
    return 0;
}

int main() {
    char exp[100];
    int i = 0;
    char x;

    printf("Enter infix expression: ");
    scanf("%s", exp);

    printf("Postfix expression: ");

    while(exp[i] != '\0') {
        if(isalnum(exp[i])) {
            printf("%c", exp[i]);
        }
        else if(exp[i] == '(') {
            push(exp[i]);
        }
        else if(exp[i] == ')') {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else {
            while(priority(stack[top]) >= priority(exp[i]))
                printf("%c", pop());
            push(exp[i]);
        }
        i++;
    }

    while(top != -1) {
        printf("%c", pop());
    }

    return 0;
}
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char c) {
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    if(c == '^') return 3;
    return 0;
}

void reverse(char exp[]) {
    int i, j;
    char temp;
    for(i = 0, j = strlen(exp)-1; i < j; i++, j--) {
        temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
    }
}
void infixToPrefix(char infix[], char prefix[]) {
    int i, j = 0;
    char temp[MAX];

    reverse(infix);

    for(i = 0; infix[i]; i++) {
        if(infix[i] == '(')
            infix[i] = ')';
        else if(infix[i] == ')')
            infix[i] = '(';
    }

    for(i = 0; infix[i]; i++) {
        if(isalnum(infix[i])) {
            temp[j++] = infix[i];
        }
        else if(infix[i] == '(') {
            push(infix[i]);
        }
        else if(infix[i] == ')') {
            while(stack[top] != '(')
                temp[j++] = pop();
            pop();
        }
        else {
            while(top != -1 && precedence(stack[top]) >= precedence(infix[i]))
                temp[j++] = pop();
            push(infix[i]);
        }
    }

    while(top != -1)
        temp[j++] = pop();

    temp[j] = '\0';

    reverse(temp);
    strcpy(prefix, temp);
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s", prefix);

    return 0;
}
/*