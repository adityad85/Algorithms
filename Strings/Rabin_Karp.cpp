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
   Problem: Search a given pattern in the string

   Algorithm : use Rabin Karp to find the pattern

   Complexity :
                * Worst Case: O(mn) m=length of the pattern and n=length of the string
                * Best Case : O(m+n)
                example : asdfghj asd

*/
long long powe(long long n,long long p,long long q)//Recursive Squaring
{
    long long ans=1;
    if(p==1)
        return n;
    ans=powe(n,p/2,q);
    ans=(ans*ans)%q;
    if(p%2==1)
        ans=(ans*n)%q;
    return ans;
}
#define d 256
//define is a preprocessor ,compiler doesn't sees it but just is used for text replacement
void RK_search(string pat,string txt,long long q)
{
    long long m=pat.length();//length of the pattern
    long long n=txt.length();//length of the text

    long long j,p=0,t=0,h=powe(d,m-1,q);//d is 256 here,maybe for all possible characters
    for(int i=0; i<m; i++)
    {
        p=(d*p+pat[i])%q;
        t=(d*t+txt[i])%q;
    }
    for(int i=0; i<=n-m; i++)
    {
        if(p==t)
        {
            for(j=0; j<m; j++)
            {
                if(txt[i+j]!=pat[j])
                    break;
            }
            if(j==m)
                cout<<"found at "<<i<<endl;
        }
        if(i<n-m)
        {
            t=(d*(t-txt[i]*h)+txt[i+m])%q;
            if(t<0)
                t=(t+q);
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string p,t;
    long long q;
    cin>>t>>p>>q;
    RK_search(p,t,q);

    return 0;
}

