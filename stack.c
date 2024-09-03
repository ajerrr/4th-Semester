#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

float stack[MAX];
int top = -1;

void push(float val) {
    stack[++top] = val;
}

float pop() {
    return stack[top--];
}

float evaluatePostfix(char* postfix) {
    int i = 0;
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i]) || (postfix[i] == '.' && isdigit(postfix[i+1]))) {
            float num = 0;
            int decimal = 0, divide = 1;
            while (isdigit(postfix[i]) || postfix[i] == '.') {
                if (postfix[i] == '.')
                    decimal = 1;
                else if (decimal)
                    num += (postfix[i] - '0') / (float)(divide *= 10);
                else
                    num = num * 10 + (postfix[i] - '0');
                i++;
            }
            push(num);
        } else {
            float val1 = pop();
            float val2 = pop();
            switch (postfix[i]) {
                case '+': push(val2 + val1); break;
                case '-': push(val2 - val1); break;
                case '*': push(val2 * val1); break;
                case '/': push(val2 / val1); break;
            }
            i++;
        }
    }
    return pop();
}

int main() {
    char postfix[MAX] = "12.3 3.4 +";
    printf("Result: %.2f\n", evaluatePostfix(postfix));
    return 0;
}

