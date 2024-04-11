#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a,b,i;
bool bb[N];
vector<int>e[N],re[N],ans;
unordered_set<int>s;
void solve(){
	if(s.empty())return;
	int x=*s.begin();
	for(int y:e[x])if(s.count(y))s.erase(y);s.erase(x);
	solve();
	for(int z:re[x])if(bb[z])return;
	bb[x]=1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)scanf("%d%d",&a,&b),e[a].push_back(b),re[b].push_back(a);
	for(i=1;i<=n;++i)s.insert(i);
	solve();
	for(i=1;i<=n;++i)if(bb[i])ans.push_back(i);
	printf("%d\n",int(ans.size()));
	for(int x:ans)printf("%d ",x);puts("");
}