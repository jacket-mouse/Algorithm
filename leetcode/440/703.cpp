#include<vector>
#include<iostream>
#include<queue>
using namespace std;
// 题目要求第三大的元素，我一直当成第三小的数来算！！
class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    public:
        KthLargest(int k, vector<int>& nums) {
            this->k = k;
            for(int i = 0; i < nums.size(); i++){
                pq.push(nums[i]);
                if(pq.size() > k)
                    pq.pop();
            }
        }
        int add(int val) {
            pq.push(val);
            if(pq.size() > k)
                pq.pop();
            return pq.top();
        }
    };
    
    /**
     * Your KthLargest object will be instantiated and called as such:
     * KthLargest* obj = new KthLargest(k, nums);
     * int param_1 = obj->add(val);
     */