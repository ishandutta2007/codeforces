#include <bits/stdc++.h>
using namespace std;
int n;
int x[51];
int y[51];
int r[51];
string __to_string(int x){
	string res;
	while(x>0){
		res+=char(x%10+48);
		x/=10;
	}
	reverse(res.begin(), res.end());
	if(res.empty()) res="0";
	return res;
}
void solve(int *x){
	int now=x[1];
	int cnt[51];
	int c=x[1];
	for(int i=0; i<=n; i++) cnt[i]=0;
	string ans;
	for(int i=1; i<=n; i++){
		string t="abs((t-"+__to_string(i)+"))";
		string c=__to_string(x[i]/2);
		if (ans.empty()) ans="("+__to_string(x[i]/2)+"*((1-"+t+")+abs(("+t+"-1))))";
		else ans="("+ans+"+("+__to_string(x[i]/2)+"*((1-"+t+")+abs(("+t+"-1)))))";
	}
	cout<<ans<<'\n';;
}
int main(){
	cin>>n;
	for(int i=1; i<=n; i++) cin>>x[i]>>y[i]>>r[i];
	solve(x);
	solve(y);
}