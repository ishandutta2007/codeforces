#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=2e5+5;
struct nod
{
	vector<int>v;
	vector<ll>suf;
	bool operator<(const nod&w)const
	{
		return v.size()<w.v.size();
	}
}a[xx];
int u[xx];
int s[xx];
bool cmp(int x,int y)
{
	return x>y;
}
signed main(){
	int T=read();
	while(T--)
	{
		int n=read();
		ll tt=0;
		for(int i=1;i<=n;i++)u[i]=read();
		for(int i=1;i<=n;i++)s[i]=read(),tt+=s[i];
		for(int i=1;i<=n;i++)a[i].v.clear(),a[i].suf.clear();
		for(int i=1;i<=n;i++)a[u[i]].v.push_back(s[i]);
		for(int i=1;i<=n;i++)sort(a[i].v.begin(),a[i].v.end(),cmp);
		for(int i=1;i<=n;i++)
		{
			if(!a[i].v.size())continue;
			a[i].suf.resize(a[i].v.size());
			a[i].suf[a[i].v.size()-1]=a[i].v[a[i].v.size()-1];
			for(int j=a[i].v.size()-2;j>=0;j--)a[i].suf[j]=a[i].suf[j+1]+a[i].v[j];
		}
		sort(a+1,a+n+1);
		int now=1;
//		for(int j=1;j<=n;j++)
//		{
////			cout<<j<<"asdaaa"<<a[j].v.size()<<"\n";
//			for(int i=0;i<a[j].v.size();i++)cout<<a[j].suf[i]<<" ";
//			puts("sadsd");
//		}
		while(!a[now].v.size())now++;
		for(int i=1;i<=n;i++)
		{
			while(a[now].v.size()<i&&now<=n)tt-=a[now].suf[0],now++;
//			cout<<now<<" "<<tt<<"\n";
			ll res=tt;
			for(int j=now;j<=n;j++)
			{
				if(a[j].v.size()%i!=0)res-=a[j].suf[a[j].v.size()/i*i];
			}
			cout<<res<<" \n"[i==n];
		}
	}
	return 0;
}