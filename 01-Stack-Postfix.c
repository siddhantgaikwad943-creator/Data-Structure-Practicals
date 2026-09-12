#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push an element into stack
void push(int x)
{
    stack[++top] = x;
}

// Pop an element from stack
int pop()
{
    return stack[top--];
}

int main()
{
    char exp[MAX];
    char *e;
    int n1, n2, n3;
    int num;

    printf("Enter the postfix expression: ");
    fgets(exp, MAX, stdin);

    e = exp;

    while (*e != '\0')
    {
        // Ignore spaces
        if (*e == ' ')
        {
            e++;
            continue;
        }

        // If character is a digit, form the complete number
        if (isdigit(*e))
        {
            num = 0;

            while (isdigit(*e))
            {
                num = num * 10 + (*e - '0');
                e++;
            }

            push(num);
        }
        else
        {
            // Check for valid operator
            if (*e == '+' || *e == '-' || *e == '*' || *e == '/')
            {
                n1 = pop();
                n2 = pop();

                switch (*e)
                {
                    case '+':
                        n3 = n2 + n1;
                        break;

                    case '-':
                        n3 = n2 - n1;
                        break;

                    case '*':
                        n3 = n2 * n1;
                        break;

                    case '/':
                        n3 = n2 / n1;
                        break;
                }

                push(n3);
            }
            else if (*e != '\n')
            {
                printf("Invalid character in expression.\n");
                return 1;
            }

            e++;
        }
    }

    printf("Result = %d\n", pop());

    return 0;
}