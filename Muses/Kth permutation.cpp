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
int factorial(int n)
{
    if(n>12) return INT_MAX;
    int f=1;
    for (int i=2; i<=n; i++)
        f*=i;
    return f;
}
void permutationHelper(vector<int >& num, int k, stringstream& ss)
{

    if(num.size()==0)return;
    int f = factorial(num.size()-1);
    int inc = k/f;    //allows you to skip over the permutations
    ss<<to_string(num[inc]);
    num.erase(num.begin()+inc);
    permutationHelper(num,k%f,ss); //recurse over the left part
}
string getpermute(int n,int k)
{
    k--;
    if(k>=factorial(n))return "";
    vector<int >num(n);
    for(int i=0; i<n; i++)
        num[i]=i+1;
    stringstream ss;
    permutationHelper(num,k,ss);
    return ss.str();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,l;
    cin>>n>>l;
    string s=getpermute(n,l);
    cout<<s;

    return 0;
}

