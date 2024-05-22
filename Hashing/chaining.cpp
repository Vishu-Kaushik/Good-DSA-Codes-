#include <iostream> 
#include <list>
using namespace std;
struct Myhash{
    int Bucket;
    list <int> *table;
    Myhash (int b)
    {
        Bucket=b;
        table = new list <int> [b];
    } 
    void insert (int key)
    {
        int i= key % Bucket; // finding index with the help of key and bucket variable.
        table[i].push_back(key);
    }
    bool search (int key)
    {
        int i=key%Bucket; // This is a Hash Function ..... not a very good function but a starting one.
        for(auto x: table[i])
        {
            if(x==key)
            {
                return true;
            }
        }
        return false;
    }
    void remove (int key)
    {
        int i= key%Bucket;
        table[i].remove(key);
    }
};

int main(int argc, char const *argv[])
{
    Myhash hash(7);
    hash.insert(79);
    hash.insert(7);
    hash.insert(9);
    hash.insert(67);
    cout<<hash.search(8)<<endl;
    cout<<hash.search(79);
    return 0;
}

