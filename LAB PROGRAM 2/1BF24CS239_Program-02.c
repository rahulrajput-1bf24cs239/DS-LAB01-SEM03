#include <stdio.h>
#include <ctype.h>

#define SIZE 50

char stack[SIZE];
int top = -1; // Global stack pointer

// Function to push an element into the stack
void push(char elem) {
    stack[++top] = elem;
}

// Function to pop an element from the stack
char pop() {
    return (stack[top--]);
}

// Function to return precedence of operators
int pr(char symbol) {
    if (symbol == '*' || symbol == '/') // Highest precedence
        return 2;
    else if (symbol == '+' || symbol == '-') // Lowest precedence
        return 1;
    else
        return 0;
}

// Main function
int main() {
    char infix[50], postfix[50], ch, elem;
    int i = 0, k = 0;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    push('#'); // Sentinel value

    while ((ch = infix[i++]) != '\0') {
        if (ch == '(') {
            push(ch);
        } else if (isalnum(ch)) {
            postfix[k++] = ch; // Operand
        } else if (ch == ')') {
            while (stack[top] != '(')
                postfix[k++] = pop();
            elem = pop(); // Remove '('
        } else { // Operator
            while (pr(stack[top]) >= pr(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }

    // Pop remaining operators
    while (stack[top] != '#')
        postfix[k++] = pop();

    postfix[k] = '\0'; // End string

    printf("\nPostfix Expression = %s\n", postfix);
    return 0;
}
