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
template<class T,class V>
class SegmentTree
{
    SegmentTree* nodes;
    int N;
public:
    SegmentTree(T arr[],int N)
    {
        this->N=N;
        nodes=new SegmentTreeNode[getSegmentTreeSize(N)];
        buildTree(arr,1,0,N-1);
    }
    ~SegmentTree()
    {
        delete[] nodes;
    }

    V getValue(int lo,int hi)
    {
        SegmentTreeNode result=getValue(1,0,N-1,lo,hi);
        return result.getValue();
    }
    void update(int index,T value)
    {
        update(1,0,N-1,index,value);
    }
private:
    void buildTree(T arr[],int stIndex,int lo,int hi)
    {
        if(lo==hi)
        {
            nodes[stIndex].assignLeaf(arr[lo]);
            return;
        }
        int left=2 * stIndex,right=left+1,mid=(lo+hi)/2;
        buildTree(arr,left,lo,mid);
        buildTree(arr,right,mid+1,hi);
        nodes[stIndex].merge(nodes[left],nodes[right]);
    }
    SegmentTreeNode getValue(int stIndex,int left,int right,int lo,int hi)
    {
        if(left==lo && right==hi)
            return nodes[stindex];

        int mid=(left +right)/2;
        if(lo>mid)
            return getValue(2*stIndex+1,mid+1,right,lo,hi);
        if(hi<=mid)
            return getValue(2*stIndex,left,mid,lo,hi);
        SegmentTreeNode leftResult=getValue(2*stIndex,left,mid,lo,mid);
        SegmentTreeNode rightResult=getValue(2*stIndex+1,mid+1,right,mid+1,hi);
        SegmentTreeNode result;
        result.merge(leftResult,rightResult);
        return result;

    }
    int getSegmentTreeSize(int N)
    {
        int size=1;
        for(; size<N; size<<=1);
        return size<<1;

    }
    void update(int stIndex,int lo,int hi,int index,T value)
    {
        if(lo==hi)
        {

            node[stIndex].assignLeaf(value);
            return ;
        }
        int left =2* stIndex,right=left+1,mid = (lo+hi)/2;
        if(index<=mid)
            update(left,lo,mid,index,value);
        else
            update(right,mid+1,hi,index,value);

        nodes[stIndex].merge(nodes[left],nodes[right]);

    }
};
//Implement Segment tree node value with a structure;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}

