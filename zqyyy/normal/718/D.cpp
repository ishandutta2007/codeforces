#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1e5+7;
int n,tot,deg[N];
map<vector<int>,int>h;
unordered_map<int,int>a[N];
vector<int>G[N];
int dfs(int x,int fa){
	if(a[x].count(fa))return a[x][fa];
	vector<int>vec;
	for(int y:G[x])if(y^fa)vec.push_back(dfs(y,x));
	sort(vec.begin(),vec.end());
	if(!h[vec])h[vec]=++tot;
	return a[x][fa]=h[vec];
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read();
	for(int i=1,x,y;i<n;i++)x=read(),y=read(),G[x].push_back(y),G[y].push_back(x),deg[x]++,deg[y]++;
	set<int>s;
	for(int i=1;i<=n;i++)if(deg[i]<4)s.insert(dfs(i,0));
	printf("%lu\n",s.size());
	return 0;
}