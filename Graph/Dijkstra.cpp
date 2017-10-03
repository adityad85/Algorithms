#include <bits/stdc++.h>
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
#define MAX 100001
vector<pii>G[MAX];
int D[MAX];
bool V[MAX];
struct comp  // for the sake of making it min-heap ,my priority queue,> if it's this way it means min heap, if its > then it means max heap
{
    bool operator()(const pii &a,const pii &b)
    {
        return a.S >b.S;
    }
};

int edges,nodes;
void Dijkstra(int s)
{
    int u,i,v,w;
    fo(i,nodes+1)D[i]=INT_MAX;
    D[s]=0;
    priority_queue<pii,vector<pii>,comp>q;
    q.push(pii(s,0));
    while(!q.empty())//Time = V.log(V) + |E|log(V)=(|E|+|V|)log(V)
    {
        u=q.top().F;
        q.pop();//This will cause O(log V)
        if(V[u])continue;
        // int size_node=G[u].size();
        for(auto e:G[u])//|E| times
        {
            v=e.F;
            w=e.S;
            if(!V[v]&&D[u]+w<D[v])
            {
                D[v]=D[u]+w;
                q.push(pii(v,D[v]));//Decrease Key causes it to be O(log(V))
            }
        }
        V[u]=1;//done with node u
    }
}
/*
This is Dijkstra for the weighted ,undirected graph that gives the single source
shortest distance to all the available nodes.
*/
/*Dijkstra's Algorithm
	 Problem (informal): Given a weighted graph G, source u and sink v, find minimally weighted u~v path in G

	 Algorithm: BFS with priority queue; maintains distance to certain node and updates along with previous

	 Complexity:
	 	* Time - O((|E|+|V|)log|V|) where V is set of vertices and E is set of edges
	 	* Space - O(|V|) to store visited vertices
*/
int main()
{
    ios_base::sync_with_stdio(false);//basically to not sync with the c and c++ stream
    cin.tie(NULL);
    int i,u,v,w,start;
    cin>>nodes>>edges;
    fo(i,edges)
    {
        cin>>u>>v>>w;
        G[u].pb(pii(v,w));//from 'u' to 'v' with weight 'w'
        G[v].pb(pii(u,w));//for undirected graph
    }
    cin>>start;
    Dijkstra(start);
    for(int i=1; i<=nodes; i++)cout<<i<<" "<<D[i]<<endl;
    return 0;
}

