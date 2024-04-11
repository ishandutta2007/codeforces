#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;

int n;
int dp[20][200200];
int lvl[200200];
int p[200200];

int kth(int nd,int k){
	int cnt=0;
	while(k>0){
		if(k%2){
			nd=dp[cnt][nd];
		}
		k/=2;
		cnt++;
	}
	return nd;
}
int lca(int a,int b){
	if(lvl[a]>lvl[b]){
		swap(a,b);
	}
	b=kth(b,lvl[b]-lvl[a]);
	if(a==b)return a;
	for(int i=19;i>=0;i--){
		if(dp[i][a]!=dp[i][b]){
			a=dp[i][a];
			b=dp[i][b];
		}
	}
	return dp[0][a];
}
int dist(int a,int b){
	int lc=lca(a,b);
	return lvl[a]+lvl[b]-2*lvl[lc];
}
int sol=0;
int _a=1,_b=1;

int sl[200100];
int main(){
	cin.sync_with_stdio(false);
	cin>>n;
	lvl[1]=1;
	for(int i=0;i<20;i++){
		dp[i][1]=1;
	}
	for(int i=2;i<=n;i++){
		int p;
		cin>>p;
		dp[0][i]=p;
		lvl[i]=lvl[p]+1;
		for(int j=1;j<20;j++){
			dp[j][i]=dp[j-1][dp[j-1][i]];
		}
		int to_a=dist(i,_a);
		int to_b=dist(i,_b);
		int mx=max(to_a,to_b);
		if(mx<=sol){
			sl[i]=sol;
			continue;
		}
		sol=mx;
		sl[i]=sol;
		if(to_a>to_b){
			_b=i;
		} else {
			_a=i;
		}
	}
	for(int i=2;i<=n;i++){
		cout<<sl[i]<<" ";
	}
}