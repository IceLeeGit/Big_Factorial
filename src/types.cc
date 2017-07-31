#include <iostream>

using namespace std;

struct node{
    int num;
    node *next;
};


void add_link(node *&head, int num)
{
    node *temp;
    temp = new node;
    temp->num = num;
    temp->next = NULL;

    if (head==NULL)
        head = temp;
    else
    {
        node *iter = head;
        while (iter->next != NULL)
        {
            iter = iter->next;
        }
        iter->next = temp;
    }
}

void insert_link(node *&head, int locate,int num)
{
    node *temp;
    temp = new node;
    temp->num = num;
    temp->next = NULL;

    if (head==NULL)
        head = temp;
    else
    {
        node *iter = head;
        int count=0;
        while (iter->next != NULL)
        {
            iter = iter->next;
            count++;
            if (count>=locate)
                break;
        }
        temp->next = iter->next;
        iter->next = temp;
    }
}

int del_link(node *&head, int locate)
{
    int ret = 0;
    if (head==NULL)
        cout<<"Not found the element in list."<<endl;
    else
    {
        node *iter = head;
        int count=0;
        while (iter->next != NULL)
        {
            iter = iter->next;
            count++;
            if (count==locate)
            {
                ret = iter->num;
                node *temp = iter->next;
                iter->next = temp->next;
                temp->next = NULL;
                delete [] temp;
            }
        }
    }
    return ret;
}

void print_link(node *&head, int locate=-1)
{
    if (head==NULL)
        cout<<"Not found the element in list."<<endl;
    else if (locate!=-1)
    {
        node *iter = head;
        int count=1;
        while (iter->next != NULL)
        {
            if (count>=locate)
            {
                break;
            }
            iter = iter->next;
            count++;
        }
        if (count == locate)
            cout<< (iter->num) <<endl;
        else
            cout<<"Not found!"<<endl;
    }
    else
    {
        node *iter = head;
        while (iter->next != NULL)
        {
            cout<<iter->num<< " ---> ";
            iter = iter->next;
        }
        cout<<iter->num<<endl;;
    }
}
