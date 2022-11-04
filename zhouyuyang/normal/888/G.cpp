#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,ch[N*31][2],id=1;
vector<int> e[N*31];
int ask(int x,int d,int v){
	if (d<0) return 0;
	int w=(v>>d)&1;
	if (ch[x][w]) return ask(ch[x][w],d-1,v);
	return ask(ch[x][w^1],d-1,v)+(1<<d);
}
long long ans;
void solve(int x,int d){
	int lc=ch[x][0],rc=ch[x][1];
	if (lc&&rc){
		int Mn=2e9;
		if (e[lc].size()>e[rc].size()) swap(lc,rc);
		for (int i=0;i<e[lc].size();i++)
			Mn=min(Mn,ask(rc,d-1,e[lc][i]));
		ans+=Mn+(1<<d);
	}
	if (lc) solve(lc,d-1);
	if (rc) solve(rc,d-1);
}
int main(){
	scanf("%d",&n);
	for (;n--;){
		int v,x=1;
		scanf("%d",&v);
		for (int i=29;i>=0;i--){
			int t=(v>>i)&1;
			if (!ch[x][t]) ch[x][t]=++id;
			x=ch[x][t];
			e[x].push_back(v);
		}
	}
	solve(1,29);
	printf("%I64d",ans);
}