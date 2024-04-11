#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=1e5+5;
int a[xx],id[xx],lsh[xx],sum[xx],n;
int lb(int x){return x&-x;}
void add(int x,int y){for(;x<=n;x+=lb(x))sum[x]+=y;}
int ask(int x){int ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}
map<int,set<int> >mp;
signed main(){
	int T=read();
	while(T--)
	{
		n=read();
		n=read();
		memset(sum,0,sizeof(sum[0])*(n+1));
		mp.clear();
		for(int i=1;i<=n;i++)a[i]=lsh[i]=read();
		sort(lsh+1,lsh+n+1);
		for(int i=1;i<=n;i++)mp[lsh[i]].insert(i);
		for(int i=1;i<=n;i++)
		{
			id[i]=*--mp[a[i]].end();
			mp[a[i]].erase(--mp[a[i]].end());
		}
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=ask(id[i]);
			add(id[i],1);
		}
		cout<<ans<<"\n";
	}
	return 0;
}