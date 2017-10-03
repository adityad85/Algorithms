#include <bits/stdc++.h>
// #include "stdafx.h"
// #pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(int i=1;i<n;i++)
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

struct edge
{
    int head;
    long cost;
};

using Graph = vector<vector<edge>>;
using SingleSp = vector<long>;
using AllSp = vector<vector<long>>;
const long INF=LONG_MAX;

Graph loadgraph(istream is)
{
    Graph g;
    int n,m;
    is>>n>>m;
    g.resize(n+1);
    while(is)
    {
        int v2,v1,c;
        cin>>v1>>v2>>c;
        if(is)
        {
            g[v1].push_back({v2,c});
        }
    }
    return g;
}
Graph addZero(Graph g)
{
    fo(i,g.size())g[0].push_back({i,0});
    return g;
}

SingleSp bellmanford(Graph &g,ing s)
{
    vector<vector<long>> memo(g.size()+2,vector<long>(g.size(),INF));
    memo[0][s]=0;
    for(int i=1; i<memo.size(); i++)
    {
        for(int n=0; n<g.size(); n++)
        {
            if(memo[i-1][n]<memo[i][n])
            {
                memo[i][n]=memo[i-1][n];
            }
            for(auto& e:g[n])
            {
                if(memo[i-1][n]!=INF)
                {
                    if(memo[i-1][n]+e.cost<memo[i][e.head])
                    {
                        memo[i][e.head]=memo[i-1][n]+e.cost;
                    }
                }
            }
        }

    }
    for(int j=0; j<g.size(); j++)
    {
        if(memo[g.size()+1][j]!=memo[g.size()][j])
        {
            cout<<"negative cycle";
        }
    }
    return memo[g.size()];
}
SingleSp dijkstra(const Graph& g,int s)
{
    SingleSp dist(g.size(),INF);
    set<pair<int,long>>front;
    front.insert({0,s});
    while(!front.empty())
    {
        pair<int,long> p = *front.begin();
        front.erase(front.begin());
        int d=p.first;
        int n=p.second;
        dist[n]=d;
        for(auto e:g[n])
        {
            if(dist[n]+e.cost<dist[e.head])
            {
                if(dist[e.head]!INF)
                {
                    front.erase(front.find({dist[e.head],e.head}));

                }
                front.insert({dist[n]+e.cost,e.head});
                dist[e.head]=dist[n]+e.cost;
            }
        }
    }
    return dist;
}
AllSp johnson(Graph &g)
{
    Graph gprime=addZero(g);
    SingleSp ssp;
    ssp=bellmanford(gprime,0);

    for(int i=1; i<g.size(); i++)
    {
        for(auto &e:g[i])
        {
            e.cost=e.cost+ssp[i]-ssp[e.head];
        }


    }
    AllSp allsp(g.size());
    for(int i=0; i<g.size(); i++)
    {
        allsp[i]=dijkstra(g,i);
    }
    for(int u=1; u<g.size(); u++)
    {
        for(int v=1; v<g.size(); v++)
        {
            if(allsp[u][v]!=INF)
                allsp[u][v]+=ssp[v]-ssp[u];
        }
    }
    return allsp;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Graph d=loadgraph(is);
    AllSp aa=johnson(g);
    return 0;
}

