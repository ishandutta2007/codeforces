#include<bits/stdc++.h>
#define int long long
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
const int xx=6e5+10;
int n,m,uu[xx],vv[xx],lsh[xx];
vector<pair<int,int> >v[xx/2];
int mx[xx<<2],id[xx<<2],tag[xx<<2],tid[xx<<2];
void add(int x,int y,int z){if(tag[x]>y)tag[x]=y,tid[x]=z;if(mx[x]>y)mx[x]=y,id[x]=z;}
void pd(int k){if(tag[k])add(k<<1,tag[k],tid[k]),add(k<<1|1,tag[k],tid[k]),tag[k]=tid[k]=0;}
void update(int k){mx[k]=mx[k<<1],id[k]=id[k<<1];if(mx[k]>mx[k<<1|1])mx[k]=mx[k<<1|1],id[k]=id[k<<1|1];}
void cover(int k,int l,int r,int x,int y,int z,int w)
{
//	cout<<z<<" "<<w<<" \n";
	if(x<=l&&r<=y)return add(k,z,w);
	pd(k);int mid=l+r>>1;
	if(x<=mid)cover(k<<1,l,mid,x,y,z,w);
	if(mid<y)cover(k<<1|1,mid+1,r,x,y,z,w);
	update(k);
}
void u(pair<int,int> &a,pair<int,int> b){if(a.first>b.first)a=b;}
pair<int,int>ask(int k,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)return make_pair(mx[k],id[k]);
	pd(k);int mid=l+r>>1;pair<int,int>ans=make_pair(0,0);
	if(x<=mid)u(ans,ask(k<<1,l,mid,x,y));
	if(mid<y)u(ans,ask(k<<1|1,mid+1,r,x,y));
	return ans;
}
int f[xx],pre[xx],vis[xx];
void print(int x)
{
	if(!x)return ;
	print(pre[x]);
	vis[x]=1;
}
signed main(){
	n=read(),m=read();
	int tt=0;
	for(int i=1;i<=m;i++)id[i]=read(),uu[i]=lsh[++tt]=read(),vv[i]=lsh[++tt]=read();
	sort(lsh+1,lsh+tt+1);
	tt=unique(lsh+1,lsh+tt+1)-lsh-1;
	for(int i=1;i<=m;i++)v[id[i]].push_back(make_pair(lower_bound(lsh+1,lsh+tt+1,uu[i])-lsh,lower_bound(lsh+1,lsh+tt+1,vv[i])-lsh));
	memset(id,0,sizeof(id));
	v[n+1].push_back(make_pair(1,tt));
	for(int i=1;i<=n+1;i++)
	{
		pair<int,int>now=make_pair(0,0);
		for(int j=0;j<v[i].size();j++)u(now,ask(1,1,tt,v[i][j].first,v[i][j].second));
//		cout<<now.first<<" "<<now.second<<'\n';
		f[i]=now.first+i-1;pre[i]=now.second;
		for(int j=0;j<v[i].size();j++)cover(1,1,tt,v[i][j].first,v[i][j].second,f[i]-i,i);
	}
	cout<<f[n+1]<<"\n";
	print(n+1);
	for(int i=1;i<=n;i++)if(!vis[i])cout<<i<<" ";
	puts("");
	return 0;
}