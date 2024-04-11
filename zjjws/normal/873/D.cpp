#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAX=1e5+3;
int a[MAX];
int nam=0;
int n,k;
bool bj=0;
inline void dfs(int l,int r,int s)
{
	s--;
	if(s==0){for(int i=l;i<r;i++)a[i]=++nam;return;}
	int s1=s>>1;
	if(s1%2==0)s1++;
	int mid=(l+r)>>1;
	if(s1>0)
	{
		if(mid<r)dfs(mid,r,s1);
		else bj=true;
	}
	if(s-s1>0)
	{
		if(l<mid)dfs(l,mid,s-s1);
		else bj=true;
	}
	
}
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
	n=rin();k=rin();
	if(k%2==0){printf("-1");return 0;}
	
	dfs(0,n,k);
//	for(i=0;i<n;i++)if(a[i]==0){printf("-1");return 0;}
	if(bj){printf("-1");return 0;}
	for(i=0;i<n-1;i++)printf("%d ",a[i]);printf("%d",a[n-1]);
	return 0;
}