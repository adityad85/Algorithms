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

/*Insertion Sort
	 Problem (informal): Given collection of objects, return sorted collection

	 Algorithm: insert element in correct position in sorted array starting from initially zero array length

	 Complexity:
	 	* Time - O(n^2) worse/average case, O(n) best case if initially sorted
	 	* Space - O(1) since no additional storage needed
*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vl asq;
	long long n,i,j,q;
	cin>>n;
	for(int i=0;cin>>q;)//use any character input it will stop the loop
        {
        asq.pb(q);
	}
	fo(i,n){
	    int k=asq[i];
	    j=i-1;
	    while(j>=0&&k<asq[j])//this is done to just keep inserting the elements and allow it to put in the right position
	    {
            asq[j+1]=asq[j];
            j--;
	    }
	    asq[j+1]=k;
	}
	fo(i,n){
	cout<<asq[i]<<" ";}

	return 0;
}

