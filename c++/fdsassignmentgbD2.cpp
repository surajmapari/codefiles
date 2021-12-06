/* Implement C++ program for expression conversion as infix to postfix and its evaluation
using stack based on given conditions
i. Operands and operator, both must be single character.
ii. Input Postfix expression must be in a desired format.
iii. Only '+', '-', '*' and '/ ' operators are expected. */

#define MAX 30
#include <iostream>
using namespace std;

class stack
{
private:
    int arr_top = -1;
    char arr[MAX];

public:
    void push(char c)
    {
        if (arr_top == MAX - 1)
        {
            std::cout << "Stack Overflow!" << std::endl;
        }
        else
        {
            arr[++arr_top] = c;
        }
    }

    void pop()
    {
        if (arr_top == -1)
        {
            std::cout << "Stack is Empty!" << std::endl;
        }
        else
        {
            arr_top--;
        }
    }

    char top()
    {
        if (arr_top == -1)
        {
            std::cout << "Stack is Empty!" << std::endl;
            return -1;
        }
        else
        {
            return arr[arr_top];
        }
    }

    bool empty()
    {
        return arr_top == -1;
    }
};

int precedence(char c)
{
    if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infix_to_postfix(string infix_expression)
{
    stack st;
    string postfix_expression;

    for (int i = 0; i < infix_expression.length(); i++)
    {
        char c = infix_expression[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            postfix_expression += c;

        else if (c == '(')
            st.push(c);

        else if (c == ')')
        {
            while (st.top() != '(')
            {
                postfix_expression += st.top();
                st.pop();
            }
            st.pop();
        }

        else
        {
            while (!st.empty() && precedence(infix_expression[i]) <= precedence(st.top()))
            {
                postfix_expression += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        postfix_expression += st.top();
        st.pop();
    }

    return postfix_expression;
}

int postfix_evalution(string postfix_expression)
{
    stack st;
    for (int i = 0; i < postfix_expression.length(); i++)
    {
        char c = postfix_expression[i];
        if (c >= '0' && c <= '9')
        {
            st.push(c - '0'); // to convert char to int
        }
        else
        {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            switch (c)
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    string choice = "y";
    string infix_expression, postfix_expression;
    while (choice == "y")
    {
        std::cout << "Enter the infix expression: ";
        getline(cin, infix_expression);
        postfix_expression = infix_to_postfix(infix_expression);
        std::cout << "The postfix expression is: " << postfix_expression << std::endl;
        std::cout << "The result of postfix expression is: " << postfix_evalution(postfix_expression) << std::endl;
        std::cout << "Do you want to continue(y/n): ";
        getline(cin, choice);
        std::cout << "--------------------------------------------------" << std::endl;
    }

    std::cout << "----------------------THANK_YOU-------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}

// sample test cases
// (a-b/c)*(a/k-l)
// (((4+6)/2)*5)+7
