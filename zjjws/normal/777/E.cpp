#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <queue>
#define LL long long
using namespace std;
const int MAX=1e5+3;
LL f[MAX];
struct milk
{
	int x,y,h;
}a[MAX];
struct cow
{
	int x;
	bool operator <(const cow y)const
	{
		return f[x]<f[y.x];
	}
};
priority_queue<cow,vector<cow>,less<cow> >q;
inline bool myru(milk x,milk y){return x.y>y.y;}
LL rin()
{
	LL s=0;
	char c=getchar();
	bool bj=0;
	for(;(c>'9'||c<'0')&&c!='-';c=getchar());
	if(c=='-')bj=1,c=getchar();
	for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
	if(bj)return -s;
	return s;
}
int main()
{
    int i,j;
    int n;
    n=rin();
    for(i=1;i<=n;i++)a[i].x=rin(),a[i].y=rin(),a[i].h=rin();
    sort(a+1,a+n+1,myru);
    int l=1,r;
    int n_2=0;
    for(;l<=n;){n_2++;LL h_s=a[l].h;int min_x=a[l].x;for(r=l;r<n&&a[r+1].y==a[l].y;r++)h_s+=a[r+1].h,min_x=min(min_x,a[r+1].x);a[n_2].x=min_x,a[n_2].y=a[l].y,a[n_2].h=h_s;l=r+1;}
    LL ans=0;
    f[0]=0;
    a[0].y=0x3f3f3f3f,a[0].x=0;
    cow md;
    md.x=0;q.push(md);
    for(i=1;i<=n_2;i++)
    {
    	for(;!q.empty()&&a[q.top().x].x>=a[i].y;q.pop());
    	f[i]=f[q.top().x]+a[i].h;
    	ans=max(ans,f[i]);
    	md.x=i;q.push(md);
	}
	printf("%lld",ans);
//	printf("\n");for(i=1;i<=n_2;i++)printf("f[%d]:%d ; ",i,f[i]);
	return 0;
}