#pragma GCC optimize(3,"inline","Ofast")
#include<bits/stdc++.h>
#define pii pair<int,int>
#define fr first 
#define sc second 
#define ll long long
using namespace std;
const int N=100010;
int num=-1,hd[5*N],nxt[5*N],to[5*N],c[5*N],seg[8*N];
int root,minx,sz[N],tot,len,w,cnt,R,tp[N];ll ans=0;
bool vis[N];pii tax[N];vector<int>trash;bool flag=0;
void add(int u,int v,int cost)
{
	nxt[++num]=hd[u],to[num]=v,c[num]=cost,hd[u]=num;
	nxt[++num]=hd[v],to[num]=u,c[num]=cost,hd[v]=num;
}
void get_sz(int x,int fa)
{
	int nw=0;sz[x]=1;
	for(int i=hd[x];i!=-1;i=nxt[i])
	{
		if(!vis[to[i]]&&to[i]!=fa)
		{
			get_sz(to[i],x);
			sz[x]+=sz[to[i]];
			nw=max(nw,sz[to[i]]);
		}
	}
	nw=max(nw,tot-sz[x]);
	if(nw<minx)minx=nw,root=x;
}
void find(int x)
{minx=1e9;get_sz(x,-1);}
void dfs(int pos,int fa,int dis1,int dis2)
{
	//if(flag)cout<<pos<<" "<<fa<<" "<<dis1<<" "<<dis2<<endl;
	if(dis1<=len&&dis2<=w){tax[++cnt].fr=dis1,tax[cnt].sc=dis2;}
	for(int i=hd[pos];i!=-1;i=nxt[i])
		if(!vis[to[i]]&&to[i]!=fa)dfs(to[i],pos,dis1+1,dis2+c[i]);
}
int push_up(int k)
{seg[k]=seg[k<<1]+seg[k<<1|1];if(seg[k])trash.push_back(k);}
int ask(int tl,int tr,int l,int r,int k)
{
	if(l>tr||r<tl)return 0;
	if(tl<=l&&r<=tr)return seg[k];
	int mid=(l+r)>>1;
	return ask(tl,tr,l,mid,k<<1)+ask(tl,tr,mid+1,r,k<<1|1);
}
void cg(int to,int l,int r,int k)
{
	if(l>to||r<to)return;
	if(l==r)
	{
		seg[k]++;
		trash.push_back(k);
		return;
	}
	int mid=(l+r)>>1;
	if(to<=mid)cg(to,l,mid,k<<1);
	if(to>mid)cg(to,mid+1,r,k<<1|1);
	push_up(k);
}
void del(int pos)
{
	int x;
	x=lower_bound(tp+1,tp+R+1,tax[pos].sc)-tp;
	if(x<=0)x=1;cg(x,1,R,1);//cout<<pos<<" "<<x<<endl,system("pause");
}
ll cal(int pos)
{
	ll x,res;
	x=upper_bound(tp+1,tp+R+1,w-tax[pos].sc)-tp;
	if(x>R)x=R;
	while(tp[x]+tax[pos].sc>w)x--;res=x-ask(1,x,1,R,1);
	if(tax[pos].sc*2<=w)res--;//cout<<pos<<" "<<x<<" "<<res<<endl,system("pause");
	return res;
}
ll work(int x,int dis1,int dis2)
{	
	//if(x==5&&dis1==1&&dis2==7)flag=1;else flag=0;
	for(int i=0;i<trash.size();i++)seg[trash[i]]=0;trash.clear();
	ll res=0,ha=0;cnt=0;int l,r,pos;
	tax[++cnt].fr=dis1,tax[cnt].sc=dis2;
	for(int i=hd[x];i!=-1;i=nxt[i])
		if(!vis[to[i]])dfs(to[i],x,1+dis1,c[i]+dis2);
	sort(tax+1,tax+cnt+1);//if(flag)for(int i=1;i<=cnt;i++)cout<<tax[i].fr<<" "<<tax[i].sc<<endl,system("pause");
	l=r=1;
	while(tax[r+1].fr+tax[l].fr<=len&&r<cnt)r++;
	for(int i=1;i<=r;i++)tp[i]=tax[i].second;
	R=r,sort(tp+1,tp+R+1);//cout<<R<<endl;
	if(l<r)res+=cal(1),del(l++);
	for(;l<r;)
	{//if(flag)cout<<res<<endl;
		while(tax[r].fr+tax[l].fr>len)del(r--);
		if(l<r)res+=cal(l),del(l++);
	}//cout<<x<<" "<<dis1<<" "<<dis2<<" "<<res<<endl,system("pause");
	return res;
}
void solve(int x)
{
	vis[x]=1;
	ans+=work(x,0,0);
	for(int i=hd[x];i!=-1;i=nxt[i])
		if(!vis[to[i]])ans-=work(to[i],1,c[i]);		
	//cout<<x<<" "<<ans<<endl;system("pause");
	for(int i=hd[x];i!=-1;i=nxt[i])
	{
		if(!vis[to[i]])
		{
			tot=sz[to[i]];
			find(to[i]);
			solve(root);
		}
	}
}
int main()
{
	int n;
	memset(hd,-1,sizeof hd);
	memset(nxt,-1,sizeof nxt);
	scanf("%d%d%d",&n,&len,&w);
	int v,cc;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&v,&cc);
		add(i+1,v,cc);
	}
	tot=n;find(1);
	solve(root);
	printf("%lld",ans);
}
/*
20 20 176
1 10
1 0
1 3
4 7
1 4
5 9
5 8
2 9
4 9
2 5
5 4
9 9
10 8
7 5
9 1
7 5
8 9
13 5
5 0
*/