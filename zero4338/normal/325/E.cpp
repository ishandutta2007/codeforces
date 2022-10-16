#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e5+5;
int n;
struct dsu
{
	int fa[maxn];
	void prework(){for(int i=0;i<n;i++)fa[i]=i;}
	int get(int x){return x==fa[x]?x:fa[x]=get(fa[x]);}
	void merge(int x,int y){fa[get(x)]=get(y);}
	bool check(int x,int y){return get(x)==get(y);}
}S;
int to[maxn];
void add(int x,int y){x%=n;y%=n;to[x]=y;S.merge(x,y);}
int main()
{
	n=read();
	if(n&1){puts("-1");return 0;}
	S.prework();
	for(int i=0;i<(n>>1);i++)add(i,i<<1),add(i+(n>>1),i<<1|1);
	for(int i=0;i<(n>>1);i++)if(!S.check(i,i+(n>>1)))add(i,i<<1|1),add(i+(n>>1),i<<1);
	int now=0;
	for(int i=0;i<=n;i++){printf("%d ",now);now=to[now];}printf("\n");
	return 0;
}