/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> oldToNew;
        oldToNew[NULL] = NULL;

        Node* curr = head;
        while (curr != NULL) {
            if (oldToNew.find(curr) == oldToNew.end()) {
                oldToNew[curr] = new Node(0);
            }
            oldToNew[curr]->val = curr->val;

            if (oldToNew.find(curr->next) == oldToNew.end()) {
                oldToNew[curr->next] = new Node(0);
            }
            oldToNew[curr]->next = oldToNew[curr->next];

            if (oldToNew.find(curr->random) == oldToNew.end()) {
                oldToNew[curr->random] = new Node(0);
            }
            oldToNew[curr]->random = oldToNew[curr->random];

            curr = curr->next;
        }

        return oldToNew[head];
    }
};


/*

[[7, 7], [13,0]]


*/