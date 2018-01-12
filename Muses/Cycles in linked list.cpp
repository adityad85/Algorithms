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
typedef struct node
{
    int data;
    struct node* next;
} node;
int cycles(node *a)
{
    node *s=a,*f=a;
    while(f&&f->next)
    {
        s=s->next;
        f=f->next->next;
        if(s==f){
                cout<<"yup";
            break;}
    }
    if(f==NULL||f->next==NULL)return -1; //frustrated me a lot , actually tried to .But,Nothing can...
    for(f=a;s!=f;s=s->next,f=f->next);
        return s->data;
}
void build_cycle(node* a,int o)
{   srand(time(NULL));
    node* p=a,*q=a;
    int n=(rand()%(rand()+1))%o;
    cout<<n<<"rand";
    while(n--)
    {
        q=q->next;
    }
    while(p->next)
        p=p->next;
    p->next=q;
    cout<<"aa";
}
void print (node* a){
node* p=a;
while(p!=NULL){
    cout<<p->data;
    p=p->next;}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    node* a=NULL,*p;

    int n,d;
    cin>>n;
    while(n--){
        cin>> d;
            node* t=(node*)malloc(sizeof(int));
        t->data=d;
        t->next=NULL;
        if(a==NULL)
        {
            a=t;
            p=a;
        }
        else
        {
            p->next=t;
            p=p->next;
        }
    }
    build_cycle(a,n);
    //print(a);
    cout<<cycles(a);
    return 0;
}


