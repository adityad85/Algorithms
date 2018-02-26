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
  The Problem here is to determine the position of the median in a matrix that includes each row as sorted.

  Algorithm: 1. Find the maximum and the minimum .
             2. know the desired position by calculating the median position with the help of the size .
             3. now calculate the place of the assumption by taking into account the minimum and the maximum values .
             4. now check the mid position and calculate the place value by upper bound function.
             5. compare the place and the desired value .if the place is less than the desired then just change the min = mid+1 else do the max= mid
             6. return at the final call. the min you have.

*/
int findmedian(vector<vector<int > > &a)
{
    int mn=a[0][0],mx=a[0][0],n=a.size(),m=a[0].size();
    for(int i=0; i<n; i++)
    {
        if(a[i][0]<mn)mn=a[i][0];
        if(a[i][m-1]>mx)mx=a[i][m-1];

    }
    int desired=(n*m+1)/2;
    while(mn<mx)
    {
        int mid=mn+ (mx-mn)/2;
        int place=0;
        for(int i=0; i<n; i++)
            place+=upper_bound(a[i].begin(),a[i].end(),mid)-a[i].begin();
        if(place<desired)
            mn=mid+1;
        else
            mx=mid;
    }
    return mn;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n;
    cin>>n;
    vector<vector<int> >a(n,vector<int>(n));
    fo(i,n)
    fo(j,n)
    cin>>a[i][j];
    int as=findmedian(a);
    return 0;
}

