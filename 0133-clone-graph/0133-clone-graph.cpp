/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node,unordered_map<Node*,Node*>& map){
        // clone the node 
        Node* newNode=new Node(node->val);
        map[node]=newNode;
        // iterate over its neighbor
        for(auto it:node->neighbors){
            // check whethers its cloned or not
            if(map.find(it)!=map.end()){
                //already cloned;
                newNode->neighbors.push_back(map[it]);
            }else{
                // not cloned till now, call dfs
                Node* temp=dfs(it,map);
                newNode->neighbors.push_back(temp);
            }
        }
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> map;
        if(node==NULL) return NULL;
        return dfs(node,map);
    }
};