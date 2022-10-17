#include <bits/stdc++.h>
using namespace std;

string s;

bool used[100010];

void solve(){
	for(int i=0;i<s.size();i++)used[i]=false;
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(used[i])continue;
		if(i+1<s.size()&&!used[i+1]&&s[i]==s[i+1]){
			used[i+1]=true;
			cnt++;
		}
		if(i+2<s.size()&&!used[i+2]&&s[i]==s[i+2]){
			used[i+2]=true;
			cnt++;
		}
	}
	printf("%d\n",cnt);
}

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		cin>>s;
		solve();
	}
}