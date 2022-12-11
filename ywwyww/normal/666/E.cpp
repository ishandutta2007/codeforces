#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
const int maxn=1100000;
const int maxsz=30000000;
struct sam
{
	int next[maxn][30];
	int fail[maxn];
	int len[maxn];
	int b[maxn];
	int q[maxn];
	int n;
	sam()
	{
		n=1;
		memset(next,0,sizeof next);
		memset(fail,0,sizeof fail);
		memset(len,0,sizeof len);
	}
	int insert(int p,int x)
	{
		if(next[p][x])
		{
			int np=next[p][x];
			if(len[np]==len[p]+1)
				return np;
			int nq=++n;
			len[nq]=len[p]+1;
			memcpy(next[nq],next[np],sizeof next[np]);
			fail[nq]=fail[np];
			fail[np]=nq;
			for(;p&&next[p][x]==np;p=fail[p])
				next[p][x]=nq;
			return nq;
		}
		int np=++n;
		len[np]=len[p]+1;
		for(;p&&!next[p][x];p=fail[p])
			next[p][x]=np;
		if(!p)
			fail[np]=1;
		else
		{
			int q=next[p][x];
			if(len[q]==len[p]+1)
				fail[np]=q;
			else
			{
				int nq=++n;
				len[nq]=len[p]+1;
				memcpy(next[nq],next[q],sizeof next[q]);
				fail[nq]=fail[q];
				fail[q]=fail[np]=nq;
				for(;p&&next[p][x]==q;p=fail[p])
					next[p][x]=nq;
			}
		}
		return np;
	}
	void sort()
	{
		memset(b,0,sizeof b);
		int i;
		for(i=1;i<=n;i++)
			b[len[i]]++;
		for(i=1;i<=n;i++)
			b[i]+=b[i-1];
		for(i=n;i>=1;i--)
			q[b[len[i]]--]=i;
	}
};
sam a;
struct p
{
	int x;
	int y;
	p()
	{
		x=y=0;
	}
};
p operator +(p a,p b)
{
	a.x+=b.x;
	return a;
}
p operator *(p a,p b)
{
	if(a.x!=b.x)
		return (a.x>b.x?a:b);
	return (a.y<b.y?a:b);
}
struct tree
{
	p s;
	int ls,rs;
	tree()
	{
		ls=rs=0;
	}
};
tree tr[maxn];
int cnt;
void insert(int &p,int x,int v,int l,int r)
{
	if(!p)
		p=++cnt;
	if(l==r)
	{
		tr[p].s.x+=v;
		tr[p].s.y=x;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)
		insert(tr[p].ls,x,v,l,mid);
	else
		insert(tr[p].rs,x,v,mid+1,r);
	tr[p].s=tr[tr[p].ls].s*tr[tr[p].rs].s;
}
int merge(int x,int y,int l,int r)
{
	if(!x||!y)
		return x+y;
	int p=++cnt;
	if(l==r)
	{
		tr[p].s=tr[x].s+tr[y].s;
		return p;
	}
	int mid=(l+r)>>1;
	tr[p].ls=merge(tr[x].ls,tr[y].ls,l,mid);
	tr[p].rs=merge(tr[x].rs,tr[y].rs,mid+1,r);
	tr[p].s=tr[tr[p].ls].s*tr[tr[p].rs].s;
	return p;
}
p query(int now,int l,int r,int L,int R)
{
	if(l<=L&&r>=R)
		return tr[now].s;
	p ans;
	int mid=(L+R)>>1;
	if(l<=mid)
		ans=ans*query(tr[now].ls,l,r,L,mid);
	if(r>mid)
		ans=ans*query(tr[now].rs,l,r,mid+1,R);
	return ans;
}
int f[21][maxn];
int pos[maxn];
int get(int x,int y)
{
	int len=y-x+1;
	y=pos[y];
	int i;
	for(i=20;i>=0;i--)
		if(a.len[f[i][y]]>=len)
			y=f[i][y];
	return y;
}
int root[maxn];
char s[maxn];
int main()
{
	memset(root,0,sizeof root);
	memset(f,0,sizeof f);
//	freopen("cf666e.in","r",stdin);
//	freopen("cf666e.out","w",stdout);
	scanf("%s",s+1);
	int last=1;
	int n=strlen(s+1);
	int i,j;
	for(i=1;i<=n;i++)
	{
		last=a.insert(last,s[i]-'a'+1);
		pos[i]=last;
	}
	int m,q;
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		last=1;
		for(j=1;j<=n;j++)
		{
			last=a.insert(last,s[j]-'a'+1);
			insert(root[last],i,1,1,m);
		}
	}
	a.sort();
	for(i=a.n;i>=1;i--)
	{
		int x=a.q[i];
		if(a.fail[x])
			root[a.fail[x]]=merge(root[a.fail[x]],root[x],1,m);
	}
	for(i=1;i<=a.n;i++)
		f[0][i]=a.fail[i];
	for(i=1;i<=20;i++)
		for(j=1;j<=a.n;j++)
			f[i][j]=f[i-1][f[i-1][j]];
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		int l,r,pl,pr;
		scanf("%d%d%d%d",&l,&r,&pl,&pr);
		int x=get(pl,pr);
		p ans=query(root[x],l,r,1,m);
		if(ans.x)
			printf("%d %d\n",ans.y,ans.x);
		else
			printf("%d 0\n",l);
	}
	return 0;
}