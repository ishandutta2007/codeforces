#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=3e5+5,B=300;
int n,q;
int a[maxn];
vector<int>pos[maxn];
int del[maxn];
void prework(int x)
{
	for(int &i:pos[x])del[i]++;
	for(int i=1;i<=n;i++)del[i]+=del[i-1];
}
int mi[maxn<<1];
int work(int x,int y,int l1,int r1,int l2,int r2)
{
	
	if(l1<0)l1=0;if(l2<0)l2=0;
	if(r1>=pos[x].size())r1=pos[x].size()-1;
	if(r2>=pos[y].size())r2=pos[y].size()-1;
	int ret=-1e9;
	int now=0,nxt=0;
	mi[maxn+0]=0;
	if(l1)mi[maxn+0]=max(mi[maxn+0],pos[x][l1-1]);
	if(l2)mi[maxn+0]=max(mi[maxn+0],pos[y][l2-1]);
	int tomi=0,tomx=0;
	while(l1<=r1&&l2<=r2)
	{
		if(pos[x][l1]<pos[y][l2])
		{
			now++;
			mi[maxn+now]=min(mi[maxn+now],pos[x][l1]);
			l1++;
		}
		else
		{
			now--;
			mi[maxn+now]=min(mi[maxn+now],pos[y][l2]);
			l2++;
		}
		if(l1>r1)nxt=pos[y][l2]-1;
		else if(l2>r2)nxt=pos[x][l1]-1;
		else nxt=min(pos[x][l1],pos[y][l2])-1;
		ret=max(ret,nxt-mi[maxn+now]);
		tomi=min(tomi,now);
		tomx=max(tomx,now);
	}
	
	while(l1<=r1)
	{
		now++;
		mi[maxn+now]=min(mi[maxn+now],pos[x][l1]);
		l1++;
		if(l1>=pos[x].size())nxt=n;
		else nxt=pos[x][l1]-1;		
		ret=max(ret,nxt-mi[maxn+now]);
		tomi=min(tomi,now);
		tomx=max(tomx,now);
	}
	while(l2<=r2)
	{
		now--;
		mi[maxn+now]=min(mi[maxn+now],pos[y][l2]);
		l2++;
		if(l2>=pos[y].size())nxt=n;
		else nxt=pos[y][l2]-1;
		ret=max(ret,nxt-mi[maxn+now]);
		tomi=min(tomi,now);
		tomx=max(tomx,now);
	}
	for(int i=tomi;i<=tomx;i++)mi[maxn+i]=1e9;
	return ret;
}
int calc(int x,int y)
{
	if(pos[y].empty())return 0;
	static bool to[maxn];
	static int pre[maxn],suf[maxn],premi[maxn],sufmi[maxn];
	memset(to,0,sizeof(bool)*pos[y].size());memset(pre,0,sizeof(int)*pos[y].size());memset(suf,0,sizeof(int)*pos[y].size());
	pre[0]=1;for(int i=1;i<pos[y].size();i++)pre[i]=pre[i-1]+1-(del[pos[y][i]]-del[pos[y][i-1]]);
	suf[pos[y].size()-1]=1;for(int i=(int)pos[y].size()-2;i>=0;i--)suf[i]=suf[i+1]+1-(del[pos[y][i+1]]-del[pos[y][i]]);
	premi[0]=0;for(int i=1;i<pos[y].size();i++)premi[i]=min(pre[i]-1,premi[i-1]);
	sufmi[pos[y].size()-1]=0;for(int i=(int)pos[y].size()-2;i>=0;i--)sufmi[i]=min(suf[i]-1,sufmi[i+1]);
	for(int i=0;i+1<pos[y].size();i++)if(pre[i]-premi[i]+suf[i+1]-sufmi[i+1]>=del[pos[y][i+1]]-del[pos[y][i]])to[i]=true;
	int l=0;
	int ret=-1e9;
	for(int i=0;i<pos[y].size();i++)if(!to[i])ret=max(ret,work(x,y,del[pos[y][l]]-(suf[l]-sufmi[l]),del[pos[y][i]]+(pre[i]-premi[i]),l,i)),l=i+1;
	return ret;
}
int main()
{
	n=read();generate_n(a+1,n,read);
	for(int i=1;i<=n;i++)pos[a[i]].push_back(i);
	int mxv=0,mxp=0;
	for(int i=1;i<=n;i++)
	{
		if(pos[i].size()==mxv)mxp=-1;
		else if(pos[i].size()>mxv){mxv=pos[i].size();mxp=i;}
	}
	if(mxp==-1){printf("%d\n",n);return 0;}
	memset(mi,0x3f,sizeof mi);
	prework(mxp);
	int ans=0;
	for(int i=1;i<=n;i++)
		if(i!=mxp)
		{
			ans=max(ans,calc(mxp,i));
		}
	printf("%d\n",ans);
	return 0;
}