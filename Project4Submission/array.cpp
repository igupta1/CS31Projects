#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int appendToAll(string a[], int n, string value);
int lookup(const string a[], int n, string target);
int positionOfMax(const string a[], int n);
int rotateLeft(string a[], int n, int pos);
int countRuns(const string a[], int n);
int flip(string a[], int n);
int differ(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int lookupAny(const string a1[], int n1, const string a2[], int n2);
int split(string a[], int n, string splitter);

int main()
{
    string h[7] = { "rishi", "margaret", "gordon", "tony", "", "john", "liz" };

    cerr << lookup(h, -2, "john") << endl;
    cerr << lookup(h, 0, "john") << endl;
    cerr << lookup(h, 3, "john") << endl;
    cerr << lookup(h, 6, "john") << endl;
    
    
    cerr << appendToAll(h, -2, "?") << endl;
    cerr << appendToAll(h, 0, "?") << endl;
    cerr << appendToAll(h, 5, "?") << endl;
    
    string h1[7] = { "rishi", "margaret", "gordon", "tony", "", "john", "liz" };
        
    cerr << positionOfMax(h1, -2) << endl;
    cerr << positionOfMax(h1, 0) << endl;
    cerr << positionOfMax(h1, 6) << endl;

    cerr << rotateLeft(h1, 4, -2) << endl;
    cerr << rotateLeft(h1, 4, 0) << endl;
    cerr << rotateLeft(h1, 4, 2) << endl;
    
    string h2[7] = { "rishi", "margaret", "gordon", "tony", "", "john", "liz" };

    string d[5] = { "margaret", "margaret", "margaret", "tony", "tony" };

    cerr << countRuns(d, 0) << endl;
    cerr << countRuns(d, -2) << endl;
    cerr << countRuns(d, 5) << endl;

    string g[4] = { "rishi", "margaret", "liz", "theresa" };

    cerr << differ(h2, -2, g, 4) << endl;
    cerr << differ(h2, 0, g, 4) << endl;
    cerr << differ(h2, 1, g, -4) << endl;
    cerr << differ(h2, 1, g, 4) << endl;
    cerr << differ(h2, 2, g, 1) << endl;
    cerr << differ(h2, 2, g, 2) << endl;
    cerr << differ(h2, 5, g, 4) << endl;

    string f[3] = { "liz", "gordon", "tony" };

    cerr << flip(f, -2) << endl;
    cerr << flip(f, 0) << endl;
    cerr << flip(f, 3) << endl;

    string e[4] = { "gordon", "tony", "", "john" };

    cerr << subsequence(h2, -2, e, 4) << endl;
    cerr << subsequence(h2, 1, e, -2) << endl;
    cerr << subsequence(h2, 0, e, 4) << endl;
    cerr << subsequence(h2, 1, e, 0) << endl;
    cerr << subsequence(h2, 3, e, 4) << endl;
    cerr << subsequence(h2, 7, e, 4) << endl;

    
    cerr << lookupAny(h2, -2, f, 3) << endl;
    cerr << lookupAny(h2, 0, f, -2) << endl;
    cerr << lookupAny(h2, 0, f, 3) << endl;
    cerr << lookupAny(h2, 1, f, 0) << endl;
    cerr << lookupAny(h2, 7, f, 3) << endl;

    cerr << split(h2, -2, "liz") << endl;
    cerr << split(h2, 0, "liz") << endl;
    cerr << split(h2, 6, "liz") << endl;
}

//this method uses a for loop to iterate through the array and append a string at the end of every element
int appendToAll(string a[], int n, string value)
{
    if (n < 0)
    {
        return -1;
    }
    
    for (int i = 0; i < n; i++)
    {
        a[i] = a[i] + value;
    }
    return n;
}

//this method uses a for loop to iterate through an array and find the position of a specific target
int lookup(const string a[], int n, string target)
{
    if (n < 0)
    {
        return -1;
    }
    
    int pos;
    
    for (pos = 0; pos < n; pos++)
    {
        if (a[pos] == target)
        {
            break;
        }
    }
    
    if (pos == n)
    {
        return -1;
    }
    return pos;
}

//this method uses a for loop to iterate through an array and it keep updating the max value its found through its iteration as its going through the array
int positionOfMax(const string a[], int n)
{
    if (n <= 0)
    {
        return -1;
    }
    
    int maxPos = 0;
    
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[maxPos])
        {
            maxPos = i;
        }
    }
    
    return maxPos;
}

//this method uses a for loop to move every single element coming after a specified index one space left. Then this method moves the element at the specified index to the end of the array at position n
int rotateLeft(string a[], int n, int pos)
{
    if (n <= 0 || pos < 0)
    {
        return -1;
    }
    
    string temp = a[pos];
    for (int i = pos; i < n-1; i++)
    {
        a[i] = a[i + 1];
    }
    a[n-1] = temp;
    return pos;
}

//this method uses a for loop to count the number of times the current element is different than the last element and that is the number of changes of runs that the array has, which is one less than the number of runs
int countRuns(const string a[], int n)
{
    if (n < 0)
    {
        return -1;
    }
    else if (n == 0)
    {
        return 0;
    }
    
    int count = 0;
    
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i-1])
        {
            count++;
        }
    }
    
    return count + 1;
}

//uses a for loop to go though half the array and swaps the ith element with the ith to last element in the array
int flip(string a[], int n)
{
    if (n <= 0)
    {
        return -1;
    }
    
    for (int i = 0; i < n/2; i++)
    {
        string temp = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = temp;
    }
    
    return n;
}

//goes through the array to with a for loop to find the first index where the elements of a1 and a2 differ from eachother
int differ(const string a1[], int n1, const string a2[], int n2)
{
    if (n1 <= 0 || n2 <= 0)
    {
        return -1;
    }
    
    int min;
    
    if (n1 < n2)
    {
        min = n1;
    }
    else
    {
        min = n2;
    }
    
    for (int i = 0; i < min; i++)
    {
        if (a1[i] != a2[i])
        {
            return i;
        }
    }
    
    return min;
}

//uses a for loop to go through every index of a1. Then from every index of a1 have another for loop to go through a2 to see if the elements in a1 match a2 to look for subsequence
int subsequence(const string a1[], int n1, const string a2[], int n2)
{
    bool found;
    
    if (n1 < 0 || n2 < 0)
    {
        return -1;
    }
    
    if (n2 == 0)
    {
        return 0;
    }
    
    for (int i = 0; i < n1-n2; i++)
    {
        int pos = 0;
        found = true;
        for (int j = i; j < n2; j++)
        {
            if (a1[j] != a2[pos])
            {
                found = false;
                break;
            }
            pos++;
        }
        
        if (found)
        {
            return i;
        }
    }
    
    return -1;
}

//this method uses nested for loops. First we iterate throuhg a1 in order to go through every element in a1. Then with we check if that element is in a2 by iterating through a2.
int lookupAny(const string a1[], int n1, const string a2[], int n2)
{
    if (n1 < 0 || n2 < 0)
    {
        return -1;
    }
    
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (a1[i] == a2[j])
            {
                return i;
            }
        }
    }
    
    return -1;
}
//this method sorts the array and then once it is sorted it goes through the array and finds the position where the splitter is not less the element
int split(string a[], int n, string splitter)
{
    //nested for loops for the bubble sort to sort the array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            //if the element to the left is larger than the element to the right, swap their positions
            if(a[j] > a[j+1])
            {
                string temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if (!(a[i] < splitter))
        {
            return i;
        }
    }
    
    return n;
}

