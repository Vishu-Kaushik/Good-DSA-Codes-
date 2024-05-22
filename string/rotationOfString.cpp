#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;

// find function in the string returns a special kind of constant i.e string:: npos
// which represents that the string passed to find is present or not and if not present then it returns --> string:: npos
bool isRotation(string &s1, string &s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }
    return ((s1 + s1).find(s2) != string::npos);
}

int main(int argc, char const *argv[])
{

    return 0;
}