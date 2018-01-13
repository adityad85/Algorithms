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

int partition (int a[],int l,int r,int x)
{

    int i ;
    for(i=l; i<r; i++)
        if(a[i]==x)
            break;
    swap(a[i],a[r]);
    i=l;
    for(int j=l; j<=r-1; j++)
    {
        if(a[j]<=x)
        {
            swap(a[i],a[j]);
            i++;
        }
    }
    swap(a[i],a[r]);
    return i;
}
int findmedian(int a[],int n)
{
    sort(a,a+n);
    return a[n/2];
}
int kthnumber(int a[],int l,int r,int k)
{
    if(k>0 && k<=r-l+1)
    {
        int n=r-l+1;
        int i,medi[(n+4)/5];
        for(i=0; i<n/5; i++)
            medi[i]=findmedian(a+l+i*5,5);
        if(i*5<n)
        {
            medi[i]=findmedian(a+l+i*5,n%5);
            i++;
        }
        int medofmed=(i==1)?medi[i-1]:kthnumber(medi,0,i-1,i/2);
        int p= partition(a,l,r,medofmed);
        int le=p-l+1;
        if(le==k)
            return a[p];
        if(le<=k)
        return kthnumber(a,p+1,r,k-p+l-1);
          else  return kthnumber(a,l,p-1,k);

    }
    return 11111;
}
//also known as the median of the medians
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {12, 3, 8, 7, 4, 19, 26};
    cout<<kthnumber(arr,0,6,6);
    return 0;
}

