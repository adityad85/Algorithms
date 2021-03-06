#include <bits/stdc++.h>
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
typedef struct node
{
    ll data;
    struct node *left,*right;
} node;
void preorder(node *root)
{
    if(root)
    {
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node *root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}
void inorder(node *root )
{
    if(root)
    {
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }

}
struct node* insert(node* root,int data)
{
    if(root == NULL)
    {
        root=(node*)malloc(sizeof(node));
        root->data=data;

        return root;
    }
    else
    {
        if(data<=root->data)
            root->left=insert(root->left,data);
        else
            root->right=insert(root->right,data);
        return root;
    }
};


int main()
{


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
