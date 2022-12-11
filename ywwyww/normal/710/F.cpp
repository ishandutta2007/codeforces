#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
struct trie
{
	int v[300010];
	int s[300010];
	int a[300010][30];
	int fail[300010];
	int rt[300010];
	int q[300010];
	int sz[300010];
	int n;
	int cnt;
	trie()
	{
		memset(v,0,sizeof v);
		memset(a,0,sizeof a);
		n=0;
	}
	void build()
	{
		cnt++;
		rt[cnt]=++n;
	}
	void merge(int x,int y)
	{
		v[x]+=v[y];
		int i;
		for(i=1;i<=26;i++)
			if(a[y][i])
			{
				if(a[x][i])
					merge(a[x][i],a[y][i]);
				else
					a[x][i]=a[y][i];
			}
	}
	void insert(int x,char *s)
	{
		int len=strlen(s+1);
		int i;
		for(i=1;i<=len;i++)
		{
			int c=s[i]-'a'+1;
			if(!a[x][c])
				a[x][c]=++n;
			x=a[x][c];
		}
		v[x]++;
	}
	void build(int rt)
	{
		int h,t,i,x;
		h=0;
		t=1;
		fail[rt]=0;
		q[++h]=rt;
		while(h>=t)
		{
			x=q[t++];
			for(i=1;i<=26;i++)
				if(a[x][i])
				{
					int fa=fail[x];
					while(fa&&!a[fa][i])
						fa=fail[fa];
					if(fa)
						fail[a[x][i]]=a[fa][i];
					else
						fail[a[x][i]]=rt;
					q[++h]=a[x][i];
				}
		}
		for(i=1;i<=h;i++)
		{
			s[q[i]]=v[q[i]];
			if(fail[q[i]])
				s[q[i]]+=s[fail[q[i]]];
		}
	}
	ll count(int rt,char *str)
	{
		int x=rt;
		ll ans=0;
		int i;
		int n=strlen(str+1);
		for(i=1;i<=n;i++)
		{
			int c=str[i]-'a'+1;
			while(x&&!a[x][c])
				x=fail[x];
			if(x)
				x=a[x][c];
			else
				x=rt;
			ans+=s[x];
		}
		return ans;
	}
};
trie a,b;
char s[300010];
int main()
{
//	freopen("cf710f.in","r",stdin);
//	freopen("cf710f.out","w",stdout);
	int n;
	scanf("%d",&n);
	int i,x;
	for(i=1;i<=n;i++)
	{
		scanf("%d%s",&x,s+1);
		if(x==1)
		{
			a.build();
			a.insert(a.rt[a.cnt],s);
			a.sz[a.cnt]=1;
			while(a.cnt>=2&&a.sz[a.cnt]==a.sz[a.cnt-1])
			{
				a.merge(a.rt[a.cnt-1],a.rt[a.cnt]);
				a.cnt--;
				a.sz[a.cnt]*=2;
			}
			a.build(a.rt[a.cnt]);
		}
		else if(x==2)
		{
			b.build();
			b.insert(b.rt[b.cnt],s);
			b.sz[b.cnt]=1;
			while(b.cnt>=2&&b.sz[b.cnt]==b.sz[b.cnt-1])
			{
				b.merge(b.rt[b.cnt-1],b.rt[b.cnt]);
				b.cnt--;
				b.sz[b.cnt]*=2;
			}
			b.build(b.rt[b.cnt]);
		}
		else
		{
			ll ans=0;
			int j;
			for(j=1;j<=a.cnt;j++)
				ans+=a.count(a.rt[j],s);
			for(j=1;j<=b.cnt;j++)
				ans-=b.count(b.rt[j],s);
			printf("%I64d\n",ans);
			fflush(stdout);
		}
	}
	return 0;
}