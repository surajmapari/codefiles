/* Queues are frequently used in computer programming, and a typical example is the
creation of a job queue by an operating system. If the operating system does not use
priorities, then the jobs are processed in the order they enter the system. Write C++
program for simulating job queue. Write functions to add job and delete job from queue. */

#include <iostream>
#include <string>
#include <sstream>
#define MAX 20
using namespace std;

struct queue
{
    int data[MAX], front, rear;
};

class queue_functions
{
private:
    struct queue q;

    bool isempty()
    {
        return (q.front == q.rear || q.rear == -1) ? true : false;
    }

    bool isfull()
    {
        return (q.front != q.rear && q.rear == MAX - 1) ? true : false;
    }

public:
    queue_functions()
    {
        q.front = q.rear = -1;
    }

    void display()
    {
        if (isempty())
        {
            std::cout << "Queue Underflow!" << std::endl;
        }
        else
        {
            for (int i = q.front + 1; i <= q.rear; i++)
            {
                std::cout << q.data[i] << " ";
            }
            std::cout << std::endl;
        }
    }

    void enqueue()
    {
        if (isfull())
        {
            std::cout << "Queue Overflow!" << std::endl;
        }
        else
        {
            int x;
            std::cout << "Enter Job: ";
            cin >> x;
            q.data[++q.rear] = x;
            display();
        }
    }

    void dequeue()
    {
        if (isempty())
        {
            std::cout << "Queue Underflow!" << std::endl;
        }
        else
        {
            std::cout << "Deleted element: " << q.data[++q.front] << std::endl;
            display();
        }
    }
};

int main()
{
    std::cout << "\n--------------------------------------------------" << std::endl;

    queue_functions obj;
    int choice;
    do
    {
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << "1.Insert Job" << std::endl;
        std::cout << "2.Delete Job" << std::endl;
        std::cout << "3.Display Jobs" << std::endl;
        std::cout << "4.Exit" << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << "Enter your choice: ";
        cin >> choice;
        std::cout << "--------------------------------------------------" << std::endl;

        switch (choice)
        {
        case 1:
            obj.enqueue();
            break;
        case 2:
            obj.dequeue();
            break;
        case 3:
            obj.display();
            break;
        default:
            break;
        }
    } while (choice != 4);

    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}