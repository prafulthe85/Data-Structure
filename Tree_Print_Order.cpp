#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
// input     :  1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
// preorder  :  1 2 4 5 7 3 6
// inorder   :  4 2 7 5 1 3 6
// postorder :  4 7 5 2 6 3 1
// level order : 1
//               2 3
//               4 5 6
//               7  
// level order : 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1  
// build    
class Node {

public:

    int data;
    Node *left;
    Node *right;

    Node (int d){
        data=d;
        left=right=nullptr;
    }
};

Node*buildtree(){
    int d;
    cin>>d;

    if(d==-1){
        return nullptr;
    }
    Node*n = new Node(d);
    n->left=buildtree();
    n->right=buildtree();

    return n;
}

void PrintPreOrder(Node * root){
    if(root==nullptr){
        return;
    }

    cout<<root->data<<" ";
    PrintPreOrder(root->left);
    PrintPreOrder(root->right);
}

void PrintInorder(Node * root){
    if(root == nullptr){
        return;
    }
    PrintInorder(root->left);
    cout<<root->data<<" ";
    PrintInorder(root->right);
}

void PrintPostOrder(Node * root){
    if(root == nullptr){
        return;
    }
    PrintPostOrder(root->left);
    PrintPostOrder(root->right);
    cout<<root->data<<" ";

}

void PrintLevelOrder(Node* root){
    queue <Node *> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        Node *temp=q.front();
        if(temp==nullptr){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(nullptr);
            }
        }

        else{
            q.pop();
            cout<<temp->data;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return;
}
// this takes input level wise as 
                            //         1
                            //        / \
                            //      2     3
                            //     / \      \
                            //    4   5      6
                            //        /
                            //       7
                              
Node * levelOrderBuild(){
    int d;
    cin>>d;
    Node *root = new Node(d);
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node * current = q.front();
        q.pop();
        int c1,c2;
        cin>>c1>>c2;

        if(c1!=-1){
            current->left = new Node(c1);
            q.push(current->left);
        }
        if(c2!=-1){
            current->right = new Node(c2);
            q.push(current->right);
        }

    }
    return root;
}

int sumofnode(Node *root){ 
    queue<Node*> q;
    q.push(root);
    int ans = 0;

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        ans += temp->data;
    }
    return ans;
}

int main(){

    cout<<"Enter values of nodes\n";
    // Node *root = buildtree();

    // PrintPreOrder(root);
    // cout<<endl;
    // PrintInorder(root);
    // cout<<endl;
    // PrintPostOrder(root);
    // cout<<endl;
    Node *root = levelOrderBuild();
    PrintLevelOrder(root);
    cout<<endl;

    cout<<"Sum : "<<sumofnode(root);

    return 0;
}