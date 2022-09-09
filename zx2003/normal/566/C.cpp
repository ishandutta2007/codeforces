#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef pair<int,int>pii;
int n,ww[N],x,y,z,i;
vector<pii>e[N];
int ss[N],sz[N],rt,sum;bool vi[N];
void getce(int x,int fa){
	sz[x]=ss[x]=1;
	for(pii y:e[x])if(!vi[y.first] && y.first!=fa)getce(y.first,x),sz[x]+=sz[y.first],ss[x]=max(ss[x],sz[y.first]);
	ss[x]=max(ss[x],sum-sz[x]);if(ss[x]<ss[rt])rt=x;
}
double dfs(int x,int fa,int d,int tp){
	double ans=ww[x]*sqrt(d)*(tp?d:1);
	for(pii y:e[x])if(y.first!=fa)ans+=dfs(y.first,x,d+y.second,tp);return ans;
}
int ans1;double ans2;
void solve(int x){
	vi[x]=1;
	double mx=-1e30,z;int id=0;
	for(pii y:e[x])if(!vi[y.first]){
		z=dfs(y.first,x,y.second,0);sz[y.first]>sz[x]?sz[y.first]=sum-sz[x]:0;
		if(z>mx)mx=z,id=y.first;
	}
	z=dfs(x,0,0,1);if(!ans1 || z<ans2)ans1=x,ans2=z;
	if(id)rt=0,sum=sz[id],getce(id,x),solve(rt);
}
int main(){
	scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d",&ww[i]);
	for(i=1;i<n;++i)scanf("%d%d%d",&x,&y,&z),e[x].push_back(pii(y,z)),e[y].push_back(pii(x,z));
	ss[0]=1<<30;rt=0;sum=n;getce(1,0);solve(rt);printf("%d %.8f\n",ans1,ans2);
	return 0;
}