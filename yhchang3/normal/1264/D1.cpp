#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

long long int dp[2000][2000][2][2];
long long int cnt[2000][2000][2][2];
void update(long long int& x,long long int b){
	x=(x+b)%mod;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	if(s.size()==1){
		cout<<0<<endl;
		return 0;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='?'||s[i]=='(')
			cnt[i][i][0][0]++;
		if(s[i]=='?'||s[i]==')')
			cnt[i][i][1][1]++;
	}
	for(int i=0;i+1<s.size();i++){
		int j=i+1;
		if(s[i]=='('||s[i]=='?')
			if(s[j]=='('||s[j]=='?')
				cnt[i][j][0][0]++;
		if(s[i]=='('||s[i]=='?')
			if(s[j]==')'||s[j]=='?')
				cnt[i][j][0][1]++,dp[i][j][0][1]++;
		if(s[i]==')'||s[i]=='?')
			if(s[j]=='('||s[j]=='?')
				cnt[i][j][1][0]++;
		if(s[i]==')'||s[i]=='?')
			if(s[j]==')'||s[j]=='?')
				cnt[i][j][1][1]++;
	}
	for(int l=2;l<s.size();l++){
		for(int i=0;i+l<s.size();i++){
			int j=i+l;
			if(s[i]=='('||s[i]=='?')
				if(s[j]=='('||s[j]=='?'){
					update(cnt[i][j][0][0],cnt[i][j-1][0][1]+cnt[i][j-1][0][0]);
					update(dp[i][j][0][0],dp[i][j-1][0][1]+dp[i][j-1][0][0]);
				}
		if(s[i]=='('||s[i]=='?')
			if(s[j]==')'||s[j]=='?'){
					update(cnt[i][j][0][1],cnt[i][j-1][0][1]+cnt[i][j-1][0][0]);
					update(dp[i][j][0][1],dp[i+1][j-1][0][0]+dp[i+1][j-1][0][1]+dp[i+1][j-1][1][0]+dp[i+1][j-1][1][1]+cnt[i][j][0][1]);
			}
		if(s[i]==')'||s[i]=='?')
			if(s[j]=='('||s[j]=='?'){
					update(cnt[i][j][1][0],cnt[i][j-1][1][0]+cnt[i][j-1][1][1]);
					update(dp[i][j][1][0],dp[i][j-1][1][1]+dp[i][j-1][1][0]);
				
			}
		if(s[i]==')'||s[i]=='?')
			if(s[j]==')'||s[j]=='?'){
					update(cnt[i][j][1][1],cnt[i+1][j][1][1]+cnt[i+1][j][0][1]);
					update(dp[i][j][1][1],dp[i+1][j][1][1]+dp[i+1][j][0][1]);
						
			}
		}
	}
	long long int ans=0;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			ans+=dp[0][s.size()-1][i][j];
	ans=(ans%mod+mod)%mod;
	cout<<ans<<endl;
}