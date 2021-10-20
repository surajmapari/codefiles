/* Q.2 Write a C++ Program to perform Stack Push() and Pop()
operation on integer and floating type data types using function template */

#include <iostream>
#include <string>
using namespace std;

template <typename type, int size>
class Stack
{
private:
    type *stack;
    int top;

public:
    Stack();
    ~Stack();

    void push(type element);
    type pop();
    void display();
    type get_top_element();
    bool is_empty();
    void clear();
};

template <typename type, int size>
Stack<type, size>::Stack()
{
    stack = new type[size];
    top = -1;
}

template <typename type, int size>
Stack<type, size>::~Stack()
{
    delete[] stack;
}

template <typename type, int size>
void Stack<type, size>::push(type element)
{
    if (top == size - 1)
    {
        throw out_of_range("Stack Overflow!! No more space to add elements.");
    }

    // insert element on next position in array
    stack[++top] = element;
}

template <typename type, int size>
type Stack<type, size>::pop()
{
    // check for underflow
    if (is_empty())
    {
        throw out_of_range("Stack Underflow!! No more element to pop.");
    }

    // pop element
    type element_popped = stack[top--];
    return element_popped;
}

template <typename type, int size>
void Stack<type, size>::display()
{
    // check for empty stack
    if (is_empty())
    {
        cout << "Woops! stack is empty." << endl;
        return;
    }

    // loop over stack and display all elements
    for (int i = top; i >= 0; i--)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}

template <typename type, int size>
type Stack<type, size>::get_top_element()
{
    if (is_empty())
    {
        throw out_of_range("Stack is empty!!");
    }
    return stack[top];
}

template <typename type, int size>
bool Stack<type, size>::is_empty()
{
    return top == -1;
}

template <typename type, int size>
void Stack<type, size>::clear()
{
    // free current memory occupied by the stack
    delete[] stack;
    // reset top
    top = -1;
    // assign new memory
    stack = new type[size];
}

int main()
{
    cout << "Stack implemented as Array";

    const int stack_size = 6;
    Stack<int, stack_size> my_stack;

    int choice;
    while (true)
    {
        cout << "\nChoose an operation:\n";
        cout << "1. Push\n"
             << "2. Pop\n"
             << "3. Display\n"
             << "4. Display top\n"
             << "5. Stack empty?\n"
             << "6. Clear stack\n"
             << "7. Exit" << endl;
        cout << "Enter a choice(1-6): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int element;
            cout << "Enter element to push: ";
            cin >> element;
            try
            {
                my_stack.push(element);
                cout << "Pushed to stack\n";
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
            break;
        case 2:
            try
            {
                int popped_element = my_stack.pop();
                cout << "Top most element popped: " << popped_element << endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
            break;
        case 3:
            cout << "Stack right now:\n";
            my_stack.display();
            break;
        case 4:
            try
            {
                cout << "Top most element: " << my_stack.get_top_element() << endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
            break;
        case 5:
            my_stack.is_empty() ? cout << "Stack is empty right now.\n" : cout << "Stack is not empty right now.\n";
            break;
        case 6:
            my_stack.clear();
            cout << "Stack cleared.\n";
            break;
        case 7:
            exit(0);
            break;
        default:
            cout << "Invalid Input!! Please Try Again.\n"
                 << endl;
            break;
        }
    }
    return 0;
}
