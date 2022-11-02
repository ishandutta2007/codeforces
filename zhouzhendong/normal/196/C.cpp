#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1505;
int n;
struct Gragh{
	int cnt,y[N*2],nxt[N*2],fst[N];
	void clear(){
		cnt=0;
		memset(fst,0,sizeof fst);
	}
	void add(int a,int b){
		y[++cnt]=b,nxt[cnt]=fst[a],fst[a]=cnt;
	}
}g;
struct Point{
	int x,y,id,ans;
}p[N],O;
bool cmpAngle(Point a,Point b){
	return 1LL*(a.y-O.y)*(b.x-O.x)<1LL*(b.y-O.y)*(a.x-O.x);
}
bool cmpid(Point a,Point b){
	return a.id<b.id;
}
int size[N];
void dfs(int x,int pre){
	size[x]=1;
	for (int i=g.fst[x];i;i=g.nxt[i])
		if (g.y[i]!=pre){
			dfs(g.y[i],x);
			size[x]+=size[g.y[i]];
		}
}
void solve(int x,int pre,int L,int R){
	for (int i=L+1;i<=R;i++)
		if (p[i].y<p[L].y||(p[i].y==p[L].y&&p[i].x<p[L].x))
			swap(p[i],p[L]);
	O=p[L];
	sort(p+L+1,p+R+1,cmpAngle);
	p[L++].ans=x;
	for (int i=g.fst[x];i;i=g.nxt[i])
		if (g.y[i]!=pre){
			solve(g.y[i],x,L,L+size[g.y[i]]-1);
			L+=size[g.y[i]];
		}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		g.add(a,b);
		g.add(b,a);
	}
	for (int i=1;i<=n;i++)
		scanf("%d%d",&p[i].x,&p[i].y),p[i].id=i;
	dfs(1,0);
	solve(1,0,1,n);
	sort(p+1,p+n+1,cmpid);
	for (int i=1;i<=n;i++)
		printf("%d ",p[i].ans);
	return 0;
}