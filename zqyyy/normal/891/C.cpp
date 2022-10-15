#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=5e5+7;
struct Edge{
	int x,y,w,id,dx,dy;
}e[N];
int pa[N];
int find(int x){return pa[x]^x?pa[x]=find(pa[x]):x;}
inline void unin(int x,int y){pa[find(x)]=find(y);}
int n,m;
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)e[i].x=read(),e[i].y=read(),e[i].w=read(),e[i].id=i;
	sort(e+1,e+m+1,[](Edge x,Edge y){return x.w<y.w;});
	for(int i=1;i<=n;i++)pa[i]=i;
	for(int i=1;i<=m;){
		int j=i;
		while(j<=m && e[j].w==e[i].w)e[j].dx=find(e[j].x),e[j].dy=find(e[j].y),j++;
		while(i<j){if(find(e[i].x)^find(e[i].y))unin(e[i].x,e[i].y);i++;}
	}
	sort(e+1,e+m+1,[](Edge x,Edge y){return x.id<y.id;});
	for(int i=1;i<=n;i++)pa[i]=i;
	int Q=read();
	while(Q--){
		int k=read();vector<Edge>E(0);
		for(int i=1;i<=k;i++)E.push_back(e[read()]);
		sort(E.begin(),E.end(),[](Edge x,Edge y){return x.w<y.w;});
		bool flg=1;
		for(int i=0;i<k && flg;){
			int j=i;
			while(j<k && E[j].w==E[i].w){
				if(find(E[j].dx)==find(E[j].dy)){flg=0;break;}
				unin(E[j].dx,E[j].dy),j++;
			}
			while(i<j)pa[E[i].dx]=E[i].dx,pa[E[i].dy]=E[i].dy,i++;
		}
		puts(flg?"YES":"NO");
	}
	return 0;
}