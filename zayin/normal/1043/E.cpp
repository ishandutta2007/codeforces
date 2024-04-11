#include<bits/stdc++.h>
#define maxn 300050
using namespace std;
typedef long long LL;

int n,m;
LL x[maxn],y[maxn];

LL sx[maxn],sy[maxn];

vector<int> G[maxn];

int pos[maxn],mp[maxn];

LL ans[maxn];

bool cmp(int i,int j)
{
	return x[i]-y[i]<x[j]-y[j];
}

int main()
{
//	freopen("c.in","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
	{
		pos[i]=i;
		scanf("%lld%lld",&x[i],&y[i]);
	}
	while (m--)
	{
		int i,j;
		scanf("%d%d",&i,&j);
		G[i].push_back(j);
		G[j].push_back(i); 
	}
	
	sort(pos+1,pos+n+1,cmp);
	for (int i=1;i<=n;++i)
		mp[pos[i]]=i;
	for (int i=1;i<=n;++i)
		sx[i]=sx[i-1]+x[pos[i]];
	for (int i=n;i;--i)
		sy[i]=sy[i+1]+y[pos[i]];
	
	/*for (int i=1;i<=n;++i)
		cout<<pos[i]<<" ";
	cout<<endl;*/
	
	for (int i=1;i<=n;++i)
	{
		ans[i]=sx[mp[i]-1]+sy[mp[i]+1]+(mp[i]-1)*y[i]+(n-mp[i])*x[i];
//		cout<<"ans:"<<i<<" "<<ans[i]<<" "<<sx[mp[i]-1]<<" "<<sy[mp[i]+1]<<endl;
		for (auto j:G[i])
			if (mp[j]<mp[i])
				ans[i]-=x[j]+y[i];
			else
				ans[i]-=x[i]+y[j];
	}
	
	for (int i=1;i<=n;++i)
		printf("%lld ",ans[i]);
	return 0;
}