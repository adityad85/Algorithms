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
template <typename T>
class Stackwithmin
{

private:
    stack< pair<T,T> > S;
public:
    void push(T& x) // what i just learned is the perfect example of why you should use const to make sure you can pass static data . all the runtime data will still work without const.
    {
        S.push(pair<T,T>(x,S.empty()?x:min(x,S.top().second)));
    }
    T pop()
    {
        if(S.empty())
            throw "error";
        pair<T,T> a=S.top();
        S.pop();
        return a.first;
    }
    T getmin()
    {
        if(S.empty())
            throw "error";
        return S.top().second;

    }
    int size()
    {
        return S.size();
    }
    bool empty()
    {
        return S.empty();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Stackwithmin<int> a;
    int v;
    cin>>v;
    a.push(v);
    cout<<a.getmin();
    return 0;
}

