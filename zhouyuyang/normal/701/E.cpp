#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 200005
#define ll long long
using namespace std;
struct edge{int to,next;}e[N*2];
ll ans,m,sum[N];
int head[N],n,x,y,tot;
inline int read(){
	int x=0;
	char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-48;
	return x;
}
inline void add(int x,int y){
	e[++tot].to=y;
	e[tot].next=head[x];
	head[x]=tot;
}
void dfs(int x,int fa){
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			dfs(e[i].to,x);
			sum[x]+=sum[e[i].to];
		}
	ans+=min(sum[x],m-sum[x]);
}
int main(){
	n=read();
	m=(ll)2*read();
	for (int i=1;i<=m;i++){
		x=read();
		sum[x]=1;
	}
	for (int i=1;i<n;i++){
		x=read();
		y=read();
		add(x,y);
		add(y,x);
	}
	dfs(1,-1);
	printf("%I64d",ans);
}