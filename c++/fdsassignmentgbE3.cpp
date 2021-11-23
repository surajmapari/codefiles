/* Pizza parlor accepting maximum M orders. Orders are served in first come first served
basis. Order once placed cannot be cancelled. Write C++ program to simulate the system
using circular queue using array. */

#include <iostream>
#include <windows.h>
#define MAX 20
using namespace std;

struct Pizza_Parlor
{
    int order_id[MAX], front, rear;
    string orderer_name[MAX];
};

class queue_functions
{
private:
    struct Pizza_Parlor q;
    bool isempty()
    {
        return (q.rear == -1) ? true : false;
    }

    bool isfull()
    {
        return ((q.rear + 1) % MAX == q.front) ? true : false;
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
            std::cout << "Cafe is EMPTY!!!" << std::endl;
        }
        else
        {
            int i = q.front;
            while (i != q.rear + 1)
            {
                std::cout << "Order Id: " << q.order_id[i] << " Orderer Name: " << q.orderer_name[i] << std::endl;
                i = (i + 1) % MAX;
            }
        }
    }

    void place_order()
    {
        if (isfull())
        {
            std::cout << "Orders are FULL!!! New orders are not possible!!!" << std::endl;
        }
        else if (isempty())
        {
            int id;
            string name;
            std::cout << "Enter Order ID: ";
            cin >> id;
            std::cout << "Enter Orderer Name: ";
            cin >> name;
            q.front = q.rear = 0;
            q.order_id[q.rear] = id;
            q.orderer_name[q.rear] = name;
            std::cout << "Order Placed successfully" << std::endl;
            std::cout << std::endl;
            display();
        }
        else
        {
            int pos = (q.rear + 1) % MAX;
            if (pos == q.front)
            {
                std::cout << "Cafe is Full!!" << std::endl;
            }
            else
            {
                int id;
                string name;
                std::cout << "Enter Order ID: ";
                cin >> id;
                std::cout << "Enter Orderer Name: ";
                cin >> name;
                q.rear = pos;
                q.order_id[q.rear] = id;
                q.orderer_name[q.rear] = name;
                std::cout << std::endl;
                display();
            }
        }
    }

    void serve_order()
    {
        if (isempty())
        {
            std::cout << "No orders to Serve!!" << std::endl;
        }
        else
        {
            std::cout << "Order Id: " << q.order_id[q.front] << " Orderer Name: " << q.orderer_name[q.front] << std::endl;
            if (q.front == q.rear)
            {
                q.front = q.rear = -1;
            }
            else
            {
                q.front = (q.front + 1) % MAX;
            }
            std::cout << "Order Served successfully" << std::endl;
            std::cout << std::endl;
            display();
        }
    }
};

int main()
{
    queue_functions obj;
    int choice;
    
    std::cout << "\n-----------------PizzaParlor Menu-----------------" << std::endl;
    do
    {
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << "1.Place Order" << std::endl;
        std::cout << "2.Serve Order" << std::endl;
        std::cout << "3.Display order_id" << std::endl;
        std::cout << "4.Exit" << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << "Enter your choice: ";
        cin >> choice;
        std::cout << "--------------------------------------------------" << std::endl;

        switch (choice)
        {
        case 1:
            obj.place_order();
            break;
        case 2:
            obj.serve_order();
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