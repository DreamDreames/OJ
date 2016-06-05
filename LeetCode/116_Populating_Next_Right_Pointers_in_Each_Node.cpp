#include "shared.h"
/*
 Given a binary tree
 
 struct TreeLinkNode {
 TreeLinkNode *left;
 TreeLinkNode *right;
 TreeLinkNode *next;
 }
 Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 
 Initially, all next pointers are set to NULL.
 
 Note:
 
 You may only use constant extra space.
 You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
 For example,
 Given the following perfect binary tree,
 1
 /  \
 2    3
 / \  / \
 4  5  6  7
 After calling your function, the tree should look like:
 1 -> NULL
 /  \
 2 -> 3 -> NULL
 / \  / \
 4->5->6->7 -> NULL
*/
namespace PopulatingNextRightPointersInEachNode{
    
    class Solution {
    public:
        void connect(TreeLinkNode *root) {
            if(root == NULL)
                return;
            vector<vector<TreeLinkNode*>> record(2);
            int level = 0;
            record[level].push_back(root);
            while(!record[level % 2].empty()){
                int index = (level ++) % 2;
                for(auto iter = record[index].begin(); iter != record[index].end(); ++ iter){
                    if(iter + 1 != record[index].end())
                        (*iter)->next = *(iter + 1);
                    if((*iter)->left != NULL)
                        record[level % 2].push_back((*iter)->left);
                    if((*iter)->right != NULL)
                        record[level % 2].push_back((*iter)->right);
                }
                record[index].clear();
            }
        }
    };
}
