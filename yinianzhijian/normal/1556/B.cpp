#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=1e5+5;
int a[xx];
vector<int>v[2];
int sum[xx],id[xx],n;
int lb(int x){return x&-x;}
void add(int x,int y){for(;x<=n;x+=lb(x))sum[x]+=y;}
int ask(int x){int ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}
ll get()
{
	memset(sum,0,sizeof(sum[0])*(n+1));
	ll res=0;
	for(int i=1;i<=n;i++)res+=id[i]-ask(id[i])-1,add(id[i],1);
	return res;
}
signed main(){
	int T=read();
	while(T--)
	{
		n=read();
		int t[2]={0,0};
		v[0].clear();
		v[1].clear();
		for(int i=1;i<=n;i++)a[i]=(read()&1),t[a[i]]++,v[a[i]].push_back(i);
		if((n&1))
		{
			if((max(t[1],t[0])-min(t[1],t[0])!=1))
			{
				puts("-1");
				continue;
				
			}
		}
		else 
		{
			if(t[0]!=t[1])
			{
				puts("-1");
				continue;
			}
		}
		if(t[0]==t[1])
		{
			int s1=0,s2=0;
			ll ans=1e18,res=0,cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(i&1)id[++cnt]=v[0][s1++];
				else id[++cnt]=v[1][s2++];
			}
			ans=min(ans,get());
			s1=0,s2=0,cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(i&1)id[++cnt]=v[1][s1++];
				else id[++cnt]=v[0][s2++];
			}
			ans=min(get(),ans);
			cout<<ans<<"\n";
		}
		else 
		{
			if(t[0]>t[1])
			{
				int s1=0,s2=0,ans=1e9,res=0,cnt=0;
				for(int i=1;i<=n;i++)
				{
					if(i&1)id[++cnt]=v[0][s1++];
					else id[++cnt]=v[1][s2++];
				}
				cout<<get()<<'\n';
			}
			else 
			{
				int s1=0,s2=0,res=0,cnt=0;
				for(int i=1;i<=n;i++)
				{
					if(i&1)id[++cnt]=v[1][s1++];
					else id[++cnt]=v[0][s2++];
				}
				cout<<get()<<"\n";
			}
		}
	}
	return 0;
}