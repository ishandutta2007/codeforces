#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
const ll MOD=998244353;

#define fr first
#define sc second
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

int main(){
	string s,t;
	cin>>s>>t;
	int x=t.size();
	while(t.size()<s.size())t+="$";
	int n=s.size();
	int m=t.size();
	
	static ll dp[3005][3005]={};
	for(int i=0;i<m;i++){
		if(t[i]==s[0]||t[i]=='$')dp[i][i+1]=1;
	}
	for(int l=1;l<m;l++){
		for(int i=0;i<m;i++){
			int j=i+l;
			if(j>m)break;
			if(i>0&&(t[i-1]==s[l]||t[i-1]=='$')){
				dp[i-1][j]+=dp[i][j];
				if(dp[i-1][j]>=MOD)dp[i-1][j]-=MOD;
			}
			if(j<m&&(t[j]==s[l]||t[j]=='$')){
				dp[i][j+1]+=dp[i][j];
				if(dp[i][j+1]>=MOD)dp[i][j+1]-=MOD;
			}
		}
	}
	ll ret=0;
	for(int i=x;i<=m;i++){
		ret+=dp[0][i];
	}
	ret*=2;
	ret%=MOD;
	cout<<ret<<endl;
}