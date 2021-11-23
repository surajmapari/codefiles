/* Department of Computer Engineering has student's club named 'Pinnacle Club'. Students
of second, third and final year of department can be granted membership on request.
Similarly one may cancel the membership of club. First node is reserved for president of
club and last node is reserved for secretary of club. Write C++ program to maintain club
member‘s information using singly linked list. Store student PRN and Name. Write
functions to:
1. Add and delete the members as well as president or even secretary.
2. Compute total number of members of club.
3. Display members.
4. Two linked lists exist for two divisions. Concatenate two lists. */

#include <iostream>
using namespace std;

class node
{
public:
    int prn, year;
    string name, post;
    node *next;
};

class pinnacle
{
    node *head = NULL, *temp = NULL;

public:
    void funAddMem(node **head)
    {
        node *new_node = new node();
        std::cout << "Enter prn: ";
        cin >> new_node->prn;
        std::cout << "Enter name: ";
        cin >> new_node->name;
        std::cout << "Enter year: ";
        cin >> new_node->year;
        std::cout << "Enter post: ";
        cin >> new_node->post;
        new_node->next = NULL;

        node *temp = new_node;

        if (*head == NULL)
        {
            *head = temp;
        }
        else
        {
            if (temp->post == "p")
            {
                temp->next = (*head)->next;
                *head = temp;
            }
            else
            {
                node *trav = *head;
                node *prev = NULL;
                while (trav->next != NULL)
                {
                    prev = trav;
                    trav = trav->next;
                }
                if (temp->post == "s")
                {
                    trav->next = temp;
                }
                else
                {
                    if (trav->post == "s")
                    {
                        if (prev == NULL)
                        {
                            temp->next = trav;
                            *head = temp;
                        }
                        else
                        {
                            temp->next = trav;
                            prev->next = temp;
                        }
                    }
                    else
                    {
                        trav->next = temp;
                    }
                }
            }
        }
    }

    void compMember(node **head)
    {
        node *trav = *head;
        int pcount = 0, scount = 0, mcount = 0;
        if (trav != NULL)
        {
            while (trav != NULL)
            {
                if (trav->post == "p")
                {
                    pcount++;
                }
                else if (trav->post == "s")
                {
                    scount++;
                }
                else
                {
                    mcount++;
                }
                trav = trav->next;
            }
            std::cout << "Pcount: " << pcount << std::endl;
            std::cout << "Mount: " << mcount << std::endl;
            std::cout << "Scount: " << scount << std::endl;
        }
        else
        {
            std::cout << "SLL is empty" << std::endl;
        }
    }

    void displaySLL(node **head)
    {
        node *trav = *head;
        if (trav != NULL)
        {
            while (trav != NULL)
            {
                std::cout << "Prn: " << trav->prn << ", Name: " << trav->name << ", Year: " << trav->year << ", Post: " << trav->post << std::endl;
                trav = trav->next;
            }
        }
        else
        {
            std::cout << "SLL is empty" << std::endl;
        }
    }

    void delSLL(node **head)
    {
        if (*head == NULL)
        {
            return;
        }
        string delmem;
        std::cout << "Enter what you want to delete(p / m / s): ";
        cin >> delmem;
        if (delmem == "p" && (*head)->post == "p")
        {
            node *temp = *head;
            *head = temp->next;
            free(temp);
            // return;
        }
        else if (delmem == "p" && (*head)->post != "p")
        {
            std::cout << "President to be deleted not present" << std::endl;
        }
        else if (delmem == "s")
        {
            node *trav = *head;
            node *prev = NULL;
            while (trav->next != NULL)
            {
                prev = trav;
                trav = trav->next;
            }
            if (trav->post == "s")
            {
                if (prev == NULL)
                {
                    head = NULL;
                    free(trav);
                }
                else
                {
                    prev->next = trav->next;
                    free(trav);
                }
                // return;
            }
            else if (trav->next == NULL)
            {
                std::cout << "Secretary to be deleted not present" << std::endl;
            }
        }
        else if (delmem == "m")
        {
            string name;
            node *trav = *head;
            node *prev = NULL;
            std::cout << "Enter name of the member to be deleted: ";
            cin >> name;
            while (trav->post == "m" && trav->next != NULL && trav->name != name)
            {
                prev = trav;
                trav = trav->next;
            }
            if (trav->post == "m" && trav->name == name && prev == NULL)
            {
                *head = trav->next;
                free(trav);
                // return;
            }
            else if (trav->post == "m" && trav->name == name)
            {
                prev->next = trav->next;
                free(trav);
                // return;
            }
            else if (trav->next == NULL && trav->name != name)
            {
                std::cout << "Member to be deleted not present" << std::endl;
            }
        }
    }

    void printReverse(node *head)
    {
        if (head == NULL)
        {
            return;
        }
        printReverse(head->next);

        std::cout << "Prn: " << head->prn << ", Name: " << head->name << ", Year: " << head->year << ", Post: " << head->post << std::endl;
    }
};

void display_concatenate(node **headA, node **headB)
{
    pinnacle obj;
    node *X, *Y;

    X = *headA;
    Y = *headB;
    if ((*headA) == NULL && (*headB) == NULL)
    {
        std::cout << "Both div's sll is empty!" << std::endl;
        return;
    }
    while (X->next != NULL)
    {
        X = X->next;
    }
    X->next = Y;
    *headA = X;

    // concatenated in DivA's sll now making DivB sll empty
    node *current = *headB;
    node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *headB = NULL;
    obj.displaySLL(&(*headA));
}

void menu(node **head)
{
    int choice;
    pinnacle obj1;
    do
    {
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << "1.Enter the student" << std::endl;
        std::cout << "2.Delete the student" << std::endl;
        std::cout << "3.Total students" << std::endl;
        std::cout << "4.Display all" << std::endl;
        std::cout << "5.Reverse Display all" << std::endl;
        std::cout << "6.Back" << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << "Enter your choice: ";
        cin >> choice;
        std::cout << "--------------------------------------------------" << std::endl;
        switch (choice)
        {
        case 1:
            obj1.funAddMem(&(*head));
            std::cout << "--------------------------------------------------" << std::endl;
            obj1.displaySLL(&(*head));
            std::cout << "\nReversed Linked List" << std::endl;
            obj1.printReverse(*head);
            break;
        case 2:
            obj1.delSLL(&(*head));
            std::cout << "--------------------------------------------------" << std::endl;
            obj1.displaySLL(&(*head));
            break;
        case 3:
            std::cout << "--------------------------------------------------" << std::endl;
            obj1.compMember(&(*head));
            break;
        case 4:
            obj1.displaySLL(&(*head));
            break;
        case 5:
            if (head == NULL)
            {
                std::cout << "SLL is empty" << std::endl;
                break;
            }
            std::cout << "Reversed Linked List" << std::endl;
            obj1.printReverse(*head);
            break;
        }
    } while (choice != 6);
}

int main()
{
    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    int choice;
    node *headA = NULL;
    node *headB = NULL;

    do
    {
        std::cout << "--------------------MAIN_MENU---------------------" << std::endl;
        std::cout << "1.Div A" << std::endl;
        std::cout << "2.Div B" << std::endl;
        std::cout << "3.Display concatenated Div A and Div B" << std::endl;
        std::cout << "4.Exit" << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << "Enter your choice: ";
        cin >> choice;
        std::cout << "--------------------------------------------------" << std::endl;
        switch (choice)
        {
        case 1:
            menu(&headA);
            break;
        case 2:
            menu(&headB);
            break;
        case 3:
            display_concatenate(&headA, &headB);
            break;
        }
    } while (choice != 4);

    // freeing the linked list
    node *currentA = headA;
    node *nextA = NULL;
    while (currentA != NULL)
    {
        nextA = currentA->next;
        free(currentA);
        currentA = nextA;
    }
    headA = NULL;

    node *currentB = headB;
    node *nextB = NULL;
    while (currentB != NULL)
    {
        nextB = currentB->next;
        free(currentB);
        currentB = nextB;
    }
    headB = NULL;

    std::cout << "--------------------THANK_YOU---------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}