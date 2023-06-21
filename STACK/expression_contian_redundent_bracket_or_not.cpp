//! Tc ---> O( N )
//! Sc ---> O( N ) using a stack 


#include <bits/stdc++.h>
bool checkStringExpression(string str)
{
    // Write your code here.
    stack<char> st;
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        bool contains = true;
        if (str[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                if (st.top() == '+' | st.top() == '-' | st.top() == '*' | st.top() == '/')
                {
                    contains = false;
                }
                st.pop();
            }
            st.pop();
            if (contains)
                return true;
        }
        else
        {
            st.push(str[i]);
        }
    }
    return false;
}


//! Sc ---> O( 1 ) here we not using any stack we will use pointers

