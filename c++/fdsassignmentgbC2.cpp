/* Second year Computer Engineering class, set A of students like Vanilla Ice-cream
and set B of students like butterscotch ice-cream.
Write C++ program to store two sets using linked list. compute and display :
a. Set of students who like either vanilla or butterscotch or both
b. Set of students who like both vanilla and butterscotch
c. Number of students who like neither vanilla nor butterscotch. */

#include <iostream>
#include <string>
#include <sstream>
#include <list>
using namespace std;

class node
{
public:
    int roll, vanilla, butterscotch;
    node *next;
};

class ll
{
public:
    void display(node *head)
    {
        node *temp = head;
        if (temp != NULL)
        {
            while (temp != NULL)
            {
                std::cout << temp->roll << " ";
                temp = temp->next;
            }
            std::cout << std::endl;
        }
        else
        {
            std::cout << "Linked list is empty!" << std::endl;
        }
    }

    void add_node(node **head)
    {
        int n;
        std::cout << "Enter how many students: ";
        cin >> n;
        std::cout << "--------------------------------------------------" << std::endl;
        for (int i = 0; i < n; i++)
        {
            node *new_node = new node();
            node *last = *head;
            std::cout << "Enter Roll: ";
            cin >> new_node->roll;
            std::cout << "Likes Vanilla      (yes = 1 / no = 0): ";
            cin >> new_node->vanilla;
            std::cout << "Likes Butterscotch (yes = 1 / no = 0): ";
            cin >> new_node->butterscotch;
            new_node->next = NULL;

            if (*head == NULL)
            {
                *head = new_node;
            }
            else
            {
                while (last->next != NULL)
                {
                    last = last->next;
                }
                last->next = new_node;
            }
            std::cout << std::endl;
        }
    }

    void either_or_both(node *head)
    {
        std::cout << "Set of students who like either vanilla or butterscotch or both: ";
        while ((head) != NULL)
        {
            if ((head)->vanilla == 0 && (head)->butterscotch == 1)
            {
                std::cout << (head)->roll << " ";
            }
            else if ((head)->vanilla == 1 && (head)->butterscotch == 0)
            {
                std::cout << (head)->roll << " ";
            }
            else if ((head)->vanilla == 1 && (head)->butterscotch == 1)
            {
                std::cout << (head)->roll << " ";
            }
            head = head->next;
        }
        std::cout << std::endl;
    }

    void both(node *head)
    {
        std::cout << "Set of students who like both vanilla and butterscotch: ";
        while ((head) != NULL)
        {
            if ((head)->vanilla == 1 && (head)->butterscotch == 1)
            {
                std::cout << (head)->roll << " ";
            }
            head = head->next;
        }
        std::cout << std::endl;
    }

    void nor_both(node *head)
    {
        int count = 0;
        std::cout << "Number of students who like neither vanilla nor butterscotch: ";
        while ((head) != NULL)
        {
            if ((head)->vanilla == 0 && (head)->butterscotch == 0)
            {
                count++;
            }
            head = head->next;
        }
        std::cout << count << std::endl;
    }
};

int main()
{
    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    ll obj1;
    node *head = NULL;
    obj1.add_node(&head);
    obj1.either_or_both(head);
    obj1.both(head);
    obj1.nor_both(head);

    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}