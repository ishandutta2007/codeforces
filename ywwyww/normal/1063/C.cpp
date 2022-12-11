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
char str[10];
char str1[10];
int n;
int main()
{
	scanf("%d",&n);
	int l=0,r=1e9;
	printf("0 0\n");
	fflush(stdout);
	scanf("%s",str1+1);
	for(int i=2;i<=n;i++)
	{
		int mid=(l+r)>>1;
		printf("%d %d\n",mid,0);
		fflush(stdout);
		scanf("%s",str+1);
		if(str[1]==str1[1])
			l=mid;
		else
			r=mid;
	}
	if(l+2<=1e9)
		printf("%d %d %d %d\n",l+1,1,l+2,3);
	else
		printf("%d %d %d %d\n",l,1,l-1,3);
	fflush(stdout);
	return 0;
}