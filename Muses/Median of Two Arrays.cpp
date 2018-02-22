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
int getOrderStatistics(const vector<int>& A,int as,int ae,const vector<int>&B,int bs,int be,int k )
{
    int n=ae-as+1,m=be-bs+1;
    if(n>m)
        return getOrderStatistics(B,bs,be,A,as,ae,k);
    if(n<=0)
        return B[bs+k-1];
    if(k==1)
        return min(A[as],B[bs]);
    int pa=min(k/2,n),pb=k-pa;
    return A[as+pa-1]<=B[bs+pb-1]?getOrderStatistics(A,as+pa,ae,B,bs,bs+pb-1,k-pa)
           :
           getOrderStatistics(A,as,as+pa-1,B,bs+pb,be,k-pb);
}
double findMedianSortedArrays(const vector<int>&A,const vector<int>&B)
{
    int n=A.size(),m=B.size();
    return (n+m)%2!=0?getOrderStatistics(A,0,n-1,B,0,m-1,(n+m)/2+1)
    :
        (getOrderStatistics(A,0,n-1,B,0,m-1,(n+m)/2)+getOrderStatistics(A,0,n-1,B,0,m-1,(n+m)/2+1))/2.0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,i;
    cin>>n>>m;
    vi a(n),b(m);
    fo(i,n)cin>>a[i];
    fo(i,m)cin>>b[i];
    double ans=findMedianSortedArrays(a,b);
    cout<<ans;

    return 0;
}

