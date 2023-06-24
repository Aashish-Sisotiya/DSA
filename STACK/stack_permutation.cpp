//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int isStackPermutation(int N, vector<int> &A, vector<int> &B)
    {
        // Tc ---> O( N )  Sc -->O( N )
        //  stack<int> st;

        // int i = 0, j = 0;

        // while (i < N)
        // {
        //     st.push(A[i]);

        //     if (st.top() == B[j])
        //     {
        //         while (!st.empty() && st.top() == B[j])
        //         {
        //             st.pop();
        //             j++;
        //         }
        //     }

        //     i++;
        // }
        // return st.empty();

        // space optimised Sc---->O( 1 )

        int i = 0, j = 0;
        for (int val : pushed)
        {
            pushed[i++] = val;
            while (i > 0 && pushed[i - 1] == popped[j])
            {
                i--;
                j++;
            }
        }

        return i == 0;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        Solution ob;
        cout << ob.isStackPermutation(n, a, b) << endl;
    }

    return 0;
}
// } Driver Code Ends