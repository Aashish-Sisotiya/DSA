//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// function Template for C++

// Function to reverse the queue.
class Solution
{
public:
    void reverse(queue<int> &q, int n)
    {
        if (n == 0)
            return;

        int elem = q.front();
        q.pop();
        n--;
        reverse(q, n);

        q.push(elem);
    }
    queue<int> rev(queue<int> q)
    {
        // add code here.
        int n = q.size();
        reverse(q, n);
        return q;
    }
};

//{ Driver Code Starts.
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        queue<int> q;
        int n, var;
        cin >> n;
        while (n--)
        {
            cin >> var;
            q.push(var);
        }
        Solution ob;
        queue<int> a = ob.rev(q);
        while (!a.empty())
        {
            cout << a.front() << " ";
            a.pop();
        }
        cout << endl;
    }
}
// } Driver Code Ends