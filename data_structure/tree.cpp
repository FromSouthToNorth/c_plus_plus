//
// Created by bw on 2022/8/31.
//
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {

    uint32_t val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(uint32_t value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }

    explicit TreeNode(uint32_t value, TreeNode *leftNode, TreeNode *rightNode) {
        val = value;
        left = leftNode;
        right = rightNode;
    }

};

class TreeNodeDfs {
public:
    vector<uint32_t> preorderTraversal(TreeNode *root) {
        vector<uint32_t> result;
        if (root == nullptr) {
            return result;
        }
        stack<TreeNode *> stk;
        TreeNode *node = root;
        while (!stk.empty() || node != nullptr) {
            while (node != nullptr) {
                result.emplace_back(node->val);
                stk.emplace(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            node = node->right;
        }
        return result;
    }

public:
    vector<uint32_t> inOrderIteration(TreeNode *root) {
        vector<uint32_t> result;
        if (root == nullptr) {
            return result;
        }
        stack<TreeNode *> stk;
        TreeNode *node = root;
        while (!stk.empty() || node != nullptr) {
            while (node != nullptr) {
                stk.emplace(node);
                node = node->left;
            }
            node = stk.top();
            result.emplace_back(node->val);
            stk.pop();
            node = node->right;
        }
        return result;
    }

public:
    vector<uint32_t> postorderDequeTraversal(TreeNode *root) {
        vector<uint32_t> result;
        if (root == nullptr) {
            return result;
        }
        stack<TreeNode *> stk;
        TreeNode *prev = nullptr;
        while (!stk.empty() || root != nullptr) {
            while (root != nullptr) {
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (root->right == nullptr || prev == root->right) {
                result.emplace_back(root->val);
                prev = root;
                root = nullptr;
            }
            else {
                stk.emplace(root);
                root = root->right;
            }
        }
        return result;
    }
};

int main() {
    TreeNode *root;
    root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(2);

    root->right = new TreeNode(5);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);

    TreeNodeDfs treeNodeDfs;

    cout << "prologue: " << endl;
    vector<uint32_t> res1 = treeNodeDfs.preorderTraversal(root);
    for (const auto &item: res1) {
        cout << item << endl;
    }

    cout << "Intermediate sequence: " << endl;
    vector<uint32_t> res2 = treeNodeDfs.inOrderIteration(root);
    for (const auto &item: res2) {
        cout << item << endl;
    }

    cout << "post order: " << endl;
    vector<uint32_t> res3 = treeNodeDfs.postorderDequeTraversal(root);
    for (const auto &item: res3) {
        cout << item << endl;
    }
    return 0;
}