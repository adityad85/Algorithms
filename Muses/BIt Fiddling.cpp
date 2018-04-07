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
typedef unsigned char uint;
const unsigned int SIZE = sizeof(uint)*8;

void printBitRepresentation(uint x)
{
    cout<<bitset<SIZE>(x)<<endl;
}
uint getNextHigherNumberContainingEqualSetBits(uint x)
{
    if(x==0)return 0;
    uint a=x&-x;
    uint b=a+x;
    uint r=b|(((x^b)>>2)/a);
    return r;
}
void generateAllSubsets(uint start)
{
    printBitRepresentation(start);
    for(uint cur=getNextHigherNumberContainingEqualSetBits(start); cur>start; cur=getNextHigherNumberContainingEqualSetBits(cur))
        printBitRepresentation(cur);

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    generateAllSubsets((1<<(SIZE-1))-1);
    generateAllSubsets(011);
    return 0;
}

