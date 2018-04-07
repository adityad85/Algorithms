#include <bits/stdc++.h>
#include<random>
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
double MonteCarlo(double pointCount)
{
    double circlePoints=0;
    double pi,x,y;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<>dis;
    for(int i=0; i<pointCount; ++i)
    {
        x=dis(gen);
        y=dis(gen);
        if(x*x+y*y<1)
            circlePoints++;
    }
    pi= (circlePoints++/pointCount)*4;
    return pi;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double pointCount,pi;
    cout<<"Enter point count";
    cin>>pointCount;
    cout<<MonteCarlo(pointCount);


    return 0;
}

