#include<bits/stdc++.h>
using namespace std;
 unordered_map<int,int>mp;
class Node{
    public:
    Node*left;
    Node*right;
    int data;
    Node(int x)
    {
        left=nullptr;
        right=nullptr;
        data=x;
    }
};
Node* Binarytree(){
    int x;
    cout<<"Enter node value if you want null then enter -1"<<endl;
    cin>>x;
    if(x==-1)  return nullptr;
    
    Node *root=new Node(x);
    cout<<"enter left child of "<<x<<endl;
    root->left=Binarytree();
    cout<<"enter right child of"<<x<<endl;
    root->right=Binarytree();
    return root;
}

void inorder(Node *root)
{
    if(root->left)
    inorder(root->left);
    cout<<root->data<<" ";
    if(root->right)
    inorder(root->right);
}
void bfs(Node*root)
{
    queue<pair<Node*,int>>q;
    q.push({root,0});
    mp[root->data]=0;
    while(!q.empty())
    {
      
        int k=q.size();
        while(k--)
        {
        Node*node=q.front().first;
        int idx=q.front().second;
        q.pop();
            mp[node->data]=idx;
            if(node->left)
                q.push({node->left,idx+1});
            if(node->right)
              q.push({node->right,idx+1});
            
        }
    }
   
}
int main(){
    Node *root=Binarytree();
    if(root==nullptr) return 0;
    inorder(root);
   
    bfs(root);
    int x,y;
    cout<<"enter the nodes whose distance you want to calculate"<<endl;
    cin>>x>>y;
    cout<<abs(mp[x]+mp[y]);
    return 0;

}