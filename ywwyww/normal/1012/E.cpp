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
int rd(){int s=0,c,b=0;while(((c=getchar())<'0'||c>'9')&&c!='-');if(c=='-'){c=getchar();b=1;}do{s=s*10+c-'0';}while((c=getchar())>='0'&&c<='9');return b?-s:s;}
void put(int x){if(!x){putchar('0');return;}static int c[20];int t=0;while(x){c[++t]=x%10;x/=10;}while(t)putchar(c[t--]+'0');}
int upmin(int &a,int b){if(b<a){a=b;return 1;}return 0;}
int upmax(int &a,int b){if(b>a){a=b;return 1;}return 0;}
const int N=200010;
int n,m;
int a[N],b[N],c[N];
int d[N];
vector<pii> g[N];
int cnt;
vector<int> s[N];
void dfs(int x)
{
	while(!g[x].empty())
	{
		auto v=g[x].back();
		g[x].pop_back();
		dfs(v.first);
		s[cnt].push_back(v.second);
	}
}
int main()
{
	open("cf1012e");
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
		c[i]=a[i];
	}
	sort(b+1,b+n+1);
	sort(c+1,c+n+1);
	int t=unique(c+1,c+n+1)-c-1;
	for(int i=1;i<=n;i++)
	{
		a[i]=lower_bound(c+1,c+t+1,a[i])-c;
		b[i]=lower_bound(c+1,c+t+1,b[i])-c;
	}
	for(int i=1;i<=n;i++)
		if(a[i]!=b[i])
			g[a[i]].push_back(pii(b[i],i));
	for(int i=1;i<=t;i++)
	{
		cnt++;
		dfs(i);
		if(s[cnt].empty())
			cnt--;
	}
	int sum=0;
	for(int i=1;i<=cnt;i++)
		sum+=s[i].size();
	if(sum>m)
	{
		printf("-1\n");
		return 0;
	}
	if(cnt==0)
	{
		printf("0\n");
		return 0;
	}
	if(cnt==1)
	{
		printf("1\n%d\n",sum);
		for(auto v:s[1])
			printf("%d ",v);
		printf("\n");
		return 0;
	}
	for(int i=cnt;i>=2;i--)
		if(i+sum<=m)
		{
			printf("%d\n",cnt-i+2);
			int sum1=0;
			for(int j=1;j<=i;j++)
				sum1+=s[j].size();
			printf("%d\n",sum1);
			for(int j=1;j<=i;j++)
				for(auto v:s[j])
					printf("%d ",v);
			printf("\n");
			printf("%d\n",i);
			for(int j=i;j>=1;j--)
				printf("%d ",s[j].front());
			for(int j=i+1;j<=cnt;j++)
			{
				printf("%d\n",(int)s[j].size());
				for(auto v:s[j])
					printf("%d ",v);
				printf("\n");
			}
			return 0;
		}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
	{
		printf("%d\n",(int)s[i].size());
		for(auto v:s[i])
			printf("%d ",v);
		printf("\n");
	}
	return 0;
}