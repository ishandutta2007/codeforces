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
int n,m;
const int xx=2e6+5;
struct node
{
	int l,r,v;
	bool operator<(const node&w)const{return v<w.v;}
}e[xx];
int vis[xx];
int mn[xx<<2],ad[xx<<2];
void add(int k,int v){mn[k]+=v,ad[k]+=v;}
void pd(int k){if(!ad[k])return;add(k<<1,ad[k]),add(k<<1|1,ad[k]);ad[k]=0;}
void update(int k){mn[k]=min(mn[k<<1],mn[k<<1|1]);}
void change(int k,int l,int r,int x,int y,int z)
{
	if(x<=l&&r<=y)return add(k,z);
	pd(k);int mid=l+r>>1;
	if(x<=mid)change(k<<1,l,mid,x,y,z);
	if(mid<y)change(k<<1|1,mid+1,r,x,y,z);
	update(k);
}
int ask(int k,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)return mn[k];
	pd(k);int mid=l+r>>1,ans=1e9;
	if(x<=mid)ans=min(ans,ask(k<<1,l,mid,x,y));
	if(mid<y)ans=min(ans,ask(k<<1|1,mid+1,r,x,y));
	return ans;
}
bool check(int x)
{
	change(1,2,m*2,e[x].l*2,e[x].r*2,-1);
	if(!ask(1,2,m*2,2,m*2))
	{
		change(1,2,m*2,e[x].l*2,e[x].r*2,1);
		return 0;
	}
	return 1;
}
signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)e[i].l=read(),e[i].r=read(),e[i].v=read();
	sort(e+1,e+n+1);
	int tt=1;
	int ans=1e9;
	for(int i=1;i<=n;i++)
	{
		change(1,2,m*2,e[i].l*2,e[i].r*2,1);
		vis[i]=1;
		if(!ask(1,2,m*2,2,m*2))continue;
		while(1)
		{
			while(!vis[tt])tt++;
			if(check(tt))vis[tt]=0;
			else break;
		}
		while(!vis[tt])tt++;
		ans=min(ans,e[i].v-e[tt].v);
	}
	cout<<ans<<'\n';
	return 0;
}