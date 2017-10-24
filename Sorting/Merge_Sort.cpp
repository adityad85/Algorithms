#include <bits/stdc++.h>
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
void merge1(vl &a,int l,int m,int r)
{
    int n1=m-l+1,i;
    int n2=r-m;
    vector<long long>L(n1),R(n2);
    fo(i,n1)L[i]=a[l+i];
    fo(i,n2)R[i]=a[m+1+i];
    int j=0,k=l,p=0;
    while(j<n1&&p<n2)
    {
        if(L[j]<R[p])
        {
            a[k]=L[j++];
        }
        else
        {
            a[k]=R[p++];
        }
        k++;
    }
    while(j<n1)
    {
        a[k++]=L[j++];
    }
    while(p<n2)
    {
        a[k++]=R[p++];
    }
}
merge_sort(vl &a,int l,int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,r);
        merge1(a,l,m,r);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long i,d;
    vl a;
    while(cin>>d)
    {
        a.pb(d);
    }
    merge_sort(a,0,a.size()-1);
    fo(i,a.size())cout<<a[i]<<" ";
    return 0;
}

