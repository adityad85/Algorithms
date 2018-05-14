#include <bits/stdc++.h>
#include<iterator>
// #include "stdafx.h"
// #pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
int mpow(int base, int exp);
void ipgraph(int m);
const int mod = 1000000007;
//=======================
/*
Problem: To traverse a BST anytime on demand to find the number whose sum is equal to the given number.

*/
struct BSTnode
{
    int data;
    BSTnode *left=NULL,*right=NULL;
};
stack<BSTnode*>peace1;
stack<BSTnode*>peace2;
typedef struct
{
    int a,b;
} tuple1;
/*class BST
{


    BSTnode *bt;
    BST(BSTnode *bst1)
    {
        bt->data=bst1->data;
        bt->left=bst1->left;
        bt->right=bst1->right;

    }*/
BSTnode* insert1(BSTnode *root,int data)
{
    if(root == NULL)
    {   //cout<<1;
        root=(BSTnode*)malloc(sizeof(BSTnode));
        root->data=data;
        //cout<<root->data;
        return root;
    }
    else
    {
        if(data<=root->data)
            root->left=insert1(root->left,data);
        else
            root->right=insert1(root->right,data);

        return root;
    }

}
BSTnode* inorderFromStart(BSTnode *bst)
{
    peace1.push(bst);
    while(bst->left!=NULL)
    {
        bst=bst->left;
        peace1.push(bst);

    }
    while(!peace1.empty())
    {
        BSTnode *top = peace1.top();
        peace1.pop();
        if(top->right!=NULL)
        {
            bst=top->right;
            peace1.push(bst);
            while(bst->left!=NULL)
            {
                bst=bst->left;
                peace1.push(bst);
            }
        }
    return top;

    }
    return NULL;
}
BSTnode* inorderFromEnd(BSTnode *bst)
{
    peace2.push(bst);
    while(bst->right!=NULL)
    {
        bst=bst->right;
        peace2.push(bst);
    }
    while(!peace2.empty())
    {
        BSTnode *top=peace2.top();
        peace2.pop();
        if(top->left!=NULL)
        {
            bst=top->left;
            peace2.push(bst);
            while(bst->right!=NULL)
            {
                bst=bst->right;
                peace2.push(bst);
            }
        }
        return top;
    }
    return NULL;

}

//};
tuple1 twoSum(BSTnode* bst,int k)
{
    if(bst==NULL)return {0,0};
    cout<<"in";
    BSTnode *bstStart=inorderFromStart(bst);
    BSTnode *bstEnd=inorderFromEnd(bst);
    BSTnode *start=bstStart;
    peace1.pop();
    BSTnode *end1= bstEnd;
    peace2.pop();
    while(start!=end1&&!peace1.empty()&&!peace2.empty())
    {//cout<<1121212121;
        if(start->data+end1->data==k)return {start->data,end1->data};
        else if(start->data+end1->data>k)
            {end1=peace2.top();
            peace2.pop();}
        else {//start=std::next(start);
            start=peace1.top();
            peace1.pop();
            }

    }
    return {0,0};
}
void inorder(BSTnode *root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }

}
void inhere(BSTnode *n){
    n=inorderFromStart(n);
    cout<<n->data;
   while(!peace1.empty()){
         n=peace1.top();
        peace1.pop();
        cout<<n->data;
        }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    BSTnode *bstz=NULL ;
    bstz=insert1(bstz,5);
    insert1(bstz,3);
    insert1(bstz,1);
    insert1(bstz,2);
    insert1(bstz,4);
    insert1(bstz,7);
    insert1(bstz,6);
    //inhere(bstz);
    tuple1 a=twoSum(bstz,10);
    cout<<a.a<<a.b;
    return 0;
}

