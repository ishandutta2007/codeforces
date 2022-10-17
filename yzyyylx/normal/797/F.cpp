#include<bits/stdc++.h>
#define ll long long
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 5010
using namespace std;

ll n,m,mou[N],dp[N][N];
P hole[N];
struct Dq
{
    ll top,tail;
    P num[N];
    void init(){top=1,tail=0;}
    void push(P u){for(;top<=tail&&u<num[tail];tail--);num[++tail]=u;}
    void pop(ll u){for(;num[top].se<u;top++);}
    ll front(){return num[top].fi;}
}dq;

int main()
{
    memset(dp,0x3f,sizeof(dp));
    ll i,j,sum=0;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
	scanf("%lld",&mou[i]);
    }
    sort(mou+1,mou+n+1);
    for(i=1;i<=m;i++)
    {
	scanf("%lld%lld",&hole[i].fi,&hole[i].se);
	sum+=hole[i].se;
    }
    if(sum<n)
    {
	puts("-1");
	return 0;
    }
    sort(hole+1,hole+m+1);
    dp[0][0]=0;
    for(i=1;i<=m;i++)
    {
	dp[i][0]=0;
	dq.init();
	dq.push(mp(0,0));
	sum=0;
	for(j=1;j<=n;j++)
	{
	    sum+=abs(mou[j]-hole[i].fi);
	    dq.push(mp(dp[i-1][j]-sum,j));
	    dq.pop(j-hole[i].se);
	    dp[i][j]=dq.front()+sum;
	}
    }
    cout<<dp[m][n];
}