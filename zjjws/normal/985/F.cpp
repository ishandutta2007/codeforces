#include <stdio.h>
#include <algorithm>
#include <vector>
#define LL long long
using namespace std;
const int N=2e5+3;
const int s1=214789;
const int s2=224737;
const int m1=999999937;
const int m2=1000000007;
int n,m;
inline int rin()
{
    int s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)s=-s;
    return s;
}
inline int gc(){char c=getchar();for(;c>'z'||c<'a';c=getchar());return c-'a';}
vector<int>a[26];
vector<LL>b[26];
vector<LL>c[26];
LL sl_1[N];
LL sl_2[N];
int d[27];
int e[27];
int t_1,t_2;
inline void find_right(int x,int R,int &right)
{
	int l=1,r=a[x].size()-1;
	for(;l<=r;)
	{
		int mid=(l+r)>>1;
		if(a[x][mid]<=R)right=mid,l=mid+1;
		else r=mid-1;
	}
	return;
}
inline void find_left(int x,int L,int &left)
{
	int l=1,r=a[x].size()-1;
	for(;l<=r;)
	{
		int mid=(l+r)>>1;
		if(a[x][mid]>=L)left=mid,r=mid-1;
		else l=mid+1;
	}
	return;
}
inline void add_d(int x,int L,int R,int i)
{
	int left=0x3f3f3f3f,right=-1;
	find_left(x,L,left);
	find_right(x,R,right);
	if(left>right)return;
	if(!i)d[++t_1]=(((b[x][right]-(b[x][left]*sl_1[right-left]%m1))+(a[x][left]-L+1)*sl_1[right-left]%m1)%m1+m1)%m1;
	else d[++t_1]=(((c[x][right]-(c[x][left]*sl_2[right-left]%m2))+(a[x][left]-L+1)*sl_2[right-left]%m2)%m2+m2)%m2;
	return;
}
inline void add_e(int x,int L,int R,int i)
{
	int left=0x3f3f3f3f,right=-1;
	find_left(x,L,left);
	find_right(x,R,right);
	if(left>right)return;
	if(!i)e[++t_2]=(((b[x][right]-(b[x][left]*sl_1[right-left]%m1))+(a[x][left]-L+1)*sl_1[right-left]%m1)%m1+m1)%m1;
	else e[++t_2]=(((c[x][right]-(c[x][left]*sl_2[right-left]%m2))+(a[x][left]-L+1)*sl_2[right-left]%m2)%m2+m2)%m2;
	return;
}
inline void work()
{
	t_1=t_2=0;
	int l,r,lens;
	l=rin();r=rin();lens=rin();
	for(int i=0;i<26;i++)add_d(i,l,l+lens-1,0),add_e(i,r,r+lens-1,0);
	if(t_1!=t_2){puts("NO");return;}
	sort(d+1,d+t_1+1);
	sort(e+1,e+t_2+1);
	for(int i=1;i<=t_1;i++)if(d[i]!=e[i]){puts("NO");return;}
	t_1=t_2=0;
	for(int i=0;i<26;i++)add_d(i,l,l+lens-1,1),add_e(i,r,r+lens-1,1);
	if(t_1!=t_2){puts("NO");return;}
	sort(d+1,d+t_1+1);
	sort(e+1,e+t_2+1);
	for(int i=1;i<=t_1;i++)if(d[i]!=e[i]){puts("NO");return;}
	puts("YES");
	return;
}
int main()
{
    int i,j;
    n=rin();m=rin();
	sl_1[0]=sl_2[0]=1;
	for(i=0;i<26;i++)a[i].push_back(0),b[i].push_back(0),c[i].push_back(0);
    for(i=1;i<=n;i++)
	{
		j=gc();
		b[j].push_back(((b[j].back()*s1+i-a[j].back())%m1+m1)%m1);
		c[j].push_back(((c[j].back()*s2+i-a[j].back())%m2+m2)%m2);
		a[j].push_back(i);
		sl_1[i]=sl_1[i-1]*s1%m1;
		sl_2[i]=sl_2[i-1]*s2%m2;
	}
	for(i=1;i<=m;i++)work();
    return 0;
}