#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

//1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
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
Node * levelorder(){
    int d;
    cin>>d;

    Node *root = new Node (d);

    
}
                        
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

int heightOfTree(Node*root){
    if(root == nullptr){
        return 0;
    }

    int h1= heightOfTree(root->left);
    int h2= heightOfTree(root->right);

    return 1+max(h1,h2);
}

// the diameter is calculated in 3 ways 
// -> calculate the height of both left and right sub tree and add them
// -> if the max diameter is present inside the left subtree
// -> if the max diameter is present inside the left subtree
// -> now we find max of the three cases 
int diameterOfTree(Node*root){
    if(root==nullptr){
        return 0;
    }
// for d1, height of left +height of right is the diameter 
    int d1 = heightOfTree(root->left)+ heightOfTree(root->right);


// for d2 make root to left sub tree node and then find the diameter same as in d1
    int d2 = diameterOfTree(root->left);


// for d3 make root to right sub tree node and then find the diameter same as in d2
    int d3 = diameterOfTree(root->right);

    return max(d1,max(d2,d3));
}
// but this approach taken time of O(n2)
// so there is another approach to solve the diameter of tree
// Now this diameter takes O(n) time to solve the diameter of tree

class HeightDiameterPair{
public:

    int diameter;
    int height;
};

HeightDiameterPair optimDiameter(Node* root){
    HeightDiameterPair p;

    if(root == nullptr){
        p.diameter=0;
        p.height=0;
        return p;
    }

    HeightDiameterPair Left = optimDiameter(root->left);
    HeightDiameterPair Right =  optimDiameter(root->right);
    

    p.height = max(Left.height,Right.height)+1;

    int D1 = Left.height + Right.height;
    int D2 = Left.diameter;
    int D3 = Right.diameter;

    p.diameter = max(D1,max(D2,D3));

    return p;
}

int main(){
    cout<<"Enter the value of nodes \n";
    Node* root = levelOrderBuild();

    PrintLevelOrder(root);

    cout<<"Diameter of tree : "<<diameterOfTree(root)<<endl; 
    cout<<"OptDiameter of tree : "<<optimDiameter(root).diameter;

    return 0;
}