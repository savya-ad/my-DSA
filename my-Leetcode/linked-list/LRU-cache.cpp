// Problem link:- https://leetcode.com/problems/lru-cache/

struct  Node{
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k, int value){
        key=k;
        val=value;
        prev=nullptr;
        next=nullptr;
    }
};
class LRUCache {
    unordered_map<int , Node*> umap;
    Node* head= new Node(-1,-1);
    Node* tail= new Node(-1,-1);
    int cap;
    
    void deleteNode(Node *curr){
        Node *prev=curr->prev;
        Node *next=curr->next;
        prev->next=next;
        next->prev=prev;
    }
    void addBegin(Node *curr){
        curr->next=head->next;
        curr->prev=head;
        head->next->prev=curr;
        head->next=curr;
    }
public:
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    int get(int key) {
        if(umap.find(key)!=umap.end()){
            int curr_val=umap[key]->val;
            put(key, curr_val);
            return curr_val;
        }
        return -1;
    }
    void put(int key, int value) {
        if(umap.find(key)!=umap.end()){     //if key exists
            deleteNode(umap[key]);              // delete node
            umap.erase(key);
            addBegin(new Node(key, value));
            umap[key]=head->next;
        }
        else{ 
            if(umap.size()==cap){        //size==full
                umap.erase(tail->prev->key);    //erasing key from umap
                deleteNode(tail->prev); 
                addBegin(new Node(key, value));
                umap[key]=head->next;// delete node
            }
            else{                       // if size is not full
                addBegin(new Node(key, value));
                umap[key]=head->next;
            }
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
