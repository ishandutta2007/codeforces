#include<bits/stdc++.h>
using namespace std;


int w[4001][4001];
int m[4001][4001];

void solve(int l,int r,int L,int R,vector<int>& dp,vector<int>& tmp){
	int mid=(l+r)>>1,k;
	tmp[mid]=dp[L-1]+w[L][mid],k=L;
	for(int i=L+1;i<=min(R,mid);i++)
		if(tmp[mid]>dp[i-1]+w[i][mid])
			k=i,tmp[mid]=dp[i-1]+w[i][mid];
	if(l<mid)	solve(l,mid-1,L,k,dp,tmp);
	if(r>mid)	solve(mid+1,r,k,R,dp,tmp);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	string s;
	getline(cin,s);
	for(int i=1;i<=n;i++){
		getline(cin,s);
		for(int j=1;j<=n;j++)
			m[i][j]=s[(j-1)<<1]-'0';
	}
	for(int l=2;l<=n;l++)
		for(int i=1;i+l-1<=n;i++){
			int j=i+l-1;
			w[i][j]=w[i+1][j]+w[i][j-1]-w[i+1][j-1]+m[i][j];
		}
	vector<int> dp(n+1),tmp(n+1);
	for(int i=1;i<=n;i++)
		dp[i]=w[1][i];
	for(int i=2;i<=k;i++){
		solve(1,n,1,n,dp,tmp);
		swap(dp,tmp);
	}
	cout<<dp[n]<<endl;
}