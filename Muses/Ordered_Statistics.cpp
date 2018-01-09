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
int partition(int a[],int l,int r)
{
    int x=a[r],i=l;
    for(int j=l; j<=r-1; j++)
    {
        if (a[j]<=x)
        {
            swap(a[j],a[i]) ;
            i++;
        }
    }
    swap(a[i],a[r]);
    return i;

}
int randomPartition (int a[],int l,int r)
{
    int n=r-l+1;
    int pivot=rand()%n ;
    swap(a[l+pivot],a[r]);
    return partition(a,l,r);

}
int  kthSmallest (int a[],int l,int r,int k)
{
    if(k>0&& k<=r-l+1)
    {
        int pos=randomPartition(a,l,r);
        if(k-1==pos-l)
            return a[pos];
        if(pos-l>k-1)
            return kthSmallest(a,l,pos-1,k);
        return kthSmallest(a,pos+1,r,k-pos+l-1);
    }

    return INT_MAX;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[]={9,4,3,6,7,1,8,5,2};
    int n=9,k;
    cin>>k;
    cout<<kthSmallest(a,0,n-1,k);

    return 0;
}

