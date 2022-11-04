#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#define ll long long
#define N 150005
using namespace std;
int f[N],sz[N],p[N],n,m,x,y;
int get(int x){return f[x]==x?x:f[x]=get(f[x]);}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) f[i]=i,sz[i]=1;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		x=get(x); y=get(y);
		if (x!=y) f[y]=x,p[x]+=p[y],sz[x]+=sz[y];
		p[x]++; 
	}
	for (int i=1;i<=n;i++){
		x=get(i);
		if ((ll)sz[x]*(sz[x]-1)/2!=(ll)p[x]){
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}