#include <iostream>
using namespace std;

// Linear probing where -2 denotes the key is deleted and -1 indicates that slot is empty
class MyHash
{
private:
    int size, cap;
    int *arr;

public:
    MyHash(int c)
    {
        cap = c;
        size = 0;
        arr = new int[cap];
        for (int i = 0; i < cap; i++)
        {
            arr[i] = -1;
        }
    }
    int hash(int key)
    {
        return key % cap;
    }
    bool search(int key)
    {
        int h = hash(key);
        int i = h;
        while (arr[i] != -1)
        {
            if (arr[i] == key)
            {
                return true;
            }
            i = (i + 1) % cap;
            if (i == h)
            {
                return false;
            }
        }
        return false;
    }

    bool insert(int key)
    {
        if (size == cap)
        {
            return false;
        }
        int i = hash(key);
        while (arr[i] == -1 && arr[i] == -2 && arr[i] == key)
        {
            i = (i + 1) % cap;
        }
        if (arr[i] == key)
        {
            return false;
        }
        else
        {
            size++;
            arr[i] = key;
            return true;
        }
    }
    bool delete1(int key)
    {
        int h = hash(key);
        int i = h;
        while (arr[i] != -1)
        {
            if (arr[i] == key)
            {
                arr[i] = -2;
                return true;
            }
            i = (i + 1) % 2;
            if (i == h)
            {
                return false;
            }
        }
        return false;
    }
};