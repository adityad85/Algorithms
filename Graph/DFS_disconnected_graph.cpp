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
#define MAX 10001
vl G[MAX],b(MAX,0);
void DFS_fun(int v){
    cout<<v<<endl;
    b[v]=1;
    for(auto e:G[v]){
        if(!b[v]){
            DFS_fun(e);
        }
    }
}int n;
void DFS(){
    for(int i=0;i<n;i++)
        if(!b[i])
        DFS_fun(i);
}
/* Depth-First Search (DFS)
	 Problem (informal): Given starting node, traverse a graph by looking at deeper nodes before closer ones
	 Algorithm: Continue down branch as far as possible, visit deepest unvisited node, backtrack
	 Complexity:
	 	* Time - O(|V| + |E|) where V is set of vertices and E is set of edges
	 	* Space - O(|V|) to store visited vertices
*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int e;
    cin>>n>>e;
    int u,v;
    for(int i=0; i<e; i++)
    {
        cin>>u>>v;
        G[u].pb(v);
    }
    DFS();
	return 0;
}

