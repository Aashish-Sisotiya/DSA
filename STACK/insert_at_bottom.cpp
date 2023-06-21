#include <bits/stdc++.h>
void insertAtBottom(stack<int> &st, int x)
{
    if (st.size() == 0)
        st.push(x);
    else
    {
        int elem = st.top();
        st.pop();
        insertAtBottom(st, x);

        st.push(elem);
    }
}
stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    // Write your code here.
    insertAtBottom(myStack, x);
    return myStack;
}
