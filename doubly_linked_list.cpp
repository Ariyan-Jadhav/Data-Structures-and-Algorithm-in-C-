#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <Algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int val)
    {
        data = val;
        prev = next = nullptr;
    }
};

class DoublyLL
{
    Node *head;

public:
    DoublyLL()
    {
        head = nullptr;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (head == nullptr)
            head = newNode;
        else
        {
            Node *temp = head;
            head->prev = newNode;
            head = newNode;
            head->next = temp;
        }
    }

    Node *get_head()
    {
        return head;
    }

    void print_list()
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << "<->";
            temp = temp->next;
        }
    }
};

Node *del_occ(Node *head)
{
    Node *temp = head;

    while (temp && temp->next)
    {
        if (temp->data == temp->next->data)
        {
            Node *duplicate = temp->next;

            temp->next = duplicate->next;

            if (duplicate->next)
                duplicate->next->prev = temp;

            delete duplicate;
        }
        else
        {
            temp = temp->next;
        }
    }

    return head;
}

vector<vector<int>> two_sum(Node *head)
{
}

int main()
{

    DoublyLL list;
    vector<int> vcc = {1, 2, 3, 4, 5, 6};
    reverse(vcc.begin(), vcc.end());
    for (int i = 0; i < vcc.size(); i++)
        list.push_front(vcc[i]);

    Node *head = list.get_head();

    // head = del_occ(head);
    vector<vector<int>> vcc = two_sum(head);

    list.print_list();
}