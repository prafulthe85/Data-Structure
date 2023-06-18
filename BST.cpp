#include <iostream>
#include <vector>
using namespace std;
class Node {
public:

    int key;
    Node *left;
    Node *right;
    Node(int key){
        this->key = key;
        left = right = nullptr;
    }
};
 
void printBST(Node *root){
    if(root==NULL){
        return ;
    }

    printBST(root->left);
    cout<<root->key<<',';
    printBST(root->right);
}

Node *insert (Node *root, int key){
    if(root==nullptr){
        return new Node(key);
    }

    // recursive case 

    if(key<root->key){
        root->left = insert(root->left,key);
    }
    else{
        root->right = insert(root->right,key);
    }

    return root;
}

// this search will take O(Height) time so it is more efficient than Binary tree 
// as it takes O(n) time  
bool search(Node* root, int key){
    if(root==nullptr){
        return false;
    }

    if(root->key == key){
        return true;
    }

    if(key<root->key){
        return search(root->left,key);
    }

    else{
        return search(root->right,key);
    }
}

// it is the helper function of remove to find the min node data in right subtree 
Node* findmin(Node*root){
    while(root->left!=nullptr){
        root=root->left;
    }
    return root;
}

// to remove a node we have three cases 1. when node has no children 2. when node has one children 3. when node has two children
// here : 1,3,4,6,7,8,10,13,14, for two children find the respective node 
// if root node has to be deleted like 8 so find the next member i.e, 10 to come in place of root node,instead of deleting
// so find 10 in  right subtree using find min function and copy it to root data and then delete prev 10 using prev 2 methods

Node*remove(Node *root, int key){
    if(root==nullptr){
        return nullptr;
    }

    else if(key<root->key){
        root->left = remove(root->left,key);
    }
    else if(key>root->key){
        root->right = remove(root->right,key);
    }

    else {
        // no children node present
        if(root->left==nullptr and root->right==nullptr){
            delete root;
            root=nullptr;
            return root;
        }

        // one children is present 
        else if (root->right==nullptr){
            Node*temp = root;
            root=root->left;
            delete temp;            
        }
        else if (root->left==nullptr){
            Node*temp = root;
            root=root->right;
            delete temp;            
        }

        // when both cildren are present
        else {
            Node*temp = findmin(root->right);
            root->key = temp->key;
            root->right = remove(root->right,temp->key);
        }
    }

    return root;
}

void printRange(Node*root,int k1, int k2){
    if(root==nullptr){ 
        return;
    }

    if(root->key>=k1 and root->key<=k2){
        printRange(root->left,k1,k2);
        cout<<root->key<<" ";
        printRange(root->right,k1,k2);
    }
    else if(root->key>k2){
        printRange(root->left,k1,k2);
    }
    else if(root->key<k1){
        printRange(root->right,k1,k2);
    }
}

void printroot2leaf(Node * root, vector<int> &path){
    if(root==nullptr){ 
        return;
    }

    if(root->left== nullptr and root->right== nullptr){
        for(int node : path){
            cout<<node<<"->";
        }
        cout<<root->key;
        cout<<endl;
    }

    path.push_back(root->key);
    printroot2leaf(root->left,path);
    printroot2leaf(root->right,path);

    path.pop_back();
    return;
}

int main(){

    Node*root = nullptr;

    vector<int> path;

    int arr[] = {8,3,10,1,6,14,4,7,13};

    for(int x: arr){
        root = insert(root,x);
    }

    printBST(root);

    int key;

    cout<<"\nEnter key\n";

    // cin>>key;
    // cout<<search(root,key)<<endl;

    // root = remove(root,key);

    // printBST(root);

    // cout<<endl;
    // printRange(root,5,12);
    
    printroot2leaf(root,path);

    return 0;
}
