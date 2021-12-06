/* A double-ended queue (deque) is a linear list in which additions and deletions may be made at either end.
Obtain a data representation mapping a deque into a one-dimensional array.
Write C++ program to stimulate deque with functions to add and delete elements from either end of the deque. */

#define MAX 100
#include <iostream>
using namespace std;

struct dequeue
{
    int data[MAX], front = -1, rear = -1;
};

class dequeue_functions
{
private:
    struct dequeue dq;
    bool isempty()
    {
        return (dq.front == -1) ? true : false;
    }

    bool isfull()
    {
        return ((dq.front == 0 && dq.rear == MAX - 1) || (dq.front == dq.rear + 1)) ? true : false;
    }

public:
    void insert_at_front()
    {
        if (isfull())
        {
            std::cout << "Deque Overflow!" << std::endl;
            return;
        }
        if (isempty())
        {
            dq.front = dq.rear = 0;
        }
        else
        {
            if (dq.front == 0)
            {
                dq.front = MAX - 1;
            }
            else
            {
                dq.front = dq.front - 1;
            }
        }
        int x;
        std::cout << "Enter the element: ";
        cin >> x;
        dq.data[dq.front] = x;
    }

    void insert_at_rear()
    {
        if (isfull())
        {
            std::cout << "Deque Overflow!" << std::endl;
            return;
        }
        if (isempty())
        {
            dq.front = dq.rear = 0;
        }
        else
        {
            if (dq.rear == MAX - 1)
            {
                dq.rear = 0;
            }
            else
            {
                dq.rear = dq.rear + 1;
            }
        }
        int x;
        std::cout << "Enter the element: ";
        cin >> x;
        dq.data[dq.rear] = x;
    }

    void delete_at_front()
    {
        if (isempty())
        {
            std::cout << "Deque Underflow!" << std::endl;
            return;
        }
        std::cout << "Deleted element is: " << dq.data[dq.front] << std::endl;
        if (dq.front == dq.rear)
        {
            dq.front = dq.rear = -1;
        }
        else
        {
            if (dq.front == MAX - 1)
            {
                dq.front = 0;
            }
            else
            {
                dq.front = dq.front + 1;
            }
        }
    }

    void delete_at_rear()
    {
        if (isempty())
        {
            std::cout << "Deque Underflow!" << std::endl;
            return;
        }
        std::cout << "Deleted element is: " << dq.data[dq.rear] << std::endl;
        if (dq.front == dq.rear)
        {
            dq.front = dq.rear = -1;
        }
        else
        {
            if (dq.rear == 0)
            {
                dq.rear = MAX - 1;
            }
            else
            {
                dq.rear = dq.rear - 1;
            }
        }
    }

    void display()
    {
        int left = dq.front, right = dq.rear;
        if (isempty())
        {
            std::cout << "Deque Underflow!" << std::endl;
            return;
        }
        if (left <= right)
        {
            while (left <= right)
            {
                std::cout << dq.data[left++] << " ";
            }
        }
        else
        {
            while (left <= MAX - 1)
            {
                std::cout << dq.data[left++] << " ";
            }
            left = 0;
            while (left <= right)
            {
                std::cout << dq.data[left++] << " ";
            }
        }
        std::cout << std::endl;
    }
};

int main()
{
    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "---------------------MAIN_MENU--------------------" << std::endl;
    dequeue_functions obj;
    char choice;
    do
    {
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << "1.Insertion from front end" << std::endl;
        std::cout << "2.Insertion from rear end" << std::endl;
        std::cout << "3.Deletion from front end" << std::endl;
        std::cout << "4.Deletion from rear end" << std::endl;
        std::cout << "5.Display" << std::endl;
        std::cout << "6.Exit" << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << "Enter the choice: ";
        cin >> choice;
        std::cout << "--------------------------------------------------" << std::endl;
        switch (choice)
        {
        case '1':
            obj.insert_at_front();
            obj.display();
            break;
        case '2':
            obj.insert_at_rear();
            obj.display();
            break;
        case '3':
            obj.delete_at_front();
            obj.display();
            break;
        case '4':
            obj.delete_at_rear();
            obj.display();
            break;
        case '5':
            obj.display();
            break;
        }
    } while (choice != '6');

    std::cout << "---------------------THANK_YOU--------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}
