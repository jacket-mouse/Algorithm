#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int left, right = 0;
        vector<vector<int>> ans;
        bool isOverlap;
        for (int i = 0; i < intervals.size(); i++)
        {
            // preprocess
            vector<int> cur = intervals[i];
            isOverlap = false;
            // process
            for (int j = 0; j < ans.size(); j++)
            {
                if (cur[0] >= ans[j][0] && cur[1] <= ans[j][1])
                {
                    isOverlap = true;
                }
                // start
                if (cur[0] >= ans[j][0] && cur[1] > ans[j][1])
                {
                    ans[j][1] = cur[1];
                    isOverlap = true;
                }
                // end
                if (cur[0] < ans[j][0] && cur[1] <= ans[j][1])
                {
                    ans[j][0] = cur[0];
                    isOverlap = true;
                }
                // include
                if (cur[0] < ans[j][0] && cur[1] > ans[j][1])
                {
                    ans[j][1] = cur[1];
                    ans[j][0] = cur[0];
                    isOverlap = true;
                }
            }
            if (!isOverlap)
            {
                int start = cur[0];

                for (int j = 0; j < ans.size(); j++)
                {
                    if (start < ans[j][0])
                        ans.insert(ans.begin() + j, cur);
                }
            }
        }
        // last merge
        for (int j = 0; j < ans.size();)
        {
            if (j == ans.size() - 1)
                break;
            if (ans[j][1] > ans[j + 1][0])
            {
                ans.erase(ans.begin() + j + 1);
                if (ans[j + 1][1] > ans[j][1])
                    ans[j][1] = ans[j + 1][1];
                j--;
            }
            j++;
        }
        return ans;
    }
};

int main()
{
    Solution sol = Solution();
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> ans = sol.merge(intervals);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}