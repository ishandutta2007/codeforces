#include<bits/stdc++.h>
using namespace std;

const int N = 200001;

int w[N],sz[N],dp1[N],dp2[N],dp3[N],ans;
int mid;
vector<int> e[N];

void predfs(int x,int p){
	sz[x]=1;
	for(int i=0;i<e[x].size();i++)
		if(e[x][i]==p){
			swap(e[x][i],e[x].back());
			e[x].pop_back();
			i--;
		}
		else{
			predfs(e[x][i],x);
			sz[x]+=sz[e[x][i]];
		}
}

void dfszz(int x){
	dp1[x]=w[x]>=mid;
	dp2[x]=dp3[x]=0;
	for(int it:e[x]){
		dfszz(it);
		if(dp1[x]){
			if(sz[it]==dp1[it])
				dp1[x]+=dp1[it];
			else{
				if(dp2[x]<dp1[it]+dp2[it]){
					dp3[x]=dp2[x];
					dp2[x]=dp1[it]+dp2[it];
				}
				else
					dp3[x]=max(dp3[x],dp1[it]+dp2[it]);
			}
		}
	}
}

void dfs(int x,int y){
	if(y==sz[1]-sz[x])
		ans=max(ans,dp1[x]+dp2[x]+y);
	else
		ans=max(ans,dp1[x]+max(y,dp2[x]));
	for(int it:e[x]){
		int z=dp1[x];
		if(sz[it]==dp1[it]){
			z-=sz[it];
			if(y==sz[1]-sz[x])
				z+=y+dp2[x];
			else
				z+=max(dp2[x],y);
		}
		else{
			int q=(dp1[it]+dp2[it])==dp2[x]?dp3[x]:dp2[x];
			if(y==sz[1]-sz[x])
				z+=y+q;
			else
				z+=max(q,y);
		}
		if(w[x]<mid)	z=0;
		dfs(it,z);
	}
}

bool check(int k){
	ans=0;
	dfszz(1);
	dfs(1,0);
	return ans>=k;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	predfs(1,0);
	int l=1,r=1000000;
	while(l<r){
		mid=(l+r+1)>>1;
		if(check(k))
			l=mid;
		else
			r=mid-1;
	}
	cout<<l<<endl;
}