#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *curr1, ListNode *curr2)
{
    if (curr1 == NULL)
        return curr2;

    else if (curr2 == NULL)
        return curr1;

    ListNode *head = NULL;
    ListNode *tail = NULL;
    // ListNode* curr1 = list1;
    // ListNode* curr2 = list2;
    if (curr1->val <= curr2->val)
    {
        head = curr1;
        tail = curr1;
        curr1 = curr1->next;
    }
    else
    {
        head = curr2;
        tail = curr2;
        curr2 = curr2->next;
    }

    while (curr1 && curr2)
    {
        if (curr1->val < curr2->val)
        {
            tail->next = curr1;
            // tail = curr1;
            curr1 = curr1->next;
        }
        else
        {
            tail->next = curr2;
            // tail = curr2;
            curr2 = curr2->next;
        }
        tail = tail->next;
    }

    if (curr1 == NULL)
    {
        tail->next = curr2;
    }
    else
    {
        tail->next = curr1;
    }
    return head;
}