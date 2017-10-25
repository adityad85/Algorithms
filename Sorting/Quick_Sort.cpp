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
/*Quicksort
	 Problem (informal): Given collection of objects, return sorted collection

	 Algorithm: Choose random partition, move all elements less than partition to its left and vice versa, quicksort subarrays

	 Complexity:
	 	* Time - O(n^2) worst case, O(nlogn) best/average case due to randomness
	 	* Space - O(logn) since quicksort() called logn times and each time partition is stored
     Notes:
        * The quick sort is better as it uses much less auxiliary space in comparison to the merge sort which uses much greater space
*/
int partition(vl &a,int l,int u)
{
    int pivot=a[u];
    int i=l-1;
    for(int j=l; j<u; j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            int t=a[j];
            a[j]=a[i];
            a[i]=t;
        }
    }
    int tt=a[i+1];
    a[i+1]=a[u];
    a[u]=tt;
    return i+1;

}
void quicksort(vl &a,int l,int u)
{
    if(l<u)
    {
        int p=partition(a,l,u);
        quicksort(a,l,p-1);
        quicksort(a,p+1,u);
    }
}
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
    quicksort(a,0,a.size()-1);
    fo(i,a.size())cout<<a[i]<<" ";

    return 0;
}

