#include<bits/stdc++.h>
using namespace std;
#define ll long long
char s[1000010];
int dp[26][1000010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>(s+1);
		int n=strlen(s+1);
		int ans=0;
		char pre1=0,pre2=0;
		for(int i=1;i<=n;i++){
			char now=s[i];
			if(s[i]==pre1||s[i]==pre2){
				now=-1;
				ans++;
			}
			pre2=pre1;
			pre1=now;
		}
		cout<<ans<<"\n";
	}
}