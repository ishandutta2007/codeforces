#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=2e5+5;
int n,a[maxn];ll ans;
int num[1<<18];
bool vis[maxn];
struct dsu
{
	int fa[1<<18],siz[1<<18];
	void prework(){iota(fa+1,fa+(1<<18)+1,1);}
	int get(int x){return x==fa[x]?x:fa[x]=get(fa[x]);}
	void merge(int x,int y)
	{
		int sum=x+y;
		if(!num[x]||!num[y])return;
		x=get(x);y=get(y);
		if(x==y)return;
		ans+=(ll)sum*((vis[x]?1:num[x])+(vis[y]?1:num[y])-1);
		fa[x]=y;vis[y]=1;
	}
}S;
int main()
{
	generate_n(a+1,n=read(),read);
	S.prework();
	int all=(1<<18)-1;
	for(int i=1;i<=n;i++)num[a[i]]++;num[0]++;
	for(int i=all;i>=0;i--)
		for(int j=i;j;j=(j-1)&i)
			S.merge(j,i^j);
	for(int i=1;i<=n;i++)ans-=a[i];
	printf("%lld\n",ans);
	return 0;
}