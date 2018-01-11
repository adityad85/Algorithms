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
int partitiona(vi &a,int l,int r)
{
    int v=a[r],i,j=l-1;
    Fo(i,l,r)
    {
        if(a[i]<=v)
        {
            j++;
            swap(a[i],a[j]);
        }
    }
    swap(a[j+1],a[r]);
    return j+1;
}
int selection_algorithm(vi &a,int l,int r,int k)
{
    while(1)
    {
        int p=partitiona(a,l,r),le;
        le=p-l+1;
        if(le==k)
            return a[p];
        if(k>=p)
        {
            l=p+1;
            k=k-le;
        }
        else
            r=p-1;
    }
}
int selection_algorithm2(vi &a,int l,int r,int k)
{
        int p=partitiona(a,l,r),le;
        le=p-l+1;
        if(le==k)
            return a[p];
        if(k>=p)
        {
            selection_algorithm(a,p+1,r,k-le);
        }
        else
            selection_algorithm(a,l,p-1,k);

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int d,n,i;
    vi v;
    cin>>n;
    fo(i,n)
    {
        cin>>d;
        v.pb(d);
    }
    cin>>d;
    cout<<selection_algorithm2(v,0,n,d);
    return 0;
}

