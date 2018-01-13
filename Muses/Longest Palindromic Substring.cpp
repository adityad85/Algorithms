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
string longestpalindrome(string a)//O(n^2) n^2 space requirements
{
    int n=a.size();
    vector<vector<bool> > p(n+1,vector<bool>(n+1,true));
    int start=0,len=1;
    int i,j;
    for(i=1; i<n; i++)  //it's acting as the length
    {
        for(j=1; j<=n-i; j++)  // and this as the starting point
        {

            p[j][i+j]=p[j+1][i+j-1]&&(a[j-1]==a[j+i-1]);
            if(p[j][j+i]&&i+1>len)
                start=j-1,len=i+1;
        }
    }
    string result(a.begin()+start,a.begin()+start+len);
    return result;
}
int centerOriented(string &a,int start,int end1)
{
    int left=start,right=end1;
    while(left>=0 && right<a.size() && a[left]==a[right])
    {
        left--;
        right++;
    }
    return right-left-1;// note this -1,cause its increasing already ,check is made after increasing.
}
string longpalin(string s) //O(N^2) but O(N) space ,no additional space
{
    int start=0,endp=0,i,n;
    int len=0;
    n=s.length();
    fo(i,n)
    {
        int l1=centerOriented(s,i,i);
        int l2=centerOriented(s,i,i+1);
        len=max(l1,l2);
//        cout<<len<<' ';
        if(len>(endp-start))
        {
            start=i-(len-1)/2;
            endp=i+len/2;
        }
    }
    return s.substr(start,endp-start+1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    cout<<longpalin(s)<<"\n";
    cout<<longestpalindrome(s);
    return 0;
}

