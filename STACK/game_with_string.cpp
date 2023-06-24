//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minValue(string s, int k)
    {
        // code here
        priority_queue<int> pq; // we are using pq because every time whrn we decrement the count of a character then we need to know the count of  character which has max count

        vector<int> hash(26, 0);
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            hash[s[i] - 97]++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (hash[i] != 0)
            {
                pq.push(hash[i]);
            }
        }
        int value = 0;
        while (k--)
        {
            int top = pq.top();
            pq.pop();
            top--;
            pq.push(top);
        }
        while (!pq.empty())
        {
            value += (pq.top() * pq.top());
            pq.pop();
        }
        return value;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int k;
        cin >> s >> k;

        Solution ob;
        cout << ob.minValue(s, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends