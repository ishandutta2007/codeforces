#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

template<class T> T T_INF(){ return 1000000000000000000; }
template<> int T_INF<int>(){ return 1000000000; }

string s,t;
int dp[100010];
void solve(){
	for(int i=0;i<s.size()+5;i++)dp[i]=-1;
	for(int i=0;i<s.size();i++){
		if((i+t.size())%2==s.size()%2&&s[i]==t[0])dp[i+1]=1;
		if(i>0)dp[i+1]=max(dp[i+1],dp[i-1]);
		if(0<=dp[i]&&dp[i]<t.size()&&t[dp[i]]==s[i])dp[i+1]=max(dp[i+1],dp[i]+1);
		else dp[i+1]=max(dp[i+1],dp[i]-1);
	}
	if(dp[s.size()]==t.size())puts("YES");
	else puts("NO");
}

int main(){
	int q;
	scanf("%d",&q);
	for(;q>0;q--){
		cin>>s>>t;
		solve();
	}
}