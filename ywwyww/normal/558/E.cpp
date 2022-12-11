#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
char s[100010];
char ss[100010];
struct tree
{
	int ls[200010];
	int rs[200010];
	int l[200010];
	int r[200010];
	int t[30][200010];
	int s[30][200010];
	int n;
	int rt;
	int sl,sr;
	int k;
	tree()
	{
		memset(ls,0,sizeof ls);
		memset(rs,0,sizeof rs);
		memset(t,-1,sizeof t);
		memset(s,0,sizeof s);
		n=0;
		rt=0;
	}
	void build(int &p,int L,int R)
	{
		p=++n;
		l[p]=L;
		r[p]=R;
		if(L==R)
			return;
		int mid=(L+R)>>1;
		build(ls[p],L,mid);
		build(rs[p],mid+1,R);
	}
	void build(int n)
	{
		build(rt,1,n);
	}
	void add(int p,int v)
	{
		t[k][p]=v;
		s[k][p]=v*(r[p]-l[p]+1);
	}
	void push(int p)
	{
		if(~t[k][p])
		{
			add(ls[p],t[k][p]);
			add(rs[p],t[k][p]);
			t[k][p]=-1;
		}
	}
	void fill(int p)
	{
		if(sl<=l[p]&&sr>=r[p])
		{
			add(p,1);
			return;
		}
		push(p);
		int mid=(l[p]+r[p])>>1;
		if(sl<=mid)
			fill(ls[p]);
		if(sr>mid)
			fill(rs[p]);
		s[k][p]=s[k][ls[p]]+s[k][rs[p]];
	}
	void fill(int o,int l,int r)
	{
		if(l>r)
			return;
		k=o;
		sl=l;
		sr=r;
		fill(rt);
	}
	int query(int p)
	{
		if(sl<=l[p]&&sr>=r[p])
		{
			int v=s[k][p];
			add(p,0);
			return v;
		}
		push(p);
		int ans=0;
		int mid=(l[p]+r[p])>>1;
		if(sl<=mid)
			ans+=query(ls[p]);
		if(sr>mid)
			ans+=query(rs[p]);
		s[k][p]=s[k][ls[p]]+s[k][rs[p]];
		return ans;
	}
	int query(int o,int l,int r)
	{
		k=o;
		sl=l;
		sr=r;
		return query(rt);
	}
	void dfs(int p)
	{
		if(l[p]==r[p])
		{
			int i;
			for(i=1;i<=26;i++)
				if(s[i][p])
				{
					ss[l[p]]=i+'a'-1;
					break;
				}
			return;
		}
		int i;
		for(i=1;i<=26;i++)
		{
			k=i;
			push(p);
		}
		dfs(ls[p]);
		dfs(rs[p]);
	}
};
void read(int &s)
{
	char c;
	while((c=getchar())<'0'||c>'9');
	s=c-48;
	while((c=getchar())>='0'&&c<='9')
		s=s*10+c-48;
}
tree a;
int b[30];
int main()
{
//	freopen("cf558e.in","r",stdin);
//	freopen("cf558e.out","w",stdout);
	int n,m;
	read(n);
	read(m);
	int i,j;
	a.build(n);
	scanf("%s",s+1);
	for(i=1;i<=n;i++)
		a.fill(s[i]-'a'+1,i,i);
	for(i=1;i<=m;i++)
	{
		int l,r,v;
		read(l);
		read(r);
		read(v);
		for(j=1;j<=26;j++)
			b[j]=a.query(j,l,r);
		if(v==1)
		{
			int k=l;
			for(j=1;j<=26;j++)
				if(b[j])
				{
					a.fill(j,k,k+b[j]-1);
					k+=b[j];
				}
		}
		else
		{
			int k=l;
			for(j=26;j>=1;j--)
				if(b[j])
				{
					a.fill(j,k,k+b[j]-1);
					k+=b[j];
				}
		}
	}
	a.dfs(a.rt);
	printf("%s\n",ss+1);
	return 0;
}