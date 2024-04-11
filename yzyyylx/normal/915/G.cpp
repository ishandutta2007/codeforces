#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define ll long long
#define N 2001000
#define MN 2000000
#define M 1000000007
using namespace std;

ll n,m,xo,sum,ans[N],num[N];
vector<int>ys[N];

inline void Add(ll &u,ll v){u=(u+v)%M;}
inline ll po(ll u,ll v)
{
    ll res=1;
    for(;v;)
    {
	if(v&1) res=res*u%M;
	u=u*u%M;
	v>>=1;
    }
    return res;
}

inline void get()
{
    int i,j;
    for(i=2;i<=MN;i++)
    {
	for(j=i;j<=MN;j+=i)
	{
	    ys[j].push_back(i);
	}
    }
}

int main()
{
    get();
    ll i,j,t,p,q;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
	for(j=0;j<ys[i].size();j++)
	{
	    t=ys[i][j];
	    Add(sum,M-ans[num[t]]);
	    num[t]++;
	    Add(sum,ans[num[t]]);
	}
	ans[i]=(po(i,n)-sum+M)%M;
	Add(xo,ans[i]^i);
    }
    cout<<xo;
}