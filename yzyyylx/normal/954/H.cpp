#include<bits/stdc++.h>
#define ll long long
#define N 5010
#define M 1000000007
using namespace std;

ll n,er,num[N],down[2][N],up[2][N],cnt[N],fs[N];
bool now,cur;

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

int main()
{
    ll i,j;
    cin>>n;
    cnt[1]=1,er=(M+1)/2;
    for(i=1;i<n;i++)
    {
	scanf("%lld",&num[i]);
	cnt[i+1]=cnt[i]*num[i]%M;
	fs[i]=(num[i]-1)*po(num[i],M-2)%M;
    }
    for(i=1;i<=n;i++) down[now][i]=up[now][i]=1;
    cur=1;
    for(i=1;i<=n*2-2;i++)
    {
	swap(now,cur);
	memset(down[now],0,sizeof(down[now]));
	memset(up[now],0,sizeof(up[now]));
	for(j=n-i;j>=1;j--) down[now][j]=down[cur][j+1]*num[j]%M;
	for(j=2;j<=n;j++)
	{
	    Add(up[now][j],up[cur][j-1]);
	    if(i>1) Add(up[now][j],down[cur][j-1]*fs[j-1]%M);
	}
	ll ans=0;
	for(j=1;j<=n;j++) Add(ans,(up[now][j]+down[now][j])*cnt[j]%M);
//	for(j=1;j<=n;j++) cout<<up[now][j]<<" ";puts("");
//	for(j=1;j<=n;j++) cout<<down[now][j]<<" ";puts("");
	printf("%lld ",ans*er%M);
    }
}