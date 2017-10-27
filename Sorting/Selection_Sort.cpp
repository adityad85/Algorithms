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
/*Selection Sort

	 Algorithm: Choose minimum of unsorted array, append to sorted array and label as sorted

	 Complexity:
	 	* Time - O(n^2) best/worse/average case, asymptotically tight
	 	* Space - O(1) since no additional storage needed
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vl a;
    int d,i;
    while(cin>>d)
    {
        a.pb(d);
    }
    fo(i,a.size())
    {
        int min=i;
        for(int j=i+1; j<a.size(); j++)
        {
            if(a[min]>a[j])
                min=j;
        }
        int t=a[min];
        a[min]=a[i];
        a[i]=t;
    }
    fo(i,a.size())cout<<a[i]<<" ";
    return 0;
}

