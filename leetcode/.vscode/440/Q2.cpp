#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
    public:
        vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2,
                                     int k) {
            vector<long long> ans;
            for (int i = 0; i < nums1.size(); i++) {
                priority_queue<int> num;
                vector<int> index;
                long long full = 0;
                for (int j = 0; j < nums1.size(); j++) {
                    if (nums1[j] < nums1[i]) {
                        index.push_back(j);
                        full += nums2[j];
                    }
                }
                if (index.size() <= k)
                    ans.push_back(full);
                else {
                    for (int j = 0; j < index.size(); j++) {
                        num.push(nums2[index[j]]);
                    }
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
// O(n^2logn) time complexity k -> n
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