#include <bits/stdc++.h>
using namespace std;
const int N=100005;
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
int n,size[N],ans=-1;
void dfs(int x,int pre){
	size[x]=1;
	for (int i=g.fst[x];i;i=g.nxt[i])
		if (g.y[i]!=pre){
			dfs(g.y[i],x);
			size[x]+=size[g.y[i]];
		}
	if (size[x]%2==0)
		ans++;
}
int main(){
	scanf("%d",&n);
	for (int i=1,a,b;i<n;i++){
		scanf("%d%d",&a,&b);
		g.add(a,b);
		g.add(b,a);
	}
	if (n%2){
		puts("-1");
		return 0;
	}
	dfs(1,0);
	printf("%d",ans);
	return 0;
}