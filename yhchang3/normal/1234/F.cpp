#include<bits/stdc++.h>
using namespace std;
 
int bit[1<<20];
int dp[1<<20];
bool on[1<<20];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	set<int> now,nxt;
	for(int i=0;i<(1<<20);i++)
		for(int j=0;j<20;j++)
			if((1<<j)&i)
				bit[i]++;
	for(int i=0;i<s.size();i++){
		int cur=1<<(s[i]-'a');
		nxt.insert(cur);
		for(int it:now)
			if(!(it&cur))
				nxt.insert(cur|it);
		now.clear();
		for(int it:nxt)
			dp[it]=bit[it],on[it]=true;
		swap(now,nxt);
	}
	int ans=0;
	for(int i=0;i<(1<<20);i++)
		for(int j=0;j<20;j++)
			if((1<<j)&i)
				dp[i]=max(dp[i],dp[i^(1<<j)]);
	for(int i=0;i<(1<<20);i++)
		if(on[i])
			ans=max(ans,bit[i]+dp[(1<<20)-i-1]);
	cout<<ans<<endl;
}