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
const int N=1010;
int a[N];
int b[N];
int ans[N][N];
int n;
int main()
{
	scanf("%d",&n);
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=i)
			flag=0;
	}
	if(flag)
	{
		printf("%d\n",n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				putchar('.');
			putchar('\n');
		}
		return 0;
	}
	int y;
	int t=0;
	for(int i=1;i<=n;i++)
		if(!b[i]&&a[i]!=i)
		{
			int x=i;
			flag++;
			if(flag!=1)
			{
				t++;
				if(y<x)
					ans[t][x]=ans[t][y]=1;
				else
					ans[t][x]=ans[t][y]=2;
				t--;
			}
			else
				x=a[x];
			int last=x;
			b[x]=1;
			for(int j=a[x];!b[j];j=a[j])
			{
				b[j]=1;
				if(last<j)
				{
					t++;
					ans[t][j]=ans[t][last]=1;
				}
				else
				{
					t++;
					ans[t][j]=ans[t][last]=2;
				}
				last=j;
			}
			if(flag==1)
				y=last;
			else
			{
				t++;
				if(last<y)
					ans[t][y]=ans[t][last]=1;
				else
					ans[t][y]=ans[t][last]=2;
			}
		}
	printf("%d\n",n-1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			if(ans[i][j]==1)
				putchar('/');
			else if(ans[i][j]==2)
				putchar('\\');
			else
				putchar('.');
		putchar('\n');
	}
	return 0;
}