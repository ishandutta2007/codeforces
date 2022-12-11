#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
#include<vector>
#include<unordered_set>
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
using std::unordered_set;
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
bool f[1010][N];
bool s[7000007];
char str[N];
int n;
int h[N];
int main()
{
	open("f");
	scanf("%d",&n);
	scanf("%s",str+1);
	int ans=1;
	memset(f[1],1,sizeof f[1]);
	for(int j=1;j<=n;j++)
		h[j]=str[j]-'a'+1;
	for(int i=2;i<=1000;i++)
	{
		memset(s,0,sizeof s);
		for(int j=n-i+1;j>=1;j--)
		{
			if(j+i<=n&&f[i-1][j+i])
				s[h[j+i]]=1;
			if(s[h[j]]||s[h[j+1]])
			{
				ans=i;
				f[i][j]=1;
			}
		}
		for(int j=1;j<=n-i+1;j++)
			h[j]=(h[j]*129+str[j+i-1]-'a'+1)%7000007;
	}
	printf("%d\n",ans);
	return 0;
}