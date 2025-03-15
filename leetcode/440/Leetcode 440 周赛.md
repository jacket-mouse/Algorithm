# Leetcode 440 周赛

## Q3 将水果装入篮子III

#线段树二分算法

```c++
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
struct Node {
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
class tree {
public:
    Node* head;
    tree(vector<int>& nums) {
        head = init(nums);
    }
  	// 利用递归进行初始化
    Node* init(vector<int>& nums){
        if(nums.size() <= 1){
            Node* node = new Node();
            node->val = nums[0];
            node->left = nullptr;
            node->right = nullptr;
            node->parent = nullptr;
            return node;
        }
        int mid = nums.size() / 2;
        vector<int> nums_left(nums.begin(), nums.begin()+mid);
        vector<int> nums_right(nums.begin()+mid, nums.end());
        Node* left = init(nums_left);
        Node* right = init(nums_right);
        Node* node = new Node();
        node->val = max(left->val, right->val);
        node->left = left;
        node->right = right;
        left->parent = node;
        right->parent = node;
        return node;
    }
  	// 打印检查初始化是否成功（层次遍历）
    void print(){
        queue<Node*> q;
        q.push(head);
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            cout<<node->val<<" ";
            if(node->left != nullptr)
                q.push(node->left);
            if(node->right != nullptr)
                q.push(node->right);
        }
    }
  	// 解题函数，从树中一层层查找，删除后在一层层向上更新
    bool deleteNode(int val){
        if(val > head->val)
            return false;
        Node* cur = head;
        while(cur->left != nullptr && cur->right != nullptr){
            if(cur->left->val >= val){
                cur = cur->left;
                continue;
            }
            if(cur->right->val >= val){
                cur = cur->right;
                continue;
            }
        }
        cur->val = 0;
        while(cur->parent != nullptr){
            cur = cur->parent;
            cur->val = max(cur->left->val, cur->right->val);
        }
        return true;
    }
};
class Solution {
    public:
        int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
            int ans = 0;
            tree t(baskets);
            for (int i = 0; i < fruits.size(); i++) {
                if(!t.deleteNode(fruits[i]))
                    ans++;
            }
            return ans;
        }
    };
// O(n^2) solution
//
// class Solution {
// public:
//     int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
//         int ans = 0;
//         for (int i = 0; i < fruits.size(); i++) {
//             for (int j = 0; j < baskets.size(); j++) {
//                 if (baskets[j] >= fruits[i]) {
//                     baskets.erase(baskets.begin() + j);
//                     fruits[i] = 0;
//                     break;
//                 }
//             }
//             if (fruits[i] != 0)
//                 ans++;
//         }
//         return ans;
//     }
// };

int main() {
    vector<int> fruits = {4, 2, 5};
    vector<int> baskets = {3, 5, 4};
    Solution s;
    cout << s.numOfUnplacedFruits(fruits, baskets) << endl;
    // tree test
    // vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // tree t(nums);
    // t.print();
    // return 0;
}
```

