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
/* Depth-First Search (DFS)
	 Problem (informal): Given starting node, traverse a graph by looking at deeper nodes before closer ones

	 Algorithm: Continue down branch as far as possible, visit deepest unvisited node, backtrack

	 Complexity:
	 	* Time - O(|V| + |E|) where V is set of vertices and E is set of edges
	 	* Space - O(|V|) to store visited vertices

	Do a depth-first search in this graph:
	1--2--4
	| /
	|/
	3
	5--6--7
	   |
	   8
	   input: 8 7
	          1 2
              1 3
              2 4
              2 3
              5 6
              6 7
              6 8
       Output:1 3 2 4
               in                    0
                                  1     2
                                3   4 5   6

               op               0 2 6 5 1 4 3

	*/
#define MAX 10001
vector<int >g[MAX];
vector<int>b(MAX,0);
void DFS(int s)
{
    stack<int> q ;//Reason of using a stack is simple as we grow recursively in dfs recursive implementation it actually
    //builds a stack inside the machine
    //which can be replicated by the stack here.Graph can be viewed from both the sides ,
    //thus if we start from one side and reach to the other side we'll
    // do that using the depth approach,every ;last element is picked again which ends up resulting in depth.
    q.push(s);
    while(!q.empty())
    {
        int t=q.top();
        q.pop();
        // cout<<t<<endl;
        if(!b[t])
        {
            b[t]=1;
            cout<<t<<endl;
        }
        for(auto e:g[t])
        {
            if(!b[e])
                q.push(e);
        }

    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int u,v,nodes,edges,i,start;
    cin>>nodes>>edges;
    fo(i,edges)
    {
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    cin>>start;
    DFS(start);

    return 0;
}

