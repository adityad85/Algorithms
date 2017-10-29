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
/*Counting Sort
	 Problem (informal): Given collection of integers, return sorted collection

	 Algorithm: Use hash table to store frequency of each integer in range [-k, k] for k = max(|min|, max) then iterate over table and output

	 Complexity:
	 	* Time - O(n+k) (best)/worst/average case, where k = max(|min|, max) (k=n^O(1))
	 	* Space - O(k) to store [-k, k] frequency table
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vl a;
    int i,d;
    while(cin>>d)
    {
        a.pb(d);

    }
    vl b(a.size()+1,0),c(a.size()+1,0);
    fo(i,a.size())b[a[i]]++;
    for(int i=1; i<b.size(); i++)
        b[i]+=b[i-1];
    int j=0;
    for(int i=0; i<a.size(); i++)
    {
        c[b[a[i]]-1]=a[i];
        b[a[i]]--;
    }
    fo(i,a.size())cout<<c[i]<<" ";
    return 0;
}

