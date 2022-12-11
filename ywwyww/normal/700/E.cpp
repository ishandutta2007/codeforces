#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
namespace seg
{
	int ls[15000010];
	int rs[15000010];
	int s[15000010];
	int cnt=0;
	int insert(int p,int x,int l,int r)
	{
		int q=++cnt;
		ls[q]=ls[p];
		rs[q]=rs[p];
		s[q]=s[p]+1;
		if(l==r)
			return q;
		int mid=(l+r)>>1;
		if(x<=mid)
			ls[q]=insert(ls[q],x,l,mid);
		else
			rs[q]=insert(rs[q],x,mid+1,r);
		return q;
	}
	int merge(int x,int y)
	{
		if(!x||!y)
			return x+y;
		int p=++cnt;
		ls[p]=merge(ls[x],ls[y]);
		rs[p]=merge(rs[x],rs[y]);
		s[p]=s[ls[p]]+s[rs[p]];
		return p;
	}
	vector<int> dfs(int p,int l,int r)
	{
		vector<int> a,b;
		if(!s[p])
			return a;
		if(l==r)
		{
			a.push_back(l);
			return a;
		}
		int mid=(l+r)>>1;
		b=dfs(ls[p],l,mid);
		a.insert(a.end(),b.begin(),b.end());
		b=dfs(rs[p],mid+1,r);
		a.insert(a.end(),b.begin(),b.end());
		return a;
	}
	int query(int p,int l,int r,int L,int R)
	{
		if(!p)
			return 0;
		if(l<=L&&r>=R)
			return s[p];
		int mid=(L+R)>>1;
		int res=0;
		if(l<=mid)
			res+=query(ls[p],l,r,L,mid);
		if(r>mid)
			res+=query(rs[p],l,r,mid+1,R);
		return res;
	}
}
int n;
namespace sam
{
	int next[400010][27];
	int fail[400010];
	int len[400010];
	int pos[400010];
	int rt[400010];
	int last,n;
	void init()
	{
		last=n=1;
	}
	void insert(int c,int ps)
	{
		int np=++n;
		int p=last;
		len[np]=len[p]+1;
		pos[np]=ps;
		rt[np]=seg::insert(rt[np],ps,1,::n);
		for(;p&&!next[p][c];p=fail[p])
			next[p][c]=np;
		if(!p)
			fail[np]=1;
		else
		{
			int q=next[p][c];
			if(len[q]==len[p]+1)
				fail[np]=q;
			else
			{
				int nq=++n;
				len[nq]=len[p]+1;
				memcpy(next[nq],next[q],sizeof next[q]);
				pos[nq]=pos[q];
				fail[nq]=fail[q];
				fail[q]=fail[np]=nq;
				for(;p&&next[p][c]==q;p=fail[p])
					next[p][c]=nq;
			}
		}
		last=np;
	}
	int b[400010];
	int q[400010];
	void sort()
	{
		memset(b,0,sizeof b);
		for(int i=1;i<=n;i++)
			b[len[i]]++;
		for(int i=1;i<=n;i++)
			b[i]+=b[i-1];
		for(int i=n;i>=1;i--)
			q[b[len[i]]--]=i;
	}
	void gao()
	{
		for(int i=n;i>=1;i--)
		{
			int x=q[i];
			if(fail[x])
				rt[fail[x]]=seg::merge(rt[fail[x]],rt[x]);
		}
	}
	int f[400010];
	int g[400010];
	int solve()
	{
		int ans=1;
		f[0]=0;
		g[0]=0;
		for(int i=2;i<=n;i++)
		{
			int x=q[i];
			if(fail[x]<=1)
			{
				f[x]=1;
				g[x]=x;
				continue;
			}
			f[x]=f[fail[x]];
			g[x]=g[fail[x]];
			if(seg::query(rt[g[x]],pos[x]-len[x]+len[g[x]],pos[x]-1,1,::n))
			{
				f[x]++;
				g[x]=x;
			}
			ans=max(ans,f[x]);
		}
		return ans;
	}
}
char s[200010];
vector<int> debug(int x)
{
	return seg::dfs(sam::rt[x],1,n);
}
int main()
{
    scanf("%d",&n);
	scanf("%s",s+1);
	sam::init();
	for(int i=1;i<=n;i++)
		sam::insert(s[i]-'a'+1,i);
	sam::sort();
	sam::gao();
	int ans=sam::solve();
	printf("%d\n",ans);
	return 0;
}