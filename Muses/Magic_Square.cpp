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
void MagicSquare(int n){
   // vector<vector<int> >v(n+1,vector<int>(n+1));
int v[n+1][n+1];
   memset(v,0,sizeof(v));
    int i=0,j=n/2,ni,nj;
    for(int k=1;k<=n*n;k++){
        v[i][j]=k;
        ni=(i-1+n)%n;
        nj=(j-1+n)%n;
        /*if(i<0)
        ni=ni+n;
        if(j<0)
            nj=nj+n;
       */ if(v[ni][nj]==0)
        {
            i=ni;
            j=nj;
        }
        else{
            i=(i+1)%n;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<v[i][j]<<" ";
        cout<<"\n";
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
//    vector<int ,vector<int>>v(n+1,vector<int>(n+1) );
    MagicSquare(n);
	return 0;
}

