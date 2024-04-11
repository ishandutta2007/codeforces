#include<map>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 100005
using namespace std;
int n,p,q,fl;
int sz[N],f[N],ans[N],vec[N][2],a[N],tg[N];
map<int,int> vis;
int get(int x){
	return f[x]==x?x:f[x]=get(f[x]); 
}
void uni(int x,int y){
	if (!y) return;
	x=get(x); y=get(y);
	if (x!=y) f[x]=y,sz[y]+=sz[x],tg[y]|=tg[x];
}
int main(){
	scanf("%d%d%d",&n,&p,&q);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		vis[a[i]]=i;
	}
	for (int i=1;i<=n;i++)
		f[i]=i,sz[i]=1;
	for (int i=1;i<=n;i++){
		fl=0; int x=vis[p-a[i]];
		if (x){
			vec[i][0]=x;
			fl=1;
		}
		x=vis[q-a[i]];
		if (x){
			vec[i][1]=x;
			fl=1;
		}
		if (a[i]==p/2||a[i]==q/2) tg[i]=1;
		if (!fl){
			puts("NO");
			return 0;
		}
	}
	for (int i=1;i<=n;i++)
		uni(i,vec[i][0]),uni(i,vec[i][1]);
	for (int i=1;i<=n;i++)
		if ((sz[get(i)]&1)&&!tg[i]){
			puts("NO");
			return 0;
		}
	puts("YES");
	for (int i=1;i<=n;i++)
		if (!vec[i][0]) ans[get(i)]=1;
	for (int i=1;i<=n;i++) printf("%d ",ans[get(i)]);
}