#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ThreadNode {
    int val;
    ThreadNode *left;
    ThreadNode *right;
    int ltag, rtag;
    ThreadNode(int x) : val(x), left(nullptr), right(nullptr), ltag(0), rtag(0) {}
    ThreadNode(int x, ThreadNode *left, ThreadNode *right) : val(x), left(left), right(right), ltag(0), rtag(0) {}
};

// 中序遍历
void inorder(TreeNode* root){
    if(root != nullptr){
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
}

// 构建中序线索树
void InThread(ThreadNode* p, ThreadNode* &pre){
    if(p != nullptr){
        InThread(p->left, pre);
        if(p->left == nullptr){
            p->left = pre;
            p->ltag = 1;
        }
        if(pre && pre->right == nullptr){
            pre->right = p;
            pre->rtag = 1;
        }
        pre = p;
        InThread(p->right, pre);
    }
}

// 查找该子树中最左的节点
ThreadNode* findleft(ThreadNode* node) {
    while(node && node->ltag == 0) node = node->left;
    return node;
}

// 查找该子树中最右的节点
ThreadNode* findright(ThreadNode* node) {
    while(node && node->rtag == 0) node = node->right;
    return node;
}

// 查找中序遍历后一个节点
ThreadNode* inorderafter(ThreadNode* node) {
    if(node->rtag == 1) return node->right;
    else return findleft(node->right);
}

// 查找中序遍历前一个节点
ThreadNode* inorderbefore(ThreadNode* node) {
    if(node->ltag == 1) return node->left;
    else return findright(node->left);
}

// 中序遍历线索树写法
void in_order_in_thread(ThreadNode* root) {
    for(ThreadNode* node = findleft(root); node != nullptr; node = inorderafter(node)) cout<<node->val<<" ";
}

// 前序遍历
void preorder(TreeNode* root){
    if(root != nullptr){
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

// 后序遍历
void postorder(TreeNode* root){
    if(root != nullptr){
        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<" ";
    }
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    inorder(root);
    cout<<endl;

    // 中序线索树
    ThreadNode* Threadroot = new ThreadNode(1);
    Threadroot->left = new ThreadNode(2);
    Threadroot->right = new ThreadNode(3);
    Threadroot->left->left = new ThreadNode(4);
    Threadroot->left->right = new ThreadNode(5);
    ThreadNode* pre = nullptr;
    InThread(Threadroot, pre); // init ThreadTree
    in_order_in_thread(Threadroot);
    return 0;
}