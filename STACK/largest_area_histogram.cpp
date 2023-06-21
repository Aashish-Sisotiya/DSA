class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        if (heights.size() == 1)
            return heights[0];
        int n = heights.size();
        vector<int> ngeRight(n, n);
        vector<int> ngeLeft(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (!st.empty())
            {
                ngeRight[i] = st.top();
            }
            st.push(i);
        }

        st = stack<int>();

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (!st.empty())
            {
                ngeLeft[i] = st.top();
            }
            st.push(i);
        }

        int maxArea = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int area = heights[i] * (ngeRight[i] - ngeLeft[i] - 1);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};