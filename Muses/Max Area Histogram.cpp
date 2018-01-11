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
int area (vi A)
{
    int n= A.size();
    vi pR(n);
    stack<int>S;
    for(int i=n-1; i>=0; i--)
    {  /*
        It gives the right end index till which the current has the local maxima.
        means the right index till which it can compute the area.as soon as it touches
        a height less than the current one . it wont be able to include that area for the current height.
        */
        while(!S.empty()&& A[S.top()]>=A[i])
            S.pop();
        pR[i]=S.empty()?n-1:S.top()-1;
        S.push(i);
    }
    while(!S.empty())S.pop();
    int maxa=0;
    for(int i=0; i<n; i++)
    {
        while (!S.empty()&& A[S.top()]>=A[i])
            S.pop();
        long long area= A[i]*(pR[i]+1-(S.empty()?0:S.top()+1));
        if(area > maxa)
            maxa =area;
        S.push(i);

    }
    return maxa;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vi a;
    int n,i,d;
    cin>>n;
    fo(i,n)
    {
        cin>>d;
        a.pb(d);
    }
    cout<<area2(a);

    return 0;
}

