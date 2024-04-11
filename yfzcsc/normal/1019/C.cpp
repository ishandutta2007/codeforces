#include<bits/stdc++.h>
#define maxn 1010000
using namespace std;
int n,m,tg[maxn]; 
vector<int>G[maxn],ans1,ans2;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
	}
	for(int i=1;i<=n;++i)if(tg[i]!=1){
		ans1.push_back(i);
		for(auto c:G[i])tg[c]=1;
	}
	for(int i=ans1.size()-1;i>=0;--i)if(tg[ans1[i]]!=2){
		ans2.push_back(ans1[i]);
		for(auto c:G[ans1[i]])tg[c]=2;
	}
	printf("%d\n",ans2.size());
	for(auto c:ans2)printf("%d ",c);
}