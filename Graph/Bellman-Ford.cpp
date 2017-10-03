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
int D[MAX],count1[MAX];
int nodes,edges;
/* I'm not marking any node as visited here that makes me repeat any node any number of times
that it is required as if there's a way from one node to another, then i'm going to push it
and i don't care how many times should my program repeat it .
but just adding a simple case if it's greater than (n-1) stop immediately.

This piece of code is so beautiful ,that it will stop as soon as the relaxations stop.
*/

/*Bellman-Ford Algorithm
	 Problem (informal): Given a weighted graph G, source u and sink v, find minimally weighted u~v path in G

	 Algorithm: Iterates over all vertices and edges and relaxes edges

	 Complexity:
	 	* Time - O(|V|*|E|) since main loop iterates over all vertices and edges
	 	* Space - O(|V| + |E|) to store edges and vertices
*/
int BellmanFord(int s)
{
    int i,u,v,w;
    fo(i,nodes+1)D[i]=INT_MAX;
    queue<int>q;
    q.push(s);
    D[s]=0;
    while(!q.empty()){
        u= q.front();
        q.pop();
        if(++count1[u]>nodes-1)return 0;
        for(auto e:G[u]){
            v=e.F;
            w=e.S;
            if(D[v]>D[u]+w){
                D[v]=D[u]+w;
                q.push(v);
            }
        }

    }
    return 1;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,u,v,w,start;
    cin>>nodes>>edges;
    fo(i,edges)
    {
        cin>>u>>v>>w;
        G[u].pb(pii(v,w));
        //G[v].pb(pii(u,w));//undirected
    }
    cin>>start;
    if(BellmanFord(start)){
        fo(i,nodes+1)cout<<i<<" "<<D[i]<<endl;
    }
    else{
        cout<<"negative cycle";
    }
    return 0;
}

