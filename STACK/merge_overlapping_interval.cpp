class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        stack<pair<int, int>> st;
        st.push({intervals[0][0], intervals[0][1]});

        for (int i = 1; i < intervals.size(); i++)
        {

            if (st.top().second >= intervals[i][0])
            {
                pair<int, int> p = st.top();
                st.pop();
                st.push({p.first, max(p.second, intervals[i][1])});
            }
            else
            {
                st.push({intervals[i][0], intervals[i][1]});
            }
        }
        while (!st.empty())
        {
            pair<int, int> p = st.top();
            st.pop();
            vector<int> v;
            v.push_back(p.first);
            v.push_back(p.second);
            merged.push_back(v);
        }

        reverse(merged.begin(), merged.end());

        return merged;
    }
};