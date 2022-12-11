#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<cmath>
#include<functional>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
void sort(int &a,int &b)
{
	if(a>b)
		swap(a,b);
}
void open(const char *s)
{
#ifndef ONLINE_JUDGE
	char str[100];
	sprintf(str,"%s.in",s);
	freopen(str,"r",stdin);
	sprintf(str,"%s.out",s);
	freopen(str,"w",stdout);
#endif
}
int rd()
{
	int s=0,c;
	while((c=getchar())<'0'||c>'9');
	do
	{
		s=s*10+c-'0';
	}
	while((c=getchar())>='0'&&c<='9');
	return s;
}
void put(int x)
{
	if(!x)
	{
		putchar('0');
		return;
	}
	static int c[20];
	int t=0;
	while(x)
	{
		c[++t]=x%10;
		x/=10;
	}
	while(t)
		putchar(c[t--]+'0');
}
int upmin(int &a,int b)
{
	if(b<a)
	{
		a=b;
		return 1;
	}
	return 0;
}
int upmax(int &a,int b)
{
	if(b>a)
	{
		a=b;
		return 1;
	}
	return 0;
}
const int N=100010;
const int inf=0x7f7f7f7f;
int n,q;
char s[N];
int c[10];
int pos,dir;
//1:right 0:left 
int left[N],right[N];
int l,r;
void init()
{
	for(int i=1;i<=n;i++)
	{
		left[i]=i-1;
		right[i]=i+1;
	}
	right[0]=1;
	left[n+1]=n;
}
void del(int x)
{
	if(!x)
		return;
	left[right[x]]=left[x];
	right[left[x]]=right[x];
}
int last;
int cnt;
int ans[10*N][10];
int f[N];
int g[N];
int fa[N];
int fa2[N];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int find2(int x)
{
	return fa2[x]==x?x:fa2[x]=find2(fa2[x]);
}
void move()
{
	while(pos>=l&&pos<=r)
	{
		if((s[pos]=='<'||s[pos]=='>')&&(s[last]=='<'||s[last]=='>'))
			del(last);
		if(s[pos]=='<')
			dir=0;
		else if(s[pos]=='>')
			dir=1;
		else
		{
			c[s[pos]-'0']++;
			if(s[pos]>'0')
				s[pos]--;
			else
				del(pos);
		}
		last=pos;
		if(dir)
		{
			pos=right[pos];
			int x=find2(last+1);
			while(x&&x<=pos)
			{
				f[x]=++cnt;
				for(int i=0;i<=9;i++)
					ans[cnt][i]=c[i];
				fa2[x]=x+1;
				x=find2(x);
			}
		}
		else
		{
			int x=find(pos);
			while(x&&x>left[pos])
			{
				g[x]=++cnt;
				for(int i=0;i<=9;i++)
					ans[cnt][i]=c[i];
				fa[x]=x-1;
				x=find(x);
			}
			pos=left[pos];
		}
		if(pos<l||pos>r)
			break;
	}
}
char str[N];
void gao()
{
	memset(f,0x7f,sizeof f);
	memset(g,0x7f,sizeof g);
	for(int i=1;i<=n+1;i++)
		fa[i]=fa2[i]=i;
	s[0]='>';
	init();
	l=0;
	r=n;
	pos=0;
	dir=1;
	last=0;
	move();
	int x,y;
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		int st=f[x];
		int ed=min(f[y+1],g[x]);
		for(int i=0;i<=9;i++)
			printf("%d ",ans[ed][i]-ans[st][i]);
		printf("\n");
	}
}
int main()
{
	open("b");
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	gao();
	return 0;
}