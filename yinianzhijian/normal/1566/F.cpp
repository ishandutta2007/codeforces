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
char st;
const int xx=2e5+5;
ll n,m;
ll a[xx];
struct node{ll l,r;bool operator<(const node&w)const{return l<w.l;};}e[xx],w[xx];
ll vis[xx];
struct no
{
	ll x,y;
	bool operator<(const no&w)const{return x<w.x;}
};
ll f[xx][2];//02 1112 
multiset<no>s;
ll mn[xx<<2];
void build(ll k,ll l,ll r)
{
	if(l==r)return mn[k]=e[l].r,void();
	ll mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	mn[k]=min(mn[k<<1],mn[k<<1|1]);
}
ll ask(ll k,ll l,ll r,ll x,ll y)
{
	if(x<=l&&r<=y)return mn[k];
	ll mid=l+r>>1,ans=2e9+1000;
	if(x<=mid)ans=min(ans,ask(k<<1,l,mid,x,y));
	if(mid<y)ans=min(ans,ask(k<<1|1,mid+1,r,x,y));
	return ans;
}
char ed;
signed main(){
//	cout<<abs(&st-&ed)/1024/1024<<"\n";
	int T=read();
	while(T--)
	{
		n=read(),m=read();
		for(int i=1;i<=n;i++)a[i]=read();
		a[++n]=-5e9-1000,a[++n]=5e9+1000;
		memset(vis,0,sizeof(vis[0])*(m+1));
		sort(a+1,a+n+1);
		s.clear();
		for(int i=1;i<=m;i++)w[i].l=read(),w[i].r=read();
		sort(w+1,w+m+1);
		ll tt=1;
		for(int i=1;i<=n;i++)
		{
			while(tt<=m&&w[tt].l<=a[i])s.insert((no){w[tt].r,tt}),tt++;
			while(s.size()&&((--s.end())->x)>=a[i])vis[((--s.end())->y)]=1,s.erase(--s.end());
		}
//		return 0;
		ll oo=0;
		for(int i=1;i<=m;i++)if(!vis[i])e[++oo]=w[i];
//		,cout<<w[i].l<<" ss "<<w[i].r<<"\n";
//		return 0;
		m=oo;
		for(int i=1;i<=n;i++)f[i][0]=f[i][1]=1e18;
		f[1][0]=f[1][1]=0;
		if(!m)
		{
			puts("0");
			continue;
		}
		build(1,1,m);
		tt=1;
		for(int i=1;i<n;i++)
		{
//			cout<<i<<" "<<f[i][0]<<" "<<f[i][1]<<"\n";
			ll l=tt,r=tt-1;
			while(r!=m&&e[r+1].l<=a[i+1])r++;
			if(l>r)// 
			{
				f[i+1][0]=min(f[i][0],f[i][1]);
				f[i+1][1]=min(f[i][0],f[i][1]);
				continue;
			}
			ll p=ask(1,1,m,l,r);
			f[i+1][0]=(a[i+1]-p)*2+min(f[i][0],f[i][1]);
			f[i+1][1]=(a[i+1]-p)+min(f[i][0],f[i][1]);
//			cout<<i<<" "<<f[i][0]<<" "<<f[i][1]<<" "<<f[i+1][0]<<" "<<f[i+1][1]<<" "<<p<<" "<<l<<" "<<r<<" "<<a[i+1]<<"\n";
			for(int j=l;j<=r;j++)
			{
				
				ll p;
				if(j!=r)p=ask(1,1,m,j+1,r);
				else p=a[i+1];
				f[i+1][0]=min(f[i+1][0],(a[i+1]-p)*2+min(f[i][0]+e[j].l-a[i],f[i][1]+(e[j].l-a[i])*2));
				f[i+1][1]=min(f[i+1][1],(a[i+1]-p)+min(f[i][0]+e[j].l-a[i],f[i][1]+(e[j].l-a[i])*2));
			}
//			cout<<i<<" "<<f[i][0]<<" "<<f[i][1]<<" "<<l<<" "<<r<<"\n";
			tt=r+1;
		}
		cout<<min(f[n][0],f[n][1])<<"\n";
	}
	return 0;
}
/*
1
4 6
2 4 6 8
3 5
4 5
7 13
8 12
10 13
16 16
*/