#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,i,f;
vector<int>e[1005];
bool isf[N],fl;
void dfs(int x){
	if(e[x].size()==0)isf[x]=1;int s=0;
	for(int i=0;i<e[x].size();++i){
		dfs(e[x][i]);s+=isf[e[x][i]];
	}
	if(e[x].size()>0 && s<3)fl=1;
}
int main(){
	cin>>n;
	for(i=2;i<=n;++i)cin>>f,e[f].push_back(i);
	dfs(1);puts(fl?"No":"Yes");
	return 0;
}