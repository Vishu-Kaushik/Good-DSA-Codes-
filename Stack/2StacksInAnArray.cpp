#include <iostream>
using namespace std;

struct TwoStacks
{
    int *arr, top1, top2, cap;
    TwoStacks(int n)
    {
        cap = n;
        top1 = -1;
        top2 = cap;
        arr = new int[cap];
    }

    void push1(int x)
    {
        if (top1 < top2 - 1)
        {
            arr[top1] = x;
            top1++;
        }
    }

    void push2(int x)
    {
        if (top1 < top2 - 1)
        {
            arr[top2] = x;
            top2--;
        }
    }

    int pop1()
    {
        if (top1 >= 0)
        {
            int x = arr[top1];
            top1--;
            return x;
        }
        else
        {
            exit(1);
        }
    }
    int pop2()
    {
        if (top2 < cap)
        {
            int x = arr[top2];
            top2++;
            return x;
        }
        else
        {
            exit(1);
        }
    }
};