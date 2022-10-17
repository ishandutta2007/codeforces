#include<bits/stdc++.h>
#define ll long long
#define N 100100
using namespace std;

ll n,k,a,b,num[N];

ll dfs(ll l,ll r,ll u,ll v)
{
    if(u>v) return a;
    ll i,j,mid=((l+r)>>1),res=b*(v-u+1)*(r-l+1);
    for(i=u;i<=v;i++) if(num[i]>mid) break;
    if(l<r) res=min(res,dfs(l,mid,u,i-1)+dfs(mid+1,r,i,v));
    return res;
}

int main()
{
    ll i,j;
    cin>>n>>k>>a>>b;
    for(i=1;i<=k;i++)
    {
	scanf("%lld",&num[i]);
    }
    sort(num+1,num+k+1);
    cout<<dfs(1,(1 << n),1,k);
}