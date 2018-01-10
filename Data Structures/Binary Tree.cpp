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
typedef struct node   // to create the node and defining as the node
{
    int data;
    struct node * left ;
    struct node * right;
} node;
node *root=NULL;
node* newnode(int n)//easy implementation of the new node creation
{
    node *temp=(node*)malloc(sizeof(int));
    temp->data=n;
    temp->left=temp->right=NULL;
    return temp;

}
int maxdepth(node *node) // measures the depth of the nodes in the tree
{
    if(node == NULL)
        return 0;
    int l=maxdepth(node->left);
    int r=maxdepth(node->right);
    if(l>r)
        return (l+1);
    else return (r+1);


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    root=newnode(5);
    root->left=newnode(4);
    root->right=newnode(6);
    cout<<root->data;
    cout<<maxdepth(root);
    return 0;
}

