#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAX=1e6+3;
struct milk
{
	int to,next;
}a[MAX<<1];
bool vit[MAX];
int f[20][MAX];
int h[MAX];
int d[MAX];
int ans[MAX];
int nam=0;
inline void dfs(int x){for(int i=h[x];i>0;i=a[i].next)if(d[a[i].to]==0)d[a[i].to]=d[x]+1,f[0][a[i].to]=x,dfs(a[i].to);}
inline void add(int x,int y,int i){a[i].to=y;a[i].next=h[x];h[x]=i;}
LL rin()
{
	LL s=0;
	char c=getchar();
	bool bj=0;
	for(;(c>'9'||c<'0')&&c!='-';c=getchar());
	if(c=='-')bj=true,c=getchar();
	for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
	if(bj)return -s;
	return s;
}
int main() {
	int i,j;
	int n,k;
	n=rin();k=rin();
	int x,y;
	for(i=1;i<n;i++)x=rin(),y=rin(),add(x,y,i),add(y,x,i+n);
	d[n]=1;
	dfs(n);
	
	f[0][n]=n;
	vit[n]=true;
	k=n-k;
	k--;
	for(i=1;(1<<i)<=n;i++)for(j=1;j<=n;j++)f[i][j]=f[i-1][f[i-1][j]];
	for(i=n-1;i>=1;i--)
	if(!vit[i])
	{
		int s=0;
		j=i;
		for(;s>=0;)
		{
			if((1<<s)>d[j]||vit[f[s][j]]==true)s--;
			else j=f[s][j],s++;
		}
		j=f[0][j];
		if(d[i]-d[j]<=k)
		{
			k-=(d[i]-d[j]);
			for(x=i;x!=j;x=f[0][x])vit[x]=true;
		}
		
	}
	for(i=1;i<=n;i++)if(!vit[i])printf("%d ",i);
	return 0;
}