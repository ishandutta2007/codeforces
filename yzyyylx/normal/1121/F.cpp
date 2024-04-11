#include<bits/stdc++.h>
#define ll long long
#define db double
#define N 5010
using namespace std;

ll n,m,a,b,last,tt,dp[N];
char str[N];
struct Node
{
    ll to[26],pa,len;
}node[N<<1];

inline void add(ll u)
{
    ll p=last,np=++tt;
    node[np].len=node[p].len+1;
    for(;p&&!node[p].to[u];p=node[p].pa) node[p].to[u]=np;
    last=np;
    if(!p)
    {
	node[np].pa=1;
	return;
    }
    ll q=node[p].to[u];
    if(node[q].len==node[p].len+1)
    {
	node[np].pa=q;
	return;
    }
    ll nq=++tt;
    node[nq].len=node[p].len+1;
    node[nq].pa=node[q].pa;
    memcpy(node[nq].to,node[q].to,sizeof(node[q].to));
    node[q].pa=node[np].pa=nq;
    for(;node[p].to[u]==q;p=node[p].pa) node[p].to[u]=nq;
}

inline void Min(ll &u,ll v){if(v<u) u=v;}
int main()
{
    memset(dp,0x3f,sizeof(dp));
    ll i,j,now;
    cin>>n>>a>>b;
    scanf("%s",str+1);
    last=tt=1;
    dp[0]=0;
    for(i=0;i<n;i++)
    {
	Min(dp[i+1],dp[i]+a);
	for(now=1,j=i+1;j<=n&&node[now].to[str[j]-'a'];now=node[now].to[str[j]-'a'],j++);
//	cerr<<i<<" "<<j-1<<endl;
	Min(dp[j-1],dp[i]+b);
	add(str[i+1]-'a');
	/*
	for(j=1;j<=tt;j++)
	{
	    cout<<j<<":";
	    for(int k=0;k<5;k++) cout<<node[j].to[k]<<" ";
	    cout<<" pa:"<<node[j].pa;
	    puts("");
	}
	puts("");
	//*/
    }
    cout<<dp[n];
}