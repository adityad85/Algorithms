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
      Problem : To find the all pair shortest paths
      Algorithm: Floyd Warshall ,Basically just run bellman ford for all the pairs and we'll have our solution.
      Time Complexity : O(V^3)
      Space Complexity: O(V^2),i tried to reduce it by using adjacency list , but i found out eventually that it was not going to
                        make much difference. you'll use the matrix to store the answer and that was already v^2.
*/
#define MAX 10001
long long n;
vector<vector<long long > >d(MAX,vector<long long>(MAX));
void floyd_warshall()
{
    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(d[i][j]>d[i][k]+d[k][j])
                    d[i][j]=d[i][k]+d[k][j];
            }

        }

    }

}
void print1()
{
    int i,j;
    fo(i,n)
    {
        fo(j,n)
        {
            if(d[i][j]!=MAX)
                cout<<d[i][j]<<" ";
        }
        cout<<endl;

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;//vertex
    int i,j;
    fo(i,n)
    {
        fo(j,n)
        {
            cin>>d[i][j];
        }
    }
    floyd_warshall();
    print1();
    return 0;
}

