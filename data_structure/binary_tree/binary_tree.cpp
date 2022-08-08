//
// Created by bw on 2022/5/13.
//
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

void insert(TreeNode *root, int val) {
    if (val < root->val) {
        if (root->left == nullptr) {
            TreeNode *node = new TreeNode;
            node->val = val;
            node->left = nullptr;
            node->right = nullptr;
            root->left = node;
        }
        else {
            insert(root->left, val);
        }
    }
    else {
        if (root->right == nullptr) {
            TreeNode *node = new TreeNode;
            node->val = val;
            node->left = nullptr;
            node->right = nullptr;
            root->right = nullptr;
        }
        else {
            insert(root->right, val);
        }
    }
}

void followUp(struct TreeNode *root) {
    if (root != nullptr) {
        followUp(root->left);
        followUp(root->right);
        std::cout << root->val << "  ";
    }
}