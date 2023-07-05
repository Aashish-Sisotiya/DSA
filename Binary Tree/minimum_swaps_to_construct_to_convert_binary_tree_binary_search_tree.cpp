#include <bits/stdc++.h>

int minSwaps(vector<int> &nums)
{
    // Code here
    //! Tc  ---> O( N*log(N)) 
    vector<pair<int, int>> vec;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        vec.push_back({nums[i], i});
    }
    sort(vec.begin(), vec.end());

    int swaps = 0;
    for (int i = 0; i < n; i++)
    {
        if (vec[i].second == i)
            continue;
        else
        {
            ++swaps;
            swap(vec[i], vec[vec[i].second]);
            --i;
        }
    }
    return swaps;
}
void inorder(vector<int> &arr, int n, vector<int> &ans, int index)
{
    if (index < n)
    {
        inorder(arr, n, ans, 2 * index + 1);
        ans.push_back(arr[index]);
        inorder(arr, n, ans, 2 * index + 2);
    }
}
int minimumSwaps(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> ans;
    inorder(arr, n, ans, 0);
    return minSwaps(ans);
}