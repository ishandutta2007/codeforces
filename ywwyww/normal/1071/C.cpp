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
const int N=100010;
int a[N];
int n;
int t=0;
int ans1[N],ans2[N],ans3[N];
void gao(int x,int y,int z)
{
	t++;
	ans1[t]=x;
	ans2[t]=y;
	ans3[t]=z;
//	printf("%d %d %d\n",x,y,z);
	a[x]^=1;
	a[y]^=1;
	a[z]^=1;
}
int main()
{
	open("c");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int l=1,r=n;
	while(r-l+1>=10)
	{
		while(r-l+1>=10&&!a[r])
			r--;
		while(r-l+1>=10&&!a[l])
			l++;
		if(r-l+1<10)
			break;
		if(a[l]&&a[l+1]&&a[l+2])
			gao(l,l+1,l+2);
		else if(a[r]&&a[r-1]&&a[r-2])
			gao(r-2,r-1,r);
		else if(a[l]&&!a[l+1]&&!a[l+2])
			gao(l,l+3,l+6);
		else if(a[l]&&!a[l+1]&&a[l+2])
			gao(l,l+2,l+4);
		else if(a[r]&&!a[r-1]&&!a[r-2])
			gao(r-6,r-3,r);
		else if(a[r]&&!a[r-1]&&a[r-2])
			gao(r-4,r-2,r);
		else if((r-l)&1)
		{
			gao(l,(l+r-1)/2,r-1);
			gao(l+1,(l+r+1)/2,r);
		}
		else
		{
			gao(l,(l+r)/2,r);
			gao(l+1,(l+r)/2,r-1);
		}
	}
	for(int i=l;i<=r-2;i++)
		if(a[i])
			gao(i,i+1,i+2);
	if(a[r])
	{
		if(r>=7)
		{
			gao(r-6,r-3,r);
			gao(r-6,r-5,r-4);
			gao(r-5,r-4,r-3);
		}
		else
		{
			printf("NO\n");
			return 0;
		}
	}
	if(a[r-1])
	{
		if(r>=8)
		{
			gao(r-7,r-4,r-1);
			gao(r-7,r-6,r-5);
			gao(r-6,r-5,r-4);
		}
		else
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	printf("%d\n",t);
	for(int i=1;i<=t;i++)
		printf("%d %d %d\n",ans1[i],ans2[i],ans3[i]);
	return 0;
}