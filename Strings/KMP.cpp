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
    Study :- http://keithschwarz.com/interesting/code/?dir=knuth-morris-pratt



*/
void lpb(string a,vl &l) // Longest Proper Boundary
{
    int len=0,i=1;
    l[0]=0;
    int n=a.length();
    while(i<n)
    {
        if(a[i]==a[len])
        {
            len++;
            l[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len=l[i-1];
            }
            else
            {
                l[i]=len;
                i++;
            }
        }
    }
}
void kmp(string p,string t)
{
    int n=p.length();
    int m=t.length();
    vl l(n);
    lpb(p,l);
    int i=0,j=0;
    while(i<m)
    {
        if(p[j]==t[i])
        {
            i++;
            j++;
        }
        if(j==n)
        {    cout<<"f";
            //found i-j
            j=l[j-1];
        }
        else if(i<m && p[j]!=t[i])
        {
            if(j!=0)
                j=l[j-1];
            else
                i++;

        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string p,t;
    cin>>p>>t;
    kmp(p,t);
    return 0;
}

