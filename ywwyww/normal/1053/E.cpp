#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
#include<vector>
//using namespace std;
using std::min;
using std::max;
using std::swap;
using std::sort;
using std::reverse;
using std::random_shuffle;
using std::lower_bound;
using std::upper_bound;
using std::unique;
using std::vector;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
void open(const char *s){
#ifndef ONLINE_JUDGE
	char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
void open2(const char *s){
#ifdef DEBUG
	char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
int rd(){int s=0,c,b=0;while(((c=getchar())<'0'||c>'9')&&c!='-');if(c=='-'){c=getchar();b=1;}do{s=s*10+c-'0';}while((c=getchar())>='0'&&c<='9');return b?-s:s;}
void put(int x){if(!x){putchar('0');return;}static int c[20];int t=0;while(x){c[++t]=x%10;x/=10;}while(t)putchar(c[t--]+'0');}
int upmin(int &a,int b){if(b<a){a=b;return 1;}return 0;}
int upmax(int &a,int b){if(b>a){a=b;return 1;}return 0;}
const int N=500010;
int a[2*N];
int aa[2*N];
void orzzjt()
{
	printf("no\n");
	exit(0);
}
int c[N],d[N],st[N],top,e[N],first[N],last[N];
int n;
vector<int> g[N];
int t=0;
vector<int> *ss;
void solve2(int l,int r)
{
	if(l==r)
		return;
	auto &sss=*ss;
	if(r==l+2)
	{
		if(!a[sss[l+1]])
			a[sss[l+1]]=--t;
		return;
	}
	if(a[sss[l+1]]&&a[sss[r-1]]&&a[sss[l+1]]!=a[sss[r-1]])
	{
		if(!a[sss[l+2]])
		{
			a[sss[l+2]]=a[sss[l]];
			solve2(l+2,r);
		}
		else if(a[sss[r-2]])
		{
			a[sss[r-2]]=a[sss[r]];
			solve2(l,r-2);
		}
		else
			orzzjt();
		return;
	}
	if(!a[sss[l+1]]&&!a[sss[r-1]])
		a[sss[l+1]]=--t;
	a[sss[l+1]]|=a[sss[r-1]];
	a[sss[r-1]]|=a[sss[l+1]];
	solve2(l+1,r-1);
}
void solve(int l,int r)
{
	vector<int> s;
	auto gao=[&s]()
	{
		while(s.size()>=3)
		{
			int sz=s.size();
			if(a[s[sz-1]]&&a[s[sz-2]]&&a[s[sz-3]]&&a[s[sz-3]]==a[s[sz-1]])
			{
				s.pop_back();
				s.pop_back();
			}
			else if(!a[s[sz-1]]&&a[s[sz-2]]&&a[s[sz-3]])
			{
				if(!a[s[sz-2]])
					a[s[sz-2]]=--t;
				a[s[sz-1]]=a[s[sz-3]];
				s.pop_back();
				s.pop_back();
			}
			else if(a[s[sz-1]]&&a[s[sz-2]]&&!a[s[sz-3]])
			{
				if(!a[s[sz-2]])
					a[s[sz-2]]=--t;
				a[s[sz-3]]=a[s[sz-1]];
				s.pop_back();
				s.pop_back();
			}
			else
				break;
		}
	};
//	if(!a[l])
		s.push_back(l);
	for(int i=l+1;i<=r-1;i++)
	{
		if(a[i])
		{
			if(c[a[i]]==1)
				s.push_back(i);
			else
			{
				int sz=g[a[i]].size();
				for(int j=0;j<sz-1;j++)
					solve(g[a[i]][j],g[a[i]][j+1]);
				s.push_back(i);
				i=g[a[i]][sz-1];
			}
		}
		else
			s.push_back(i);
		gao();
//		if(a[l])
//			a[r]=a[l];
	}
//	if(!a[r])
		s.push_back(r);
	gao();
	if(s.size()>1)
	{
		ss=&s;
		solve2(0,s.size()-1);
	}
//	if(!a[l])
//	{
//		int v=--t;
//		a[l]=a[r]=v;
//	}
//	int sz=s.size();
//	for(int i=0;i<sz;i+=2)
//		if(!a[s[i]])
//			a[s[i]]=a[l];
//	int flag=0;
//	for(int i=1;i<sz;i+=2)
//		if(!a[s[i]])
//			flag=1;
//	int z;
//	if(flag)
//		z=--t;
//	for(int i=1;i<sz;i+=2)
//		if(!a[s[i]])
//			a[s[i]]=z;
}
int now=1;
int f[N];
int getnext()
{
	while(c[now])
		now++;
	return now++;
}
namespace zjtakioi2019
{
	int c[N],d[N],st[N],top,e[N],first[N],last[N];
	vector<int> g[N];
	void check()
	{
		for(int i=1;i<=n;i++)
			e[i]=-1;
		for(int i=1;i<=2*n-1;i++)
		{
			if(a[i])
			{
				c[a[i]]++;
				if(~e[a[i]]&&e[a[i]]!=(i&1))
					orzzjt();
				else
					e[a[i]]=i&1;
				g[a[i]].push_back(i);
			}
		}
		for(int i=1;i<=2*n-1;i++)
		{
			if(a[i]&&c[a[i]]>=2)
			{
				d[a[i]]++;
				if(d[a[i]]==1)
				{
					st[++top]=a[i];
					first[a[i]]=i;
				}
				else if(d[a[i]]<c[a[i]])
				{
					if(st[top]!=a[i])
						orzzjt();
				}
				else if(d[a[i]]==c[a[i]])
				{
					if(st[top]!=a[i])
						orzzjt();
					top--;
					last[a[i]]=i;
				}
			}
		}
		if(top)
			orzzjt();
		for(int i=1;i<=n;i++)
			if(c[i]==0)
				orzzjt();
		for(int i=1;i<=n;i++)
			d[i]=0;
		for(int i=1;i<=2*n-1;i++)
		{
			if(top>=2&&st[top-1]==a[i])
				top--;
			else
				st[++top]=a[i];
		}
		if(top!=1)
			orzzjt();
	}
}
using zjtakioi2019::check;
int main()
{
	open("e");
	scanf("%d",&n);
	int pos=0;
	for(int i=1;i<=2*n-1;i++)
		scanf("%d",&a[i]);
	a[1]|=a[2*n-1];
	a[2*n-1]|=a[1];
	for(int i=1;i<=2*n-1;i++)
		if(!pos&&a[i])
			pos=i;
	if(!pos)
	{
		printf("yes\n");
		for(int i=1;i<=n;i++)
			printf("%d ",i);
		for(int i=n-1;i>=1;i--)
			printf("%d ",i);
		return 0;
	}
	int tt=0;
	for(int i=pos;i<=2*n-1;i++)
		aa[++tt]=a[i];
	for(int i=2;i<=pos;i++)
		aa[++tt]=a[i];
	memcpy(a,aa,sizeof(a));
	
	a[2*n-1]=a[1];
	
	for(int i=1;i<=n;i++)
		e[i]=-1;
	for(int i=1;i<=2*n-1;i++)
	{
		c[a[i]]++;
		if(a[i])
		{
			if(~e[a[i]]&&e[a[i]]!=(i&1))
				orzzjt();
			else
				e[a[i]]=i&1;
			g[a[i]].push_back(i);
		}
	}
	for(int i=1;i<=2*n-1;i++)
	{
		if(a[i]&&c[a[i]]>=2)
		{
			d[a[i]]++;
			if(d[a[i]]==1)
			{
				st[++top]=a[i];
				first[a[i]]=i;
			}
			else if(d[a[i]]<c[a[i]])
			{
				if(st[top]!=a[i])
					orzzjt();
			}
			else if(d[a[i]]==c[a[i]])
			{
				if(st[top]!=a[i])
					orzzjt();
				top--;
				last[a[i]]=i;
			}
		}
	}
	if(a[1])
	{
		int sz=g[a[1]].size();
		for(int i=0;i<sz-1;i++)
			solve(g[a[1]][i],g[a[1]][i+1]);
	}
	for(int i=1;i<=-t;i++)
		f[i]=getnext();
	for(int i=1;i<=2*n-1;i++)
		if(a[i]<0)
			a[i]=f[-a[i]];
	check();
	printf("yes\n");
//	for(int i=1;i<=2*n-1;i++)
//		printf("%d ",a[i]);
//	return 1;
	for(int i=2*n-1-pos+1;i<=2*n-1;i++)
		printf("%d ",a[i]);
	for(int i=2;i<=2*n-1-pos+1;i++)
		printf("%d ",a[i]);
//	return 1;
	return 0;
}