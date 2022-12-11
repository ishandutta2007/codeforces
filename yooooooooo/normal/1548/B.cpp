#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
	ll id,x;
	node(ll nid=0,ll nx=0){id=nid;x=nx;}
};
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
ll a[200005],b[200005];
ll T,n,nw,ans=0;
vector<node>res[2];
void init()
{
	res[0].clear();
	res[1].clear();
	ans=1;
}
void add(int md,node x,int r)
{
	if(x.x>1)ans=max(ans,r+2-x.id);
	if(x.x>1&&(res[md].size()==0||res[md].back().x!=x.x))res[md].push_back(x);
}
int main()
{
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		init();
		ans=1;
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(int i=2;i<=n;i++)b[i-1]=abs(a[i]-a[i-1]);
		nw=0;
		n--;
		if(n==0)
		{
			printf("%lld\n",ans);
			continue;
		}
		res[nw].push_back(node(1,b[1]));
		if(b[1]>1)ans=max(ans,2ll);
		for(int i=2;i<=n;i++)
		{
			nw=!nw;
			res[nw].clear();
			for(int j=0;j<res[!nw].size();j++)
			{
				ll tmp=res[!nw][j].x;
				//printf("%d %lld %lld\n",i,tmp,res[!nw][j].id);
				res[!nw][j].x=gcd(tmp,b[i]);
				add(nw,res[!nw][j],i);
			}
			add(nw,node(i,b[i]),i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}