#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m,a[100100];
map<int,vector<pii> >st;
vector<int> G;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;++i)scanf("%d",&a[i]);
	a[++n]=1e9;
	sort(a+1,a+n+1);
	for(int i=1,x1,x2,y;i<=m;++i)scanf("%d%d%d",&x1,&x2,&y),st[y].push_back(pii(x1,x2));
	for(auto& s:st){
		int nw=0;
		sort(s.second.begin(),s.second.end());
		for(auto p:s.second)
			if(p.first!=nw+1)break;
			else nw=p.second;
		G.push_back(nw);
	}
	sort(G.begin(),G.end());
	int ans=1<<20,cnt=G.size();
	for(int i=1,j=0;i<=n;++i){
		while(j<G.size()&&G[j]<a[i])j++,cnt--;
		ans=min(ans,i-1+cnt);
	}
	printf("%d",ans);
}