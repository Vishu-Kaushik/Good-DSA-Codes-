#include <iostream>
#include <utility>
using namespace std;
// Question is --> We are given two strings and we need to convert s1 into s2 in minimun number of operations
// Recursive solution
// Only three are allowed insert,delete and replace
int editDistance(string s1, string s2, int m, int n)
{
    if (m == 0)
    {
        return n;
    }
    if (n == 0)
    {
        return m;
    }
    if (s1[m - 1] == s2[n - 1])
    {
        return editDistance(s1, s2, m - 1, n - 1);
    }
    else
    {
        return 1 + min(editDistance(s1, s2, m, n - 1),           // Insert Opeartion
                       min(editDistance(s1, s2, m - 1, n),       // Delete Operation
                           editDistance(s1, s2, m - 1, n - 1))); // Replace Operation
    }
}

/*
    Description about 3 operation
    1. Insert --> We insert the last character of the second string into first string then compare and delete the characters of
                both the strings i.e length of first string remains same and length of second string reduces by 1
    2. Delete --> We simply delete the last character of first string only and then compare the remaining characters i.e length of
                first string reduces by 1 and the length of second string remains same.
    3. Replace --> We simply replace the last character of the first string with the last character of 2nd string and does not alter
                the 2nd string .... just last character of first string is altered and thus the lengths of both strings are reduced
                by 1
*/