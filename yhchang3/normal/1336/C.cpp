#include<bits/stdc++.h>
using namespace std;

string s,t;
int n,m;

const int mod = 998244353;

void add(int &x,int y){
	x+=y;
	if(x>=mod)	x-=mod;
}

bool equal(int x,int y){
	if(y>=t.size()||t[y]==s[x])	return true;
	else	return false;
}

int dp[3010][3010];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>s>>t;
	n=s.size(),m=t.size();
	for(int i=0;i<n;i++)
		if(equal(0,i))
			dp[0][i]=2;
	for(int i=1;i<n;i++){
		for(int l=0;l+i<n;l++){
			int r = l+i;
			if(equal(i,l))
				add(dp[i][l],dp[i-1][l+1]);
			if(equal(i,r))
				add(dp[i][l],dp[i-1][l]);
		}
	}
	int ans = 0;
	for(int i=m-1;i<n;i++)
		add(ans,dp[i][0]);
	cout<<ans<<endl;
}