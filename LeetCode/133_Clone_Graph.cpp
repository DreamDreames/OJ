#include "shared.h"
/*
 Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 
 
 OJ's undirected graph serialization:
 Nodes are labeled uniquely.
 
 We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
 As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 
 The graph has a total of three nodes, and therefore contains three parts as separated by #.
 
 First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 Second node is labeled as 1. Connect node 1 to node 2.
 Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
 Visually, the graph looks like the following:
 
      1
     / \
    /   \
    0 --- 2
         / \
         \_/
*/
namespace CloneGraph {
    struct UndirectedGraphNode {
        int label;
        vector<UndirectedGraphNode *> neighbors;
        UndirectedGraphNode(int x) : label(x) {};
    };

    class Solution {
    public:
        UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
            if(node == NULL)
                return NULL;
            
            unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nodeMap;
            queue<UndirectedGraphNode*> toVisit;
            toVisit.push(node);
            auto newNode = new UndirectedGraphNode(node->label);
            nodeMap[node] = newNode;
            while(!toVisit.empty()){
                auto current = toVisit.front();
                toVisit.pop();
                auto currentCopy = nodeMap[current];
                for(int i = 0; i < current->neighbors.size(); ++ i){
                    auto neighbor = current->neighbors[i];
                    if(nodeMap.find(neighbor) != nodeMap.end()){
                        currentCopy->neighbors.push_back(nodeMap[neighbor]);
                    }
                    else{
                        auto neighborCopy = new UndirectedGraphNode(neighbor->label);
                        nodeMap[neighbor] = neighborCopy;
                        toVisit.push(neighbor);
                        currentCopy->neighbors.push_back(neighborCopy);
                    }
                }
            }
            return newNode;
        }

    };
    
    TEST(CloneGraph, clone){
        UndirectedGraphNode* node = new UndirectedGraphNode(0);
        node->neighbors.push_back(node);
        node->neighbors.push_back(node);
        Solution sln;
        auto newNode = sln.cloneGraph(node);
        ASSERT_EQ(2, newNode->neighbors.size());
    }
}
