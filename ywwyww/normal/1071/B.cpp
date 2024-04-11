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
using std::queue;
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
int n,k;
int f[N][N];
char str[N][N];
bool b[N][N];
vector<pii> q,q2;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%s",str[i]+1);
	memset(f,0x7f,sizeof f);
	f[1][1]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(str[i][j]!='a')
				f[i][j]++;
			if(i<n)
				upmin(f[i+1][j],f[i][j]);
			if(j<n)
				upmin(f[i][j+1],f[i][j]);
		}
	int s=-1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(f[i][j]<=k)
				s=max(s,i+j);
	for(int i=1;i<=s-1;i++)
		putchar('a');
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(f[i][j]<=k&&i+j==s)
				q.push_back(pii(i,j));
	if(s==-1)
	{
		putchar(str[1][1]);
		q.push_back(pii(1,1));
	}
	while(q.front().first!=n||q.front().second!=n)
	{
		int s=0x7fffffff;
		for(auto v:q)
		{
			if(v.first<n)
				s=min(s,(int)str[v.first+1][v.second]);
			if(v.second<n)
				s=min(s,(int)str[v.first][v.second+1]);
		}
		putchar(s);
		for(auto v:q)
		{
			if(v.first<n&&str[v.first+1][v.second]==s&&!b[v.first+1][v.second])
			{
				b[v.first+1][v.second]=1;
				q2.push_back(pii(v.first+1,v.second));
			}
			if(v.second<n&&str[v.first][v.second+1]==s&&!b[v.first][v.second+1])
			{
				b[v.first][v.second+1]=1;
				q2.push_back(pii(v.first,v.second+1));
			}
		}
		q=q2;
		q2.clear();
	}
	return 0;
}