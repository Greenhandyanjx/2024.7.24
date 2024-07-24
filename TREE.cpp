#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;
struct TreeNode {
public:
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode():left(NULL),right(NULL){}
    TreeNode(int value):left(NULL),right(NULL),val(value){}
};
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL)return new TreeNode(val);
        TreeNode* cur = root;
        while (cur->val > val || cur->val < val)
        {
            if (cur->val > val) {
                if (cur->left != NULL)
                    cur = cur->left;
                else
                {
                    cur->left = new TreeNode(val);
                    return root;
                }
            }
            if (cur->val < val) {
                if (cur->right != NULL)
                    cur = cur->right;
                else
                {
                    cur->right = new TreeNode(val);
                    return root;
                }
            }
        }
        return root;
    }
};
//class Solution {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if (root == NULL)return NULL;
//        if (p->val < root->val && q->val < root->val) {
//            TreeNode* left = lowestCommonAncestor(root->left, p, q);
//            if (left != NULL)
//                return left;
//        }
//        else if (p->val > root->val && q->val > root->val) {
//            TreeNode* right = lowestCommonAncestor(root->right, p, q);
//            if (right != NULL)
//                return right;
//        }
//        return root;
//    }
//};
//class Solution {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if (root == NULL)return NULL;
//        if (root == q || root == p)return root;
//        queue<TreeNode*> que;
//        que.push(root);
//        while (!que.empty()) {
//            int size = que.size();
//            while (size--) {
//                TreeNode* node = que.front();
//                que.pop();
//                if (node) {
//                    que.push(node->left);
//                    que.push(node->right);
//                    if (node->val >= p->val && node->val <= q->val)return node;
//                }
//            }
//        }
//        return root;
//    }
//};
//class Solution {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if (root == NULL)return NULL;
//        if (root == p || root == q)return root;
//        TreeNode* left = lowestCommonAncestor(root->left, q, p);
//        TreeNode* right = lowestCommonAncestor(root->right, q, p);
//        if (left != NULL && right != NULL)return root;
//        if (left == NULL && right != NULL)return right;
//        if (left != NULL && right == NULL)return left;
//        return NULL;
//    }
//};
//class Solution {
//public:
//    unordered_map<int, int>map;
//    vector<int>res;
//    void traversal(TreeNode* root) {
//        if (root == NULL)return;
//        traversal(root->left);
//        map[root->val]++;
//        traversal(root->right);
//        return;
//    }
//    bool static cmp(pair<int, int> a, pair<int, int> b) {
//        return a.second > b.second;
//    }
//    vector<int> findMode(TreeNode* root) {
//        traversal(root);
//        vector<pair<int, int>>vec;
//        for (auto i : map) {
//            vec.push_back(i);
//        }
//        sort(vec.begin(), vec.end(), cmp);
//        int fre = vec[0].second;
//        for (auto i : vec) {
//            if (i.second == fre) {
//                res.push_back(i.first);
//            }
//        }
//        return res;
//    }
//};
//class Solution {
//public:
//    TreeNode* pre = NULL;
//    vector<int>result;
//    map<int,int>res;
//    void traversal(TreeNode* root) {
//        if (root == NULL)return;
//        traversal(root->left);
//        if (pre != NULL && pre->val == root->val) {
//            res[pre->val]++;
//        }
//        pre = root;
//        traversal(root->right);
//        return;
//    }
//    vector<int> findMode(TreeNode* root) {
//        traversal(root);
//        int fre=-1;
//        for (auto i : res) {
//            if (fre == -1 || fre == i.second) {
//                result.push_back(i.first);
//            }
//            fre = i.second;
//        }
//        return result;
//    }
//};