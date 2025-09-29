#include <stdio.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int precedence(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return -1;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, k = 0;
    char symbol;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while ((symbol = infix[i++]) != '\0') {
        // If operand (A–Z or a–z), directly add to postfix
        if ((symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z')) {
            postfix[k++] = symbol;
        }
        else if (symbol == '(') {
            push(symbol);
        }
        else if (symbol == ')') {
            while (stack[top] != '(')
                postfix[k++] = pop();
            pop(); // remove '('
        }
        else { // Operator
            while (top != -1 && precedence(stack[top]) >= precedence(symbol)) {
                postfix[k++] = pop();
            }
            push(symbol);
        }
    }

    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
