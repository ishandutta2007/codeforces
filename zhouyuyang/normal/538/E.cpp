#include<bits/stdc++.h>
#define N 200005
using namespace std;
int mx[N],mn[N],w[N];
vector<int> e[N];
void dfs(int x){
	if (e[x].size()==0){
		w[x]=mx[x]=mn[x]=1;
		return;
	}
	int mv=1<<30;
	for (int i=0;i<e[x].size();i++){
		int y=e[x][i];
		dfs(y); w[x]+=w[y];
		mv=min(mv,mn[y]);
		mn[x]+=w[y]-mx[y]+1;
	}
	mx[x]=w[x]-mv+1;
}
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
	}
	dfs(1);
	printf("%d %d",mx[1],mn[1]);
}