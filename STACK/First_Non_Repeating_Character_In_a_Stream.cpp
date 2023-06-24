//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 
// } Driver Code Ends
class Solution
{
public:
    // it can also be solved with a doubly linked list ;
    string FirstNonRepeating(string A)
    {
        // Code here

        queue<char> q;
        vector<int> hashArr(26, 0);
        string ans = "";

        int n = A.length();
        for (int i = 0; i < n; i++)
        {
            q.push(A[i]);
            hashArr[A[i] - 'a']++;

            while (!q.empty())
            {
                if (hashArr[q.front() - 'a'] > 1)
                    q.pop();
                else
                {
                    ans += q.front();
                    break;
                }
            }
            if (q.empty())
            {
                ans += "#";
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends