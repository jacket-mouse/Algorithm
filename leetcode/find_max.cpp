#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
class Solution {
    public:
        vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2,
                                     int k) {
            vector<long long> ans;
            for (int i = 0; i < nums1.size(); i++) {
                int sum = 0;
                priority_queue<int> num;
                long long full = 0;
                for (int j = 0; j < nums1.size() && j != i; j++) {
                    if (nums1[j] < nums1[i]) {
                        sum++;
                        full += nums2[j];
                        num.push(nums2[j]);
                    }
                }
                if (sum <= k)
                    ans.push_back(full);
                else {
                    full = 0;
                    for (int j = 0; j < k; j++) {
                        full += num.top();
                        num.pop();
                    }
                    ans.push_back(full);
                }
            }
            return ans;
        }
    };
    int main() {
        Solution s;
        vector<int> nums1 = {4, 2, 1, 5, 3};
        vector<int> nums2 = {10, 20, 30, 40, 50};
        vector<long long> ans = s.findMaxSum(nums1, nums2, 2);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        return 0;
    }