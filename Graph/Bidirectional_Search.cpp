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
vl G[MAX],v(MAX,0),p(MAX,0);
int V;
void BFS(queue<int>&q,vl &v,int p[]){
int u=q.front();
q.pop();
for(long long e:G[u]){
  if(!v[e]){
    p[e]=u;
    v[e]=1;
    q.push(e);
  }
}}
int isInter(vl &s_v,vl &t_v){
int inter =1;
for(int i=0;i<V;i++){
    if(s_v[i]&&t_v[i])
        return i;
}
return -1;
}
void print(int s_p[],int t_p[],int s,int t,int inter){

    vector<long long>path;
    path.pb(inter);
    int i=inter;
    while(i!=s){
        path.pb(s_p[i]);
        i=s_p[i];
    }
    reverse(path.begin(),path.end());
    i=inter;
    while(i!=t){
        path.pb(t_p[i]);
        i=t_p[i];
    }
    for(auto e:path){
        cout<<e<<endl;
    }

}
int bidirSearch(int s,int d){
    vl s_v(MAX,0),d_v(MAX,0);
    int s_p[MAX],d_p[MAX];
    queue<int> s_q,d_q;
    int inter=-1;
    s_q.push(s);
    s_v[s]=1;
    s_p[s]=-1;
    d_q.push(d);
    d_v[d]=1;
    d_p[d]=-1;
    while(!s_q.empty() &&!d_q.empty()){
        BFS(s_q,s_v,s_p);
        BFS(d_q,d_v,d_p);
        inter=isInter(s_v,d_v);
        if(inter!=-1){
            cout<<s<<" "<<d<<endl;
            cout<<"intersection"<<inter<<endl;
            print(s_p,d_p,s,d,inter);
            return 1;
        }
    }
    return -1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int v,e,u;
    cin>>V>>e;
    for(int i=0;i<e;i++){
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    int s;
    cin>>s>>v;
    if(bidirSearch(s,v)==-1)
        cout<<"No"<<endl;
	return 0;
}

