class Solution
{
public:
    int sumOfMaxMinElemOfSubarraySizeK(vector<int> &vec, int k)
    {
        int i = 0, j = 0;
        int n = vec.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int sum = 0;
        while (j < n)
        {
            mini = min(mini, vec[j]);
            maxi = max(maxi, vec[j]);
            if (j - i + 1 < k)
            {
                j++;
            }
            else if (j - i + 1 == k)
            {
                sum += maxi + mini;
                i++;
                j++;
            }
        }
        return sum;
    }
};