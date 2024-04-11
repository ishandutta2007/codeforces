#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a,b,i,d[N],s[2];
vector<int>e[N];
void dfs(int x,int fa){
	d[x]=d[fa]^1;++s[d[x]];
	for(int y:e[x])if(y!=fa)dfs(y,x);
}
int main(){
	scanf("%d",&n);for(i=1;i<n;++i)scanf("%d%d",&a,&b),e[a].push_back(b),e[b].push_back(a);
	dfs(1,0);printf("%d\n",min(s[0],s[1])-1);
}