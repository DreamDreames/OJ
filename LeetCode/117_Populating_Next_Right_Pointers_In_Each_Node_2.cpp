#include "shared.h"

namespace PopulatingNextRightPointersInEachNode2{
    class Solution {
    public:
        void connect(TreeLinkNode *root) {
            TreeLinkNode* current = root;
            while(current && (current->left || current->right || current->next)){
                
                auto horizon = current;
                while(horizon){
                    TreeLinkNode* temp = horizon->next;
                    while(temp){
                        if(temp->left){
                            temp = temp->left;
                            break;
                        }
                        else if(temp->right){
                            temp = temp->right;
                            break;
                        }
                        else temp = temp->next;
                    }
                    if(horizon->right){
                        horizon->right->next = temp;
                        temp = horizon->right;
                    }
                    if(horizon->left)
                        horizon->left->next = temp;
                    horizon = horizon->next;
                }
                if(current->left)
                    current = current->left;
                else if(current->right)
                    current = current->right;
                else
                    current = current->next;
            }
        }
    };
}
