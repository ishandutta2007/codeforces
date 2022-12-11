#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
#include<vector>
#include<queue>
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
using std::deque;
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
const int N=2010;
int s[N][N];
int sl[N][N],sr[N][N];
int b[N][N];
int a[N][N];
deque<pii> q;
int gao0(int x,int y,int v1,int v2)
{
	if(a[x][y]&&v1<sl[x][y])
	{
		sl[x][y]=v1;
		sr[x][y]=v2;
		if(b[x][y]!=2)
		{
			b[x][y]=2;
			q.push_front(pii(x,y));
		}
	}
}
int gao1(int x,int y,int v1,int v2)
{
	if(a[x][y]&&v1<sl[x][y])
	{
		sl[x][y]=v1;
		sr[x][y]=v2;
		if(b[x][y]==0)
		{
			b[x][y]=1;
			q.push_back(pii(x,y));
		}
	}
}
char str[N];
int sx,sy,n,m,s1,s2;
void bfs()
{
	memset(sl,0x7f,sizeof sl);
	memset(sr,0x7f,sizeof sr);
	q.push_back(pii(sx,sy));
	s[sx][sy]=1;
	sl[sx][sy]=0;
	sr[sx][sy]=0;
	while(!q.empty())
	{
		pii x=q.front();
		q.pop_front();
		s[x.first][x.second]=1;
		int v1=sl[x.first][x.second];
		int v2=sr[x.first][x.second];
		gao1(x.first,x.second-1,v1+1,v2);
		gao1(x.first,x.second+1,v1,v2+1);
		gao0(x.first-1,x.second,v1,v2);
		gao0(x.first+1,x.second,v1,v2);
	}
}
int main()
{
	open("b");
	scanf("%d%d",&n,&m);
	scanf("%d%d",&sx,&sy);
	scanf("%d%d",&s1,&s2);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str+1);
		for(int j=1;j<=m;j++)
			if(str[j]=='.')
				a[i][j]=1;
			else
				a[i][j]=0;
	}
	bfs();
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans+=(s[i][j]&&sl[i][j]<=s1&&sr[i][j]<=s2);
	printf("%d\n",ans);
	return 0;
}