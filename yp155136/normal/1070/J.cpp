#include <bits/stdc++.h>
using namespace std;

const int MAX=2e5+5;

int n,m,k;
int cnt[99],dp[MAX];
string s;
int can(){
	for(int i=0;i<=k;i++)	dp[i]=0;
	dp[0]=1;
	for(int i=0;i<26;i++){
		for(int j=k;j>=cnt[i];j--){
			if(dp[j-cnt[i]])	dp[j]=1;
		}
	}
	for(int i=n;i<=k-m;i++)	if(dp[i])	return 1;
	return 0;
}
long long pp(int x){
	for(int i=0;i<=n;i++)	dp[i]=0;
	dp[0]=1;
	for(int i=0;i<26;i++){
		if(i==x)	continue;
		for(int j=n;j>=cnt[i];j--){
			if(dp[j-cnt[i]])	dp[j]=1;
		}
	}
	long long mi=(long long)MAX*MAX;
	for(int i=n;i>=0;i--)
		if(dp[i]&&(i+cnt[x]-(k-m))>=0)
			mi=min(mi,(long long)(n-i)*(i+cnt[x]-(k-m)));
	return mi;
	assert(0);
}
int pro(){
	
	memset(cnt,0,sizeof cnt);
	for(char c:s)	cnt[c-'A']++;
	if(can())	return 0;
	long long mi=(long long)MAX*MAX;
	for(int i=0;i<26;i++){
		if(!cnt[i])	continue;
		mi=min(mi,pp(i));
	}
	return mi;
}
int main(){
	ios::sync_with_stdio(0);	cin.tie(0);
	int t;	cin >> t;
	while(t--){
		cin>>n>>m>>k;
		cin >> s;
		cout<<pro()<< '\n';
	}
	return 0;
}