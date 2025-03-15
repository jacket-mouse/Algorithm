#include<vector>
#include<iostream>
using namespace std;
class SegmentTree {
    vector<int> tree;
    void maintain(int index){
        tree[index] = max(tree[index*2], tree[index*2+1]);
    }
    void build(vector<int>& nums, int index, int left, int right){
        if(left == right){
            tree[index] = nums[left];
            return;
        }
        int mid = (left + right) / 2;
        build(nums, index * 2, left, mid);
        build(nums, index * 2 + 1, mid + 1, right);
        maintain(index);
    }
public:
    SegmentTree(vector<int>& nums){
        tree.resize(nums.size() * 4);
        build(nums, 1, 0, nums.size() - 1);
    }
    int findMax(int val, int index, int left, int right){
        if(val > tree[index]) return -1;
        if(left == right) {
            int tmp = tree[index];
            tree[index] = -1;
            return tmp;
        }
        int mid = (left + right) / 2;
        int i = findMax(val, index * 2, left, mid);
        if(i == -1)
            i = findMax(val, index * 2 + 1, mid + 1, right);
        maintain(index);
        return i;
    }
    void print(){
        for(int i = 0; i < tree.size(); i++){
            cout<<tree[i]<<" ";
        }
    }
};
class Solution {
    public:
        int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
            SegmentTree st(baskets);
            int ans = 0;
            for(int i = 0; i < fruits.size(); i++){
                if(st.findMax(fruits[i], 1, 0, baskets.size() - 1) == -1)
                    ans++;
            }
            return ans;
        }
    };

int main(){
    vector<int> basket({1, 2, 3, 4, 5});
    SegmentTree st(basket);
    st.print();
    cout<<endl;
}