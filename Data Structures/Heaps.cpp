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
void max_heap(int a[],int i,int n)
{
    int left = 2*i;
    int right=2*i+1,largest;
    if(left<=n && a[i]<a[left] )
        largest=left;
    else
        largest=i;
    if(right <=n && a[i]<a[right])
        largest=right;
    if(largest!=i)
    {
        swap(a[i],a[largest]);
        max_heap(a,largest,n);
    }
}
void build_heap(int arr[],int n)
{
    for(int i=n/2; i>=1; i--)
    {
        max_heap(arr,i,n);
    }
}
/*
void heap_sort(int a[],int n)
{
    build_heap(a,n);
    int l =n;
    for(int i=n; i>=2; i--)
    {
        swap(a[i],a[1]);
        l=l-1;
        max_heap(a,1,l);
    }
}
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[7];
    for(int i=1;i<=6;i++)
        cin>>a[i];
    max_heap(a,6);

    for(int i=1;i<=6;i++)
        cout<<a[i]<<" ";
    return 0;
}

