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
int a,b;
vector<int> s1,s2;
int check(int x)
{
	int s=0;
	int v1=a,v2=b;
	for(;x;x=min(x-1,max(v1,v2)))
		if(v1>=v2)
		{
			if(v1>=x)
			{
				v1-=x;
				s++;
			}
			else if(v2>=x)
			{
				v2-=x;
				s++;
			}
		}
		else
		{
			if(v2>=x)
			{
				v2-=x;
				s++;
			}
			else if(v1>=x)
			{
				v1-=x;
				s++;
			}
		}
	return s;
}
int gao(int x)
{
	int s=0;
	int v1=a,v2=b;
	for(;x;x=min(x-1,max(v1,v2)))
		if(v1>=v2)
		{
			if(v1>=x)
			{
				v1-=x;
				s++;
			s1.push_back(x);
			}
			else if(v2>=x)
			{
				v2-=x;
				s++;
			s2.push_back(x);
			}
		}
		else
		{
			if(v2>=x)
			{
				v2-=x;
				s++;
			s2.push_back(x);
			}
			else if(v1>=x)
			{
				v1-=x;
				s++;
			s1.push_back(x);
			}
		}
	return s;
}
int main()
{
	scanf("%d%d",&a,&b);
	int l=1,r=1e9;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid)==mid)
			l=mid;
		else
			r=mid-1;
	}
	gao(l);
	printf("%d\n",s1.size());
	for(auto v:s1)
		printf("%d ",v);
	printf("\n");
	printf("%d\n",s2.size());
	for(auto v:s2)
		printf("%d ",v);
	printf("\n");
	return 0;
}