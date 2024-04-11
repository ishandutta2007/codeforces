#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,xi[maxn],yi[maxn],mnx,mxx,mny,mxy;
vector<int>G;
int f(int a,int b,int c){
	if(a==b||b==c||a==c)return -1e9;
	int lx=min(min(xi[a],xi[b]),xi[c]);
	int rx=max(max(xi[a],xi[b]),xi[c]);
	int ly=min(min(yi[a],yi[b]),yi[c]);
	int ry=max(max(yi[a],yi[b]),yi[c]);
	return (ry-ly+rx-lx)*2;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&xi[i],&yi[i]);
	mnx=*min_element(xi+1,xi+n+1);
	mxx=*max_element(xi+1,xi+n+1);
	mny=*min_element(yi+1,yi+n+1);
	mxy=*max_element(yi+1,yi+n+1);
	int ans=-1e9;
	for(int i=1;i<=n;++i)
		if(xi[i]==mnx||xi[i]==mxx||yi[i]==mny||yi[i]==mxy)
			G.push_back(i);
	for(int i=1;i<=n;++i)
		for(auto a:G)
			for(auto b:G)
				ans=max(ans,f(a,b,i));
	printf("%d ",ans);
	for(int i=4;i<=n;++i)printf("%d ",(mxy-mny+mxx-mnx)*2);
}