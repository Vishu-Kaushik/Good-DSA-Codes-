#include <iostream>
#include <string>
using namespace std;
const int charr = 256;
// Method 1 -> using count array
// needs two traversals of the string
int rep1(string s)
{
    int count[charr] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        count[s[i]]++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (count[s[i]] == 1)
        {
            return i;
        }
    }
    return -1;
}
// Method 2 ->
// needs one traversal of the string and one traversal upto 256
int rep2(string s)
{
    int count[charr];
    fill(count, count + charr, -1);
    for (int i = 0; i < s.length(); i++)
    {
        if (count[s[i]] == -1)
        {
            count[s[i]] = i;
        }
        else
        {
            count[s[i]] = -2;
        }
    }
    int res = INT16_MAX;
    for (int i = 0; i < charr; i++)
    {
        /* code */
        if (count[i] >= 0)
        {
            res = min(res, count[i]);
        }
    }
    return (res == INT16_MAX) ? -1 : res;
}
int main(int argc, char const *argv[])
{
    string s;
    cout << "Enter the string" << endl;
    getline(cin, s);
    cout << rep2(s);
    return 0;
}
