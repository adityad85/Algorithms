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
/*
	Do a breadth-first search in this graph:
	1--2--4--7
	| / \    |
	|/   \   |
	3     5--6
	8--9

	Input:-  9 9
             1 2
             1 3
             2 4
             2 5
             2 3
             4 7
             5 6
             7 6
             8 9
    Output:- 1
             2 3
             4 5
             7 6
             thus : 1 2 3 4 5 7 6
	*/
#define MAX 10001
vl g[MAX];
vector<int>b(MAX,0);
void BFS(int s)
{
    queue<int> q;
    q.push(s);
    //b[s]=1;  A blunder ,Don't do that ever like me
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        if(b[t])continue;
        cout<<t<<endl;
        for(auto e:g[t])
        {
            if(!b[e])
            {
                q.push(e);
            }

        }
        b[t]=1;

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
    BFS(start);
    return 0;
}

