#include<bits/stdc++.h>
using namespace std;
 
int visit[40],deg[40],n,m;
vector<long long int> component[7];
bool e[40][40];
// 0: no 0
// 1: no 1
// 2: no 2
// 3: no 0 1
// 4: no 0 2
// 5: no 1 2
 
vector<int> now;
long long int Mask[40];
bool bipartite(int x){
	bool ok=true;
	for(int i=0;i<n;i++)
		if(e[x][i]){
			if(visit[i]){
				if(visit[i]+visit[x]!=3)	return false;
			}
			else{
				visit[i]=3-visit[x];
				ok&=bipartite(i);
			}
		}
	return ok;
}
long long int F(long long int mask,int N,int where){
	if(mask==0)	return 1;
	int cur;
	for(cur=where;;cur++)
		if(mask&(1LL<<cur))
			break;
	long long int x=mask;
    x^=(1LL<<cur);
    long long int res=F(x,N,cur+1);
    long long int tmp=x&Mask[now[cur]];
    if(!tmp)
    	return res*2;
    else
    	return res+F(x^tmp,N,cur+1);
}

void dfs(int x){
	visit[x]=1;
	now.emplace_back(x);
	for(int i=0;i<n;i++)
		if(e[x][i])
			if(!visit[i])
				dfs(i);
}


void solve(int x){
	if(deg[x]==0){
		for(int i=0;i<7;i++)
			component[i].emplace_back(2);
		return;
	}
	now.clear();
	dfs(x);
	for(int it:now)
		visit[it]=false;
	for(int i=0;i<now.size();i++)
		for(int j=0;j<now.size();j++)
			if(e[now[i]][now[j]])
				Mask[now[i]]|=(1LL<<j);
	long long int tmp=F((1LL<<(now.size()))-1,now.size(),0);
	component[0].emplace_back(tmp);
	component[1].emplace_back(2);
	component[2].emplace_back(tmp);
	component[3].emplace_back(1);
	for(int it:now)
		visit[it]=false;
	visit[x]=1;
	if(bipartite(x))	component[4].emplace_back(2);
	else component[4].emplace_back(0);
	component[5].emplace_back(1);
	component[6].emplace_back(0); 
	for(int it:now)
		visit[it]=true;
}
 
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y;
		x--;y--;
		e[x][y]=e[y][x]=true;
		deg[x]++;deg[y]++;
	}
	for(int i=0;i<n;i++)
		if(!visit[i])
			solve(i);
	for(int i=0;i<7;i++)
		for(int j=1;j<component[i].size();j++)
			component[i][0]*=component[i][j];
	cout<<(1LL<<n)-(component[0][0]+component[1][0]+component[2][0]-component[3][0]-component[4][0]-component[5][0]+component[6][0]);
}