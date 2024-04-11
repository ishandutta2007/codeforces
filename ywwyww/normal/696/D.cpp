#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
struct trie
{
	int a[30];
	int t[30];
	int f;
	int s;
	trie()
	{
		memset(a,0,sizeof a);
		memset(t,0,sizeof t);
		f=0;
		s=0;
	}
};
trie a[210];
int cnt;
int rt;
void insert(int &p,char *s,int v)
{
	if(!p)
		p=++cnt;
	if(s[0]=='\0')
		a[p].s+=v;
	else
		insert(a[p].a[s[0]-'a'+1],s+1,v);
}
int c[210];
char s[1010];
int q[1010];
int head,tail;
struct mat
{
	ll a[210][210];
	mat()
	{
		memset(a,0xf0,sizeof a);
	}
	ll* operator [](int x)
	{
		return a[x];
	}
};
mat operator +(mat a,mat b)
{
	mat c;
	int i,j,k;
	for(i=1;i<=cnt;i++)
		for(j=1;j<=cnt;j++)
			for(k=1;k<=cnt;k++)
				c[i][k]=max(c[i][k],a[i][j]+b[j][k]);
	return c;
}
mat d;
mat pow(mat a,ll b)
{
	mat s;
	int i;
	for(i=1;i<=cnt;i++)
		s[i][i]=0;
	while(b)
	{
		if(b&1)
			s=s+a;
		a=a+a;
		b>>=1;
	}
	return s;
}
int main()
{
	cnt=0;
	rt=0;
	int n;
	ll m;
	scanf("%d%I64d",&n,&m);
	int i,j;
	for(i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		insert(rt,s+1,c[i]);
	}
	head=0;
	tail=1;
	q[++head]=rt;
	while(head>=tail)
	{
		int x=q[tail++];
		for(i=1;i<=26;i++)
			if(a[x].a[i])
			{
				int fa=a[x].f;
				while(fa&&!a[fa].a[i])
					fa=a[fa].f;
				if(fa)
					a[a[x].a[i]].f=a[fa].a[i];
				else
					a[a[x].a[i]].f=rt;
				q[++head]=a[x].a[i];
			}
		a[x].s+=a[a[x].f].s;
		for(i=1;i<=26;i++)
			if(a[x].a[i])
				a[x].t[i]=a[x].a[i];
			else if(a[x].f)
				a[x].t[i]=a[a[x].f].t[i];
			else
				a[x].t[i]=rt;
	}
	for(i=1;i<=cnt;i++)
		for(j=1;j<=26;j++)
			d[i][a[i].t[j]]=a[a[i].t[j]].s;
	d=pow(d,m);
	ll ans=0;
	for(i=1;i<=cnt;i++)
		ans=max(ans,d[1][i]);
	printf("%I64d\n",ans);
	return 0;
}