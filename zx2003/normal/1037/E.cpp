#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
unordered_set<int>e[N];
int n,m,k,ex[N],ey[N],i,ans,ot[N];
bool bb[N];
void del(int x){
	bb[x]=0;--ans;
	for(int y:e[x])e[y].erase(x);
	for(int y:e[x])if(bb[y] && e[y].size()<k)del(y);
	e[x].clear();
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k;
	for(i=1;i<=m;++i)cin>>ex[i]>>ey[i],e[ex[i]].insert(ey[i]),e[ey[i]].insert(ex[i]);
	memset(bb+1,1,n);ans=n;
	for(i=1;i<=n;++i)if(bb[i] && e[i].size()<k)del(i);
	for(i=m;i;--i){
		ot[i]=ans;
		if(bb[ex[i]] && bb[ey[i]]){
			e[ex[i]].erase(ey[i]);
			e[ey[i]].erase(ex[i]);
			if(bb[ex[i]] && e[ex[i]].size()<k)del(ex[i]);
			if(bb[ey[i]] && e[ey[i]].size()<k)del(ey[i]);
		}
	}
	for(i=1;i<=m;++i)cout<<ot[i]<<'\n';
	return 0;
}