#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    public:
        vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2,
                                     int k) {
            int n = nums1.size();
            vector<long long> ans(n);
            // 1: value1, 2: index, 3: value2
            vector<pair<int, pair<int, int>>> nums;
            for (int i = 0; i < nums1.size(); i++) {
                nums.push_back({nums1[i], {i, nums2[i]}});
            }

            sort(nums.begin(), nums.end());
            priority_queue<int, vector<int>, greater<int>> num;
            long long record = 0;
            for (int i = 0; i < nums.size(); i++) {
                // if the value is the same as the previous one, the result is the same
                if(i != 0 && nums[i].first == nums[i-1].first){
                    ans[nums[i].second.first] = ans[nums[i-1].second.first];
                    num.push(nums[i].second.second);
                    record += nums[i].second.second;
                    continue;
                }
                if (num.size() <= k) {
                    ans[nums[i].second.first] = record;
                    num.push(nums[i].second.second);
                    record += nums[i].second.second;
                } else {
                    while (num.size() > k) {
                        record -= num.top();
                        num.pop();
                    }
                    ans[nums[i].second.first] = record;
                    num.push(nums[i].second.second);
                    record += nums[i].second.second;
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
// O(n^2logn) time complexity k -> n || index.size() -> n
//
// class Solution {
//     public:
//         vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2,
//                                      int k) {
//             vector<long long> ans;
//             for (int i = 0; i < nums1.size(); i++) {
//                 priority_queue<int> num;
//                 vector<int> index;
//                 long long full = 0;
//                 for (int j = 0; j < nums1.size(); j++) {
//                     if (nums1[j] < nums1[i]) {
//                         index.push_back(j);
//                         full += nums2[j];
//                     }
//                 }
//                 if (index.size() <= k)
//                     ans.push_back(full);
//                 else {
//                     for (int j = 0; j < index.size(); j++) {
//                         num.push(nums2[index[j]]);
//                     }
//                     full = 0;
//                     for (int j = 0; j < k; j++) {
//                         full += num.top();
//                         num.pop();
//                     }
//                     ans.push_back(full);
//                 }
//             }
//             return ans;
//         }
//     };