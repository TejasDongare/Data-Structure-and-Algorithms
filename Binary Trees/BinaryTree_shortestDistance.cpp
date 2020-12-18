#include <iostream>
#include<queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data=d;
        right=NULL;
        left=NULL;
    }
};
class user_pair
{
public:
    int height;
    int diameter;
};
class height_balanced_pair
{
public:
    int height;
    bool ans;
};
node *build_tree()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    node *root=new node(d);
    root->left=build_tree();
    root->right=build_tree();
    return root;
}
void preorder(node *head)
{
    if(head==NULL)
    {
        return;
    }
    cout<<head->data<<" ";
    preorder(head->left);
    preorder(head->right);
    return;
}
//finding height Take O(n)
int height(node *head)
{
    if(head==NULL)
    {
        return 0;
    }
    int left_height=height(head->left);
    int right_height=height(head->right);
    return max(left_height,right_height)+1;
}
//printing Kth Level Takes O(n)
void PrintKthLevel(node *head,int k)
{
    if(head==NULL)
    {
        return;
    }
    if(k==1)
    {
        cout<<head->data<<" ";
        return;
    }
    PrintKthLevel(head->left,k-1);
    PrintKthLevel(head->right,k-1);
    return;
}
//printing Level_order takes O(n*n)
void level_order(node *head)
{
    int h=height(head);
    for(int i=1;i<=h;i++)
    {
        cout<<"Level "<<i<<" :- ";
        PrintKthLevel(head,i);
        cout<<endl;
    }
}
//BFS and level order are same but level order does it in O(n) 
void BFS(node *head)
{
    queue<node*> q;
    q.push(head);
    while(!q.empty())
    {
        node *temp=q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
    }
}
//BFS If We Need with each level with different level
void BFS_With_New_line(node *head)
{
    queue<node*> q;
    q.push(head);
    q.push(NULL);
    while(!q.empty())
    {
        //cout<<"q.size()"<<q.size()<<"q.front() "<<q.front()<<endl;
        node *temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        if(temp!=NULL)
        {
            cout<<temp->data<<" ";
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
        }
    }
}
//**********OR*********
/*
void BFS_With_New_line(node *head)
{
    queue<node*> q;
    q.push(head);
    q.push(NULL);
    while((!q.empty()) and !(q.size()==1 and q.front()==NULL))
    {
       // cout<<"q.size() "<<q.size()<<"q.front() "<<(q.front())<<endl;
        node *temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            cout<<endl;
            q.push(NULL);
        }
        if(temp!=NULL)
        {
            cout<<temp->data<<" ";
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
        }
    }
}
*/
int count_nodes(node *head)
{
    if(head==NULL)
    {
        return 0;
    }
    int l=count_nodes(head->left);
    int r=count_nodes(head->right);
    return l+r+1;
}
int Sum(node *head)
{
    if(head==NULL)
    {
        return 0;
    }
    int l=Sum(head->left);
    int r = Sum(head->right);
    return l+r+head->data;
}
//Complexity for diameter is O(n*n) Top down
int diameter(node *head)
{
    if(head==NULL)
    {
        return 0;
    }
    //if passing through root
    int left_height=height(head->left);
    int right_height=height(head->right);
    //if diameter lies in left sub tree
    int l=diameter(head->left);
    //if diameter lies in right subtree
    int r=diameter(head->right);
    return max(max(left_height+right_height,l),r);
}
//more efficient diameter calculating in O(n) bottom up which is post order traversal
user_pair fastDiameter(node*head)
{
    user_pair p;
    if(head==NULL)
    {
        p.diameter=p.height=0;
        return p;
    }
    //post order traversal is like bottom up
    user_pair left=fastDiameter(head->left);
    user_pair right=fastDiameter(head->right);
    p.height=max(left.height,right.height)+1;
    p.diameter=max(left.height+right.height,max(right.diameter,left.diameter));
    return p;
}
int sum_tree(node* head)
{
    if(head==NULL)
    {
        return 0;
    }
    int l=sum_tree(head->left);
    int r=sum_tree(head->right);
    if(!(l==0 and r==0))
    {
        int temp=head->data;
        head->data=l+r;
        return l+r+temp;
    }
    return head->data;
}
height_balanced_pair is_height_balanced(node *head)
{
    height_balanced_pair p;
    if(head==NULL)
    {
        p.ans=true;
        p.height=0;
        return p;
    }
    height_balanced_pair left=is_height_balanced(head->left);
    height_balanced_pair right=is_height_balanced(head->right);
    if(left.height-right.height<=1 and left.ans and right.ans)
    {
        p.ans=true;
    }
    else
    {
        p.ans=false;
    }
    p.height=max(left.height,right.height)+1;
    return p;
}
node* build_height_balanced_tree_using_array(int *a,int n,int s,int e)
{   
    if(s>e)
    {
        return NULL;
    }
    int mid=(s+e)/2;
    node *root=new node(a[mid]);
    root->left=build_height_balanced_tree_using_array(a,n,s,mid-1);
    root->right=build_height_balanced_tree_using_array(a,n,mid+1,e);
    return root;
}
void RightViewTree(node *head,int current_level,int &maxlevel)
{
    if(head==NULL)
    {
        return;
    }
    //root
    if(maxlevel<current_level)
    {
        cout<<head->data<<" ";
        maxlevel=current_level;
    }
    //right 
    RightViewTree(head->right,current_level+1,maxlevel);
    //left
    RightViewTree(head->left,current_level+1,maxlevel);
    return;
}
void printAtDistance(node *head,int k)
{
    if(head==NULL or k<0)
    {
        return;
    }
    if(k==0)
    {
        cout<<head->data<<" ";
    }
    printAtDistance(head->left,k-1);
    printAtDistance(head->right,k-1);
}
int kthDistanceFromTargetNode(node *head,int k,node *target)
{
    if(head==NULL)
    {
        return -1;
    }
    if(target==head)
    {
        printAtDistance(head,k);
        return k-1;
    }
    int dl=kthDistanceFromTargetNode(head->left,k,target);
    if(dl>-1)
    {
        if(dl==0)
        {
            cout<<head->data<<" ";
        }
        else
        {
            printAtDistance(head->right,dl-1);
        }
        return dl-1;
    }
    int dr=kthDistanceFromTargetNode(head->right,k,target);
    if(dr!=-1)
    {
        if(dr==0)
        {
            cout<<head->data<<" ";
        }
        else
        {
            printAtDistance(head->left,dr-1);
        }
        return dr-1;
    }
    return -1;
}
node* LCA(node *head,int a,int b)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->data==a or head->data==b)
    {
        return head;
    }
    node *left=LCA(head->left,a,b);
    node *right=LCA(head->right,a,b);
    if(left!=NULL and right!=NULL)
    {
        return head;
    }
    if(left!=NULL)
    {
        return left;
    }
    return right;
}
class MS
{
public:
    int branchsum;
    int maxsum;
    MS()
    {
        branchsum=0;
        maxsum=0;
    }
};
MS max_sum(node *head)
{
    MS p;
    if(head==NULL)
    {
        return p;
    }
    MS left=max_sum(head->left);
    MS right=max_sum(head->right);
    int op1=head->data;
    int op2=left.branchsum+head->data;
    int op3=right.branchsum+head->data;
    int op4=left.branchsum+head->data;
    int current_ans_through_root=max(op1,max(op2,max(op3,op4)));
    //branch sum of the current root
    p.branchsum=max(left.branchsum,max(right.branchsum,0))+head->data;
    p.maxsum=max(left.maxsum,max(right.maxsum,current_ans_through_root));
    return p;
}
//Search level from a root or any particular node
int search_level_from_head(node *head,int a,int level)
{
    if(head==NULL)
    {
        return -1;
    }
    if(a==head->data)
    {
        return level;
    }
    int l=search_level_from_head(head->left,a,level+1);
    if(l!=-1)
    {
        return l;
    }
    return search_level_from_head(head->right,a,level+1);
}
int finddistance(node *head,int a,int b)
{
    node* lca=LCA(head,a,b);
    int l=search_level_from_head(lca,a,0);
    int r=search_level_from_head(lca,b,0);
    return l+r;
}
int main() 
{
    node *head=build_tree();
    cout<<finddistance(head,9,7);
}
