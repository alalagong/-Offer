#include <iostream>
#include <deque>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
// 增
int ls_inc(vector<int> vec, int target)
{
    int size = vec.size();
    vector<int> dp(size+1, 0);

    for(int i = 1; i < size+1; ++i)
    {
        dp[i] = 0;
        for(int j = 1; j < i; ++j)
        {
            if(vec[j-1] < vec[i-1] && vec[j-1] > target && dp[j] > dp[i])
                dp[i] = dp[j];
        }
        dp[i] = dp[i] + 1;
    }
    int max1 = 0;
    for(int i = 0; i < size+1; i++)
        max1 = max(max1, dp[i]);
    return max1;
}

// 减
int ls_dec(vector<int> vec, int target)
{
    int size = vec.size();
    vector<int> dp(size+1, 0);

    for(int i = 1; i < size+1; ++i)
    {
        dp[i] = 0;
        for(int j = 1; j < i; ++j)
        {
            if(vec[j-1] > vec[i-1] && vec[i-1] > target && dp[j] > dp[i])
                dp[i] = dp[j];
        }
        dp[i] = dp[i] + 1;
    }
    int max1 = 0;
    for(int i = 0; i < size+1; i++)
        max1 = max(max1, dp[i]);
    return max1;
}

int main()
{
    // vector<int> vec{87, 70, 17, 12, 14, 86, 61, 51, 12, 90, 69, 89, 4, 65};
    // vector<int> vec{5,4,3,2,1,2,3,4,5};
    int T;
    cin >> T;

    for(int i = 0; i < T; ++i)
{
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    for(int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }
     map<int, pair<int, set<int>>> count;
    
    for(int i = 0; i < 9; ++i)
    {
        count[vec[i]].first++;
        count[vec[i]].second.insert(i);
    }
    
    int res = 0;
    for(auto it : count)
    {
        if(it.second.first > 1)  // 相同的
        {
            // 未考虑多个相同
            for(auto it1 = it.second.second.begin(); it1 != it.second.second.end(); it1++ )
            for(auto it2 = ++it1; it2 != it.second.second.end(); it2++ )
            // auto it1 = it.second.second.begin();
            {
                vector<int> left(vec.begin(), vec.begin()+*it1);
                vector<int> right(vec.begin()+*(it2), vec.end());
                int left_count = ls_dec(left, it.first);
                int right_count = ls_inc(right, it.first);
                res = max(min(right_count, left_count), res);
            }

        }
    }

    cout << res*2+2 <<endl;;
}
    return 0;
}